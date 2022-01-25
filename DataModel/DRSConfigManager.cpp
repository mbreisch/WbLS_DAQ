#include <DRSConfigManager.h>

DRSConfigManager::DRSConfigManager(){}

bool DRSConfigManager::Send(zmq::socket_t* sock)
{
    zmq::message_t msg0(sizeof VersionNumber);
    memcpy(msg0.data(), &VersionNumber, sizeof VersionNumber);

    zmq::message_t msg1(sizeof ReceiveFlag);
    memcpy(msg1.data(), &ReceiveFlag, sizeof ReceiveFlag);

    sock->send(msg0,ZMQ_SNDMORE);
    sock->send(msg1);

    return true;
}

bool DRSConfigManager::Receive(zmq::socket_t* sock)
{
    zmq::message_t msg;

    //VersionNumber
    sock->recv(&msg);
    unsigned int TVersion;
    TVersion=*(reinterpret_cast<unsigned int*>(msg.data())); 
    if(TVersion!=VersionNumber){return false;}
	
    //flag
    sock->recv(&msg);
    ReceiveFlag=*(reinterpret_cast<int*>(msg.data())); 

    return true;
}

bool DRSConfigManager::Print()
{
    return true;
}
