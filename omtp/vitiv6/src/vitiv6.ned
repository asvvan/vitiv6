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

package vitiv6;

simple MobileNode {
	parameters:
	    bool athome; //true if at home, false otherwise
	    int srctouse; // 0 mn, 1 ha
	gates:
	    input in0;
        output out0; // 0 comunica con correspondent node
        input in1;
        output out1; // 1 comunica con home agent
}

simple CorrNode {
	gates:
	    input in0;
        output out0; // 0 comunica con mobile node
        input in1;
        output out1; // 1 comunica con home agent
}

simple HomeAgent {
	gates:
	    input in0;
        output out0; // 0 comunica con correspondent node
        input in1;
        output out1; // 1 comunica con mobile node
}

network Rete01 {
	submodules:
	    mn: MobileNode;
	    cn: CorrNode;
	    ha: HomeAgent;
	    
	connections:
        mn.out0 --> {  delay = 100ms; } --> cn.in0;
        mn.in0 <-- {  delay = 100ms; } <-- cn.out0;
        ha.out0 --> {  delay = 100ms; } --> cn.in1;
        ha.in0 <-- {  delay = 100ms; } <-- cn.out1;
        mn.out1 --> {  delay = 100ms; } --> ha.in1;
        mn.in1 <-- {  delay = 100ms; } <-- ha.out1;
}