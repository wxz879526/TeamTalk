#include "logindialog.h"
#include "ui_logindialog.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

LoginDialog::LoginDialog(QWidget *parent) :
    QWidget(parent),
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
