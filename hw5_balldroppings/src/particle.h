#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class particle{
	
    public:
	
		
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
        ofSoundPlayer loopingSound;
			
        particle();
		virtual ~particle(){};
    
        void setup();
        void resetForce();
        void setInitialCondition(float px, float py, float vx, float vy);
        void update();
        void bounce(float angle);
        void draw();
        void sound();

    protected:
    private:
};

#endif // PARTICLE_H
