#ifndef DRSDataManager_H
#define DRSDataManager_H

#include "zmq.hpp"
#include <SerialisableObject.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class DRSDataManager
{
    friend class boost::serialization::access;

    public:
        DRSDataManager();

        bool Send(zmq::socket_t* sock);
        bool Receive(zmq::socket_t* sock);

        unsigned int VersionNumber = 0x0001;

        bool Print();

    private:

        template <class Archive> void serialize(Archive& ar, const unsigned int version)
        {}

};

#endif
