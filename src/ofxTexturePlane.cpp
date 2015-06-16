#include "ofxTexturePlane.h"

void ofxTexturePlane::setup(string filename){
    setup(filename, ofGetWidth(), ofGetHeight());
}

void ofxTexturePlane::setup(string filename, int width, int height){
    ofDisableArbTex();
    image.loadImage(filename);
    texture = image.getTextureReference();
    texture.setTextureWrap(GL_MIRRORED_REPEAT, GL_MIRRORED_REPEAT);
    plane.set(width, height);
    plane.setPosition(width * 0.5, height * 0.5, 0);
    plane.setResolution(2, 2);
    setOffsetX(0);
    setOffsetY(0);
}

void ofxTexturePlane::draw() {
    plane.mapTexCoords(tx0, ty0, tx1, ty1);
    plane.mapTexCoords(tx1, ty1, tx0, ty0);
    texture.bind();
    plane.draw();
    texture.unbind();
}

void ofxTexturePlane::setOffsetX(float offsetX) {
    tx0 = offsetX;
}

void ofxTexturePlane::setOffsetY(float offsetY) {
    ty0 = offsetY;
}