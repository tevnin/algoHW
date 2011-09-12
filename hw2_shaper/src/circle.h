//
//  circle.h
//  hw2_click
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
        void interpolateByPct(float myPct);
        
        ofPoint pos;
        ofPoint posA;
        ofPoint posB;
        float pct;
        
        float radius;
        float radiusA;
        float radiusB;


};



#endif
