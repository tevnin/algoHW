#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofBackground(200,200,200);
    
    lastMouseX = 0;
    lastMouseY = 0;
    
    myCircle.posA.x = lastMouseX;
    myCircle.posA.y = lastMouseY;
    myCircle.posB.x = 400;
    myCircle.posB.y = 400;
    myCircle.radiusA = 10;
    myCircle.radiusB = 100;
    
    
    myCircle.interpolateByPct(0);
    pct = 0;
    
    mouseCount = false;

}

//--------------------------------------------------------------
void testApp::update(){
    
    lastMouseX = myCircle.pos.x;
    lastMouseY = myCircle.pos.y;

    
    pct+=0.005f;
    if (pct > 1) {
		pct = 1;							// just between 0 and 1 (0% and 100%)
	}	
    //pct+=(float)abs(myCircle.posA.x - myCircle.posB.x)/100;
    
    myCircle.interpolateByPct(pct);

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    
    myFlower.draw();
    myCircle.draw();
    

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){


}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    myFlower.pos.x = x;
    myFlower.pos.y = y;
    
    myCircle.posA.x = lastMouseX;
    myCircle.posA.y = lastMouseY;
    myCircle.posB.x = x;
    myCircle.posB.y = y;
    
    if(mouseCount){
        myCircle.radiusA = myCircle.radius;
        myCircle.radiusB = 100;
    }else{
        myCircle.radiusA = myCircle.radius;
        myCircle.radiusB = 10;
    }
    
    mouseCount = !mouseCount;
    pct = 0;
    

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