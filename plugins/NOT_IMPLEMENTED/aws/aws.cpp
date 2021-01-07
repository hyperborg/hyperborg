#include <aws.h>

aws::aws(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Amazon Web Services (AWS)");
	manifest.insert("domain","aws");
}

aws::~aws()
{
}

void aws::init()
{
}

void aws::async_setup()
{
}


void aws::async_setup_entry()
{
}


void aws::_validate_aws_credentials()
{
}


