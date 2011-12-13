
#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"

/* ****************************************
 
this example is still rough working out
lots of bugs but have fun!

****************************************** */
#define N_SOUNDS 5

class SoundData {
public:
	int	 soundID;
	bool bHit;
};


// ------------------------------------------------- App
class testApp : public ofBaseApp {
	
public:
	
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
    
    // this is the function for contacts
	void contactStart(ofxBox2dContactArgs &e);
	void contactEnd(ofxBox2dContactArgs &e);
    
    // when the ball hits we play this sound
	ofSoundPlayer  sound[N_SOUNDS];
	
	vector <ofPolyline>			lines;
    vector <ofPoint>            points;
	ofxBox2d					box2d;
	vector <ofxBox2dCircle>		circles;
	vector <ofxBox2dPolygon>	polyLines;
    

};
