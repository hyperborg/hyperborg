/* This device file is from the HyperBorg testpad for testing an array of
   BME688 sensors. It is intentionally commented out, since it is not yet
   compatible with HFS!
*/

/*
#include <iostream>

extern "C"
{
    #include <linux/i2c-dev.h>
    #include <i2c/smbus.h>
}

#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    printf("BME688 TEST!\n");

    int file;
    int adapter_nr = 14; // 13 - 010V, 14-BME688
    char filename[20];

    snprintf(filename, 19, "/dev/i2c-%d", adapter_nr);
    file = open(filename, O_RDWR);
    if (file < 0) {
      printf("cannot open device\n");
      // ERROR HANDLING; you can check errno to see what went wrong 
      exit(1);
    }

//    int addr = 0x5f;      // 0x5f 010V
    int addr = 0x77;        // 0x77 BME688

    if (ioctl(file, I2C_SLAVE, addr) < 0) {
      printf("cannot slave\n");
      // ERROR HANDLING; you can check errno to see what went wrong
      exit(1);
    }

    // ---------------------------------
    // Temperature reading for BME688
    // ---------------------------------
    // Initializing variables

    __u8 tmp_a;
    __u8 tmp_b;
    __u8 tmp_c;
    unsigned int par_t1 = 0;
    unsigned int par_t2 = 0;
    unsigned int par_t3 = 0;
    unsigned int temp_adc = 0;
    unsigned int press_adc = 0;
    unsigned int hum_adc = 0;
    unsigned int rv = 0;
    unsigned int rv1 = 0;
    unsigned int rv2 = 0;

    // Setting device oversamplings
    printf(" Setting IIR filter control \n");
    tmp_a = 0b00101001;
    i2c_smbus_write_i2c_block_data(file, 0x75, 1, &tmp_a);

    // Setting device oversamplings
    printf(" Setting humidity oversampling \n");
    tmp_a = 0b00000010;
    i2c_smbus_write_i2c_block_data(file, 0x72, 1, &tmp_a);

    printf(" Pre-setting oversamplings and trigger one measurement\n");
    tmp_a = 0b01010101;
    i2c_smbus_write_i2c_block_data(file, 0x74, 1, &tmp_a);

    // reading par_t1
    rv = i2c_smbus_read_i2c_block_data(file, 0xEA, 1, &tmp_a);
    rv = i2c_smbus_read_i2c_block_data(file, 0xE9, 1, &tmp_b);
    par_t1=tmp_a*256+tmp_b;

    // reading par_t2
    rv = i2c_smbus_read_i2c_block_data(file, 0x8B, 1, &tmp_a);
    rv = i2c_smbus_read_i2c_block_data(file, 0x8A, 1, &tmp_b);
    par_t2=tmp_a*256+tmp_b;

    // reading par_t3
    rv = i2c_smbus_read_i2c_block_data(file, 0x8C, 1, &tmp_a);
    par_t3 = tmp_a;

    // reading temp_adc
    rv = i2c_smbus_read_i2c_block_data(file, 0x22, 1, &tmp_a);
    rv = i2c_smbus_read_i2c_block_data(file, 0x23, 1, &tmp_b);
    rv = i2c_smbus_read_i2c_block_data(file, 0x24, 1, &tmp_c);
    tmp_c = tmp_c & 0xF0;
    temp_adc = tmp_a;
    temp_adc = temp_adc << 8;
    temp_adc += tmp_b;
    temp_adc = temp_adc << 8;
    temp_adc +=tmp_c;
    temp_adc = temp_adc >> 4;

    printf("============== \n");

    printf(" par_t1:   %d\n", par_t1);
    printf(" par_t2:   %d\n", par_t2);
    printf(" par_t3:   %d\n", par_t3);
    printf(" temp_adc: %d\n", temp_adc);

    printf("============== \n");


    double var1 = (((double)temp_adc / 16384.0) - ((double)par_t1/1024.0))*(double)par_t2;
    double var2 = ((((double)temp_adc/131072.0) - ((double)par_t1/8192.0)) *
                   (((double)temp_adc/131072.0) - ((double)par_t1/8192.0)))*
                    ((double)par_t3*16.0);
    double var3 = 0;
    double var4 = 0;
    double t_fine = var1 + var2;
    double temp_comp = t_fine/5120.0;

    printf("var1 %f\n", var1);
    printf("var2 %f\n", var2);
    printf("t_fine %f\n", t_fine);
    printf("temp_comp %f\n", temp_comp);
    printf("\n=== PRESSURE ===\n");

    // Pressure calculations
    unsigned int par[11] = {0,0,0,0,0,0,0,0,0,0,0}; // one more for 1 based index
    // reading par_p1
    rv = i2c_smbus_read_i2c_block_data(file, 0x8F, 1, &tmp_a);
    rv = i2c_smbus_read_i2c_block_data(file, 0x8E, 1, &tmp_b);
    par[1]=tmp_a*256+tmp_b;

    // reading par_p2
    rv = i2c_smbus_read_i2c_block_data(file, 0x91, 1, &tmp_a);
    rv = i2c_smbus_read_i2c_block_data(file, 0x90, 1, &tmp_b);
    par[2]=tmp_a*256+tmp_b;

    // reading par_p3
    rv = i2c_smbus_read_i2c_block_data(file, 0x92, 1, &tmp_a);
    par[3]= tmp_a;

    // reading par_p4
    rv = i2c_smbus_read_i2c_block_data(file, 0x95, 1, &tmp_a);
    rv = i2c_smbus_read_i2c_block_data(file, 0x94, 1, &tmp_b);
    par[4]=tmp_a*256+tmp_b;

    // reading par_p5
    rv = i2c_smbus_read_i2c_block_data(file, 0x97, 1, &tmp_a);
    rv = i2c_smbus_read_i2c_block_data(file, 0x96, 1, &tmp_b);
    par[5]=tmp_a*256+tmp_b;

    // reading par_p6
    rv = i2c_smbus_read_i2c_block_data(file, 0x99, 1, &tmp_a);
    par[6]= tmp_a;

    // reading par_p7
    rv = i2c_smbus_read_i2c_block_data(file, 0x98, 1, &tmp_a);
    par[7]= tmp_a;

    // reading par_p8
    rv = i2c_smbus_read_i2c_block_data(file, 0x9D, 1, &tmp_a);
    rv = i2c_smbus_read_i2c_block_data(file, 0x9C, 1, &tmp_b);
    par[8]=tmp_a*256+tmp_b;

    // reading par_p9
    rv = i2c_smbus_read_i2c_block_data(file, 0x9F, 1, &tmp_a);
    rv = i2c_smbus_read_i2c_block_data(file, 0x9E, 1, &tmp_b);
    par[9]=tmp_a*256+tmp_b;

    // reading par_p10
    rv = i2c_smbus_read_i2c_block_data(file, 0xA0, 1, &tmp_a);
    par[10]= tmp_a;


    // reading press_adc
    rv = i2c_smbus_read_i2c_block_data(file, 0x1F, 1, &tmp_a);
    rv = i2c_smbus_read_i2c_block_data(file, 0x20, 1, &tmp_b);
    rv = i2c_smbus_read_i2c_block_data(file, 0x21, 1, &tmp_c);
    tmp_c = tmp_c & 0xF0;
    press_adc = tmp_a;
    press_adc = press_adc << 8;
    press_adc += tmp_b;
    press_adc = press_adc << 8;
    press_adc +=tmp_c;
    press_adc = press_adc >> 4;

    var1 = ((double)t_fine/2.0)-64000.0;
    var2 = var1 * var1 *((double)par[6] / 131072.0);
    var2 = var2 + (var1*(double)par[5] * 2.0);
    var2 = (var2/4.0) +((double)par[4]*65536.0);
    var1 = ((((double)par[3] * var1 * var1) / 16384.0) + ((double)par[2] * var1)) / 524288.0;
    var1 = (1.0 + (var1/32768.0))*(double)par[1];

    double press_comp = 1048576.0 - (double)press_adc;
    press_comp =((press_comp-(var2/4096.0))*6250.0)/var1;
    var1 = ((double)par[9]*press_comp*press_comp)/2147483648.0;
    var2 = press_comp*((double)par[8]/32768.0);
    var3 = (press_comp/256.0)*(press_comp/256.0)*(press_comp/256.0)*(par[10]/131072.0);
    press_comp = press_comp + (var1 + var2 + var3 + ((double)par[7]*128.0))/16.0;

    printf("var1 %f\n", var1);
    printf("var2 %f\n", var2);
    printf("var3 %f\n", var3);
    printf("press_comp %f\n", press_comp);

    printf("\n=== HUMIDITY ===\n");

    unsigned int h[8] = {0,0,0,0,0,0,0,0};  // one more for 1 based index
    double hum_comp = 0;

    // reading par_h1
    rv = i2c_smbus_read_i2c_block_data(file, 0xE3, 1, &tmp_a);
    rv = i2c_smbus_read_i2c_block_data(file, 0xE2, 1, &tmp_b);
    tmp_b = tmp_b & 0x0F;
    h[1] = tmp_a;
    h[1] = h[1]<<4;
    h[1] += tmp_b;

    // reading par_h2
    rv = i2c_smbus_read_i2c_block_data(file, 0xE1, 1, &tmp_a);
    rv = i2c_smbus_read_i2c_block_data(file, 0xE2, 1, &tmp_b);
    tmp_b = tmp_b & 0xF0;
    h[2] = tmp_a*256+tmp_b;
    h[2] = h[2]>>4;

    // reading par_h3
    rv = i2c_smbus_read_i2c_block_data(file, 0xE4, 1, &tmp_a);
    h[3]= tmp_a;

    // reading par_h4
    rv = i2c_smbus_read_i2c_block_data(file, 0xE5, 1, &tmp_a);
    h[4]= tmp_a;

    // reading par_h5
    rv = i2c_smbus_read_i2c_block_data(file, 0xE6, 1, &tmp_a);
    h[5]= tmp_a;

    // reading par_h6
    rv = i2c_smbus_read_i2c_block_data(file, 0xE7, 1, &tmp_a);
    h[6]= tmp_a;

    // reading par_h7
    rv = i2c_smbus_read_i2c_block_data(file, 0xE8, 1, &tmp_a);
    h[7]= tmp_a;

    // reading hum_adc
    rv1 = i2c_smbus_read_i2c_block_data(file, 0x25, 1, &tmp_a);
    rv2 = i2c_smbus_read_i2c_block_data(file, 0x26, 1, &tmp_b);
    printf("\t0x25: %d\n", tmp_a);
    printf("\t0x26: %d\n", tmp_b);
    hum_adc = tmp_a*256 + tmp_b;

    var1 = hum_adc-(((double)h[1] * 16.0) + (((double)h[3]/2.0)*temp_comp));
    var2 = var1*(((double)h[2] / 262144.0) * (1.0+(((double)h[4]/16384.0)*
           temp_comp)+(((double)h[5]/1048576.0) * temp_comp * temp_comp)));
    var3 = (double)h[6]/16384.0;
    var4 = (double)h[7]/2097152.0;

    hum_comp = var2 + ((var3 + (var4*temp_comp)) * var2 * var2);

    printf(" h[1]: %d\n", h[1]);
    printf(" h[2]: %d\n", h[2]);
    printf(" h[3]: %d\n", h[3]);
    printf(" h[4]: %d\n", h[4]);
    printf(" h[5]: %d\n", h[5]);
    printf(" h[6]: %d\n", h[6]);
    printf(" h[7]: %d\n", h[7]);

    printf(" var1:   %f\n", var1);
    printf(" var2:   %f\n", var2);
    printf(" var3:   %f\n", var3);
    printf(" var4:   %f\n", var4);
    printf(" rv1:    %d\n", rv1);
    printf(" rv2:    %d\n", rv2);
    printf(" hum_adc: %d\n", hum_adc);
    printf(" hum_comp: %f\n", hum_comp);

    close(file);

    return 0;
}
*/