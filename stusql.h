#ifndef STUSQL_H
#define STUSQL_H

#include <QObject>
#include <QSqlDatabase>

//2022/4/9 16:09
//学生信息
class StuInfo {
public:
    int id;
    QString Stu_name;
    quint8  Stu_age;
    quint32 Stu_grade;
    quint32 Stu_class;
    quint32 Stu_id;
    QString Stu_phone;
    QString Stu_wechat;
};

//用户信息
class UserInfo {
public:
    QString username;
    QString password;
    QString permission;
};

class stuSql : public QObject
{
    Q_OBJECT
public:
    static stuSql* ptrStuSql;
    static stuSql* getinstance(){
        if(nullptr == ptrStuSql) {
            ptrStuSql = new stuSql;
        }
        return ptrStuSql;
    }

    explicit stuSql(QObject *parent = nullptr);

    //打开数据库
    void init_Database();

    //获取所有学生数量
    quint32 get_StuCnt();

    //页数是从零开始的,0,object就是0
     QList<StuInfo> getPageStu(quint32 page,quint32 uiCnt);

    //增加一个学生
    //一次只能录入一个学生
    bool add_StuInfor(StuInfo Stu_info);

    //删除一个学生
    bool delete_StuInfor(int Stu_id);

    //清空学生表
    bool clear_StuTable();

    //修改学生信息
    bool modify_StuInfo(StuInfo Stu_info);

    //查找所有用户
    //QVector<UserInfo> getAllUser();
    QList<UserInfo> get_AllUser();

    //查询用户是否存在
    bool is_Exit(QString string_Username);

    //修改用户信息
    bool modify_User_information(UserInfo string_UserInfo);

    //添加单个用户
    bool AddUser(UserInfo User_info);

    //删除单个用户
    bool delete_User(QString string_Username);

signals:
private:
        QSqlDatabase Stu_db;
};

#endif // STUSQL_H
