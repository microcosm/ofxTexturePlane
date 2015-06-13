#pragma once

#include "ofMain.h"

class ofxTexturePlane  : public ofBaseApp{

public:
    void setup(string filename);
    void setOffsetX(float offsetX);
    void setOffsetY(float offsetY);
protected:
    ofImage image;
    ofTexture texture;
    float tx0, ty0, tx1, ty1;
};