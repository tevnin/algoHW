//
//  circle.h
//  hw2_xeno
//
//  Created by Tami Evnin on 9/8/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//


#ifndef CIRCLE_h
#define CIRCLE_h

#include "ofMain.h"

class circle {
    
public:
    
    circle();
    
    void draw();
    void xenoToPoint(float catchX, float catchY);
    void interpolateByPct(float myPct);
    
    ofPoint		pos;
    float		catchUpSpeed;		// take this pct of where I want to be, and 1-catchUpSpeed of my pos
    
    float radius;
    float radiusA;
    float radiusB;
    float pct;
    
    
};



#endif
