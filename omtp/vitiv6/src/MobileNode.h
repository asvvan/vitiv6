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
#include <vector>
#include "BindingCache.h"

class MobileNode : public cSimpleModule {
private:
    bool athome;
    int srctouse;
    std::vector<BindingCache> BU_list;
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    void mv_detection();
public:
    MobileNode();
    virtual ~MobileNode();
    void sendpkg();
    // search a binding cache inside the list and return it
    BindingCache searchBU_list(int id);
    // add a new binding cache in the list
    void addBU_List(BindingCache bc);
    // remove all the biniding from the list
    void resetBU_list();
    // periodical control to clean the list from dead (lifetime) BC
    void cleanBU_list();

    bool isAthome() const {
        return athome;
    }

    void setAthome(bool athome) {
        this->athome = athome;
    }

    int getSrctouse() const {
        return srctouse;
    }

    void setSrctouse(int srctouse) {
        this->srctouse = srctouse;
    }
};

#endif /* MOBILENODE_H_ */
