/*
 * MobileNode.cc
 *
 *  Created on: May 30, 2014
 *      Author: sandro
 */

#include <omnetpp.h>
#include <string.h>
#include <vector>
#include <stdio.h>
#include "hamn_m.h"
#include "BindingUpdate.cc"

#define HN 0 // home network
#define FN 1 // foreign network
#define NN 2 // no network

#define LIFETIME 100 // lifetime for binding update list elements

class MobileNode : public cSimpleModule
{
private:
    simtime_t CtrlTimeout; // timeout per i messaggi di controllo
    cMessage *CtrlTimeoutEvent; // pointer al self message di controllo
    simtime_t MsTimeout; // timeout per mobile solicitation
    cMessage *MsTimeoutEvent; // holds pointer to the MS timeout self-message
    simtime_t MdTimeout; // timeout per movement detection
    cMessage *MdTimeoutEvent; // holds pointer to the MD timeout self-message
    simtime_t RdTimeout; // timeout per router discovery
    cMessage *RdTimeoutEvent; // holds the pointer to the RD timeout self-message
    std::string mnaddress; // mobile node actual ipv6 address
    std::string mnrouter; // mobile node default router
    std::string haaddress; // home address
    std::string homeAgent; // home agent address
    simtime_t halifetime; // lifetime del home address
    int state; // state HN, FN, NN
    std::vector<BindingUpdate*> BU_list; // binding update list

public:
    MobileNode();
    ~MobileNode();
    void sendSolicitation();
    void homeLinkDetection();
    void movementDetection();
    void sendMessage();
    void icmpErrorCode1(Hamn *hmsg);
    void icmpErrorCode2(Hamn *hmsg);
    void bindingErrorStatus1(Hamn *hmsg);
    void bindingErrorStatus2(Hamn *hmsg);
    void formingNewCoA();
    void routerDiscovery();
    void compareBUandCoA(); // compare at bootstrapping if CoA is in BU list
    bool checkBU(Hamn *hmsg, int &indice, std::string &fromwho);

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
    RdTimeoutEvent = NULL;
}

MobileNode::~MobileNode()
{
    cancelAndDelete(CtrlTimeoutEvent);
    cancelAndDelete(MsTimeoutEvent);
    cancelAndDelete(MdTimeoutEvent);
    cancelAndDelete(RdTimeoutEvent);
    for (int i=0; i<BU_list.size(); i++) {
        delete BU_list[i];
    }
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

    // vari timeout
    RdTimeout = 5;

    // manda il messaggio di controllo fra CtrlTimeout
    scheduleAt(simTime()+CtrlTimeout, CtrlTimeoutEvent);

}

void MobileNode::handleMessage(cMessage *msg)
{
    if(msg->isSelfMessage())
    {
        if (state != NN) {
            if (msg==CtrlTimeoutEvent)
            {
                //EV << "Arrivato il messaggio di controllo!\n";
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
                EV << "Movement detection non arrivato, discovering new default router!\n";
                routerDiscovery();
            }
            else if (msg==RdTimeoutEvent)
            {
                EV << "Router discovery non arrivato, provo a ricercare la rete";
                state = NN;
            }
        }

        else // if state == NN
        {
            routerDiscovery();
            if (msg==CtrlTimeoutEvent) {
                // manda il messaggio di controllo fra CtrlTimeout
                scheduleAt(simTime()+CtrlTimeout, CtrlTimeoutEvent);
            }
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
            if (RdTimeoutEvent!=NULL) {
                cancelEvent(RdTimeoutEvent); // se il router e' accessibile
                                        // non c'e' bisogno di router discovery
            }
            sendMessage();
        }
        else if(strtocmp.compare("ICMP error code 1") == 0) icmpErrorCode1(hmsg);
        else if(strtocmp.compare("ICMP error code 2") == 0) icmpErrorCode2(hmsg);
        else if(strtocmp.compare("Binding error status 1") == 0) bindingErrorStatus1(hmsg);
        else if(strtocmp.compare("Binding error status 2") == 0) bindingErrorStatus2(hmsg);
        else if(strtocmp.compare("IPv6 changed") == 0 || strtocmp.compare("Primary CoA deprecated") == 0)
            {
                EV << "Ipv6 changed or primary CoA deprecated, forming new CoA!";
                formingNewCoA();
            }
        else if(strtocmp.compare("Router discovery") == 0)
            {
                EV << "Router Discovery accepted!";
                cancelEvent(RdTimeoutEvent);
                formingNewCoA();
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

void MobileNode::compareBUandCoA()
{
    std::string strtofind = mnaddress + haaddress;
    for (int i=0; i<BU_list.size(); i++) {
        if (strtofind.compare(BU_list[i]->getId()) != 0) {
            formingNewCoA();
        }
    }
}

void MobileNode::sendSolicitation()
{
    if (MsTimeoutEvent && MsTimeoutEvent->isScheduled())
    {
        EV << "Mobile solicitation already scheduled!\n";
    }
    else {
        Hamn *ms = new Hamn();
        ms->setMsg("mobile solicitation");
        MsTimeout = 5.0;
        MsTimeoutEvent = new cMessage("Self message mobile solicitation");

        EV << "Sending mobile solicitation!\n";
        send(ms,"out");
        scheduleAt(simTime()+MsTimeout, MsTimeoutEvent);
    }
}

void MobileNode::movementDetection()
{
    if (MdTimeoutEvent && MdTimeoutEvent->isScheduled()) {
        EV << "Movement detection already scheduled!\n";
    }
    else {
        Hamn *md = new Hamn();
        md->setMsg("movement detection");
        MdTimeout = 5.0;
        MdTimeoutEvent = new cMessage("Self message movement detection");

        EV << "Sending movement detection!\n";
        send(md,"out");

        scheduleAt(simTime()+MdTimeout,MdTimeoutEvent);
    }
}

void MobileNode::sendMessage()
{
    Hamn *msg = new Hamn();
    msg->setMsg("Messaggio dal mobile node al home agent!");
    send(msg,"out");
}

void MobileNode::icmpErrorCode1(Hamn *hmsg)
{
    // If the mobile node receives such an ICMP error message in response to
    // a return routability rocedure or Binding Update, it SHOULD record in
    // its Binding Update List that future Binding Updates SHOULD NOT be
    // sent to this destination. Such Binding Update List entries SHOULD be
    // removed after a period of time in order to allow for retrying route
    // optimization
    int indice = 0;
    std::string fromwho = "";
    if (checkBU(hmsg,indice,fromwho)) {
        BU_list.erase(BU_list.begin() + indice);
    }
    delete hmsg;
}

void MobileNode::icmpErrorCode2(Hamn *hmsg)
{
    // If a mobile node receives an ICMP Parameter Problem, Code 2, message
    // from some node indicating that it does not support the Home Address option
    // the mobile node SHOULD log the error and then discard the ICMP message

    // LOG THE ERROR SOMEWHERE

    delete hmsg;
}

void MobileNode::bindingErrorStatus1(Hamn *hmsg)
{
    // section 11.3.6
    int indice = -1;
    std::string fromwho = "";
    if (checkBU(hmsg, indice, fromwho)) {
        if (fromwho.compare("ha")) {
            // MN SHOULD send a Binding Update to the HA - section 11.7.1
        }
        else if (fromwho.compare("cn")) {
            // do we have upper layer porgress information with CN ?
            // ignore message or remove BU in two cases
        }
    }
}

bool MobileNode::checkBU(Hamn * hmsg, int & indice, std::string & fromwho)
{
    const char* chartocompare = hmsg->getSource();
    std::string strtocompare(chartocompare);
    for (int i=0; i<BU_list.size(); i++) {
        if(strtocompare.compare(BU_list[i]->getIpHomeaddress())) {
            indice = i;
            fromwho = "ha";
            return true;
        }
        else if (strtocompare.compare(BU_list[i]->getIpCn())) {
            indice = i;
            fromwho = "cn";
            return true;
        }
    }
    return false;
}

void MobileNode::bindingErrorStatus2(Hamn *hmsg)
{
    // section 11.3.6
    // if expecting ack from CN MN SHOULD ignore this message
    // else MN SHOULD cease the use of any extensions tot his specification
}

void MobileNode::formingNewCoA()
{
    // section 11.5.3
    BindingUpdate* newBU = new BindingUpdate(mnaddress, haaddress, LIFETIME);
    BU_list.push_back(newBU);
}

void MobileNode::routerDiscovery()
{
    if (RdTimeoutEvent && RdTimeoutEvent->isScheduled()) {
        EV << "Router discovery already scheduled!";
    }
    else {
        RdTimeoutEvent = new cMessage("self message router discovery");
        Hamn *msg = new Hamn();
        msg->setMsg("Router discovery");
        send(msg,"out");
        scheduleAt(simTime() + RdTimeout,RdTimeoutEvent);
    }
    // section Movement Detection 11.5.1

}
