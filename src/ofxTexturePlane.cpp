#include "ofxTexturePlane.h"

void ofxTexturePlane::setup(string filename, int textureScale) {
    setup(filename, ofGetWidth(), ofGetHeight(), textureScale);
}

void ofxTexturePlane::setup(string filename, int width, int height, int textureScale) {
    ofDisableArbTex();
    image.loadImage(filename);
    texture = image.getTextureReference();
    texture.setTextureWrap(GL_MIRRORED_REPEAT, GL_MIRRORED_REPEAT);
    plane.setResolution(2, 2);
    plane.set(width, height);
    plane.setPosition(width * 0.5, height * 0.5, 0);
    setTextureScale(textureScale, false);
    setInitialTextureOffset();
}

void ofxTexturePlane::draw(int x, int y) {
    setPlanePosition(x, y);
    draw();
}

void ofxTexturePlane::draw() {
    plane.mapTexCoords(tx0, ty0, tx1, ty1);
    plane.mapTexCoords(tx1, ty1, tx0, ty0);
    texture.bind();
    plane.draw();
    texture.unbind();
}

void ofxTexturePlane::setPlaneSize(int width, int height) {
    plane.set(width, height);
    setPlanePosition(plane.getPosition().x, plane.getPosition().y);
    setOffsetTextureSizeX();
    setOffsetTextureSizeY();
}

void ofxTexturePlane::setPlaneWidth(int width) {
    setPlaneSize(width, plane.getHeight());
}

void ofxTexturePlane::setPlaneHeight(int height) {
    setPlaneSize(plane.getWidth(), height);
}

void ofxTexturePlane::setPlanePosition(int x, int y) {
    plane.setPosition(x + plane.getWidth() * 0.5, y + plane.getHeight() * 0.5, plane.getPosition().z);
}

void ofxTexturePlane::setTextureScale(float _scale, bool calculateTextureSizes) {
    scale = _scale;
    if(calculateTextureSizes) {
        setOffsetTextureSizeX();
        setOffsetTextureSizeY();
    }
}

void ofxTexturePlane::setTextureOffsetX(float offsetX) {
    tx0 = offsetX;
    setOffsetTextureSizeX();
}

void ofxTexturePlane::setTextureOffsetY(float offsetY) {
    ty0 = offsetY;
    setOffsetTextureSizeY();
}

void ofxTexturePlane::incrementTextureOffsetX(float amount) {
    setTextureOffsetX(tx0 + amount);
}

void ofxTexturePlane::incrementTextureOffsetY(float amount) {
    setTextureOffsetY(ty0 + amount);
}

void ofxTexturePlane::setInitialTextureOffset() {
    setTextureOffsetX(-calculateTextureSizeX());
    setTextureOffsetY(-calculateTextureSizeY());
}

void ofxTexturePlane::setOffsetTextureSizeX() {
    tx1 = tx0 + (calculateTextureSizeX() / scale);
}

void ofxTexturePlane::setOffsetTextureSizeY() {
    ty1 = ty0 + (calculateTextureSizeY() / scale);
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