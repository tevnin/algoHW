#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofBackground(200,200,200);
    
    lastMouseX = 100;
    lastMouseY = 100;
    
    for(int i=0; i<100; i++){
        myCircle.push_back( circle () );
        
        myCircle[i].pos.x = i*100;
        myCircle[i].pos.y = 100;
        myCircle[i].widthA = 10;
        myCircle[i].widthB = 100;
        myCircle[i].rA = i*30;
        myCircle[i].rB = 255;
        myCircle[i].gA = i*30;
        myCircle[i].gB = 0;
        myCircle[i].bA = i*30;
        myCircle[i].bB = 127;
        myCircle[i].interpolateByPct(0);
    }
    
    
    
    pct = 0;
    
    mouseCount = false;

}

//--------------------------------------------------------------
void testApp::update(){
    
    for(int i=0; i<myCircle.size(); i++){
        lastMouseX = myCircle[i].widthA;
        lastMouseY = myCircle[i].widthB;
        
        myCircle[i].interpolateByPct(pct);
    }

    
    pct+=0.005f;
    if (pct > 1) {
		pct = 1;							// just between 0 and 1 (0% and 100%)
	}	
    //pct+=(float)abs(myCircle.posA.x - myCircle.posB.x)/100;
    
    

}

//--------------------------------------------------------------
void testApp::draw(){
    
    for(int i=0; i<myCircle.size(); i++){
        myCircle[i].draw();
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){


}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    for(int i=0; i<myCircle.size(); i++){
        
        if(mouseCount){
            myCircle[i].widthA = myCircle[i].width;
            myCircle[i].widthB = 100;            
            myCircle[i].rA = myCircle[i].r;
            myCircle[i].rB = 255;
            myCircle[i].gA = myCircle[i].g;
            myCircle[i].gB = 0;
            myCircle[i].bA = myCircle[i].b;
            myCircle[i].bB = 127;
        }else{
            myCircle[i].widthA = myCircle[i].width;
            myCircle[i].widthB = 10;
            myCircle[i].rA = myCircle[i].r;
            myCircle[i].rB = i*30;
            myCircle[i].gA = myCircle[i].g;
            myCircle[i].gB = i*30;
            myCircle[i].bA = myCircle[i].b;
            myCircle[i].bB = i*30;
            
        }
    }
    
    mouseCount = !mouseCount;
    pct = 0;
    

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}