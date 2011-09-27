#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	ofSetVerticalSync(true);

	ofEnableAlphaBlending();
	ofBackground(153,221,255);

    
    for(int i=0; i<6; i++){
        
        myFish.push_back( fish() );
        
        myFish[i].radiusA = 10;
        myFish[i].radiusB = 20;
        myFish[i].pos.x = 200;
        myFish[i].pos.y = 0;
        
    }
	
}

//--------------------------------------------------------------
void testApp::update(){
    
    myFish[0].xenoToPoint(mouseX,mouseY);
    
    for(int i=1; i<myFish.size(); i++){
        myFish[i].xenoToPoint(myFish[i-1].pos.x,myFish[i-1].pos.y);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i=0; i<myFish.size();i++){
        myFish[i].draw();
    }
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
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
