#include "fish.h"


//------------------------------------------------------------------
fish::fish(){
	catchUpSpeed = 0.02f;
	
	pos.set(0,0);
	prevPos.set(0,0);
    tail.set(-50,5);
}

//------------------------------------------------------------------
void fish::draw() {
	ofFill();
	
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(238,115,59);
    ofFill();
	
	ofPushMatrix();
		ofTranslate(pos.x, pos.y, 0);
		ofRotateZ(angle * RAD_TO_DEG);
    ofScale(0.5, 0.5);
    
        //tail fin
        ofSetColor(0, 0, 0);
        ofBeginShape();
            ofVertex(0,0);
            ofBezierVertex(0, 0, -30, 50, -60+tail.x, -5+tail.y);
            ofBezierVertex(-60+tail.x,-5+tail.y, -10, 20, 0, 0);
        ofEndShape(true);
    
        ofSetColor(0, 0, 0);
        ofBeginShape();
            ofVertex(0,0);
            ofBezierVertex(0, 0, -30, -50, -50+tail.x, -5+tail.y);
            ofBezierVertex(-50+tail.x,-5+tail.y, -10, -10, 0, 0);
        ofEndShape(true);
    
        //fins
        ofSetColor(0,0,0);
        ofBeginShape();
            ofVertex(50, -40);
            ofBezierVertex(50, -40, 65, -50, 70, 0);
            ofBezierVertex(70, 0, 50, -10, 50, -40);
        ofEndShape(true);
    
        ofBeginShape();
            ofVertex(50, 40);
            ofBezierVertex(50, 40, 65, 50, 70, 0);
            ofBezierVertex(70, 0, 50, 10, 50, 40);
        ofEndShape(true);
    
        //white
        ofSetColor(255,255,255);
        ofBeginShape();
            ofVertex(20, 0);
            ofBezierVertex(20, 0, 50, -50, 100, 0);
            ofBezierVertex(100, 0, 50, 50, 20, 0);
        ofEndShape(true);
    
        //orange
        ofSetColor(238,115,59);
        ofBeginShape();
            ofVertex(20, 0);
            ofBezierVertex(20, 0, 50, -40, 100, 0);
            ofBezierVertex(100, 0, 50, 40, 20, 0);
        ofEndShape(true);
    
        //black
        ofSetColor(0,0,0);
        ofBeginShape();
            ofVertex(0, 0);
            ofBezierVertex(0, 0, 65, -30, 100, 0);
            ofBezierVertex(100, 0, 65, 30, 0, 0);
        ofEndShape(true);
    
        //eyes
        ofSetColor(0,0,0);
            ofCircle(90, 10, 6);
            ofCircle(90,-10,6);
        ofSetColor(238,115,59);
            ofCircle(90,10,2);
            ofCircle(90,-10,2);
	
	
	ofPopMatrix();
	
	
}

//------------------------------------------------------------------
void fish::xenoToPoint(float catchX, float catchY){
	
	
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x; 
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    //radius = catchUpSpeed * radiusB + (1-catchUpSpeed) * radiusA;
    tail.x = catchUpSpeed * catchX + (1-catchUpSpeed) * .75*tail.x;
    tail.y = catchUpSpeed * catchY + (1-catchUpSpeed) * .75*tail.y;

	float dx = pos.x - prevPos.x;
	float dy = pos.y - prevPos.y;
	
	angle = atan2(dy, dx);

	prevPos.x = pos.x;
	prevPos.y = pos.y;
	

}
