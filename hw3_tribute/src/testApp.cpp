#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofBackground(0,0,0);
	
	ofSetCircleResolution(100);
	
	
	radius = 50;

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
    //float opSinOfTimeMapped     = ofMap(sinOfTimeMapped, 0, 255, 255, 0);
    float angle = sinOfTimeMapped;
	ofSetColor(sinOfTimeMapped, sinOfTimeMapped, sinOfTimeMapped);
	
    for(int i=0; i<3;i++){
        float x = xorig + radius * cos(angle)*i;
        float y = yorig + radius * -sin(angle)*i;
        
       
            ofPoint temp;
            temp.x = x;
            temp.y = y;
            points.push_back(temp);
            if (points.size() > 1000){
                points.erase(points.begin());
            }

        
        
        ofSetRectMode(OF_RECTMODE_CENTER);
        //ofSetColor(255,0,127);
        //ofFill();
        //ofCircle(x,y,10);
        
        ofSetColor(255,255,255);
        
        ofNoFill();
        ofBeginShape();
        for (int i = 0; i < points.size(); i++){
            ofVertex(points[i].x, points[i].y);
        }
        ofEndShape();
    }
    
    //ofBackground(opSinOfTimeMapped, opSinOfTimeMapped, opSinOfTimeMapped);
	
	
	
	
	
	
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

