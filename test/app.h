#ifndef APP_H
#define APP_H

#include <QMainWindow>

namespace Ui {
class App;
}

class App : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit App(QWidget *parent = 0);
    App(QWidget *parent = 0,const QString user="");
    ~App();
    
private slots:
    void on_actionExit_triggered();

private:
    Ui::App *ui;
    QString user;
};

#endif // APP_H
