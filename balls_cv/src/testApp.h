#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxBox2d.h"


#define _USE_LIVE_VIDEO		// uncomment this to use a live camera
                            // otherwise, we'll use a movie file

#define N_SOUNDS 5

class SoundData {
public:
	int	 soundID;
	bool bHit;
};


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
        //contact (ball to line)
        void contactStart(ofxBox2dContactArgs &e);
        void contactEnd(ofxBox2dContactArgs &e);
    
        //ball hits line sound
        ofSoundPlayer  sound[N_SOUNDS];

        #ifdef _USE_LIVE_VIDEO
		  ofVideoGrabber            vidGrabber;
		#else
		  ofVideoPlayer             vidPlayer;
		#endif

        ofxCvColorImage             colorImg;

        ofxCvGrayscaleImage         grayImage;
		ofxCvGrayscaleImage         grayBg;
		ofxCvGrayscaleImage         grayDiff;

        ofxCvContourFinder          contourFinder;

		int                         threshold;
		bool                        bLearnBakground;
	
		
		ofxBox2d                    physics;
		vector <ofxBox2dCircle>     balls;
		ofxBox2dPolygon             poly;
		int                         nbCircles;
		
		bool                        bDrawDebug;
	


};

