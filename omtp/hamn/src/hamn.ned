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

package hamn;

simple MobileNode {
	parameters:
	    int state; //0 at home, 1 at foreign, 2 no network
	    int srctouse; // 0 mn, 1 ha
	gates:
	    input in0;
        output out0; // 0 comunica con home agent
}

simple HomeAgent {
	gates:
	    input in0;
        output out0; // 0 comunica con mobile node
}

network reteOne {
	submodules:
	    mn: MobileNode;
	    ha: HomeAgent;
	    
	connections:
        mn.out0 --> {  delay = 100ms; } --> ha.in0;
        mn.in0 <-- {  delay = 100ms; } <-- ha.out0;
}