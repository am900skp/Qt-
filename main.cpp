#include "mainwindow.h"
#include "page_login.h"     //登录界面头文件
#include <QApplication>
#include "stusql.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    stuSql sql;

    return a.exec();
}

