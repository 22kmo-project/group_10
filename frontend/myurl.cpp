#include "myurl.h"

MyUrl::MyUrl()
{
    base_url = "http://localhost:3000/";

}

QString MyUrl::getBaseUrl()
{
    return base_url;
}

void MyUrl::setBaseUrl(QString url)
{
    base_url = url;
}

QString MyUrl::base_url
{
    "http://localhost:3000/"
    //"http://localhost:3000/"
};
