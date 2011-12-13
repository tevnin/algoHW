#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //ofBackground(0, 0, 0);

	#ifdef _USE_LIVE_VIDEO
        vidGrabber.setVerbose(true);
        vidGrabber.initGrabber(320,240);
	#else
        vidPlayer.loadMovie("fingers.mov");
        vidPlayer.play();
	#endif

    colorImg.allocate(320,240);
	grayImage.allocate(320,240);
	grayBg.allocate(320,240);
	grayDiff.allocate(320,240);

	// Box2d
	physics.init();
	physics.createBounds();
	physics.setGravity(0, 10);
	physics.checkBounds(true);
	physics.setFPS(30);
    
    // register the listener so that we get the events
	ofAddListener(physics.contactStartEvents, this, &testApp::contactStart);
	ofAddListener(physics.contactEndEvents, this, &testApp::contactEnd);
    
    // load the soundfile
	for (int i=0; i<N_SOUNDS; i++) {
		sound[i].loadSound("Electronic_Chime-KevanGC-495939803.mp3");
        sound[i].setVolume(1);
		sound[i].setMultiPlay(true);
		sound[i].setLoop(false);
	}
	
	
	
	bLearnBakground = true;
	threshold = 80;
	
	ofSetFrameRate(60);
	
	bDrawDebug = true;
}
//--------------------------------------------------------------
void testApp::contactStart(ofxBox2dContactArgs &e) {
	if(e.a != NULL && e.b != NULL) { 
		
		// if we collide with the ground we do not
		// want to play a sound. this is how you do that
		if(e.a->GetType() == b2Shape::e_polygon && e.b->GetType() == b2Shape::e_circle) {
			
			SoundData * aData = (SoundData*)e.a->GetBody()->GetUserData();
			SoundData * bData = (SoundData*)e.b->GetBody()->GetUserData();
			
			if(aData) {
				aData->bHit = true;
				sound[aData->soundID].play();
			}
			
			if(bData) {
				bData->bHit = true;
				sound[bData->soundID].play();
			}
		}
	}
}

//--------------------------------------------------------------
void testApp::contactEnd(ofxBox2dContactArgs &e) {
	if(e.a != NULL && e.b != NULL) { 
		
		SoundData * aData = (SoundData*)e.a->GetBody()->GetUserData();
		SoundData * bData = (SoundData*)e.b->GetBody()->GetUserData();
		
		if(aData) {
			aData->bHit = false;
            sound[aData->soundID].stop();
		}
		
		if(bData) {
			bData->bHit = false;
            sound[bData->soundID].stop();
		}
	}
}

//--------------------------------------------------------------
void testApp::update(){
	//ofBackground(0,0,0);
    
    // add some circles every so often
    if(ofGetFrameNum()%120 == 0) {
        ofxBox2dCircle circle;
        circle.setPhysics(3.0, 0.53, 0.1);
        circle.setup(physics.getWorld(), ofGetWidth()/2, 50, ofRandom(4,20));
        circle.setData(new SoundData());
        SoundData * sd = (SoundData*)circle.getData();
        sd->bHit	= false;
        balls.push_back(circle);	
    }

    bool bNewFrame = false;

	#ifdef _USE_LIVE_VIDEO
       vidGrabber.grabFrame();
	   bNewFrame = vidGrabber.isFrameNew();
    #else
        vidPlayer.idleMovie();
        bNewFrame = vidPlayer.isFrameNew();
	#endif

	if (bNewFrame){

		#ifdef _USE_LIVE_VIDEO
            colorImg.setFromPixels(vidGrabber.getPixels(), 320,240);
	    #else
            colorImg.setFromPixels(vidPlayer.getPixels(), 320,240);
        #endif

        grayImage = colorImg;
		if (bLearnBakground == true){
			grayBg = grayImage;		// the = sign copys the pixels from grayImage into grayBg (operator overloading)
			bLearnBakground = false;
		}

		// take the abs value of the difference between background and incoming and then threshold:
		grayDiff.absDiff(grayBg, grayImage);
		grayDiff.threshold(threshold);

		// find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
		// also, find holes is set to true so we will get interior contours as well....
		contourFinder.findContours(grayDiff, 20, (340*240)/3, 10, true);	// find holes
		
		
		
		if (contourFinder.nBlobs >= 1){
			
			//physics.world->DestroyBody(poly.body);
			poly.destroy();
			
			for (int i=0; i < contourFinder.blobs[0].pts.size(); i++) {  
				
				float scaleX = (float)ofGetWidth() / (float)320;
				float scaleY = (float)ofGetHeight() / (float)240;
				ofPoint blobPt = contourFinder.blobs[0].pts[i];
				blobPt.x *= scaleX;
				blobPt.y *= scaleY;
				
				
				poly.addVertex( blobPt); 
			}  
			//poly.triangulate(20, 100);
			poly.create(physics.getWorld());  
		}
		
		
	}

	
	physics.update();
	
}

//--------------------------------------------------------------
void testApp::draw(){
    
	
	if (bDrawDebug){
	
        // draw the incoming, the grayscale, the bg and the thresholded difference
        ofSetHexColor(0xffffff);
        colorImg.draw(20,20);
        grayImage.draw(360,20);
        grayBg.draw(20,280);
        grayDiff.draw(360,280);
        
        
        

        // then draw the contours:

        ofFill();
        ofSetHexColor(0x333333);
        ofRect(360,540,320,240);
        ofSetHexColor(0xffffff);

        // we could draw the whole contour finder
        //contourFinder.draw(360,540);

        // or, instead we can draw each blob individually,
        // this is how to get access to them:
        for (int i = 0; i < contourFinder.nBlobs; i++){
            contourFinder.blobs[i].draw(360,540);
        }

        // finally, a report:

        ofSetHexColor(0xffffff);
        char reportStr[1024];
        sprintf(reportStr, "bg subtraction and blob detection\npress ' ' to capture bg\nthreshold %i (press: +/-)\nnum blobs found %i, fps: %f", threshold, contourFinder.nBlobs, ofGetFrameRate());
        ofDrawBitmapString(reportStr, 20, 600);

	}else{
        ofSetHexColor(0xffffff);
        colorImg.draw(0,0,ofGetWidth(),ofGetHeight());
    }
	
	
	// Physics

	int nbBalls = balls.size();
	for(int i=0; i<nbBalls; i++){
        SoundData * data = (SoundData*)balls[i].getData();
        ofSetColor(255, 255, 255);
        ofFill();	
        balls[i].draw();
    }
    
    
//	
//	ofFill();
//	ofSetColor(255,0,255);
//	poly.draw();
//	ofNoFill();
//	ofSetColor(255,255,255);
//	poly.draw();
	

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	switch (key){
		case ' ':
			bLearnBakground = true;
			break;
		case '+':
			threshold ++;
			if (threshold > 255) threshold = 255;
			break;
		case '-':
			threshold --;
			if (threshold < 0) threshold = 0;
			break;
		case 'd':
			bDrawDebug = !bDrawDebug;
			break;			
		case 'c':
//			ofxBox2dCircle circle;
//			circle.setPhysics(3.0, 0.53, 0.1);
//			circle.setup(physics.getWorld(), ofGetWidth()/2, 50, ofRandom(4,20));
//            circle.setData(new SoundData());
//            SoundData * sd = (SoundData*)circle.getData();
//            sd->bHit	= false;
//			balls.push_back(circle);
			break;
		}
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
