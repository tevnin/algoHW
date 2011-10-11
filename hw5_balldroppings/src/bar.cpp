//
//  bar.cpp
//  algo_wk5
//
//  Created by Tami Evnin on 10/4/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "bar.h"

//------------------------------------------------------------
bar::bar(){
    
}
//------------------------------------------------------------
void bar::setup(){
//    loopingSound.loadSound("drawbar_c4_a.aif");
//	loopingSound.setVolume(0);
//	loopingSound.setLoop(true);
//	loopingSound.play();
    
}

//------------------------------------------------------------
void bar::update(){

}
//------------------------------------------------------------
void bar::drawPos1(int x1, int y1){
	pos1.set(x1,y1);
	barInfo();
}
//------------------------------------------------------------
void bar::drawPos2(int x2, int y2){
	pos2.set(x2,y2);
	barInfo();
}
//------------------------------------------------------------
void bar::barInfo(){
    barAngle = atan2(pos2.y-pos1.y,pos2.x-pos1.x);
    barDist = ofDist(pos1.x, pos1.y, pos2.x, pos2.y);
}
//------------------------------------------------------------
void bar::draw(){
    ofLine(pos1.x,pos1.y,pos2.x,pos2.y);
    
    
//    //musica
//    loopingSound.setVolume(30);
//    
//    
//    float pitch = ofMap(pos1.y, 0, (float)ofGetHeight(), 2.5, 0.1);
//    loopingSound.setSpeed(pitch);
//    
//    float pan = ofMap(pos1.x, 0, (float)ofGetWidth(), -1, 1);
//    loopingSound.setPan(pan);
//    //loopingSound.play();


}

//------------------------------------------------------------
void bar::sound(){
//        loopingSound.play();
}
