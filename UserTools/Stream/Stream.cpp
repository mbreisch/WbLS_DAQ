#include "Stream.h"

Stream::Stream():Tool(){}


bool Stream::Initialise(std::string configfile, DataModel &data)
{
    if(configfile!="")  m_variables.Initialise(configfile);
    //m_variables.Print();

    m_data= &data;
    m_log= m_data->Log;

    if(!m_variables.Get("verbose",m_verbose)) m_verbose=1;

    std::string IP="";
    std::string PORT="0";
    if(!m_variables.Get("IP",IP)) IP="127.0.0.1";
    if(!m_variables.Get("PORT",PORT)) PORT="8888";

    std::string connection="tcp://"+IP+":"+port;
    sock=new zmq::socket_t(*(m_data->context), ZMQ_DEALER);
    sock->connect(connection.c_str());


    return true;
}


bool Stream::Execute()
{
    //Use the pre-set functions to send data and print send data infos
    m_data->DRSData.Send(sock);
    m_data->DRSData.Print();

    return true;
}


bool Stream::Finalise()
{
    delete sock;
    sock=0; 

    return true;
}
