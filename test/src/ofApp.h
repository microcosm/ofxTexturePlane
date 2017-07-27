#pragma once

#include "ofMain.h"
#include "ofxTexturePlane.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxTexturePlane a100x400, a200x400, a400x100, a400x200, a400x400;
    ofxTexturePlane b100x400, b200x400, b400x100, b400x200, b400x400;
    ofxTexturePlane c100x400, c200x400, c400x100, c400x200, c400x400;
    ofxTexturePlane d100x400, d200x400, d400x100, d400x200, d400x400;
    ofxTexturePlane e100x400, e200x400, e400x100, e400x200, e400x400;
};
