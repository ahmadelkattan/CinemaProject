#include "welcomewindow.h"
#include "loginwindow.h"
#include "ui_welcomewindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent, QString username, int age)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    ui->labelHello->setText("hello "+username +" "+ QString :: number ( age ));
    QPixmap pix ("E:\\qt assignment\\CinemaProject\\picturee.jpg");
    int w= ui->labelWelcome->width();
    int h = ui->labelWelcome->height();
    ui->labelWelcome->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_pushButtonLogout_clicked()
{
    hide();
    LoginWindow * loginwindow= new LoginWindow(this); //create new window
    loginwindow->show(); //show the new window
}

