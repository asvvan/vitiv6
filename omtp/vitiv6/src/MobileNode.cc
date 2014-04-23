//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include <src/MobileNode.h>
#include "hamnhamh1_m.h"

#define MN 0
#define HA 1
#define CN 2

Define_Module(MobileNode);

void MobileNode::initialize() {
    athome = par("athome");
    sendpkg();
}

void MobileNode::handleMessage(cMessage *msg) {
    //HamnhamnMsg1 *hhmsg = check_and_cast<HamnhamnMsg1 *>(msg);
    sendpkg();
}

void MobileNode::sendpkg()
{
    HamnhamnMsg1 *msg = new HamnhamnMsg1();
    msg->msg_var = "puppa from mobile node!";
    srctouse = par("srctouse");
    msg->source_var =  srctouse;
    msg->destination_var = CN;

    //chiamata al movement detection
    mv_detection();

    if (athome) {
        //normal ipv6
        send(msg, "out0");
    }
    else { // sono fuori casa
        if (srctouse == HA) {
            //uso la HA mentre sono fuori casa
            //faccio normalipv6
            send(msg, "out0");
        }
        else {
            //uso la CoA mentre sono fuori casa
            //posso fare Route Optimization se esiste la Binding Cache
            //altrimenti uso Reverse Tunelling
            send(msg, "out1");
        }
    }
}

void MobileNode::mv_detection() {
    if (athome) athome = false;
    else athome = true;
}

MobileNode::MobileNode() {
    // TODO Auto-generated constructor stub

}

MobileNode::~MobileNode() {
    // TODO Auto-generated destructor stub
}

