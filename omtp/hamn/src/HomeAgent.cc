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

#include <src/HomeAgent.h>

#define DATA 0
#define SOLICITATION 1
#define ERROR_ICMP 2
#define ERROR_BINDING 3

Define_Module(HomeAgent);

HomeAgent::HomeAgent() {
    // TODO Auto-generated constructor stub

}

HomeAgent::~HomeAgent() {
    // TODO Auto-generated destructor stub
}

void HomeAgent::handleMessage(cMessage *msg)
{
    hamn_msg *hhmsg = check_and_cast<hamn_msg *>(msg);

    switch(hhmsg->type_var) {
    case DATA:
        handleData(hhmsg);
    break;
    case SOLICITATION:
        handleSolicitation(hhmsg);
    break;
    case ERROR_ICMP:
    case ERROR_BINDING:
        handleError(hhmsg);
    break;
    }
}

void HomeAgent::handleSolicitation(hamn_msg *msg)
{
    msg->lifetime_var += 100;
    msg->destination_var = MNADDRESS;
    msg->source_var = HAADDRESS;
    send(msg, "out0");
}

void HomeAgent::handleError(hamn_msg *msg)
{
    msg->destination_var = MNADDRESS;
    msg->source_var = HAADDRESS;
    msg->type_var = ERROR_ICMP;
    msg->msg_var = "Code 1";
    send(msg, "out0");
}
