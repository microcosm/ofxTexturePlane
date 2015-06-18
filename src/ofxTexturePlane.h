#pragma once

#include "ofMain.h"

enum ofxTexturePlaneOffset {
    TEXTURE_OFFSET_TOP_LEFT,
    TEXTURE_OFFSET_TOP_CENTER,
    TEXTURE_OFFSET_TOP_RIGHT,
    TEXTURE_OFFSET_MIDDLE_LEFT,
    TEXTURE_OFFSET_MIDDLE_CENTER,
    TEXTURE_OFFSET_MIDDLE_RIGHT,
    TEXTURE_OFFSET_BOTTOM_LEFT,
    TEXTURE_OFFSET_BOTTOM_CENTER,
    TEXTURE_OFFSET_BOTTOM_RIGHT
};

class ofxTexturePlane : public ofBaseApp{

public:
    void setup(string filename, int textureScale=1, ofxTexturePlaneOffset offset=TEXTURE_OFFSET_TOP_LEFT);
    void setup(string filename, int width, int height, int textureScale=1, ofxTexturePlaneOffset offset=TEXTURE_OFFSET_TOP_LEFT);
    void draw(int x, int y);
    void draw();

    void setPlaneSize(int width, int height);
    void setPlaneWidth(int width);
    void setPlaneHeight(int height);
    void setPlanePosition(int x, int y);

    void setTextureOffset(ofxTexturePlaneOffset offset);
    void setTextureOffset(float offsetX, float offsetY);
    void setTextureOffsetX(float offsetX);
    void setTextureOffsetY(float offsetY);
    void incrementTextureOffset(float amountX, float amountY);
    void incrementTextureOffsetX(float amount);
    void incrementTextureOffsetY(float amount);
    
    void setTextureScale(float scale);
    void incrementTextureScale(float amount);

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