#include "ofxTexturePlane.h"

void ofxTexturePlane::setup(string filename, float textureScale, ofxTexturePlaneOffset offset) {
    setup(filename, ofGetWidth(), ofGetHeight(), textureScale, offset);
}

void ofxTexturePlane::setup(string filename, int width, int height, float textureScale, ofxTexturePlaneOffset offset) {
    ofDisableArbTex();
    image.loadImage(filename);
    texture = image.getTextureReference();
    texture.setTextureWrap(GL_MIRRORED_REPEAT, GL_MIRRORED_REPEAT);
    plane.setResolution(2, 2);
    plane.set(width, height);
    plane.setPosition(width * 0.5, height * 0.5, 0);
    scale = textureScale;
    setTextureOffset(offset);
    ofEnableArbTex();
}

void ofxTexturePlane::draw(int x, int y) {
    setPlanePosition(x, y);
    draw();
}

void ofxTexturePlane::draw(ofVec2f position) {
    draw(position.x, position.y);
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

void ofxTexturePlane::setPlanePosition(ofVec2f position) {
    setPlanePosition(position.x, position.y);
}

void ofxTexturePlane::setTextureOffset(ofxTexturePlaneOffset offset) {
    switch(offset){
        case TEXTURE_OFFSET_TOP_LEFT:
        case TEXTURE_OFFSET_MIDDLE_LEFT:
        case TEXTURE_OFFSET_BOTTOM_LEFT:
            setTextureOffsetX(0);
            break;
        case TEXTURE_OFFSET_TOP_CENTER:
        case TEXTURE_OFFSET_MIDDLE_CENTER:
        case TEXTURE_OFFSET_BOTTOM_CENTER:
            setTextureOffsetX(getCenteredOffset(0.5, calculateTextureSizeX()));
            break;
        case TEXTURE_OFFSET_TOP_RIGHT:
        case TEXTURE_OFFSET_MIDDLE_RIGHT:
        case TEXTURE_OFFSET_BOTTOM_RIGHT:
            setTextureOffsetX(1 - calculateTextureSizeX());
            break;
    }

    switch(offset){
        case TEXTURE_OFFSET_TOP_LEFT:
        case TEXTURE_OFFSET_TOP_CENTER:
        case TEXTURE_OFFSET_TOP_RIGHT:
            setTextureOffsetY(0);
            break;
        case TEXTURE_OFFSET_MIDDLE_LEFT:
        case TEXTURE_OFFSET_MIDDLE_CENTER:
        case TEXTURE_OFFSET_MIDDLE_RIGHT:
            setTextureOffsetY(getCenteredOffset(0.5, calculateTextureSizeY()));
            break;
        case TEXTURE_OFFSET_BOTTOM_LEFT:
        case TEXTURE_OFFSET_BOTTOM_CENTER:
        case TEXTURE_OFFSET_BOTTOM_RIGHT:
            setTextureOffsetY(1 - calculateTextureSizeY());
            break;
    }
}

void ofxTexturePlane::setTextureOffset(float offsetX, float offsetY) {
    setTextureOffsetX(offsetX);
    setTextureOffsetY(offsetY);
}

void ofxTexturePlane::setTextureOffset(ofVec2f offset) {
    setTextureOffset(offset.x, offset.y);
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

void ofxTexturePlane::incrementTextureOffset(ofVec2f amount) {
    incrementTextureOffset(amount.x, amount.y);
}

void ofxTexturePlane::incrementTextureOffsetX(float amount) {
    setTextureOffsetX(tx0 + amount);
}

void ofxTexturePlane::incrementTextureOffsetY(float amount) {
    setTextureOffsetY(ty0 + amount);
}

void ofxTexturePlane::setTexturePosition(float positionX, float positionY) {
    setTexturePositionX(positionX);
    setTexturePositionY(positionY);
}

void ofxTexturePlane::setTexturePosition(ofVec2f position) {
    setTexturePosition(position.x, position.y);
}

void ofxTexturePlane::setTexturePositionX(float positionX) {
    setTextureOffsetX(getCenteredOffset(positionX, calculateTextureSizeX()));
}

void ofxTexturePlane::setTexturePositionY(float positionY) {
    setTextureOffsetY(getCenteredOffset(positionY, calculateTextureSizeY()));
}

void ofxTexturePlane::setTextureScale(float _scale) {
    textureSize.x = calculateTextureSizeX();
    textureSize.y = calculateTextureSizeY();
    scale = _scale;
    incrementTextureOffsetX((textureSize.x - calculateTextureSizeX()) * 0.5);
    incrementTextureOffsetY((textureSize.y - calculateTextureSizeY()) * 0.5);
}

void ofxTexturePlane::incrementTextureScale(float amount) {
    setTextureScale(scale + amount);
}

void ofxTexturePlane::setOffsetTextureSizeX() {
    tx1 = tx0 + calculateTextureSizeX();
}

void ofxTexturePlane::setOffsetTextureSizeY() {
    ty1 = ty0 + calculateTextureSizeY();
}

float ofxTexturePlane::calculateTextureSizeX() {
    textureSize.x =  imageIsTallerThanWide() ? 1 : calculateImageFraction();
    textureSize.x *= planeIsTallerThanWide() ? calculatePlaneFraction() : 1;
    textureSize.x /= scale;
    return textureSize.x;
}

float ofxTexturePlane::calculateTextureSizeY() {
    textureSize.y =  imageIsTallerThanWide() ? calculateImageFraction() : 1;
    textureSize.y *= planeIsTallerThanWide() ? 1 : calculatePlaneFraction();
    textureSize.y /= scale;
    return textureSize.y;
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

float ofxTexturePlane::getCenteredOffset(float normalizedPosition, float textureSize) {
    return normalizedPosition - textureSize * normalizedPosition;
}