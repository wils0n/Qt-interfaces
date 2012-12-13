#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Login(QWidget *parent = 0);
    ~Login();

signals:
    //void coger();

private slots:
    void autentificar();
    //void validarDatos();
    void on_lineEdit_textChanged(const QString &arg1);
    void on_lineEdit_2_textChanged(const QString &arg1);

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
