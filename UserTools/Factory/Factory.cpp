#include "Factory.h"

Tool* Factory(std::string tool) {
Tool* ret=0;

// if (tool=="Type") tool=new Type;
if (tool=="ReadData") ret=new ReadData;
if (tool=="Receive") ret=new Receive;
if (tool=="SetupDRS") ret=new SetupDRS;
if (tool=="Stream") ret=new Stream;
return ret;
}
