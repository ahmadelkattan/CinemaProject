#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "welcomewindow.h"
#include "registerwindow.h"
#include "Users.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->labelError->setVisible(false);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButtonLogin_clicked()
{
    bool found=false;
    int index=0;
    for (int i=0;i<100;i++)
    {
        if (ui->lineEditUsername->text()==usernames[i]&&ui->lineEditPassword->text()==passwords[i])
        {
            found=true;
            index=i;
            break;
        }
    }
    if (found)
    {
        hide();
        WelcomeWindow * welcomewindow= new WelcomeWindow(this, ui->lineEditUsername->text(), ages[index]); //create new window
        welcomewindow->show(); //show the new window
    }
    else
    {
        ui->labelError->setVisible(true);
    }
}


void LoginWindow::on_pushButtonRegister_clicked()
{
    hide();
    RegisterWindow * registerwindow= new RegisterWindow(this); //create new window
    registerwindow->show(); //show the new window
}

