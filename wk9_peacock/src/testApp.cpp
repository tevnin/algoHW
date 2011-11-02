#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofBackground(0,0,0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	
    center.setInitialCondition(ofGetWidth()/2, ofGetHeight()/2, 0, 0);
	for(int i=0;i<5; i++){
        particle myParticle;
        //parameters = setInitialCondition(pos.x, pos.y, vel.x, vel.y)
        myParticle.setInitialCondition( ofGetWidth()/2 + 200*cos(i*-PI/5-PI/10), ofGetHeight()/2 + 200* sin(i*-PI/5-PI/10),0,0 );
        particlesOutside.push_back(myParticle);        
    
    }
    
    for(int i=0;i<10; i++){
        particle myParticle;
        myParticle.setInitialCondition( ofGetWidth()/2 + 150*cos(i*-PI/10-PI/20), ofGetHeight()/2 + 150* sin(i*-PI/10-PI/20),0,0 );
        particlesInside.push_back(myParticle);
    }

	
	spring mySpring;

    
    for (int j = 0; j < particlesInside.size(); j++){
        
        mySpring.distance		=  ofDist(particlesInside[0].pos.x, particlesOutside[0].pos.x,particlesInside[0].pos.y, particlesOutside[0].pos.y);
        mySpring.springiness	= 0.2f;
                
        if(j%2 == 1){
            mySpring.particleA = & (particlesInside[(j)]);
            mySpring.particleB = & (particlesOutside[((j+1)/2-1)]);
        }
        if(j%2 == 0){
            mySpring.particleA = & (particlesInside[(j)]);
            mySpring.particleB = & (particlesOutside[j/2]);
        }

        springs.push_back(mySpring);

    }
    
    for (int j = 0; j < particlesInside.size(); j++){
        
        mySpring.distance		=  ofDist(particlesInside[0].pos.x, particlesOutside[0].pos.x,particlesInside[0].pos.y, particlesOutside[0].pos.y);
        mySpring.springiness	= 0.2f;
        mySpring.particleA = & (particlesInside[(j)]);
        mySpring.particleB = & (center);

        springs.push_back(mySpring);
        
    }
    
    for (int j = 0; j < particlesInside.size(); j+=2){
        
        mySpring.distance		=  ofDist(particlesInside[0].pos.x, particlesInside[1].pos.x,particlesInside[0].pos.y, particlesInside[1].pos.y);
        mySpring.springiness	= 0.2f;
        mySpring.particleA = & (particlesInside[(j)]);
        mySpring.particleB = & (particlesInside[j+1]);
        
        springs.push_back(mySpring);
        
    }
    
    for (int j = 0; j < particlesOutside.size(); j++){
        
        mySpring.distance		=  ofDist(particlesOutside[0].pos.x, center.pos.x,particlesOutside[0].pos.y, center.pos.y);
        mySpring.springiness	= 0.2f;
        mySpring.particleA = & (particlesOutside[(j)]);
        mySpring.particleB = & (center);
        
        springs.push_back(mySpring);
        
    }

	
	
		
	
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	/*springs[0].distance = 100 + 50 * sin(ofGetElapsedTimef()*8);
	springs[2].distance = 100 + 50 * sin(ofGetElapsedTimef()*8 + PI);
	
	
	for (int i = 0; i < particlesInside.size(); i++){
		particlesInside[i].resetForce();
	}
    for (int i = 0; i < particlesOutside.size(); i++){
		particlesOutside[i].resetForce();
	}
	
	for (int i = 0; i < particlesInside.size(); i++){
		particlesInside[i].addForce(0,0.1f);
		particlesInside[i].addRepulsionForce(mouseX, mouseY, 300, 0.7f);
	}
    for (int i = 0; i < particlesOutside.size(); i++){
		particlesOutside[i].addForce(0,0.1f);
		particlesOutside[i].addRepulsionForce(mouseX, mouseY, 300, 0.7f);
	}
	
	for (int i = 0; i < springs.size(); i++){
		springs[i].update();
	}
	
	
	for (int i = 0; i < particlesInside.size(); i++){
		particlesInside[i].bounceOffWalls();
		particlesInside[i].addDampingForce();
		particlesInside[i].update();
	}
    for (int i = 0; i < particlesOutside.size(); i++){
		particlesOutside[i].bounceOffWalls();
		particlesOutside[i].addDampingForce();
		particlesOutside[i].update();
	}*/
}

//--------------------------------------------------------------
void testApp::draw(){
	

	ofSetColor(0xffffff);
	
    center.draw();
    
	for (int i = 0; i < particlesOutside.size(); i++){
		particlesOutside[i].draw();
	}
    
    for (int i = 0; i < particlesInside.size(); i++){
        particlesInside[i].draw();
	}
	
	for (int i = 0; i < springs.size(); i++){
		springs[i].draw();
	}

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
//	switch (key){
//			
//		case ' ':
//			// reposition everything: 
//			for (int i = 0; i < particles.size(); i++){
//				particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
//			}
//			break;
//	}
	
	
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
//	particles[0].pos.set(mouseX, mouseY);
	/*particles.erase(particles.begin());
	particle myParticle;
	myParticle.setInitialCondition(x,y,0,0);
	particles.push_back(myParticle);*/
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
//	particles[0].bFixed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	
//	particles[0].bFixed = false;
}

