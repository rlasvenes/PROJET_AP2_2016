#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include "View.h"

class TcpClient : public sf::TcpSocket
{
private:

    sf::TcpSocket _socket;
    unsigned int _portNumber;
    sf::TcpListener _listener; // for the server only

    std::string * _data; // facultatif, donc peut être NULL (pointeur)
    std::size_t received;

public:

    TcpClient();

    // GETTERS
    unsigned int getPortNumber() const;

    void setClientPortNumber(unsigned int value); // TcpServer get it's port number and assignate it to the client
    void setConnectionToSocket(sf::IpAddress IP, unsigned int port_value);

    void setPortToListen(unsigned int value);
    void setAcceptationListener(sf::Socket socket_value);

    void sendData(const void * data, std::size_t size); // send data to the targetted IP
    std::string receivedData(void *data, std::size_t size, std::size_t &received);
};

#endif // TCPCLIENT_H
