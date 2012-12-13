#include "app.h"
#include "ui_app.h"
#include <QLabel>
App::App(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::App)
{
    ui->setupUi(this);
    //ui->statusbar->addPermanentWidget(new QLabel("usuario: "+this->user));
    ui->statusbar->addPermanentWidget(new QLabel(this->user));
}

App::App(QWidget *parent, const QString user):
QMainWindow(parent),
ui(new Ui::App), user(user)
{
    ui->setupUi(this);
    //ui->statusbar->addPermanentWidget(new QLabel("usuario: "+this->user));
    ui->statusbar->addPermanentWidget(new QLabel(this->user));
}

App::~App()
{
    delete ui;
}

void App::on_actionExit_triggered()
{
    qApp->exit(0);//¿qApp?¿que es?
}
