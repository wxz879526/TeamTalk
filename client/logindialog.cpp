#include "logindialog.h"
#include "ui_logindialog.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMouseEvent>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);

    QFile file(":/resource/qss/LoginDialog.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    setStyleSheet(stylesheet);
    file.close();

    qDebug() << stylesheet;
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::mousePressEvent(QMouseEvent *e)
{
    m_orgin = e->globalPos()-this->pos();
}

void LoginDialog::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton)
     {
        QPoint move_pos = e->globalPos();
        this->move(move_pos-m_orgin);
     }
}
