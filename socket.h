#ifndef SOCKET_H
#define SOCKET_H

#include <QUdpSocket>


class Socket : public QUdpSocket
{
public:
    Socket(quint16);
    void sendData(QString);
    QString receiveData();

private:
    quint16 port;

};

#endif // SOCKET_H
