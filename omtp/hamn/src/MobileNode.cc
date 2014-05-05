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

#define HN 0 // home network
#define FN 1 // foreign network
#define NN 2 // no network

#define DATA 0
#define SOLICITATION 1
#define ERROR 2

Define_Module(MobileNode);

MobileNode::MobileNode() {
    // TODO Auto-generated constructor stub
    mnaddress = "1.1.1.1";
    haaddress = "1.1.1.4";
    halifetime = 0;
}

MobileNode::~MobileNode() {
    // TODO Auto-generated destructor stub
}

void MobileNode::initialize() {
    state = par("state");
    mobileSolicitation();
}

void MobileNode::handleMessage(cMessage *msg) {
    mobileSolicitation();
}

void MobileNode::updateState() {
    if ( mnaddress.compare(0,5,haaddress) == 0 ) state = HN;
    else if ( !mnaddress.empty() ) state = FN;
    else state = NN;
}

BindingUpdate MobileNode::creteNewBU(std::string mn, std::string ha)
{
    BindingUpdate *bu = new BindingUpdate();
    bu->setIpCoa(mnaddress);
    bu->setIpHomeaddress(haaddress);
    return *bu;
}

bool MobileNode::mobileSolicitation()
{
    hamn_msg *msg = new hamn_msg();
    msg->source_var = mnaddress;
    msg->destination_var = haaddress;
    msg->msg_var = "Puppa!";
    msg->type_var = SOLICITATION;
    msg->lifetime_var = halifetime;

    send(msg, "out0");
    return true;
}
