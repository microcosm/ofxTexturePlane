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
    void incrementOffsetX(float amount);
    void incrementOffsetY(float amount);
protected:
    void setInitialOffset();
    float calculateTextureSizeX();
    float calculateTextureSizeY();

    bool imageIsTallerThanWide();
    float calculateImageFraction();
    float smallestImageDimension();
    float largestImageDimension();

    ofImage image;
    ofTexture texture;
    ofPlanePrimitive plane;
    float tx0, ty0, tx1, ty1;
};