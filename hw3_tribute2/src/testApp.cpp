#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofBackground(0,0,0);
	
	ofSetCircleResolution(100);

}

//--------------------------------------------------------------
void testApp::update(){
	
	
	

}

//--------------------------------------------------------------
void testApp::draw(){
	
    float xorig = ofGetWidth()/2;
	float yorig = ofGetHeight()/2;
	
	for (int i = 0; i < 20; i++){
        
		float radius = 50 + i * 20;
		float angle = ofGetElapsedTimef() * (1 + i / 50.0);
        float col = ofMap(sin( ofGetElapsedTimef()), -1, 1, 0, 255);
		float x = xorig + radius * cos(angle * 3.4);
		float y = yorig + radius * -sin(angle * 4.7);
        
        ofPoint temp;
        temp.x = x;
        temp.y = y;
        points.push_back(temp);
        if (points.size() > 100){
            points.erase(points.begin());
        }
		
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofSetColor(col,100,127-col);
		//ofCircle(x,y,1);
        
        ofNoFill();
        ofBeginShape();
        for (int i = 0; i < points.size(); i++){
            ofVertex(points[i].x, points[i].y);
        }
        ofEndShape();
        
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

