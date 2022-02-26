#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "socket.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Socket *server;
    quint16 serverPort;

    Socket *client;
    quint16 clientPort;

public slots:
    void updateServerUI();
    void updateClientUI();
private slots:
    void on_clientPortPushButton_clicked();
    void on_serverPortPushButton_clicked();
    void on_clientMessagePushButton_clicked();
    void on_serverMessagePushButton_clicked();
};

#endif // MAINWINDOW_H
