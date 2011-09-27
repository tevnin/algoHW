#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofBackground(0,0,0);
	
	ofSetCircleResolution(100);
	
	radius = 50;
    
    r1 = 255;
    g1 = 255;
    b1 = 255;
    r2 = 255;
    g2 = 255;
    b2 = 0;
    
    
    backR1 = 94;
    backG1 = 25;
    backB1 = 105;
    backR2 = 153;
    backG2 = 221;
    backB2 = 255;
    
    
    


}

//--------------------------------------------------------------
void testApp::update(){
	
	
	radius = radius + 0.1;

}

//--------------------------------------------------------------
void testApp::draw(){
	
	float xorig = 500;
	float yorig = 300;
	
    
    
	float sinOfTime				= sin( ofGetElapsedTimef() );
	float sinOfTimeMapped		= ofMap( sinOfTime, -1, 1, 0, 100);
    float angle = ofGetElapsedTimef()+50;
    
    //sun & moon color
    float percent = (sinOfTimeMapped)/(float)100;    
    r = (1 - percent)*r1 + percent*r2;
    g = (1 - percent)*g1 + percent*g2;
    b = (1 - percent)*b1 + percent*b2;
    
    //percent = (sinOfTimeMapped)/(float)100;    
    backR = (1 - percent)*backR1 + percent*backR2;
    backG = (1 - percent)*backG1 + percent*backG2;
    backB = (1 - percent)*backB1 + percent*backB2;

	//sun & moon position
	float x = xorig + radius * -cos(angle);
	float y = yorig + radius * -sin(angle);
		
	ofSetColor(r, g, b);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofFill();
	ofCircle(x,y,50);
    ofBackground(backR, backG, backB);
	
	
	
	
	
	
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

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

