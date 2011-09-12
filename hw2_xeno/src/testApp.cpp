#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
	ofBackground(200,200,200);

    
    circ.radiusA = 10;
    circ.radiusB = 30;
    circ2.radiusA = 8;
    circ2.radiusB = 20;
    circ3.radiusA = 6;
    circ3.radiusB = 10;
    circ4.radiusA = 4;
    circ4.radiusB = 8;
    
    circ.pos.x = 100;
    circ.pos.y = 50;
    circ2.pos.x = 100;
    circ2.pos.y = 50;
    circ3.pos.x = 100;
    circ3.pos.y = 50;
    circ4.pos.x = 100;
    circ4.pos.y = 50;
    
    circ.interpolateByPct(0);
    circ2.interpolateByPct(0);
    circ3.interpolateByPct(0);
    circ4.interpolateByPct(0);

    pct = 0;

}

//--------------------------------------------------------------
void testApp::update(){
    
    pct+=0.005f;
    if (pct > 1) {
		pct = 1;							// just between 0 and 1 (0% and 100%)
	}

    
    circ.xenoToPoint(mouseX, mouseY);
    circ2.xenoToPoint(circ.pos.x, circ.pos.y);
    circ3.xenoToPoint(circ2.pos.x, circ2.pos.y);
    circ4.xenoToPoint(circ3.pos.x, circ3.pos.y);
    //pct+=(float)abs(myCircle.posA.x - myCircle.posB.x)/100;
    circ.interpolateByPct(pct);
    circ2.interpolateByPct(pct);
    circ3.interpolateByPct(pct);
    circ4.interpolateByPct(pct);
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    circ.draw();
    circ2.draw();
    circ3.draw();
    circ4.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
    pct = 0;

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}