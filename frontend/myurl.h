#ifndef MYURL_H
#define MYURL_H

#include <QString>


class MyUrl
{
public:
    MyUrl();
    static QString getBaseUrl();
    static void setBaseUrl(QString url);

private:
    static QString base_url;

};

#endif // MYURL_H
