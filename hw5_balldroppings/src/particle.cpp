#include "particle.h"


//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,0,0);
}

//------------------------------------------------------------
void particle::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}


//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
	vel.set(vx,vy);
}

//------------------------------------------------------------
void particle::update(){	
	vel = vel + frc;
	pos = pos + vel; 
}

//------------------------------------------------------------
void particle::draw(){
    ofCircle(pos.x, pos.y, 3);
}

