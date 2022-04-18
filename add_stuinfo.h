#ifndef ADD_STUINFO_H
#define ADD_STUINFO_H

#include <QDialog>
#include "stusql.h"
namespace Ui {
class Add_StuInfo;
}

class Add_StuInfo : public QDialog
{
    Q_OBJECT

public:
    explicit Add_StuInfo(QWidget *parent = nullptr);
    ~Add_StuInfo();

    void  setType(bool is_modify,StuInfo Stu_infor = {});
private slots:

    //增加界面的 "保存"Button
    void on_pushButton_clicked();

    //学生管理界面的"增加"Button
    void on_pushButton_2_clicked();

private:
    Ui::Add_StuInfo *ui;
    bool m_modify;        //修改信息
    StuInfo m_infor;
};

#endif // ADD_STUINFO_H
