//
//  circle.cpp
//  hw2_click
//
//  Created by Tami Evnin on 9/8/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "circle.h"

//--------------------------------------------------------------
circle::circle(){
    
}

//--------------------------------------------------------------
void circle::draw(){
    ofFill();
    ofSetColor(255,0,127);
    ofCircle(pos.x, pos.y, radius);
    
}

//--------------------------------------------------------------
void circle::interpolateByPct(float myPct){
    pct = myPct;
    pos.x = (1-pct)*posA.x + pct*posB.x;
    pos.y = (1-pct)*posA.y + pct*posB.y;
    radius = (1-pct)*radiusA + pct*radiusB;
    //radius = 50;
    
}
