#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect(socket,SIGNAL(readyRead()),this,SLOT());

    //server = new Socket(8001);
    //client = new Socket(7000);

    //connect(server,SIGNAL(readyRead()),this,SLOT(updateUI()));
    //connect(server,SIGNAL(readyRead()),this,SLOT(updateUI()));


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::updateUI(){

    QString clientMessage;
    QString serverMessage;

    serverMessage = server->receiveData();
    clientMessage = client->receiveData();

    ui->clientReceiveMessageLabel->setText(serverMessage);
    ui->serverReceiveMessageLabel->setText(clientMessage);

}

void MainWindow::on_clientPortPushButton_clicked()
{
   QString portS = ui->clientPortLineEdit->text();
   clientPort = (quint16)portS.toUInt();

   client = new Socket(clientPort);
   connect(client,SIGNAL(readyRead()),this,SLOT(updateUI()));
   qDebug()<<"client socket created";

}

void MainWindow::on_serverPortPushButton_clicked()
{
    QString portS = ui->serverPortLineEdit->text();
    serverPort = (quint16)portS.toUInt();

    server = new Socket(serverPort);
    connect(server,SIGNAL(readyRead()),this,SLOT(updateUI()));
    qDebug()<<"server socket created";
}

void MainWindow::on_clientMessagePushButton_clicked()
{
    QString message= ui->clientMessageLineEdit->text();
    //ui->clientMessageLineEdit->setText("");
    client->sendData(message);
}

void MainWindow::on_serverMessagePushButton_clicked()
{
    QString message = ui->serverMessageLineEdit->text();
    //ui->serverMessageLineEdit->setText("");
    server->sendData(message);
}
