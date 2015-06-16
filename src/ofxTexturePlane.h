#pragma once

#include "ofMain.h"

class ofxTexturePlane  : public ofBaseApp{

public:
    void setup(string filename);
    void setup(string filename, int width, int height);
    void draw(int x, int y);
    void draw();
    void setOffsetX(float offsetX);
    void setOffsetY(float offsetY);
protected:
    void setInitialOffset();
    bool imageIsTallerThanWide();
    float calculateFraction();
    float smallestDimension();
    float largestDimension();
    ofImage image;
    ofTexture texture;
    ofPlanePrimitive plane;
    float tx0, ty0, tx1, ty1;
};