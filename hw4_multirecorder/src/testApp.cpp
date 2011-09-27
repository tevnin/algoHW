#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(true);
	
	ofBackground(0, 0, 0);
	TPR.setup();
    TPR2.setup();
	playbackStartTime = 0;
    
    newRecorder = false;
    
    loopingSound.loadSound("drawbar_c4_a.aif");
	loopingSound.setVolume(0);
	loopingSound.setLoop(true);
	loopingSound.play();
	
}


//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

	
	// -------------------------- draw the point at the current time
	if (TPR.bHaveADrawing()){			// if we have a drawing to work with
		
		// figure out what time we are at, and make sure we playback cyclically (!)
		// use the duration here and make sure our timeToCheck is in the range of 0 - duration
        
		float timeToCheck = ofGetElapsedTimef() - playbackStartTime;
		while (timeToCheck > TPR.getDuration() && TPR.getDuration() > 0){
			timeToCheck -= TPR.getDuration();
		}
        
        float timeToCheck_2 = ofGetElapsedTimef() - playbackStartTime + 2.0;
		while (timeToCheck_2 > TPR2.getDuration() && TPR2.getDuration() > 0){
			timeToCheck_2 -= TPR2.getDuration();
		}
		
		// get the position and velocity at timeToCheck
		ofPoint pos = TPR.getPositionForTime(timeToCheck);
		ofPoint vel = TPR.getVelocityForTime(timeToCheck);
		ofPoint pos2 = TPR.getPositionForTime(timeToCheck);
        ofPoint vel2 = TPR.getVelocityForTime(timeToCheck);
        
        //subract 1 from timeToCheck
        ofPoint pos_2 = TPR.getPositionForTime(timeToCheck_2);
		ofPoint vel_2 = TPR.getVelocityForTime(timeToCheck_2);
		ofPoint pos2_2 = TPR.getPositionForTime(timeToCheck_2);
        ofPoint vel2_2 = TPR.getVelocityForTime(timeToCheck_2);
        
		// since velocity is a line, we want to know how long it is. 
		float lengthOfVel = ofDist(0,0,vel.x, vel.y);
        float lengthOfVel2 = ofDist(0,0,vel2.x, vel2.y);
        
        float lengthOfVel_2 = ofDist(0,0,vel_2.x, vel_2.y);
        float lengthOfVel2_2 = ofDist(0,0,vel2_2.x, vel2_2.y);
        
        //musica
        float soundVolume = ofMap(lengthOfVel, 0,200, 0,1);
		loopingSound.setVolume(soundVolume);
		
		
		float pitch = ofMap(pos.y, 0, (float)ofGetHeight(), 2.5, 0.1);
		loopingSound.setSpeed(pitch);
		
		float pan = ofMap(pos.x, 0, (float)ofGetWidth(), -1, 1);
		loopingSound.setPan(pan);

		
		ofFill();
		ofSetColor(171,96,231);
		ofCircle(pos.x, pos.y, 2 + lengthOfVel/5.0);
        
        
        
        ofSetColor(99,216,96);
        ofCircle(pos_2.x, pos_2.y, 2 + lengthOfVel_2/5.0);
		
		
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
	TPR.addPoint(x,y);
    TPR2.addPoint(x,y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
	TPR.startDrawing(x,y);
    TPR2.startDrawing(x,y);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
	TPR.endDrawing();
    TPR2.endDrawing();
	playbackStartTime = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}



