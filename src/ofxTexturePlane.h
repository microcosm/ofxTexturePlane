#pragma once

#include "ofMain.h"

class ofxTexturePlane  : public ofBaseApp{

public:
    void setup(string filename);
    void setup(string filename, int width, int height);
    void draw();
    void setOffsetX(float offsetX);
    void setOffsetY(float offsetY);
protected:
    ofImage image;
    ofTexture texture;
    ofPlanePrimitive plane;
    float tx0, ty0, tx1, ty1;
};