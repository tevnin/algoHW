#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
	
	ofBackground(0, 0, 0);
	
	//p.setInitialCondition(300,300,ofRandom(-1,1), ofRandom(-1,1));
    p.setup();
    
    start = 0;
    end = 0;
    
    doDraw = false;
    
    
}

//--------------------------------------------------------------
void testApp::update(){

	p.update();
    
        

        distStuff = ofDist(p.pos.x, p.pos.y, b.pos1.x+cos(b.barAngle*b.barDist), b.pos1.y+sin(b.barAngle*b.barDist));

        if(distStuff <= 25){
            p.bounce(b.barAngle);
            //p.sound();
        }


    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofNoFill();
    ofCircle(ofGetWidth()/2,100, 10);
    
    
    if(ofGetFrameNum()%60 == 0){
        
    }

    ofFill();
	ofSetColor(0xffffff);
	p.draw();
    
    //if(doDraw == true){
        b.draw();
    //}
    
    /*ofDrawBitmapString("distStuff = "+ofToString(distStuff), 10, 10);
    ofDrawBitmapString("p.vel.y = "+ofToString(p.vel.y), 10, 30);
    ofDrawBitmapString("barAngle = "+ofToString(b.barAngle), 10, 50);
    ofDrawBitmapString("barDist = "+ofToString(b.barDist), 10, 60);
    ofDrawBitmapString("b.pos1.x+cos(b.barAngle*b.barDist)-ofGetWidth()/2 = "+ofToString(b.pos1.x+cos(b.barAngle*b.barDist)-ofGetWidth()/2), 10, 80);
    
    ofDrawBitmapString("p.pos.x = "+ofToString(p.pos.x)+" p.pos.y = "+ofToString(p.pos.y), 10, 120);
    ofDrawBitmapString("b.pos1.x = "+ofToString(b.pos1.x)+" b.pos1.y = "+ofToString(b.pos1.y), 10, 140);*/

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    if(key == 'b' || key == 'B'){
        p.setInitialCondition(ofGetWidth()/2,100,0,10);
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
    b.drawPos2(x, y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    b.drawPos1(x, y);
    doDraw = false;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    
    
    doDraw = true;
    
}
