//
//  flower.cpp
//  hw2_click
//
//  Created by Tami Evnin on 9/12/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "flower.h"

//--------------------------------------------------------------
flower::flower(){
    
}

//--------------------------------------------------------------
void flower::draw(){
    
    ofFill();
    
    ofSetColor(255, 0, 127);
    ofCircle(pos.x, pos.y, 60);
    ofSetColor(255,255,255);
    ofCircle(pos.x, pos.y, 30);
    
}

