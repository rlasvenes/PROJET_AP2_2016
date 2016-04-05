#include "TcpClient.h"
#include <cstdlib>
#include <ctime>

TcpClient::TcpClient()
{
    this->setClientPortNumber(rand() % 65536 + 1024);
}

unsigned int TcpClient::getPortNumber() const
{
    return _portNumber;
}

void TcpClient::setClientPortNumber(unsigned int value)
{
    _portNumber = value;
}

void TcpClient::setPortToListen(unsigned int value)
{
    _listener.listen(value);
}

void TcpClient::setAcceptationListener(sf::Socket socket_value)
{
    _listener.accept(_socket);
}

void TcpClient::setConnectionToSocket(sf::IpAddress IP, unsigned int port_value)
{
    _socket.connect(IP, port_value);
}

void TcpClient::sendData(const void * data, std::size_t size)
{
    _socket.send(data, size);
}

std::string TcpClient::receivedData(void *data, std::size_t size, std::size_t &received)
{
    _socket.receive(data, size, received);
    // return this;
}
