#include "add_stuinfo.h"
#include "ui_add_stuinfo.h"
#include "stusql.h"
#include <QMessageBox>
#include <QString>
#include "mainwindow.h"
#include <QDebug>
#include <iostream>
using namespace std;

Add_StuInfo::Add_StuInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_StuInfo)
{
    ui->setupUi(this);
}

Add_StuInfo::~Add_StuInfo()
{
    delete ui;
}

void Add_StuInfo::setType(bool is_modify,StuInfo Stu_infor)
{
    m_modify = is_modify;
    m_infor = Stu_infor;
    ui->lineEdit->setText(Stu_infor.Stu_name);              //姓名标签
    ui->spinBox->setValue(Stu_infor.Stu_age);
    ui->lineEdit_3->setText(QString::number(Stu_infor.Stu_class));
    ui->lineEdit_2->setText(QString::number(Stu_infor.Stu_grade));
    ui->lineEdit_5->setText(Stu_infor.Stu_phone);
    ui->lineEdit_6->setText(Stu_infor.Stu_wechat);
}

//增加界面的"保存"Button
void Add_StuInfo::on_pushButton_clicked()
{
    StuInfo Stu_infor;
    auto ptr = stuSql::getinstance();

    //这里我不知道为什么标签不能设置名字,只能用默认的
    Stu_infor.Stu_name = ui->lineEdit->text();
    Stu_infor.Stu_age = ui->spinBox->text().toUInt();
    Stu_infor.Stu_grade = ui->lineEdit_2->text().toUInt();
    Stu_infor.Stu_class = ui-> lineEdit_3->text().toUInt();
//    Stu_infor.Stu_id = ui->lineEdit_4->text().toUInt();
    Stu_infor.Stu_phone = ui->lineEdit_5->text();
    Stu_infor.Stu_wechat = ui->lineEdit_6->text();
//    Stu_infor.Stu_id = ui->lineEdit_4->text();
    if(m_modify) {
        ptr->add_StuInfor(Stu_infor);
    }
    else {
//        Stu_infor.id = m_id;
        ptr->modify_StuInfo(Stu_infor);
    }
    QMessageBox::information(nullptr,"数据","存储成功");
    this->hide();
}

//增加界面的"取消"Button
void Add_StuInfo::on_pushButton_2_clicked()
{
     this->hide();
}
