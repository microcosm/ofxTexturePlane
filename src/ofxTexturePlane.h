#pragma once

#include "ofMain.h"

enum ofxTexturePlaneOffset {
    TEXTURE_OFFSET_TOP_LEFT,
    TEXTURE_OFFSET_TOP_CENTER,
    TEXTURE_OFFSET_TOP_CENTER_LEFT_EDGE,
    TEXTURE_OFFSET_TOP_CENTER_RIGHT_EDGE,
    TEXTURE_OFFSET_TOP_RIGHT,
    TEXTURE_OFFSET_MIDDLE_LEFT,
    TEXTURE_OFFSET_MIDDLE_CENTER,
    TEXTURE_OFFSET_MIDDLE_CENTER_LEFT_EDGE,
    TEXTURE_OFFSET_MIDDLE_CENTER_RIGHT_EDGE,
    TEXTURE_OFFSET_MIDDLE_RIGHT,
    TEXTURE_OFFSET_BOTTOM_LEFT,
    TEXTURE_OFFSET_BOTTOM_CENTER,
    TEXTURE_OFFSET_BOTTOM_CENTER_LEFT_EDGE,
    TEXTURE_OFFSET_BOTTOM_CENTER_RIGHT_EDGE,
    TEXTURE_OFFSET_BOTTOM_RIGHT
};

enum ofxTexturePlaneFlip {
    TEXTURE_FLIP_HORIZONTAL,
    TEXTURE_FLIP_VERTICAL,
    TEXTURE_FLIP_BOTH,
    TEXTURE_FLIP_NO_FLIP
};

class ofxTexturePlane : public ofBaseApp{

public:
    void setup(string filename, float textureScale=1, ofxTexturePlaneOffset offset=TEXTURE_OFFSET_TOP_LEFT);
    void setup(string filename, ofVec2f size, float textureScale=1, ofxTexturePlaneOffset offset=TEXTURE_OFFSET_TOP_LEFT);
    void setup(string filename, float width, float height, float textureScale=1, ofxTexturePlaneOffset offset=TEXTURE_OFFSET_TOP_LEFT);
    void draw(int x, int y, ofxTexturePlaneFlip flip=TEXTURE_FLIP_NO_FLIP);
    void draw(ofVec2f position);
    void draw();

    void setPlaneSize(float width, float height);
    void setPlaneWidth(float width);
    void setPlaneHeight(float height);
    void setPlanePosition(int x, int y);
    void setPlanePosition(ofVec2f position);

    void setTextureOffset(ofxTexturePlaneOffset offset);
    void setTextureOffset(int offsetIndex);
    void setTextureOffset(float offsetX, float offsetY);
    void setTextureOffset(ofVec2f offset);
    void setTextureOffsetX(float offsetX);
    void setTextureOffsetY(float offsetY);
    void incrementTextureOffset(float amountX, float amountY);
    void incrementTextureOffset(ofVec2f amount);
    void incrementTextureOffsetX(float amount);
    void incrementTextureOffsetY(float amount);

    void setTexturePosition(float positionX, float positionY);
    void setTexturePosition(ofVec2f position);
    void setTexturePositionX(float positionX);
    void setTexturePositionY(float positionY);
    void setTextureScale(float scale);
    void incrementTextureScale(float amount);

    void flipTexture(ofxTexturePlaneFlip flip);
protected:
    void backup();
    void restore();
    void loadIndexableOffsets();

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

    float getCenteredOffset(float normalizedPosition, float textureSize);
    void swap(float &val1, float &val2);

    ofImage image;
    ofTexture texture;
    ofPlanePrimitive plane;
    float tx0, ty0, tx1, ty1;
    float scale;
    ofVec2f textureSize;

    ofVec3f backup_planePosition;
    float backup_tx0, backup_ty0, backup_tx1, backup_ty1;
    vector<ofxTexturePlaneOffset> offsets;
};