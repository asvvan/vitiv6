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
#include "hamnhamh1_m.h"

#define MN 0
#define HA 1
#define CN 2

Define_Module(HomeAgent);

void HomeAgent::initialize() {

}

void HomeAgent::handleMessage(cMessage *msg) {
    HamnhamnMsg1 *hhmsg = check_and_cast<HamnhamnMsg1 *>(msg);

    if (hhmsg->destination_var == CN) {
        send(hhmsg, "out0");
    }
    else {
        send(hhmsg, "out1");
    }
}

HomeAgent::HomeAgent() {
    // TODO Auto-generated constructor stub

}

HomeAgent::~HomeAgent() {
    // TODO Auto-generated destructor stub
}

