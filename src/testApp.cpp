#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
    ofBackground(0,0,0);

    videoPlayer.loadMovie("smalll.mov");
    videoPlayer.setLoopState(OF_LOOP_NORMAL);
    videoPlayer.play();
    videoPlayer.setPaused(true);
    videoPlayer.setFrame(targetFrame = 0);
    
    
    
    int winW, winH;

    winW = 600;
    winH = 400;
    
    ofSetWindowShape(winW, winH);

 
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
    videoPlayer.setFrame(targetFrame);
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

        ofSetColor(pixels[pindex],
                   pixels[pindex+1],
                   pixels[pindex+2]);    // red, 50% transparent

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
    }

    if (key == OF_KEY_RIGHT){
        targetFrame = targetFrame+1;
        
        if(targetFrame >= videoPlayer.getTotalNumFrames()){
            targetFrame = 0;
        }
    }

    if (key == OF_KEY_LEFT && targetFrame > 0){
        targetFrame = targetFrame-1;
    }

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


