#include "ofApp.h"

void ofApp::setup(){
    seamlessPlane.setup("seamless.jpg", 200, 200);
    buildingPlane.setup("building.png", 200, 200);
    landscapePlane.setup("landscape.png", 200, 200);
}

void ofApp::update(){

}

void ofApp::draw(){
    seamlessPlane.draw(20, 20);
    buildingPlane.draw(240, 20);
    landscapePlane.draw(460, 20);
}

void ofApp::keyPressed(int key){

}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y ){

}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){

}

void ofApp::mouseReleased(int x, int y, int button){

}

void ofApp::windowResized(int w, int h){

}

void ofApp::gotMessage(ofMessage msg){

}

void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
