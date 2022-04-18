#include "page_login.h"
#include "ui_page_login.h"
#include <iostream>

Page_Login::Page_Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page_Login)
{
    ui->setupUi(this);
}

Page_Login::~Page_Login()
{
    delete ui;
}

//在数据库中查找用户名和密码
void Page_Login::on_bin_login_clicked()
{
    emit sendLoginSuccess();
//    std::cout << "senLoginSuccess" << std::endl;
}

void Page_Login::on_bin_exit_clicked()
{
    exit(0);
}
