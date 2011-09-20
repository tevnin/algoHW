#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofBackground(0,0,0);
	
	ofSetCircleResolution(100);
    
    rect.x = 0;
    rect.y = ofGetHeight()/2;

}

//--------------------------------------------------------------
void testApp::update(){
	
	

}

//--------------------------------------------------------------
void testApp::draw(){
	
	
	float sinOfTime = sin( ofGetElapsedTimef() * 6);
    float cosOfTime = cos( ofGetElapsedTimef() );
	float sinOfTimeMapped = ofMap( sinOfTime, -1, 1, 500, 100);
    float locX = ofMap(sinOfTime, -1,1,0,ofGetWidth());
    //float locY = ofMap(cosOfTime, -1,1,ofGetHeight()/2-100,ofGetHeight()/2+100);
    float col = ofMap(sinOfTime, -1,1,0,255);
    
    
    
    rect.x++;
	rect.y = sinOfTimeMapped*(ofGetElapsedTimef()/10);
    
    ofPoint temp;
	temp.x = rect.x;
	temp.y = rect.y;
	points.push_back(temp);
	if (points.size() > 350){
		points.erase(points.begin());
	}
	
	
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(255,0,127);
	ofFill();
	ofCircle(rect.x,rect.y,10);
	
	ofSetColor(255,255,255);
    //ofSetColor(col, col, col);
	
	//ofNoFill();
	ofBeginShape();
	for (int i = 0; i < points.size(); i++){
		ofVertex(points[i].x, points[i].y);
	}
	ofEndShape();

	

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

