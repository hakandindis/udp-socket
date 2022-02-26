#include "socket.h"

Socket::Socket(quint16 _port): port(_port)
{
    this->bind(QHostAddress::LocalHost,port);
}


void Socket::sendData(QString message){

    QByteArray buffer;

    buffer= message.toUtf8();
    this->writeDatagram(buffer.data(),QHostAddress::LocalHost,port);
}


QString Socket::receiveData(){

    QByteArray buffer;
    QString message;

    QHostAddress senderAddress;
    quint16 senderPort;

    while(this->hasPendingDatagrams()){

        buffer.resize(this->pendingDatagramSize());

        this->readDatagram(buffer.data(),buffer.size(),&senderAddress,&senderPort);
    }

    message = buffer.data();

    return message;

}




