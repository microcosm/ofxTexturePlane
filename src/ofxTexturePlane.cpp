#include "ofxTexturePlane.h"

void ofxTexturePlane::setup(string filename){
    ofDisableArbTex();
    image.loadImage(filename);
    texture = image.getTextureReference();
    texture.setTextureWrap(GL_MIRRORED_REPEAT, GL_MIRRORED_REPEAT);
    setOffsetX(0);
    setOffsetY(0);
}

void ofxTexturePlane::setOffsetX(float offsetX) {
    tx0 = offsetX;
}

void ofxTexturePlane::setOffsetY(float offsetY) {
    ty0 = offsetY;
}