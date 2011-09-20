#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofEnableAlphaBlending();
	ofBackground(30,30,30);
	
	
	// set the position of the rectangle:
    
    for(int i=0; i<6; i++){
        
        myRectangle.push_back( rectangle() );
        
        myRectangle[i].radiusA = 21-(2*i);
        myRectangle[i].radiusB = 50-(2*i);
        myRectangle[i].pos.x = 100;
        myRectangle[i].pos.y = 50;
        //myRectangle[i].interpolateByPct(0);
    }
	
}

//--------------------------------------------------------------
void testApp::update(){
    
    myRectangle[0].xenoToPoint(mouseX,mouseY);
    //myRectangle[0].interpolateByPct(pct);
    
    for(int i=1; i<myRectangle.size(); i++){
        myRectangle[i].xenoToPoint(myRectangle[i-1].pos.x,myRectangle[i-1].pos.y);
        //myRectangle[i].interpolateByPct(pct);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i=0; i<myRectangle.size();i++){
        myRectangle[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
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
void testApp::mouseReleased(){
}
