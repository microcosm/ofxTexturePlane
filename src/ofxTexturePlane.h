#pragma once

#include "ofMain.h"

class ofxTexturePlane  : public ofBaseApp{

public:
    void setup(string filename, int textureScale=1);
    void setup(string filename, int width, int height, int textureScale=1);
    void draw(int x, int y);
    void draw();

    void setPlaneSize(int width, int height);
    void setPlaneWidth(int width);
    void setPlaneHeight(int height);
    void setPlanePosition(int x, int y);

    void setTextureScale(float scale, bool calculateTextureSizes=true);
    void setTextureOffsetX(float offsetX);
    void setTextureOffsetY(float offsetY);
    void incrementTextureOffsetX(float amount);
    void incrementTextureOffsetY(float amount);
    void setTextureOffsetTopLeft();

protected:
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