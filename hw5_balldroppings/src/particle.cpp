#include "particle.h"


//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,0,0);
}
//------------------------------------------------------------
void particle::setup(){
    loopingSound.loadSound("drawbar_c4_a.aif");
    loopingSound.setVolume(0);
    //loopingSound.setLoop(true);
    //loopingSound.play();
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
    
    if(pos.x <= 0 || pos.x >= ofGetWidth()){
        vel *= -1;
    }
    if(pos.y <= 0 || pos.y >= ofGetHeight()){
        vel *= -1;
    }
}
//------------------------------------------------------------
void particle::bounce(float angle){
    
    vel.x = -vel.x-(cos(angle)+ofDegToRad(90-angle));
    vel.y = -vel.y-(sin(angle)+ofDegToRad(90-angle));
    loopingSound.play();
    
//    vel.x = -vel.x*cos(angle);
//    vel.y = -vel.y*sin(angle);
    
    sound();

}

//------------------------------------------------------------
void particle::draw(){
    ofCircle(pos.x, pos.y, 3);
}

void particle::sound(){
    //musica
    loopingSound.setVolume(30);
    
    
    float pitch = ofMap(pos.y, 0, (float)ofGetHeight(), 2.5, 0.1);
    loopingSound.setSpeed(pitch);
    
    float pan = ofMap(pos.x, 0, (float)ofGetWidth(), -1, 1);
    loopingSound.setPan(pan);

    loopingSound.play();
}

