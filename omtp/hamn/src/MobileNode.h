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

#ifndef MOBILENODE_H_
#define MOBILENODE_H_

#include <omnetpp.h>
#include <string>
#include <vector>
#include "BindingUpdate.h"

class MobileNode : public cSimpleModule {
    int state; // HN, FN or NN
    std::string mnaddress;
    std::string haaddress;
    std::vector<BindingUpdate> BU_list;
public:
    MobileNode();
    virtual ~MobileNode();
    void updateState();
    BindingUpdate creteNewBU(std::string mn, std::string ha);
    bool mobileSolicitation();
};

#endif /* MOBILENODE_H_ */