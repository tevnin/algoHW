#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //white 238,233,233
    //pink 255,20,147
    ofBackground(238,233,233);

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255,20,147);
    // T
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofRect(ofGetWidth()/4, ofGetHeight()/4, 30, ofGetHeight()/2);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofRect(ofGetWidth()/4+15, ofGetHeight()/4, ofGetWidth()/4+15, 30);
    ofSetRectMode(OF_RECTMODE_CORNER);
    
    // a
    ofBezier(ofGetWidth()/2-50, ofGetHeight()/2, ofGetWidth()/3-50, ofGetHeight()/2, ofGetWidth()/3-50, 3*ofGetHeight()/4, ofGetWidth()/2-50, 3*ofGetHeight()/4);
    ofSetColor(238,233,233);
    ofBezier(ofGetWidth()/2-20, ofGetHeight()/2+20, ofGetWidth()/3-50, ofGetHeight()/2+30, ofGetWidth()/3-20, 3*ofGetHeight()/4-30, ofGetWidth()/2-20, 3*ofGetHeight()/4-20);
    ofSetColor(255,20,147);
    ofRect(ofGetWidth()/2-50, ofGetHeight()/2, 30, ofGetHeight()/4 +30);
    //ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2, 3*ofGetHeight()/4+30);
    
    
    // m
    ofRect(2*ofGetWidth()/3 - 130, ofGetHeight()/2, 30, ofGetHeight()/4);
    
    ofBezier(2*ofGetWidth()/3 - 120, 3*ofGetHeight()/4, 2*ofGetWidth()/3-100, ofGetHeight()/2 - 20, 2*ofGetWidth()/3 -20, ofGetHeight()/2 -20, 2*ofGetWidth()/3, 3*ofGetHeight()/4);
    ofSetColor(238,233,233);
    ofBezier(2*ofGetWidth()/3 -100, 3*ofGetHeight()/4, 2*ofGetWidth()/3 -100, ofGetHeight()/2, 2*ofGetWidth()/3 -20, ofGetHeight()/2, 2*ofGetWidth()/3 -20, 3*ofGetHeight()/4);
    ofSetColor(255,20,147);
    
    ofBezier(2*ofGetWidth()/3 - 20, 3*ofGetHeight()/4, 2*ofGetWidth()/3, ofGetHeight()/2 - 20, 2*ofGetWidth()/3 + 80, ofGetHeight()/2 -20, 2*ofGetWidth()/3 + 100, 3*ofGetHeight()/4);
    ofSetColor(238,233,233);
    ofBezier(2*ofGetWidth()/3, 3*ofGetHeight()/4, 2*ofGetWidth()/3, ofGetHeight()/2, 2*ofGetWidth()/3 + 80, ofGetHeight()/2, 2*ofGetWidth()/3 + 80, 3*ofGetHeight()/4);
    ofSetColor(255,20,147);
    
    
    // i
    ofRect(4*ofGetWidth()/5, ofGetHeight()/2 - 60, 30, 30);
    ofRect(4*ofGetWidth()/5, ofGetHeight()/2, 30, ofGetHeight()/4);

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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}