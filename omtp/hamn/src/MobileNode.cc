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

Define_Module(MobileNode);

MobileNode::MobileNode() {
    // TODO Auto-generated constructor stub
    mnaddress = "1.1.1.1";
    haaddress = "1.1.1.4";
}

MobileNode::~MobileNode() {
    // TODO Auto-generated destructor stub
}

void updateState() {
    if ( mnaddress.compare(0,5,haaddress) == 0 ) state = HN;
    else if ( mnaddress != NULL ) state = FN;
    else state = NN;
}

BindingUpdate creteNewBU(std::string mn, std::string ha)
{
    BindingUpdate *bu = new BindingUpdate();
    bu->setIpCoa(mnaddress);
    bu->setIpHomeaddress(haaddress);
}

bool mobileSolicitation()
{

}
