#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>        //刷新屏幕需要
#include <QFile>
#include <QCoreApplication>
#include <QRandomGenerator>     //随机生成
#include <QDebug>
#include <iostream>
#include <QString>
#include <QMessageBox>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,m_ptrStuSql(nullptr)
{
    ui->setupUi(this);
    m_dlgLogin.show();

    auto f = [&]()
    {
        this->show();
    };

    connect(&m_dlgLogin,&Page_Login::sendLoginSuccess,this,f);

    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(1);
    QStringList File;
    File << "学生信息管理系统";
    QTreeWidgetItem *pTree_Father = new QTreeWidgetItem(ui->treeWidget,File);
    ui->treeWidget->addTopLevelItem(pTree_Father);
    File.clear();
    File << "学生管理";
    //子类1
    QTreeWidgetItem *pTree_SonFirst = new QTreeWidgetItem(pTree_Father,File);
    File.clear();
    File << "管理员管理";
    //子类2
    QTreeWidgetItem *pTree_SonSecond = new QTreeWidgetItem(pTree_Father,File);
    pTree_Father->addChild(pTree_SonFirst);
    pTree_Father->addChild(pTree_SonSecond);
    ui->treeWidget->expandAll();

    m_ptrStuSql = stuSql::getinstance();
    m_ptrStuSql->init_Database();

    m_lNames << "王峻熙";
    m_lNames << "张嘉懿";
    m_lNames << "李煜城";
    m_lNames << "赵懿轩";
    m_lNames << "王烨华";
    m_lNames << "杨煜祺";
    m_lNames << "阎智宸";
    m_lNames << "孙正豪";
    m_lNames << "吴昊然";
    m_lNames << "郭志泽";
    m_lNames << "李明杰";
    m_lNames << "杨弘文";
    m_lNames << "靳烨伟";
    m_lNames << "马苑博";
    m_lNames << "张鹏涛";
    m_lNames << "叶红艳";
    m_lNames << "张天荣";
    m_lNames << "孙志梅";
    m_lNames << "刘雪恩";
    m_lNames << "孙荣 ";
    m_lNames << "严正明";
    m_lNames << "樊梨花";
    m_lNames << "范海霞";
    m_lNames << "卢玉霞";
    m_lNames << "刘小二";
    m_lNames << "张素珍";
    m_lNames << "刘晓芒";
    m_lNames << "杨素萍";
    m_lNames << "潘晓娟";
    m_lNames << "何云霞";
    m_lNames << "郭川川";
    m_lNames << "吴莎莎";
    m_lNames << "严夏红";
    m_lNames << "闫春芝";
    m_lNames << "王晓正";
    m_lNames << "徐小明";
    m_lNames << "王仕兰";
    m_lNames << "东方蓉";
    m_lNames << "吴娟 ";
    m_lNames << "张伶边";
    m_lNames << "董飘萨";
    m_lNames << "曹兰芳";
    m_lNames << "吴春芳";
    m_lNames << "王媛媛";
    m_lNames << "张秀艳";
    m_lNames << "吴少耀";
    m_lNames << "董亚娟";
    m_lNames << "杨翠霞";
    m_lNames << "薛爱珍";
    m_lNames << "董晓";
    m_lNames << "裴玉";
    m_lNames << "陈英";
    m_lNames << "赵兵";
    m_lNames << "王麒民";
    m_lNames << "戴国强";
    m_lNames << "陶洪万";
    m_lNames << "朱洪纯";
    m_lNames << "徐亚玲";
    m_lNames << "徐宗玲";
    m_lNames << "刘海琪";
    m_lNames << "曾辉";
    m_lNames << "唐转兵";
    m_lNames << "黄飞";
    m_lNames << "光光";
    m_lNames << "谢林华";
    m_lNames << "梁远述";
    m_lNames << "王波香";
    m_lNames << "王洪超";
    m_lNames << "刘江";
    m_lNames << "黄光平";
    m_lNames << "赵磊";
    m_lNames << "杨春香";
    m_lNames << "卢军";
    m_lNames << "谭恢来";
    m_lNames << "徐福海";
    m_lNames << "陈群华";
    m_lNames << "敬小玲";
    m_lNames << "王柏杨";
    m_lNames << "刘崇溶";
    m_lNames << "袁微";
    m_lNames << "冯世军";
    m_lNames << "袁舒含";
    m_lNames << "李贵君";
    m_lNames << "袁绍斌";
    m_lNames << "李定其";
    m_lNames << "罗江山";
    m_lNames << "王广芳";
    m_lNames << "孔宪全";
    m_lNames << "曹兴富";
    m_lNames << "游伟";
    m_lNames << "宁有洁";
    m_lNames << "陈桂香";
    m_lNames << "王恒英";
    m_lNames << "吴文模";
    m_lNames << "叶元凤";
    m_lNames << "陈德民";
    m_lNames << "樊艳林";
    m_lNames << "赵斌";
    m_lNames << "罗宏";
    m_lNames << "胡支陶";
    m_lNames << "胡支炎";
    m_lNames << "张伟";
    m_lNames << "丛占国";
    m_lNames << "赵一航";
    m_lNames << "徐子程";
    m_lNames << "傅长远";
    m_lNames << "赵秀宇";
    m_lNames << "王海龙";
    m_lNames << "张涛";
    m_lNames << "姜雪娜";
    m_lNames << "冷忠仁";
    m_lNames << "曹松";

    upDatabase();

    //this->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//优化界面
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    /*这里我本来想通过按F6 然后更改一下界面的配色
        没整好:
            1>>不会配色,配不出好看的颜色
            2>>css没学过,还得现查,搞得好慢,功能全部实现后在测试
    */
    if(event->key() == Qt::Key_F6) {
        QFile Q_File;
        auto str = QCoreApplication::applicationDirPath();
        Q_File.setFileName(str+"//"+"stuqss.css");
        Q_File.open(QIODevice::ReadOnly);
        QString strQss = Q_File.readAll();
        this->setStyleSheet(strQss);
        m_dlgLogin.setStyleSheet(strQss);
    }
}

//测试数据
void MainWindow::on_btn_simulation_clicked()
{
    QStringList l;
    QRandomGenerator grade_rand;
    QRandomGenerator class_rand;

    grade_rand.seed(0);
    class_rand.seed(0);

    for(int i = 0; i < m_lNames.size(); i++) {
        StuInfo infor;
        infor.Stu_name = m_lNames[i];
         auto grade = grade_rand.bounded(7,10);     // 7 - 9 左闭右开
         auto ui_class = grade_rand.bounded(1,8);
         //        if(i % 3 == 0) {
//             info.Stu_name = QString("张%1").arg(i);
//        }
//        if(i % 2 == 0) {
//            info.Stu_name = QString("李%1").arg(i);
//        }
//        if(i % 7 == 0) {
//            info.Stu_name = QString("孙%1").arg(i);
//        }

        if(i % 3 == 0) {
             infor.Stu_age = 16;
        }
        if(i % 2 == 0) {
            infor.Stu_age = 17;
        }
        if(i % 7 == 0) {
            infor.Stu_age = 18;
        }

        infor.Stu_grade = grade;
        infor.Stu_class = ui_class;
        infor.Stu_id = 1;
        infor.Stu_phone = "159812888";
        infor.Stu_wechat = "codecpp";

        m_ptrStuSql->add_StuInfor(infor);
    }
    upDatabase();
}

//学生管理界面的增加学生信息Button
void MainWindow::on_pushButton_2_clicked()
{
    m_Addstu.setType(true);
    m_Addstu.exec();
    upDatabase();
}

void MainWindow::on_pushButton_6_clicked()
{
    m_ptrStuSql->clear_StuTable();
    upDatabase();
}

void MainWindow::upDatabase()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(9);
    QStringList l_Label;        //二进制的表达操作无效
    l_Label << "序号" << "id" << "姓名" << "年龄" << "年级" << "班级" << "学号"
            << "电话" << "微信";
    //写头
    ui->tableWidget->setHorizontalHeaderLabels(l_Label);

    //之选中行
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    //只选中一块
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    //每一个选项不可编辑,但是现在一点还会选中一行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    auto cnt = m_ptrStuSql->get_StuCnt();
    ui->label_4->setText(QString("目前学生数量: %1").arg(cnt));
    QList<StuInfo> L_Student = m_ptrStuSql->getPageStu(0,cnt);

    ui->tableWidget->setRowCount(cnt);

    static int size = 0;
    for(int j = 0; j < L_Student.size(); j++) {
        ui->tableWidget->setItem(j,0,new QTableWidgetItem(QString::number(j)));
        ui->tableWidget->setItem(j,1,new QTableWidgetItem(QString::number(L_Student[j].id)));
        ui->tableWidget->setItem(j,2,new QTableWidgetItem(L_Student[j].Stu_name));
        ui->tableWidget->setItem(j,3,new QTableWidgetItem(QString::number(L_Student[j].Stu_age)));
        ui->tableWidget->setItem(j,4,new QTableWidgetItem(QString::number(L_Student[j].Stu_grade)));
        ui->tableWidget->setItem(j,5,new QTableWidgetItem(QString::number(L_Student[j].Stu_class)));
        ui->tableWidget->setItem(j,6,new QTableWidgetItem(QString::number(L_Student[j].Stu_id)));
        ui->tableWidget->setItem(j,7,new QTableWidgetItem(L_Student[j].Stu_phone));
        ui->tableWidget->setItem(j,8,new QTableWidgetItem(L_Student[j].Stu_wechat));
        size++;
    }
    printf("size:%d",size);
}

void MainWindow::on_pushButton_clicked()
{
    exit(0);
}

//学生管理界面的删除信息
void MainWindow::on_pushButton_5_clicked()
{
    //想不到更好的优化方法了,
    //把upDatabase()里的接收一下
    int j = ui->tableWidget->currentRow();
    if(j >= 0) {
        int Temp_Stu_id = ui->tableWidget->item(j,1)->text().toUInt();
        m_ptrStuSql->delete_StuInfor(Temp_Stu_id);
        upDatabase();
        QMessageBox::information(nullptr,"信息","删除成功");
    }

}

//学生管理界面的修改信息
void MainWindow::on_pushButton_4_clicked()
{
    StuInfo Stu_infor;
    int index = ui->tableWidget->currentRow();
    if(index >= 0) {
        Stu_infor.id = ui->tableWidget->item(index,1)->text().toUInt();
        Stu_infor.Stu_name = ui->tableWidget->item(index,2)->text();
        Stu_infor.Stu_age= ui->tableWidget->item(index,3)->text().toUInt();
        Stu_infor.Stu_grade= ui->tableWidget->item(index,4)->text().toUInt();
        Stu_infor.Stu_class= ui->tableWidget->item(index,5)->text().toUInt();
        Stu_infor.Stu_id= ui->tableWidget->item(index,6)->text().toUInt();
        Stu_infor.Stu_phone= ui->tableWidget->item(index,7)->text();
        Stu_infor.Stu_wechat= ui->tableWidget->item(index,8)->text();
        m_Addstu.setType(false,Stu_infor);
        m_Addstu.exec();
    }
    upDatabase();
}
