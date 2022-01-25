#ifndef Stream_H
#define Stream_H

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <chrono>

#include "Tool.h"


/**
* \class Stream
* Tool for DRS data streaming
* $Author: Marc Breisch $
* $Date: 2022/01/25 $
*/

class Stream: public Tool 
{
    public:

    Stream(); ///< Simple constructor
    bool Initialise(std::string configfile,DataModel &data); ///< Initialise Function for setting up Tool resorces. @param configfile The path and name of the dynamic configuration file to read in. @param data A reference to the transient data class used to pass information between Tools.
    bool Execute(); ///< Executre function used to perform Tool perpose. 
    bool Finalise(); ///< Finalise funciton used to clean up resorces.

    std::chrono::high_resolution_clock m_clock;	
    unsigned long long getTime()
    {
        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(m_clock.now().time_since_epoch()).count();
        return (unsigned long long)time;
    }

    private:
        zmq::socket_t* sock;
        boost::posix_time::ptime first;

};

#endif
