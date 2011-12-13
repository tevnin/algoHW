#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	
	ofBackgroundHex(0x000000);
	ofSetLogLevel(OF_LOG_NOTICE);
	ofSetVerticalSync(true);
	
	// Box2d
	box2d.init();
	box2d.setGravity(0, 20);
	box2d.createGround();
	box2d.setFPS(30.0);
    
    // register the listener so that we get the events
	ofAddListener(box2d.contactStartEvents, this, &testApp::contactStart);
	ofAddListener(box2d.contactEndEvents, this, &testApp::contactEnd);
    

    // load the soundfile
	for (int i=0; i<N_SOUNDS; i++) {
		sound[i].loadSound("Electronic_Chime-KevanGC-495939803.mp3");
        sound[i].setVolume(1);
		sound[i].setMultiPlay(true);
		sound[i].setLoop(false);
	}

	
	// load the lines we saved...
	ifstream f;
	f.open(ofToDataPath("lines.txt").c_str());
	vector <string> strLines;
	while (!f.eof()) {
		string ptStr;
		getline(f, ptStr);
		strLines.push_back(ptStr);
	}
	f.close();
	
	for (int i=0; i<strLines.size(); i++) {
		vector <string> pts = ofSplitString(strLines[i], ",");
		if(pts.size() > 0) {
			ofxBox2dPolygon poly;
			for (int j=0; j<pts.size(); j+=2) {
				if(pts[j].size() > 0) {
					float x = ofToFloat(pts[j]);
					float y = ofToFloat(pts[j+1]);
					poly.addVertex(x, y);
				}				
			}
			poly.create(box2d.getWorld());
			polyLines.push_back(poly);
		}
	}
	
}
//--------------------------------------------------------------
void testApp::contactStart(ofxBox2dContactArgs &e) {
	if(e.a != NULL && e.b != NULL) { 
		
		// if we collide with the ground we do not
		// want to play a sound. this is how you do that
		if(e.a->GetType() == b2Shape::e_polygon && e.b->GetType() == b2Shape::e_circle) {
			
			SoundData * aData = (SoundData*)e.a->GetBody()->GetUserData();
			SoundData * bData = (SoundData*)e.b->GetBody()->GetUserData();
			
//			if(aData) {
//				aData->bHit = true;
//				sound[aData->soundID].play();
//			}
			
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
void testApp::update() {
	
	// add some circles every so often
	if(ofGetFrameNum()%1000 == 0) {
		ofxBox2dCircle c;
		c.setPhysics(1, 0.5, 0.1);
		c.setup(box2d.getWorld(), ofRandom(50, 50), -20, ofRandom(3, 10));
       
        c.setData(new SoundData());
		SoundData * sd = (SoundData*)c.getData();
//		sd->soundID = ofRandom(0, N_SOUNDS);
		sd->bHit	= false;

		circles.push_back(c);		
	}
	
	box2d.update();	
}

//--------------------------------------------------------------
void testApp::draw() {
	
	
	// some circles :)
	for (int i=0; i<circles.size(); i++) {
		ofFill();
        
        SoundData * data = (SoundData*)circles[i].getData();
        
		ofSetHexColor(0xffffff);
		circles[i].draw();
	}
	
	ofSetHexColor(0xffffff);
	ofNoFill();
	for (int i=0; i<lines.size(); i++) {
		lines[i].draw();
	}	
	for (int i=0; i<polyLines.size(); i++) {
		polyLines[i].draw();
	}	
	
	string info = "Draw a shape with the mouse\n";
	info += "Press 1 to add some circles\n";
	info += "Press c to clear everything\n";
	
	ofSetHexColor(0x444342);
	ofDrawBitmapString(info, 10, 15);
        
}


//--------------------------------------------------------------
void testApp::keyPressed(int key) {
	
	if(key == '1') {
		ofxBox2dCircle c;
		c.setPhysics(1, 0.5, 0.5);
		c.setup(box2d.getWorld(), mouseX, mouseY, 10);
        c.setData(new SoundData());
		SoundData * sd = (SoundData*)c.getData();
        //		sd->soundID = ofRandom(0, N_SOUNDS);
		sd->bHit	= false;

		circles.push_back(c);
	}
	
	if(key == 'c') {
		lines.clear();
		for (int i=0; i<polyLines.size(); i++) {
			polyLines[i].destroy();
		}
	}
	
	/*
	// want to save out some line...
	if(key == ' ') {
		ofstream f;
		f.clear();
		f.open(ofToDataPath("lines.txt").c_str());
		for (int i=0; i<lines.size(); i++) {
			for (int j=0; j<lines[i].size(); j++) {
				float x = lines[i][j].x;
				float y = lines[i][j].y;
				f << x << "," << y << ",";
			}
			f << "\n";
		}
		f.close();lines.clear();
	}*/
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ) {
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
	lines.back().addVertex(x, y);

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
	lines.push_back(ofPolyline());
	lines.back().addVertex(x, y);
    

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {
	
	ofxBox2dPolygon poly;
	lines.back().simplify();
	
	for (int i=0; i<lines.back().size(); i++) {
		poly.addVertex(lines.back()[i]);
	}
	
	//poly.setPhysics(1, .2, 1);  // uncomment this to see it fall!
	poly.create(box2d.getWorld());
	polyLines.push_back(poly);
	
	//lines.clear();
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h) {
}

