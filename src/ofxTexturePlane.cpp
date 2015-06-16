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
    setInitialOffset();
}

void ofxTexturePlane::draw(int x, int y) {
    plane.setPosition(x + plane.getWidth() * 0.5, y + plane.getHeight() * 0.5, 0);
    draw();
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
    tx1 = tx0 + (imageIsTallerThanWide() ? 1 : calculateFraction());
}

void ofxTexturePlane::setOffsetY(float offsetY) {
    ty0 = offsetY;
    ty1 = ty0 + (imageIsTallerThanWide() ? calculateFraction() : 1);
}

void ofxTexturePlane::setInitialOffset() {
    if(imageIsTallerThanWide()) {
        setOffsetX(1);
        setOffsetY(-calculateFraction());
    } else {
        setOffsetX(-calculateFraction());
        setOffsetY(1);
    }
}

bool ofxTexturePlane::imageIsTallerThanWide() {
    return image.getHeight() > image.getWidth();
}

float ofxTexturePlane::calculateFraction() {
    return smallestDimension() / largestDimension();
}

float ofxTexturePlane::smallestDimension() {
    return imageIsTallerThanWide() ? image.getWidth() : image.getHeight();
}

float ofxTexturePlane::largestDimension() {
    return imageIsTallerThanWide() ? image.getHeight() : image.getWidth();
}