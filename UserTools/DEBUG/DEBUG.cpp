#include "DEBUG.h"

DEBUG::DEBUG():Tool(){}


bool DEBUG::Initialise(std::string configfile, DataModel &data)
{
    if(configfile!="")  m_variables.Initialise(configfile);
    //m_variables.Print();

    m_data= &data;
    m_log= m_data->Log;

    if(!m_variables.Get("verbose",m_verbose)) m_verbose=1;

    return true;
}


bool DEBUG::Execute()
{
    while(true)
    {
        std::string input;
        std::cout << "Enter command: ";
        std::cin >> input;
        std::cout << std::endl;
        
        stringstream ss;
        unsigned int cmd;
        ss << input;
        ss >> std::hex >> cmd;
        m_data->USB->sendData(cmd);

        std::cout << "Sending: " << std::hex << cmd << std::endl;
    }    
    
    return true;
}


bool DEBUG::Finalise()
{
    return true;
}
