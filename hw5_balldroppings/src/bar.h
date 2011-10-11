//
//  bar.h
//  algo_wk5
//
//  Created by Tami Evnin on 10/4/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef algo_wk5_bar_h
#define algo_wk5_bar_h

#include "ofMain.h"

class bar{
	
    public:
    
    ofVec2f pos1;
    ofVec2f pos2;
    float barAngle;
    float barDist;
//    ofSoundPlayer loopingSound;
    
    bar();
    void setup();
    void update();
    void drawPos1(int x1, int y1);
    void drawPos2(int x2, int y2);
    void barInfo();
    void draw();
    void sound();
    
    

};


#endif
