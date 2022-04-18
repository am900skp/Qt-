#include "stusql.h"
#include <QMessageBox>       //QSqlDataBase数据库
#include <QSqlQuery>         //操作SqlLite3
#include <QtDebug>
#include <QApplication>
#include <QCoreApplication>
#include <QString>           //lastError();
#include <QSqlError>         //QSqlError返回值
#include <iostream>
#include "mainwindow.h"
using namespace std;

/*
    继承Object//第一添加<QSqlDatabase>头文件出现报错
    解决方案:右击项目名称,点清楚,(在csdn上找到的方法)
*/

//类外初始化
stuSql* stuSql::ptrStuSql = nullptr;

stuSql::stuSql(QObject *parent): QObject{parent}
{
        cout << "Build";
        //构建个对象
        //QSqlQuery q("", db);

//         init_Database();

//        StuInfo sTest;
//        sTest.Stu_name = "小黑";
//        for(int i = 0; i < 10; i++) {
//        add_StuInfor(sTest);
//          cout << "lu ru shuju" << endl;
//         }

//     get_StuCnt();
//     getPageStu(2,3);

//     delete_StuInfor(18);
//        cout << "delete yes" << endl;
//      StuInfo s;
//      s.id = 1;
//      s.Stu_name = "dd";

//      modify_StuInfo(s);
//      cout << "modigy yes" << endl;

        //测试用户表的增删改查
//      UserInfo infor;
//      infor.username = "sunkaipeng";
//      infor.password = "123456";
//      infor.permission = "admin";

//    AddUser(infor);       //ok
//    AddUser(infor);       //ok

//    auto l = get_AllUser();     //ok
//    qDebug() << is_Exit("sunkaipeng");  //ok

      /*

     */

//      infor.password = "666";
//      modify_User_information(infor);

      //这个删除会将重名的全部删除
//    delete_User("sunkaipeng");

    //测试插入信息
    //q.exec("INSERT INTO student VALUES (NULL, '张三', 12, 3, 2, 1, 15940224444, 'asdzhang')");
//        cout << "inset yes" << endl;
}


//初始化数据库
void stuSql::init_Database()
{
    cout << "init_Database" << endl;
    if (QSqlDatabase::drivers().isEmpty()) {
        qDebug() << "No database drivers found";
    }
    Stu_db = QSqlDatabase::addDatabase("QSQLITE");
#if 0
    auto Qstring = QCoreApplication::applicationDirPath() + "Stu_System.db";
    qDebug() << Qstring;
#endif
    Stu_db.setDatabaseName("D:\\SqlLite\\SqlLite3\\Package\\Stu_System.db");
    cout << "init_Database success" << endl;
    if (!Stu_db.open()) {
          qDebug() << "Stu_System.db not open";
    }
}

//获取所有学生数量
quint32 stuSql::get_StuCnt()
{
     QSqlQuery Sql_db(Stu_db);
     Sql_db.exec("select count(id) from student;");
     quint32 uiCnt = 0;
     while(Sql_db.next()) {
         uiCnt = Sql_db.value(0).toInt();
     }
     cout << "get uiCnt" << endl;
     return uiCnt;
}

//获取学生的第几页数据,注意页数是从零开始的
QList<StuInfo> stuSql::getPageStu(quint32 page, quint32 uiCnt)
{
    QList<StuInfo> l_page;
    QSqlQuery Sql_db(Stu_db);
    QString string_sql = QString("select * from student order by id limit %1 offset %2")
            .arg(uiCnt)
            .arg(page * uiCnt);
    Sql_db.exec(string_sql);

    StuInfo Stu_infor;
    static int getPageStu = 0;

    while(Sql_db.next()) {
      Stu_infor.id = Sql_db.value(0).toUInt();
      Stu_infor.Stu_name = Sql_db.value(1).toString();
      Stu_infor.Stu_age = Sql_db.value(2).toUInt();
      Stu_infor.Stu_grade = Sql_db.value(3).toUInt();
      Stu_infor.Stu_class = Sql_db.value(4).toUInt();
      Stu_infor.Stu_id = Sql_db.value(5).toUInt();
      Stu_infor.Stu_phone = Sql_db.value(6).toString();
      Stu_infor.Stu_wechat = Sql_db.value(7).toString();
      l_page.push_back(Stu_infor);
      getPageStu++;
    }
    printf("%d\n",getPageStu);
    return l_page;
}

bool stuSql::add_StuInfor(StuInfo Stu_info)
{
    QSqlQuery Sql_db(Stu_db);
    QString string_Sql = QString("insert into student values(null,'%1',%2,%3,%4,%5,'%6','%7')")
            .arg(Stu_info.Stu_name)
            .arg(Stu_info.Stu_age)
            .arg(Stu_info.Stu_grade)
            .arg(Stu_info.Stu_class)
            .arg(Stu_info.Stu_id)
            .arg(Stu_info.Stu_phone)
            .arg(Stu_info.Stu_wechat);
    //q.exec("INSERT INTO student VALUES (NULL, '张三', 12, 3, 2, 1, 15940224444, 'asdzhang')");
    qDebug() << Sql_db.exec(string_Sql);
    return Sql_db.exec(string_Sql);
}

//删除学生
bool stuSql::delete_StuInfor(int Stu_id)
{
    QSqlQuery Sql_db(Stu_db);
    QString string_Sql = QString("delete from student where id = %1")
    .arg(Stu_id);

    return Sql_db.exec(string_Sql);
}

//清空学生表
bool stuSql::clear_StuTable()
{
    QSqlQuery string_Sql(Stu_db);
    string_Sql.exec("delete from student");
    //删除每一次记录,不然主键的序号不会刷新
    return string_Sql.exec("delete from sqlite_sequence where name = 'student' ");
}

bool stuSql::modify_StuInfo(StuInfo Stu_info)
{
    QSqlQuery Sql_db(Stu_db);
    QString string_Sql = QString("update student set name = '%1',age = %2, grade = %3, "
                                 "class = %4, studentid = %5,"
                                 "phone = '%6', "
                                 "wechat = '%7' where id = %8")
            .arg(Stu_info.Stu_name)
            .arg(Stu_info.Stu_age)
            .arg(Stu_info.Stu_grade)
            .arg(Stu_info.Stu_class)
            .arg(Stu_info.Stu_id)
            .arg(Stu_info.Stu_phone)
            .arg(Stu_info.Stu_wechat).arg(Stu_info.id);
    bool ret = Sql_db.exec(string_Sql);
    qDebug() << string_Sql;
    QSqlError e = Sql_db.lastError();
    if(e.isValid()) {
        qDebug() << e.text();
    }
    return ret;
}

//查询所有用户
QList<UserInfo> stuSql::get_AllUser()
{
    QList<UserInfo> l_page;
    QSqlQuery Sql_db(Stu_db);
    Sql_db.exec("select * from username");
    UserInfo Stu_infor;
    static int getAllUser = 0;
    while(Sql_db.next()) {
      Stu_infor.username = Sql_db.value(0).toString();
      Stu_infor.password = Sql_db.value(1).toString();
      Stu_infor.permission = Sql_db.value(2).toString();
      l_page.push_back(Stu_infor);
      getAllUser++;
    }
    printf("%d\n",getAllUser);
    return l_page;
}

//查询用户是否存在
bool stuSql::is_Exit(QString string_Username)
{
    QSqlQuery Sql_db(Stu_db);
    Sql_db.exec(QString("select *from username where username = '%1'")
                .arg(string_Username));
    return Sql_db.next();
}

//修改用户信息
bool stuSql::modify_User_information(UserInfo string_UserInfo)
{
    QSqlQuery Sql_db(Stu_db);
    QString string_Sql = QString("update username set password = '%1',auth = '%2' where username = '%3'")
            .arg(string_UserInfo.password)
            .arg(string_UserInfo.permission)
            .arg(string_UserInfo.username);
    bool ret = Sql_db.exec(string_Sql);
    QSqlError e = Sql_db.lastError();
    if(e.isValid()) {
         qDebug() << e.text();
    }
    return ret;
}

//添加单个用户
bool stuSql::AddUser(UserInfo User_info)
{
    QSqlQuery Sql_db(Stu_db);
    QString string_Sql = QString("insert into username values ('%1','%2','%3')")
            .arg(User_info.username)
            .arg(User_info.password)
            .arg(User_info.permission);

    bool ret = Sql_db.exec(string_Sql);
    QSqlError e = Sql_db.lastError();
    if(e.isValid()) {
        qDebug() << e.text();
    }

    return ret;
}

//删除单个用户
bool stuSql::delete_User(QString string_Username)
{
    QSqlQuery Sql_db(Stu_db);
    Sql_db.exec(QString("delete from username where username = '%1'")
                .arg(string_Username));
    return Sql_db.next();
}


