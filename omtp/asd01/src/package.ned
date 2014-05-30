package asd01;

@license(LGPL);

simple MobileNode {
	gates:
	    input in;
	    output out;
}

simple HomeAgent {
	gates:
	    input in;
	    output out;
}

network asd01 {
	submodules:
	    mn: MobileNode;
	    ha: HomeAgent;
	connections:
	    mn.out --> { delay = 100ms; } --> ha.in;
	    mn.in <-- { delay = 100ms; } <-- ha.out;
}