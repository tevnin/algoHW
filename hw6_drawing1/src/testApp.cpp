#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
    
    ofBackground(255,240,240);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	
	for (int i = 0; i < 500; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		particles.push_back(myParticle);
	}
	
	VF.setupField(60,40,ofGetWidth(), ofGetHeight());
    
    radius=5;
    

	//loopingSound.play();
	
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		
		// get the force from the vector field: 
		ofVec2f frc;
		frc = VF.getForceFromPos(particles[i].pos.x, particles[i].pos.y);
		particles[i].addForce(frc.x, frc.y);
		particles[i].addDampingForce();
		particles[i].update();
        
	
	}
	
	//VF.fadeField(0.99f);
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofEnableAlphaBlending();
	ofSetColor(0,0,0, 200);
	//VF.draw();
	
	//ofSetColor(0x000000);
    

    
//    if(ofGetFrameNum()%50 == 0){
//        VF.addOutwardCircle(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 200, 0.5f);
//    }



    if(radius < 1){
        radius = 1;
    }
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
        
        //musica
//        loopingSound.setVolume(2);
//        float pitch = ofMap(particles[i].pos.y, 0, (float)ofGetHeight(), 2.5, 0.1);
//        loopingSound.setSpeed(pitch);
//        
//        float pan = ofMap(particles[i].pos.x, 0, (float)ofGetWidth(), -1, 1);
//        loopingSound.setPan(pan);
//        loopingSound.play();
	}
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	if (key == ' '){
		VF.clear();
	} 
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
	float diffx = x - prevMouseX;
	float diffy = y - prevMouseY;
    //radius = diffx*0.5;
	
	VF.addVectorCircle((float)x, (float)y, diffx*0.3, diffy*0.3, 60, 0.3f);
	
	prevMouseX = x;
	prevMouseY = y;
    
//    VF.addOutwardCircle(x, y, 80, 0.3f);
    
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	prevMouseX = x; 
	prevMouseY = y;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
