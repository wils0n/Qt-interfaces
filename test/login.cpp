#include "login.h"
#include "app.h"
#include "ui_login.h"
#include <QMessageBox>
Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    //this->setWindowFlags(Qt::Window|Qt::MSWindowsFixedSizeDialogHint);

    //connect(this,SIGNAL(coger()),this,SLOT(validarDatos()));
}

Login::~Login()
{
    delete ui;
}

void Login::autentificar()
{
    //codigo
    /*QMessageBox::information(this,"ok","signals and slots conectados"
                             +tr("\n tu usuario: %0").arg(ui->lineEdit->text())
                             +tr("\n tu pass: %0").arg(ui->lineEdit_2->text()));*/
    const QString user=ui->lineEdit->text();
    const QString pass=ui->lineEdit_2->text();

    bool ok = user == "wilson" && pass == "tuxi" ? true : false;

    if (ok){
       //QMessageBox::information(this,"ok","CORRECTO");
        //App *a=new App(0);//0 es el por defecto recibe el constructor de la clase App
        App *a=new App(0,user);
        a->show();
        close();

    }else{
        //QMessageBox::information(this,"ok","INCORRECTO");

        ui->label->setText("Datos Incorrectos");
        const QString style="QLabel{color:red;text-align:center}";
        ui->label->setStyleSheet(style);
    }

    //emit coger();
}

/*void Login::validarDatos()
{
    QMessageBox::information(this,"ok","Aqui se emitio \nla senial y se ejecuto el \nslot validarDatos");

}*/


/*
hay una falla en el razonamiento de abajo, ya que si hago tab a password el boton se habilita estando el user vacio
eso no debe ser asi
NOTA: no es tan importante si es que a las finales cuando se verifica sale un mensaje de error como un label
*/
void Login::on_lineEdit_textChanged(const QString &user)//si user es diferente de vacio entoncs password y boton no es editable
{
    if (user.isEmpty()==true)
        ui->lineEdit_2->setEnabled(false);//no se puede editar
    else
        ui->lineEdit_2->setEnabled(true);

    ui->pushButton->setEnabled(false);
}

void Login::on_lineEdit_2_textChanged(const QString &pass)//si pass es diferente de vacio entoncs es editable
{
    //ui->pushButton->setEnabled(pass.isEmpty() ? false:true);
    if (pass.isEmpty()==true)
        ui->pushButton->setEnabled(false);//no se puede pulsar
    else
        ui->pushButton->setEnabled(true);
}

