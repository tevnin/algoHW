#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
	
		vector < ofPoint > points;
		
	
		float radius;
    
        float r,g,b,r1,g1,b1,r2,g2,b2;
        float backR,backG,backB,backR1,backR2,backG1,backG2,backB1,backB2;
	

};

#endif
