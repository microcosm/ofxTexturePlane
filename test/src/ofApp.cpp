#include "ofApp.h"

void ofApp::setup(){
    ofSetWindowShape(1600, 1000);

    //To test cover flow mode
    /*a100x400.setup("100x400.png", 100, 400);
    a200x400.setup("200x400.png", 200, 400);
    a400x100.setup("400x100.png", 400, 100);
    a400x200.setup("400x200.png", 400, 200);
    a400x400.setup("400x400.png", 400, 400);

    b100x400.setup("200x400.png", 100, 400);
    b200x400.setup("400x100.png", 200, 400);
    b400x100.setup("400x200.png", 400, 100);
    b400x200.setup("400x400.png", 400, 200);
    b400x400.setup("100x400.png", 400, 400);

    c100x400.setup("400x100.png", 100, 400);
    c200x400.setup("400x200.png", 200, 400);
    c400x100.setup("400x400.png", 400, 100);
    c400x200.setup("100x400.png", 400, 200);
    c400x400.setup("200x400.png", 400, 400);

    d100x400.setup("400x200.png", 100, 400);
    d200x400.setup("400x400.png", 200, 400);
    d400x100.setup("100x400.png", 400, 100);
    d400x200.setup("200x400.png", 400, 200);
    d400x400.setup("400x100.png", 400, 400);

    e100x400.setup("400x400.png", 100, 400);
    e200x400.setup("100x400.png", 200, 400);
    e400x100.setup("200x400.png", 400, 100);
    e400x200.setup("400x100.png", 400, 200);
    e400x400.setup("400x200.png", 400, 400);*/

    //To test fit mode
    a100x400.setup("100x400.png", 100, 400, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);
    a200x400.setup("200x400.png", 200, 400, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);
    a400x100.setup("400x100.png", 400, 100, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);
    a400x200.setup("400x200.png", 400, 200, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);
    a400x400.setup("400x400.png", 400, 400, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);

    b100x400.setup("200x400.png", 100, 400, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);
    b200x400.setup("400x100.png", 200, 400, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);
    b400x100.setup("400x200.png", 400, 100, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);
    b400x200.setup("400x400.png", 400, 200, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);
    b400x400.setup("100x400.png", 400, 400, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);

    c100x400.setup("400x100.png", 100, 400, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);
    c200x400.setup("400x200.png", 200, 400, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);
    c400x100.setup("400x400.png", 400, 100, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);
    c400x200.setup("100x400.png", 400, 200, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);
    c400x400.setup("200x400.png", 400, 400, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);

    d100x400.setup("400x200.png", 100, 400, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);
    d200x400.setup("400x400.png", 200, 400, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);
    d400x100.setup("100x400.png", 400, 100, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);
    d400x200.setup("200x400.png", 400, 200, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);
    d400x400.setup("400x100.png", 400, 400, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);

    e100x400.setup("400x400.png", 100, 400, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);
    e200x400.setup("100x400.png", 200, 400, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);
    e400x100.setup("200x400.png", 400, 100, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);
    e400x200.setup("400x100.png", 400, 200, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);
    e400x400.setup("400x200.png", 400, 400, 1, TEXTURE_OFFSET_MIDDLE_CENTER, TEXTURE_MODE_FIT);
}

void ofApp::update(){

}

void ofApp::draw(){
    ofScale(0.33, 0.33);

    a100x400.draw(10, 10);
    a200x400.draw(120, 10);
    a400x100.draw(330, 10);
    a400x200.draw(740, 10);
    a400x400.draw(1150, 10);

    b100x400.draw(10, 510);
    b200x400.draw(120, 510);
    b400x100.draw(330, 510);
    b400x200.draw(740, 510);
    b400x400.draw(1150, 510);

    c100x400.draw(10, 1020);
    c200x400.draw(120, 1020);
    c400x100.draw(330, 1020);
    c400x200.draw(740, 1020);
    c400x400.draw(1150, 1020);

    d100x400.draw(10, 1530);
    d200x400.draw(120, 1530);
    d400x100.draw(330, 1530);
    d400x200.draw(740, 1530);
    d400x400.draw(1150, 1530);

    e100x400.draw(10, 2040);
    e200x400.draw(120, 2040);
    e400x100.draw(330, 2040);
    e400x200.draw(740, 2040);
    e400x400.draw(1150, 2040);
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
