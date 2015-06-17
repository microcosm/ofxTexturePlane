#pragma once

#include "ofMain.h"

class ofxTexturePlane  : public ofBaseApp{

public:
    void setup(string filename);
    void setup(string filename, int width, int height);
    void draw(int x, int y);
    void draw();

    void setPlaneSize(int width, int height, bool calculateTextureSizes=true);
    void setPlaneWidth(int width);
    void setPlaneHeight(int height);

    void setTextureScale(float scale);
    void setTextureOffsetX(float offsetX);
    void setTextureOffsetY(float offsetY);
    void incrementTextureOffsetX(float amount);
    void incrementTextureOffsetY(float amount);

protected:
    void setInitialTextureOffset();
    void setOffsetTextureSizeX();
    void setOffsetTextureSizeY();
    float calculateTextureSizeX();
    float calculateTextureSizeY();

    bool imageIsTallerThanWide();
    float calculateImageFraction();
    float smallestImageDimension();
    float largestImageDimension();

    bool planeIsTallerThanWide();
    float calculatePlaneFraction();
    float smallestPlaneDimension();
    float largestPlaneDimension();

    ofImage image;
    ofTexture texture;
    ofPlanePrimitive plane;
    float tx0, ty0, tx1, ty1;
    float scale;
};