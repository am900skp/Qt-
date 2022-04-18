#ifndef PAGE_LOGIN_H
#define PAGE_LOGIN_H

#include <QWidget>

namespace Ui {
class Page_Login;
}

class Page_Login : public QWidget
{
    Q_OBJECT

public:
    explicit Page_Login(QWidget *parent = nullptr);
    ~Page_Login();

private slots:
    //登录界面的登录Button
    void on_bin_login_clicked();

    //登陆界面的取消Button
    void on_bin_exit_clicked();
signals:
    //如果成功的话,发送signal
    void sendLoginSuccess();
private:
    Ui::Page_Login *ui;
};

#endif // PAGE_LOGIN_H
