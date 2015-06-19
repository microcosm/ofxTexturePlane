#include "ofxTexturePlane.h"

void ofxTexturePlane::setup(string filename, int textureScale, ofxTexturePlaneOffset offset) {
    setup(filename, ofGetWidth(), ofGetHeight(), textureScale, offset);
}

void ofxTexturePlane::setup(string filename, int width, int height, int textureScale, ofxTexturePlaneOffset offset) {
    ofDisableArbTex();
    image.loadImage(filename);
    texture = image.getTextureReference();
    texture.setTextureWrap(GL_MIRRORED_REPEAT, GL_MIRRORED_REPEAT);
    plane.setResolution(2, 2);
    plane.set(width, height);
    plane.setPosition(width * 0.5, height * 0.5, 0);
    scale = textureScale;
    setTextureOffset(offset);
}

void ofxTexturePlane::draw(int x, int y) {
    setPlanePosition(x, y);
    draw();
}

void ofxTexturePlane::draw() {
    plane.mapTexCoords(tx0, ty0, tx1, ty1);
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

void ofxTexturePlane::setTextureOffset(ofxTexturePlaneOffset offset) {
    switch(offset){
        case TEXTURE_OFFSET_TOP_LEFT:
            setTextureOffsetX(0);
            setTextureOffsetY(0);
            break;
        case TEXTURE_OFFSET_TOP_CENTER:
            setTextureOffsetX(0.5-((calculateTextureSizeX() / scale) * 0.5));
            setTextureOffsetY(0);
            break;
        case TEXTURE_OFFSET_TOP_RIGHT:
            setTextureOffsetX(1-(calculateTextureSizeX() / scale));
            setTextureOffsetY(0);
            break;
        case TEXTURE_OFFSET_MIDDLE_LEFT:
            setTextureOffsetX(0);
            setTextureOffsetY(0.5-((calculateTextureSizeY() / scale) * 0.5));
            break;
        case TEXTURE_OFFSET_MIDDLE_CENTER:
            setTextureOffsetX(0.5-((calculateTextureSizeX() / scale) * 0.5));
            setTextureOffsetY(0.5-((calculateTextureSizeY() / scale) * 0.5));
            break;
        case TEXTURE_OFFSET_MIDDLE_RIGHT:
            setTextureOffsetX(1-(calculateTextureSizeX() / scale));
            setTextureOffsetY(0.5-((calculateTextureSizeY() / scale) * 0.5));
            break;
        case TEXTURE_OFFSET_BOTTOM_LEFT:
            setTextureOffsetX(0);
            setTextureOffsetY(1-(calculateTextureSizeY() / scale));
            break;
        case TEXTURE_OFFSET_BOTTOM_CENTER:
            setTextureOffsetX(0.5-((calculateTextureSizeX() / scale) * 0.5));
            setTextureOffsetY(1-(calculateTextureSizeY() / scale));
            break;
        case TEXTURE_OFFSET_BOTTOM_RIGHT:
            setTextureOffsetX(1-(calculateTextureSizeX() / scale));
            setTextureOffsetY(1-(calculateTextureSizeY() / scale));
            break;
    }
}

void ofxTexturePlane::setTextureOffset(float offsetX, float offsetY) {
    setTextureOffsetX(offsetX);
    setTextureOffsetY(offsetY);
}

void ofxTexturePlane::setTextureOffsetX(float offsetX) {
    tx0 = offsetX;
    setOffsetTextureSizeX();
}

void ofxTexturePlane::setTextureOffsetY(float offsetY) {
    ty0 = offsetY;
    setOffsetTextureSizeY();
}

void ofxTexturePlane::incrementTextureOffset(float amountX, float amountY) {
    incrementTextureOffsetX(amountX);
    incrementTextureOffsetY(amountY);
}

void ofxTexturePlane::incrementTextureOffsetX(float amount) {
    setTextureOffsetX(tx0 + amount);
}

void ofxTexturePlane::incrementTextureOffsetY(float amount) {
    setTextureOffsetY(ty0 + amount);
}

void ofxTexturePlane::setTextureScale(float _scale) {
    float difference = scale - _scale;
    float diffMapped = ofMap(difference, 0, scale, 0, 1);
    scale = _scale;
    tx0 -= tx0 * (-diffMapped * 0.5);
    ty0 -= ty0 * (-diffMapped * 0.5);
    setOffsetTextureSizeX();
    setOffsetTextureSizeY();
}

void ofxTexturePlane::incrementTextureScale(float amount) {
    setTextureScale(scale + amount);
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