#ifndef Receive_H
#define Receive_H

#include <string>
#include <iostream>

#include "Tool.h"


/**
* \class Receive
*
* Tool for config data receive
* $Author: Marc Breisch $
* $Date: 2022/01/25 $
* 
*/
class Receive: public Tool 
{

    public:

        Receive(); ///< Simple constructor
        bool Initialise(std::string configfile,DataModel &data); ///< Initialise Function for setting up Tool resorces. @param configfile The path and name of the dynamic configuration file to read in. @param data A reference to the transient data class used to pass information between Tools.
        bool Execute(); ///< Executre function used to perform Tool perpose. 
        bool Finalise(); ///< Finalise funciton used to clean up resorces.


    private:
        zmq::socket_t* sock;
        zmq::pollitem_t items[1];

};

#endif
