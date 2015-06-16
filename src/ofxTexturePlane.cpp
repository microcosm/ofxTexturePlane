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
    tx1 = tx0 + calculateTextureSizeX();
}

void ofxTexturePlane::setOffsetY(float offsetY) {
    ty0 = offsetY;
    ty1 = ty0 + calculateTextureSizeY();
}

void ofxTexturePlane::incrementOffsetX(float amount) {
    setOffsetX(tx0 + amount);
}

void ofxTexturePlane::incrementOffsetY(float amount) {
    setOffsetY(ty0 + amount);
}

void ofxTexturePlane::setInitialOffset() {
    setOffsetX(-calculateTextureSizeX());
    setOffsetY(-calculateTextureSizeY());
}

float ofxTexturePlane::calculateTextureSizeX() {
    return (imageIsTallerThanWide() ? 1 : calculateImageFraction()) *
           (planeIsTallerThanWide() ? calculatePlaneFraction() : 1);
}

float ofxTexturePlane::calculateTextureSizeY() {
    return (imageIsTallerThanWide() ? calculateImageFraction() : 1) *
           (planeIsTallerThanWide() ? 1 : calculatePlaneFraction());
}

bool ofxTexturePlane::imageIsTallerThanWide() {
    return image.getHeight() > image.getWidth();
}

float ofxTexturePlane::calculateImageFraction() {
    return smallestImageDimension() / largestImageDimension();
}

float ofxTexturePlane::smallestImageDimension() {
    return imageIsTallerThanWide() ? image.getWidth() : image.getHeight();
}

float ofxTexturePlane::largestImageDimension() {
    return imageIsTallerThanWide() ? image.getHeight() : image.getWidth();
}

bool ofxTexturePlane::planeIsTallerThanWide() {
    return plane.getHeight() > plane.getWidth();
}

float ofxTexturePlane::calculatePlaneFraction() {
    return smallestPlaneDimension() / largestPlaneDimension();
}

float ofxTexturePlane::smallestPlaneDimension() {
    return planeIsTallerThanWide() ? plane.getWidth() : plane.getHeight();
}

float ofxTexturePlane::largestPlaneDimension() {
    return planeIsTallerThanWide() ? plane.getHeight() : plane.getWidth();
}