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

#ifndef HOMEAGENT_H_
#define HOMEAGENT_H_

extern const char * MNADDRESS;
extern const char * HAADDRESS;

#include <omnetpp.h>
#include <string>
#include <vector>
#include "BindingUpdate.h"
#include "hamn_msg_m.h"

class HomeAgent : public cSimpleModule {
public:
    HomeAgent();
    virtual ~HomeAgent();
    void handleMessage(cMessage *msg);
    void handleData(cMessage *msg) {}
    void handleSolicitation(hamn_msg *msg);
    void handleError(hamn_msg *msg);
    const char * MNADDRESS = "1.1.1.1";
    const char * HAADDRESS = "1.1.1.4";
};

#endif /* HOMEAGENT_H_ */
