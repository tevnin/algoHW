#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofBackground(200,200,200);
	
	
	// set the "a" and "b" positions of the rectangle...
	
	myRectangle.posa.x = 20;
	myRectangle.posa.y = 100;
	myRectangle.posb.x = ofGetWidth();
	myRectangle.posb.y = 100;
	myRectangle.interpolateByPct(0);	// start at 0 pct
	pct = 0;							// a variable we can alter...
	
	
	
} 

//--------------------------------------------------------------
void testApp::update(){
	
	// to see pct in the console
	//printf("%f \n", pct);
    //0.000001f;
	pct += 0.000001f;							// increase by a certain amount
	if (pct > 1) {
		pct = 0;							// just between 0 and 1 (0% and 100%)
	}	
	myRectangle.interpolateByPct(pct);		// go between pta and ptb

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofDrawBitmapString("elapsed time: "+ofToString(ofGetElapsedTimeMillis()), 20, 200);
    if(myRectangle.pos.x == 0){
        ofDrawBitmapString("start time: "+ofToString(ofGetElapsedTimeMillis()), 20, 250);
    }else if(myRectangle.pos.x == ofGetWidth()){
        ofDrawBitmapString("end time: "+ofToString(ofGetElapsedTimeMillis()), 20, 300);
    }
    
	myRectangle.draw();
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
	
//	myRectangle.posa.x = x;
//	myRectangle.posa.y = y;
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
