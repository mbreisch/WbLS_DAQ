#include <DRSDataManager.h>

DRSDataManager::DRSDataManager(){}

bool DRSDataManager::Send(zmq::socket_t* sock)
{
    zmq::message_t msg1(sizeof VersionNumber);
    std::memcpy(msg1.data(), &VersionNumber, sizeof VersionNumber);

    sock->send(msg1);

    return true;
}


bool DRSDataManager::Receive(zmq::socket_t* sock)
{
    zmq::message_t msg;

    sock->recv(&msg);
    unsigned int tempVersionNumber;
    tempVersionNumber=*(reinterpret_cast<unsigned int*>(msg.data())); 
    if(tempVersionNumber != VersionNumber){return false;}

    return true;
}


bool DRSDataManager::Print()
{}

