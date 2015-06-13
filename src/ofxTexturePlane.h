#pragma once

#include "ofMain.h"

class ofxTexturePlane  : public ofBaseApp{

public:
    void setup(string filename);
protected:
    ofImage image;
    ofTexture texture;
};