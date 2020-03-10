#include <badboy.h>

void badboy::init()
{
    printf("--badboy init--\n");
    nullPtrCall();
    infiniteLoop();
}

void badboy::infiniteLoop()
{
    qDebug() << "INFINITE LOOP";
    log(2, "Badboy is used for infinite loop. Is it a test system?");
    int a=0;
    while(1)
    {
	a++;
	if (a>a+1)
	    a--;
    }
}

void badboy::nullPtrCall()
{
    log(2, "Badboy is used for null ptr call. Is it a test system?");
    qDebug() << "NULL PTR CALL";
    QObject *obj=NULL;
    qDebug() << obj->objectName();
}