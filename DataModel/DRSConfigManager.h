#ifndef DRSConfigManager_H
#define DRSConfigManager_H

#include "zmq.hpp"
#include <SerialisableObject.h>
#include <iostream>
#include <vector>

class DRSConfigManager : public SerialisableObject
{
    friend class boost::serialization::access;

    public:
        DRSConfigManager();

        //Comms
        bool Send(zmq::socket_t* sock);
        bool Receive(zmq::socket_t* sock);

        unsigned int VersionNumber = 0x0001;
        int ReceiveFlag = 0;

        bool Print();

    private:

        template <class Archive> void serialize(Archive& ar, const unsigned int version)
        {}
};

#endif
