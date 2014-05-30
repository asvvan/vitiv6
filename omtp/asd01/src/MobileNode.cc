/*
 * MobileNode.cc
 *
 *  Created on: May 30, 2014
 *      Author: sandro
 */

#include <omnetpp.h>
#include <string.h>
#include <stdio.h>
#include "hamn_m.h"

#define HN 0 // home network
#define FN 1 // foreign network
#define NN 2 // no network

class MobileNode : public cSimpleModule
{
private:
    simtime_t CtrlTimeout; // timeout per i messaggi di controllo
    cMessage *CtrlTimeoutEvent; // pointer al self message di controllo
    simtime_t MsTimeout; // timeout per mobile solicitation
    cMessage *MsTimeoutEvent; // holds pointer to the MS timeout self-message
    simtime_t MdTimeout; // timeout per movement detection
    cMessage *MdTimeoutEvent; // holds pointer to the MD timeout self-message
    std::string mnaddress; // mobile node actual ipv6 address
    std::string mnrouter; // mobile node default router
    std::string haaddress; // home address
    std::string homeAgent; // home agent address
    simtime_t halifetime; // lifetime del home address
    int state; // state HN, FN, NN

public:
    MobileNode();
    ~MobileNode();
    void sendSolicitation();
    void homeLinkDetection();
    void movementDetection();
    void sendMessage();

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(MobileNode);

MobileNode::MobileNode()
{
    CtrlTimeoutEvent = NULL;
    MsTimeoutEvent = NULL;
    MdTimeoutEvent = NULL;
}

MobileNode::~MobileNode()
{
    cancelAndDelete(CtrlTimeoutEvent);
    cancelAndDelete(MsTimeoutEvent);
    cancelAndDelete(MdTimeoutEvent);
}

void MobileNode::initialize()
{
    // messaggio di controllo arriva ogni secondo
    CtrlTimeout = 1.0;
    CtrlTimeoutEvent = new cMessage("Self message di controllo!");

    // primi valori
    mnaddress = "3.2.1.4";
    mnrouter = "3.2.1.1";
    haaddress = "1.1.1.4";
    homeAgent = "1.1.1.1";
    halifetime = 0;
    //bootstraping
    homeLinkDetection();

    // manda il messaggio di controllo fra CtrlTimeout
    scheduleAt(simTime()+CtrlTimeout, CtrlTimeoutEvent);

}

void MobileNode::handleMessage(cMessage *msg)
{
    if(msg->isSelfMessage())
    {
        if (msg==CtrlTimeoutEvent)
        {
            EV << "Arrivato il messaggio di controllo!\n";
            if(simTime() >= halifetime) {
                sendSolicitation();
            }
            if(uniform(0,1) < 0.2) {
                EV << "Voglio mandare un messaggio!";
                bubble("Voglio mandare un messaggio!");
                movementDetection();
            }
            // manda il messaggio di controllo fra CtrlTimeout
            scheduleAt(simTime()+CtrlTimeout, CtrlTimeoutEvent);
        }
        else if (msg==MsTimeoutEvent)
        {
            EV << "Solicitaton non arrivato, rimando la solicitation!\n";
            sendSolicitation();
        }
        else if (msg==MdTimeoutEvent)
        {
            EV << "Movement detection non arrivato, rimando!\n";
            movementDetection();
        }
    }
    else
    {
        Hamn *hmsg = check_and_cast<Hamn *>(msg);
        const char* tocmp = hmsg->getMsg();
        std::string strtocmp(tocmp);
        if (strtocmp.compare("mobile solicitation") == 0)
        {
            EV << "Solicitation accepted!\n";
            halifetime = simTime() + hmsg->getLifetime();
            cancelEvent(MsTimeoutEvent);
        }
        else if(strtocmp.compare("movement detection") == 0)
        {
            EV << "Movement detection accepted!\n";
            cancelEvent(MdTimeoutEvent);
            sendMessage();
        }
    }
}

void MobileNode::homeLinkDetection()
{
    if (mnaddress.compare(haaddress) == 0)
    {
        state = HN;
        EV << "State: home network!\n";
    }
    else
    {
        sendSolicitation();
    }
}

void MobileNode::sendSolicitation()
{
    Hamn *ms = new Hamn();
    ms->setMsg("mobile solicitation");
    MsTimeout = 5.0;
    MsTimeoutEvent = new cMessage("Self message mobile solicitation");

    EV << "Sending mobile solicitation!\n";
    send(ms,"out");
    scheduleAt(simTime()+MsTimeout, MsTimeoutEvent);
}

void MobileNode::movementDetection()
{
    Hamn *md = new Hamn();
    md->setMsg("movement detection");
    MdTimeout = 5.0;
    MdTimeoutEvent = new cMessage("Self message movement detection");

    EV << "Sending movement detection!\n";
    send(md,"out");
    scheduleAt(simTime()+MdTimeout,MdTimeoutEvent);
}

void MobileNode::sendMessage()
{
    Hamn *msg = new Hamn();
    msg->setMsg("Puppa!");
    send(msg,"out");
}
