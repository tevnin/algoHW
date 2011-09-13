#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
	ofBackground(200,200,200);
    
    for(int i=0; i<6; i++){
        
        circs.push_back( circle() );
        
        circs[i].radiusA = 21-(2*i);
        circs[i].radiusB = 50-(2*i);
        circs[i].pos.x = 100;
        circs[i].pos.y = 50;
        circs[i].interpolateByPct(0);
    }


    pct = 0;

}

//--------------------------------------------------------------
void testApp::update(){
    
    pct+=0.005f;
    if (pct > 1) {
		pct = 1;							// just between 0 and 1 (0% and 100%)
	}
    
    circs[0].xenoToPoint(mouseX,mouseY);
    circs[0].interpolateByPct(pct);
    
    for(int i=1; i<circs.size(); i++){
        circs[i].xenoToPoint(circs[i-1].pos.x,circs[i-1].pos.y);
        circs[i].interpolateByPct(pct);
    }

    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for(int i=0; i<circs.size(); i++){
        circs[i].draw();
    }

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