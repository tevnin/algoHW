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
    
    bar();
    void update();
    void draw(int _x1, int _y1, int _x2, int _y2);
    

};


#endif
