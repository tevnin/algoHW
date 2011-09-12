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
    catchUpSpeed = 0.03f;
    
}

//--------------------------------------------------------------
void circle::draw(){
    ofFill();
    ofSetColor(255,0,127);
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

