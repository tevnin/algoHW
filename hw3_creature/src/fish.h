#ifndef FISH_H
#define FISH_H

#include "ofMain.h"

class fish {

	public:
	
        fish();
	
		void	draw();
		void	xenoToPoint(float catchX, float catchY);
	
		ofPoint		pos;
		ofPoint		prevPos;
        ofPoint     tail;
			
		float		angle;
        float       radius;
        float       radiusA;
        float       radiusB;
	
	
		float		catchUpSpeed;		// take this pct of where I want to be, and 1-catchUpSpeed of my pos
	

	
	
	
};

#endif // FISH_H
