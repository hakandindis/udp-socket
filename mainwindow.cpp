#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateClientUI(){

    QString message;

    message = client->receiveData();
    ui->clientReceiveMessageLabel->setText(message);
}

void MainWindow::updateServerUI(){

    QString message;

    message = server->receiveData();
    ui->serverReceiveMessageLabel->setText(message);
}


void MainWindow::on_clientPortPushButton_clicked()
{
   QString portS = ui->clientPortLineEdit->text();
   clientPort = (quint16)portS.toUInt();

   client = new Socket(clientPort);
   connect(client,SIGNAL(readyRead()),this,SLOT(updateClientUI()));
   qDebug()<<"client socket created";

}

void MainWindow::on_serverPortPushButton_clicked()
{
    QString portS = ui->serverPortLineEdit->text();
    serverPort = (quint16)portS.toUInt();

    server = new Socket(serverPort);
    connect(server,SIGNAL(readyRead()),this,SLOT(updateServerUI()));
    qDebug()<<"server socket created";
}

void MainWindow::on_clientMessagePushButton_clicked()
{
    QString message= ui->clientMessageLineEdit->text();
    //ui->clientMessageLineEdit->setText("");
    client->sendData(message,serverPort);
}

void MainWindow::on_serverMessagePushButton_clicked()
{
    QString message = ui->serverMessageLineEdit->text();
    //ui->serverMessageLineEdit->setText("");
    server->sendData(message,clientPort);
}
