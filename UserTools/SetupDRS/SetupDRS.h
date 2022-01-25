#ifndef SetupDRS_H
#define SetupDRS_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <chrono>

#include "Tool.h"


/**
* \class SetupDRS
*
* Tool to set received setting on a DRS4 eval board
* $Author: Marc Breisch $
* $Date: 2022/01/25 $
* 
*/
class SetupDRS: public Tool 
{
    public:
        SetupDRS(); ///< Simple constructor
        bool Initialise(std::string configfile,DataModel &data); ///< Initialise Function for setting up Tool resorces. @param configfile The path and name of the dynamic configuration file to read in. @param data A reference to the transient data class used to pass information between Tools.
        bool Execute(); ///< Executre function used to perform Tool perpose. 
        bool Finalise(); ///< Finalise funciton used to clean up resorces.

    private:

};

#endif
