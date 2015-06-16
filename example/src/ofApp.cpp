#include "ofApp.h"

void ofApp::setup(){
    seamlessPlane1.setup("seamless.jpg", 200, 200);
    buildingPlane1.setup("building.png", 200, 200);
    landscapePlane1.setup("landscape.png", 200, 200);

    seamlessPlane2.setup("seamless.jpg", 200, 200);
    buildingPlane2.setup("building.png", 200, 200);
    landscapePlane2.setup("landscape.png", 200, 200);
}

void ofApp::update(){
    seamlessPlane1.incrementOffsetX(0.001);
    buildingPlane1.incrementOffsetY(0.001);
    landscapePlane1.incrementOffsetX(0.001);

    seamlessPlane2.incrementOffsetX(-0.001);
    buildingPlane2.incrementOffsetY(-0.001);
    landscapePlane2.incrementOffsetX(-0.001);
}

void ofApp::draw(){
    seamlessPlane1.draw(20, 20);
    buildingPlane1.draw(240, 20);
    landscapePlane1.draw(460, 20);

    seamlessPlane2.draw(20, 240);
    buildingPlane2.draw(240, 240);
    landscapePlane2.draw(460, 240);
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
