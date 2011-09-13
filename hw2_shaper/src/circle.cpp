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
    //ofSetColor(255,0,127);
    ofSetColor(r, g, b);
    //ofSetRectMode( OF_RECTMODE_CENTER );
    for(int i=0; i<10; i++){
        ofRect(pos.x, pos.y*i, width,width);
    }
    
}

//--------------------------------------------------------------
void circle::interpolateByPct(float myPct){
    pct = myPct;
    //pos.x = (1-pct)*posA.x + pct*posB.x;
    //pos.y = (1-pct)*posA.y + pct*posB.y;
    width = (1-pct)*widthA + pct*widthB;
    r = (1-pct)*rA + pct*rB;
    g = (1-pct)*gA + pct*gB;
    b = (1-pct)*bA + pct*bB;
    //width = 50;
    
}
