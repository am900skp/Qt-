#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "add_stuinfo.h"
#include "stusql.h"
#include <QMainWindow>
#include "page_login.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

void upDatabase();

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //实现一个按键刷新屏幕的功能
    virtual void keyPressEvent(QKeyEvent *event);

private slots:

    //学生管理界面的退出Button
    void on_pushButton_clicked();

    //学生管理界面的测试数据Button
    void on_btn_simulation_clicked();

    //学生管理界面的增加学生信息Button
    void on_pushButton_2_clicked();

    //学生管理界面的清空学生表Button
    void on_pushButton_6_clicked();

    //学生管理界面的删除信息Button
    void on_pushButton_5_clicked();

    //学生管理界面的修改信息Button
    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Page_Login m_dlgLogin;
    stuSql* m_ptrStuSql;
    QStringList m_lNames;   //测试名字
    Add_StuInfo m_Addstu;

    void upDatabase();
};
#endif // MAINWINDOW_H
