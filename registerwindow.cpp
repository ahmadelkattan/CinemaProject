#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "welcomewindow.h"
#include "Users.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->labelExistingerror->setVisible(false);
    ui->labelNotMatchingerror->setVisible(false);
    ui->labelage12error->setVisible(false);
    ui->labelallfillederror->setVisible(false);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_pushButton_clicked()
{
    ui->labelExistingerror->setVisible(false);
    ui->labelNotMatchingerror->setVisible(false);
    ui->labelage12error->setVisible(false);
    ui->labelallfillederror->setVisible(false);
    QString username=ui->lineEditUsername->text();
    QString password=ui->lineEditPassword->text();
    QString repassword=ui->lineEditRetypePassword->text();
    int year= ui->comboBoxYear->currentText().toInt();
    int month= ui->comboBoxMonth->currentText().toInt();
    int day=ui->comboBoxDay->currentText().toInt();
    QString gender;
    QString adminoruser;
    QString genre[6]={"none","none","none","none","none","none"};
    if (ui->radioButtonMale->isChecked())
    {
        gender="male";
    }
    else if(ui->radioButtonFemale->isChecked())
    {
    gender="female";
    }
    else
    ui->labelallfillederror->setVisible(true);

    if (ui->radioButtonAdmin->isChecked())
    {
       adminoruser="admin";
    }
    else if(ui->radioButtonUser->isChecked())
    {
        adminoruser="user";
    }
    else
        ui->labelallfillederror->setVisible(true);
    if (ui->checkBox->isChecked())
    {
        genre[0]="Action";
    }
    if (ui->checkBox_2->isChecked())
    {
        genre[1]="Comedy";
    }
    if (ui->checkBox_3->isChecked())
    {
        genre[2]="Romance";
    }
    if (ui->checkBox_4->isChecked())
    {
        genre[3]="Drama";
    }
    if (ui->checkBox_5->isChecked())
    {
        genre[4]="Horror";
    }
    if (ui->checkBox_6->isChecked())
    {
        genre[5]="Other";
    }
    QString checkifempty;
    bool empty=true;
    for (int i=0;i<6;i++)
    {
        if(genre[i]!="none")
        {
            empty=false;
        }
    }
    if (empty)
    {
          ui->labelallfillederror->setVisible(true);
    }
    bool usernameexist=false;
    for (int i=0;i<100;i++)
    {
        if(username==usernames[i])
        {
            usernameexist=true;
            break;
        }
    }
    if (usernameexist)
    {
        ui->labelExistingerror->setVisible(true);
    }
    if(password!=repassword)
    {
        ui->labelNotMatchingerror->setVisible(true);
    }
    int age= 2024-year;
    if(age<12)
    {
        ui->labelage12error->setVisible(true);
    }
    if(!ui->labelExistingerror->isVisible()&&!ui->labelNotMatchingerror->isVisible()&&!ui->labelage12error->isVisible()&&!ui->labelallfillederror->isVisible())
    {

        usernames[userscount]=username;
        passwords[userscount]=password;
        ages[userscount]=age;
        userscount++;
        hide();
        WelcomeWindow * welcomewindow= new WelcomeWindow(this, username, age); //create new window
        welcomewindow->show(); //show the new window
    }

}

