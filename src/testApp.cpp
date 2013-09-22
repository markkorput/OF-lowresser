#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
    ofBackground(0,0,0);

    videoPlayer.loadMovie("smalll.mov");
    videoPlayer.setLoopState(OF_LOOP_NORMAL);
    videoPlayer.play();
//    videoPlayer.setPaused(true);
    videoPlayer.setFrame(targetFrame = 0);
    
    
    
    int winW, winH;

    winW = 600;
    winH = 400;
    
    ofSetWindowShape(winW, winH);

    // a pixel must be brighter than this to turn into the secondary color (monchormatic display)
    treshold = 450;
    
    ofSetLogLevel(OF_LOG_VERBOSE);
    
	//need this for alpha to come through
//	ofEnableAlphaBlending();

    // allocate our image buffers
//    rgb.allocate(videoPlayer.getWidth(), videoPlayer.getHeight());
//    rgb2.allocate(videoPlayer.getWidth(),videoPlayer.getHeight());
//    maskImg.allocate(videoPlayer.getWidth(),videoPlayer.getHeight());
//    fbo.allocate(rgb2.getWidth()+10, rgb2.getHeight()+10);
}

//--------------------------------------------------------------


void testApp::update(){
    if(videoPlayer.isPaused()) videoPlayer.setFrame(targetFrame);
    videoPlayer.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0,0,0);
    drawGrid();
    videoPlayer.draw(0,0);
}

void testApp::drawGrid(){
    ofPushStyle();
    
    int gridX = 0;
    int gridY = 50;
    gridCellSize = 5;
    gridSpacing = 5;
    

    unsigned char * pixels = videoPlayer.getPixels();
    
    for(int py=0; py<videoPlayer.getHeight(); py++){
      for(int px=0; px<videoPlayer.getWidth(); px++){
        int pindex = (py * videoPlayer.getWidth() + px)*3;

          if(pixels[pindex]+pixels[pindex+1]+pixels[pindex+2] > treshold){
              ofSetColor(0, 0, 255);
          } else {
              ofSetColor(255,255,0);
          }
//        ofSetColor(pixels[pindex],
//                   pixels[pindex+1],
//                   pixels[pindex+2]);    // red, 50% transparent

        ofRect(gridX+(gridCellSize+gridSpacing)*px,
               gridY+(gridCellSize+gridSpacing)*py,
               gridCellSize,
               gridCellSize);
      }
    }
    
    ofPopStyle();

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    if (key == ' '){
        videoPlayer.setPaused(!videoPlayer.isPaused());
    }

    if (key == OF_KEY_RIGHT){
        videoPlayer.setPaused(true);
        targetFrame = targetFrame+1;
        
        if(targetFrame >= videoPlayer.getTotalNumFrames()){
            targetFrame = 0;
        }
        
        ofLog(OF_LOG_VERBOSE, "Current frame: " + ofToString(targetFrame));
    }

    if (key == OF_KEY_LEFT && targetFrame > 0){
        videoPlayer.setPaused(true);
        targetFrame = targetFrame-1;
        ofLog(OF_LOG_VERBOSE, "Current frame: " + ofToString(targetFrame));
    }
    
    if(key == OF_KEY_DOWN){ treshold--; ofLog(OF_LOG_VERBOSE, "Treshold: " + ofToString(treshold)); }
    if(key == OF_KEY_UP){ treshold++; ofLog(OF_LOG_VERBOSE, "Treshold: " + ofToString(treshold)); }

    if (key == '['){}
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


//--------------------------------------------------------------
void testApp::exit()
{

}


