//
//  circle.cpp
//  hw2_xeno
//
//  Created by Tami Evnin on 9/8/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "circle.h"

//--------------------------------------------------------------
circle::circle(){
    catchUpSpeed = ofRandom(0.01f,0.06f);
    r = ofRandom(100,255);
    g = ofRandom(100,255);
    b = ofRandom(100,255);
    
}

//--------------------------------------------------------------
void circle::draw(){
    ofFill();
    ofSetColor(r,g,b);
    ofCircle(pos.x, pos.y, radius);
    
}

//--------------------------------------------------------------
void circle::xenoToPoint(float catchX, float catchY){
    pos.x = (1-catchUpSpeed) * pos.x + catchUpSpeed * catchX; 
	pos.y = (1-catchUpSpeed) * pos.y + catchUpSpeed * catchY; 
    radius = (1-pct)*radiusA + pct*radiusB;
    //radius = 50;
    
}
//--------------------------------------------------------------
void circle::interpolateByPct(float myPct){
    pct = myPct;
    radius = (1-pct)*radiusA + pct*radiusB;
    //radius = 50;
    
}

