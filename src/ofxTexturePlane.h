#pragma once

#include "ofMain.h"

enum ofxTexturePlaneOffset {
    TEXTURE_OFFSET_TOP_LEFT,
    TEXTURE_OFFSET_TOP_CENTER,
    TEXTURE_OFFSET_TOP_RIGHT,
    TEXTURE_OFFSET__TOP__LEFT_TO_CENTER,
    TEXTURE_OFFSET__TOP__RIGHT_TO_CENTER,

    TEXTURE_OFFSET_MIDDLE_LEFT,
    TEXTURE_OFFSET_MIDDLE_CENTER,
    TEXTURE_OFFSET_MIDDLE_RIGHT,
    TEXTURE_OFFSET__MIDDLE__LEFT_TO_CENTER,
    TEXTURE_OFFSET__MIDDLE__RIGHT_TO_CENTER,

    TEXTURE_OFFSET_BOTTOM_LEFT,
    TEXTURE_OFFSET_BOTTOM_CENTER,
    TEXTURE_OFFSET_BOTTOM_RIGHT,
    TEXTURE_OFFSET__BOTTOM__LEFT_TO_CENTER,
    TEXTURE_OFFSET__BOTTOM__RIGHT_TO_CENTER,

    TEXTURE_OFFSET__TOP_TO_MIDDLE__LEFT,
    TEXTURE_OFFSET__TOP_TO_MIDDLE__CENTER,
    TEXTURE_OFFSET__TOP_TO_MIDDLE__RIGHT,
    TEXTURE_OFFSET__TOP_TO_MIDDLE__LEFT_TO_CENTER,
    TEXTURE_OFFSET__TOP_TO_MIDDLE__RIGHT_TO_CENTER,

    TEXTURE_OFFSET__BOTTOM_TO_MIDDLE__LEFT,
    TEXTURE_OFFSET__BOTTOM_TO_MIDDLE__CENTER,
    TEXTURE_OFFSET__BOTTOM_TO_MIDDLE__RIGHT,
    TEXTURE_OFFSET__BOTTOM_TO_MIDDLE__LEFT_TO_CENTER,
    TEXTURE_OFFSET__BOTTOM_TO_MIDDLE__RIGHT_TO_CENTER
};

enum ofxTexturePlaneFlip {
    TEXTURE_FLIP_HORIZONTAL,
    TEXTURE_FLIP_VERTICAL,
    TEXTURE_FLIP_BOTH,
    TEXTURE_FLIP_NO_FLIP
};

enum ofxTexturePlaneMode {
    TEXTURE_MODE_COVER,
    TEXTURE_MODE_FIT
};

enum ofxTexturePlaneWrap {
    TEXTURE_WRAP_REPEAT,
    TEXTURE_WRAP_MIRRORED_REPEAT,
    TEXTURE_WRAP_CLAMP_TO_EDGE,
    TEXTURE_WRAP_CLAMP_TO_BORDER
};

class ofxTexturePlane : public ofBaseApp{

public:
    void setup(string filename, float textureScale=1, ofxTexturePlaneOffset offset=TEXTURE_OFFSET_TOP_LEFT, ofxTexturePlaneMode mode=TEXTURE_MODE_COVER, ofxTexturePlaneWrap wrap=TEXTURE_WRAP_MIRRORED_REPEAT);
    void setup(ofImage& image, float textureScale=1, ofxTexturePlaneOffset offset=TEXTURE_OFFSET_TOP_LEFT, ofxTexturePlaneMode mode=TEXTURE_MODE_COVER, ofxTexturePlaneWrap wrap=TEXTURE_WRAP_MIRRORED_REPEAT);
    void setup(string filename, ofVec2f size, float textureScale=1, ofxTexturePlaneOffset offset=TEXTURE_OFFSET_TOP_LEFT, ofxTexturePlaneMode mode=TEXTURE_MODE_COVER, ofxTexturePlaneWrap wrap=TEXTURE_WRAP_MIRRORED_REPEAT);
    void setup(ofImage& image, ofVec2f size, float textureScale=1, ofxTexturePlaneOffset offset=TEXTURE_OFFSET_TOP_LEFT, ofxTexturePlaneMode mode=TEXTURE_MODE_COVER, ofxTexturePlaneWrap wrap=TEXTURE_WRAP_MIRRORED_REPEAT);
    void setup(string filename, float width, float height, float textureScale=1, ofxTexturePlaneOffset offset=TEXTURE_OFFSET_TOP_LEFT, ofxTexturePlaneMode mode=TEXTURE_MODE_COVER, ofxTexturePlaneWrap wrap=TEXTURE_WRAP_MIRRORED_REPEAT);
    void setup(ofImage& image, float width, float height, float textureScale=1, ofxTexturePlaneOffset offset=TEXTURE_OFFSET_TOP_LEFT, ofxTexturePlaneMode mode=TEXTURE_MODE_COVER, ofxTexturePlaneWrap wrap=TEXTURE_WRAP_MIRRORED_REPEAT);

    void draw(int x, int y, ofxTexturePlaneFlip flip=TEXTURE_FLIP_NO_FLIP);
    void draw(ofVec2f position);
    void draw();

    void setPlaneSize(float width, float height);
    void setPlaneWidth(float width);
    void setPlaneHeight(float height);
    void setPlanePosition(int x, int y);
    void setPlanePosition(ofVec2f position);

    void setTextureMode(ofxTexturePlaneMode mode);

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
    void calculateTextureSizes();

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
    ofxTexturePlaneMode textureMode;
};
