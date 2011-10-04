#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	ofBackground(0, 0, 0);
	
	p.setInitialCondition(300,300,ofRandom(-1,1), ofRandom(-1,1));
    
    start = 0;
    end = 0;
    
    doDraw = false;
    
    loopingSound.loadSound("drawbar_c4_a.aif");
	loopingSound.setVolume(0);
	loopingSound.setLoop(true);
	loopingSound.play();
}

//--------------------------------------------------------------
void testApp::update(){

	p.update();
    
    for(int i=0; i<line.size(); i++){
        if(ofDist(p.pos.x, p.pos.y, line[i].x, line[i].y) == 0){
            p.vel.y *= -1;
        }
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofNoFill();
    ofCircle(ofGetWidth()/2,100, 10);
    
    
    if(ofGetFrameNum()%60 == 0){
        p.setInitialCondition(ofGetWidth()/2,100,0,10);
    }

    ofFill();
	ofSetColor(0xffffff);
	p.draw();
    
    if(doDraw == true){
        b.draw(start.x,start.y,end.x,end.y);
    }
    
    //musica
    //float soundVolume = ofMap(line[0].x, 0,200, 0,1);
    loopingSound.setVolume(30);
    
    
    float pitch = ofMap(p.pos.y, 0, (float)ofGetHeight(), 2.5, 0.1);
    loopingSound.setSpeed(pitch);
    
    float pan = ofMap(p.pos.x, 0, (float)ofGetWidth(), -1, 1);
    loopingSound.setPan(pan);
    
    ofFill();
    ofSetColor(255, 255, 255);
    for(int i=0; i<line.size(); i++){
        ofDrawBitmapString(ofToString(ofDist(p.pos.x, p.pos.y, line[i].x, line[i].y)), 10, 100);
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
    
    ofPoint temp;
	temp.x = x;
	temp.y = y;
	line.push_back(temp);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
    line.clear();
	ofPoint temp;
	temp.x = x;
	temp.y = y;
	line.push_back(temp);
    
    start.x = line[0].x;
    start.y = line[0].y;
    
    doDraw = false;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    end.x = line[line.size()-1].x;
    end.y = line[line.size()-1].y;
    
    doDraw = true;
    
}
