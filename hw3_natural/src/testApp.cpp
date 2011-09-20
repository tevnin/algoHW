#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofBackground(0,0,0);
	
	ofSetCircleResolution(100);
	
	radius = 50;
    
    r1 = 255;
    g1 = 255;
    b1 = 0;
    r2 = 255;
    g2 = 255;
    b2 = 255;


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
	float sinOfTimeMapped		= ofMap( sinOfTime, -1, 1, 0, 255);
    float opSinOfTimeMapped     = ofMap(sinOfTimeMapped, 0, 255, 255, 0);
    float angle = ofGetElapsedTimef()+50;
    
    //sun & moon color
    float percent = (opSinOfTimeMapped)/(float)100;    
    r = (1 - percent)*r1 + percent*r2;
    g = (1 - percent)*g1 + percent*g2;
    b = (1 - percent)*b1 + percent*b2;

	//sun & moon position
	float x = xorig + radius * sin(angle);
	float y = yorig + radius * -cos(angle);
	
	ofPoint temp;
	temp.x = x;
	temp.y = y;
	points.push_back(temp);
	if (points.size() > 1000){
		points.erase(points.begin());
	}
	
	ofSetColor(r, g, b);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofFill();
	ofCircle(x,y,50);

    ofBackground(sinOfTimeMapped, sinOfTimeMapped, sinOfTimeMapped);
	
	
	
	
	
	
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

