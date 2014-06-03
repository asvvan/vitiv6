/*
 * HomeAgent.cc
 *
 *  Created on: May 30, 2014
 *      Author: sandro
 */

#include <omnetpp.h>
#include <string.h>
#include <stdio.h>
#include "hamn_m.h"

class HomeAgent : public cSimpleModule {
public:
    HomeAgent();
    virtual ~HomeAgent();
    void handleMessage(cMessage *msg);
 };

Define_Module(HomeAgent);

HomeAgent::HomeAgent()
{

}

HomeAgent::~HomeAgent()
{

}

void HomeAgent::handleMessage(cMessage *msg)
{
    Hamn *hmsg = check_and_cast<Hamn *>(msg);
    const char* tocmp = hmsg->getMsg();
    std::string strtocmp(tocmp);
    if (strtocmp.compare("mobile solicitation") == 0)
    {
        hmsg->setLifetime(7);
        send(hmsg,"out");
    }
    else if(strtocmp.compare("movement detection") == 0)
    {
        send(hmsg,"out");
    }
    else if(strtocmp.compare("Puppa!") == 0)
    {
        bubble("Puppa pure te!");
        EV << "Puppa pure te!";
        delete msg;
    }
}
