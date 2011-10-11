#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
    //ofBackground(46,1,85);
    ofBackground(0,0,0);
	
	
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
    middleX = ofRandom(100, ofGetWidth() - 100);
    middleY = ofRandom(100, ofGetHeight() - 100);
    
    ofSetColor(ofRandom(255),31,83);
}

//--------------------------------------------------------------
void testApp::update(){

	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		//particles[i].addForce(0,0.04);  // gravity
		particles[i].addDampingForce();
		particles[i].update();
	}
    
    frameCounter++;
    middleX = ofRandom(100, ofGetWidth() - 100);
    middleY = ofRandom(100, ofGetHeight() - 100);

}

//--------------------------------------------------------------
void testApp::draw(){	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
        
        ofPoint temp;
        temp.x = particles[i].pos.x;
        temp.y = particles[i].pos.y;
        points.push_back(temp);
        if (points.size() > 1000){
            points.erase(points.begin());
        }

	}

    
    //ofNoFill();
//	ofSetColor(255, 255, 255);
//	for (int i = 0; i < points.size(); i++){
//        ofBeginShape();
//		ofVertex(points[i].x, points[i].y);
//        ofEndShape();
//	}
	
    
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
