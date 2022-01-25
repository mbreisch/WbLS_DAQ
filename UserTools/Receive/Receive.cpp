#include "Receive.h"

Receive::Receive():Tool(){}


bool Receive::Initialise(std::string configfile, DataModel &data)
{
    if(configfile!="")  m_variables.Initialise(configfile);
    //m_variables.Print();

    m_data= &data;
    m_log= m_data->Log;

    if(!m_variables.Get("verbose",m_verbose)) m_verbose=1;

    //Grab IP ans PORT for the ZMQ comms
    std::string IP="";
    std::string PORT="0";

    if(!m_variables.Get("IP_BIND",IP)) IP="0.0.0.0";
    if(!m_variables.Get("Port_BIND",PORT)) PORT="6666";

    std::string connection="tcp://"+IP+":"+PORT;

    sock=new zmq::socket_t(*(m_data->context), ZMQ_DEALER);

    sock->bind(connection.c_str());

    items[0].socket = *sock;
    items[0].fd = 0;
    items[0].events = ZMQ_POLLIN;
    items[0].revents =0;

    return true;
}


bool Receive::Execute()
{
    int timer;

    //If a setting receive hasn't happened wait forever, 
    //otherwise go on after 10us
    if(m_data->DRSConfig.ReceiveFlag==0)
    {
        timer = -1;
    }else
    {
        timer = 10;
    }

    zmq::poll(&items[0], 1, timer);
    if((items [0].revents & ZMQ_POLLIN)) 
    {
        //Use the pre-set config functions to receive and print the received data
        m_data->DRSConfig.Receive(sock);
        m_data->DRSConfig.Print();
    }

    return true;
}


bool Receive::Finalise()
{
    delete sock;
    sock=0;
    
    return true;
}


