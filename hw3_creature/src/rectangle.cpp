#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
	catchUpSpeed = 0.06f;
	
	pos.set(0,0);
	prevPos.set(0,0);
}

//------------------------------------------------------------------
void rectangle::draw() {
	ofFill();
	
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
	
	ofPushMatrix();
		ofTranslate(pos.x, pos.y, 0);
		ofRotateZ(angle * RAD_TO_DEG);
		ofCircle( 0,0, radius);
	
		ofRect(15,0,3,3);
	
	
	ofPopMatrix();
	
	
}

//------------------------------------------------------------------
void rectangle::xenoToPoint(float catchX, float catchY){
	
	
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x; 
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    //radius = (1-sin(ofGetElapsedTimef()))*radiusA + sin(ofGetElapsedTimef())*radiusB;
    radius = 10;

	float dx = pos.x - prevPos.x;
	float dy = pos.y - prevPos.y;
	
	angle = atan2(dy, dx);

	prevPos.x = pos.x;
	prevPos.y = pos.y;
	

}
