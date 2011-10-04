#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
    ofBackground(46,1,85);
	
	
	for (int i = 0; i < 1000; i++){
		particle myParticle;
		float vx = ofRandom(-4,4);
		float vy = ofRandom(-4,4);
		myParticle.setInitialCondition(300,300,vx, vy);
		// more interesting with diversity :)
		// uncomment this: 
		//myParticle.damping = ofRandom(0.01, 0.05);
		particles.push_back(myParticle);
	}
	
    frameCounter = 0;
    middleX = ofRandom(ofGetWidth());
    middleY = ofRandom(ofGetHeight());
    
    ofSetColor(ofRandom(255),31,83);
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
		//particles[i].addForce(0,0.04);  // gravity
		particles[i].addDampingForce();
		particles[i].update();
	}
    
    frameCounter++;
    middleX = ofRandom(ofGetWidth());
    middleY = ofRandom(ofGetHeight());

}

//--------------------------------------------------------------
void testApp::draw(){

	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
    
    if(frameCounter%120 == 0){
        ofSetColor(ofRandom(255),31,83);
        for (int i = 0; i < particles.size(); i++){
            float vx = ofRandom(-4,4);
            float vy = ofRandom(-4,4);
            particles[i].setInitialCondition(middleX,middleY,vx, vy);	
            
        }
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
