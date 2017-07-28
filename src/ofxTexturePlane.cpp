#include "ofxTexturePlane.h"

void ofxTexturePlane::setup(string filename, float textureScale, ofxTexturePlaneOffset offset, ofxTexturePlaneMode mode, ofxTexturePlaneWrap wrap) {
    setup(filename, ofGetWidth(), ofGetHeight(), textureScale, offset, mode, wrap);
}

void ofxTexturePlane::setup(ofImage& image, float textureScale, ofxTexturePlaneOffset offset, ofxTexturePlaneMode mode, ofxTexturePlaneWrap wrap) {
    setup(image, ofGetWidth(), ofGetHeight(), textureScale, offset, mode, wrap);
}

void ofxTexturePlane::setup(string filename, ofVec2f size, float textureScale, ofxTexturePlaneOffset offset, ofxTexturePlaneMode mode, ofxTexturePlaneWrap wrap) {
    setup(filename, size.x, size.y, textureScale, offset, mode, wrap);
}

void ofxTexturePlane::setup(ofImage& image, ofVec2f size, float textureScale, ofxTexturePlaneOffset offset, ofxTexturePlaneMode mode, ofxTexturePlaneWrap wrap) {
    setup(image, size.x, size.y, textureScale, offset, mode, wrap);
}

void ofxTexturePlane::setup(string filename, float width, float height, float textureScale, ofxTexturePlaneOffset offset, ofxTexturePlaneMode mode, ofxTexturePlaneWrap wrap) {
    ofDisableArbTex();
    image.load(filename);
    setup(image, width, height, textureScale, offset, mode, wrap);
}

void ofxTexturePlane::setup(ofImage& image, float width, float height, float textureScale, ofxTexturePlaneOffset offset, ofxTexturePlaneMode mode, ofxTexturePlaneWrap wrap) {
    ofDisableArbTex();
    texture = image.getTexture();

    if(wrap == TEXTURE_WRAP_REPEAT){
        texture.setTextureWrap(GL_REPEAT, GL_REPEAT);
    }else if(wrap == TEXTURE_WRAP_MIRRORED_REPEAT){
        texture.setTextureWrap(GL_MIRRORED_REPEAT, GL_MIRRORED_REPEAT);
    }else if(wrap == TEXTURE_WRAP_CLAMP_TO_EDGE){
        texture.setTextureWrap(GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);
    }else if(wrap == TEXTURE_WRAP_CLAMP_TO_BORDER){
        texture.setTextureWrap(GL_CLAMP_TO_BORDER, GL_CLAMP_TO_BORDER);
    }

    plane.setResolution(2, 2);
    plane.set(width, height);
    plane.setPosition(width * 0.5, height * 0.5, 0);
    scale = textureScale;
    setTextureMode(mode);
    setTextureOffset(offset);
    loadIndexableOffsets();
}

void ofxTexturePlane::draw(int x, int y, ofxTexturePlaneFlip flip) {
    backup();
    setPlanePosition(x, y);
    flipTexture(flip);
    draw();
    restore();
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

void ofxTexturePlane::setPlaneSize(float width, float height) {
    plane.set(width, height);
    setPlanePosition(plane.getPosition().x, plane.getPosition().y);
    setOffsetTextureSizeX();
    setOffsetTextureSizeY();
}

void ofxTexturePlane::setPlaneWidth(float width) {
    setPlaneSize(width, plane.getHeight());
}

void ofxTexturePlane::setPlaneHeight(float height) {
    setPlaneSize(plane.getWidth(), height);
}

void ofxTexturePlane::setPlanePosition(int x, int y) {
    plane.setPosition(x + plane.getWidth() * 0.5, y + plane.getHeight() * 0.5, plane.getPosition().z);
}

void ofxTexturePlane::setPlanePosition(ofVec2f position) {
    setPlanePosition(position.x, position.y);
}

void ofxTexturePlane::setTextureMode(ofxTexturePlaneMode mode) {
    textureMode = mode;
}

void ofxTexturePlane::setTextureOffset(ofxTexturePlaneOffset offset) {
    switch(offset){
        case TEXTURE_OFFSET_TOP_LEFT:
        case TEXTURE_OFFSET_MIDDLE_LEFT:
        case TEXTURE_OFFSET_BOTTOM_LEFT:
        case TEXTURE_OFFSET__TOP_TO_MIDDLE__LEFT:
        case TEXTURE_OFFSET__BOTTOM_TO_MIDDLE__LEFT:
            setTextureOffsetX(0);
            break;
        case TEXTURE_OFFSET_TOP_CENTER:
        case TEXTURE_OFFSET_MIDDLE_CENTER:
        case TEXTURE_OFFSET_BOTTOM_CENTER:
        case TEXTURE_OFFSET__TOP_TO_MIDDLE__CENTER:
        case TEXTURE_OFFSET__BOTTOM_TO_MIDDLE__CENTER:
            calculateTextureSizes();
            setTextureOffsetX(getCenteredOffset(0.5, textureSize.x));
            break;
        case TEXTURE_OFFSET_TOP_RIGHT:
        case TEXTURE_OFFSET_MIDDLE_RIGHT:
        case TEXTURE_OFFSET_BOTTOM_RIGHT:
        case TEXTURE_OFFSET__TOP_TO_MIDDLE__RIGHT:
        case TEXTURE_OFFSET__BOTTOM_TO_MIDDLE__RIGHT:
            calculateTextureSizes();
            setTextureOffsetX(1 - textureSize.x);
            break;
        case TEXTURE_OFFSET__TOP__LEFT_TO_CENTER:
        case TEXTURE_OFFSET__MIDDLE__LEFT_TO_CENTER:
        case TEXTURE_OFFSET__BOTTOM__LEFT_TO_CENTER:
        case TEXTURE_OFFSET__TOP_TO_MIDDLE__LEFT_TO_CENTER:
        case TEXTURE_OFFSET__BOTTOM_TO_MIDDLE__LEFT_TO_CENTER:
            calculateTextureSizes();
            setTextureOffsetX(getCenteredOffset(0.5, textureSize.x));
            incrementTextureOffsetX(-0.5);
            break;
        case TEXTURE_OFFSET__TOP__RIGHT_TO_CENTER:
        case TEXTURE_OFFSET__MIDDLE__RIGHT_TO_CENTER:
        case TEXTURE_OFFSET__BOTTOM__RIGHT_TO_CENTER:
        case TEXTURE_OFFSET__TOP_TO_MIDDLE__RIGHT_TO_CENTER:
        case TEXTURE_OFFSET__BOTTOM_TO_MIDDLE__RIGHT_TO_CENTER:
            calculateTextureSizes();
            setTextureOffsetX(getCenteredOffset(0.5, textureSize.x));
            incrementTextureOffsetX(0.5);
            break;
    }

    switch(offset){
        case TEXTURE_OFFSET_TOP_LEFT:
        case TEXTURE_OFFSET_TOP_CENTER:
        case TEXTURE_OFFSET_TOP_RIGHT:
        case TEXTURE_OFFSET__TOP__LEFT_TO_CENTER:
        case TEXTURE_OFFSET__TOP__RIGHT_TO_CENTER:
            setTextureOffsetY(0);
            break;
        case TEXTURE_OFFSET_MIDDLE_LEFT:
        case TEXTURE_OFFSET_MIDDLE_CENTER:
        case TEXTURE_OFFSET_MIDDLE_RIGHT:
        case TEXTURE_OFFSET__MIDDLE__LEFT_TO_CENTER:
        case TEXTURE_OFFSET__MIDDLE__RIGHT_TO_CENTER:
            calculateTextureSizes();
            setTextureOffsetY(getCenteredOffset(0.5, textureSize.y));
            break;
        case TEXTURE_OFFSET_BOTTOM_LEFT:
        case TEXTURE_OFFSET_BOTTOM_CENTER:
        case TEXTURE_OFFSET_BOTTOM_RIGHT:
        case TEXTURE_OFFSET__BOTTOM__LEFT_TO_CENTER:
        case TEXTURE_OFFSET__BOTTOM__RIGHT_TO_CENTER:
            calculateTextureSizes();
            setTextureOffsetY(1 - textureSize.y);
            break;
        case TEXTURE_OFFSET__TOP_TO_MIDDLE__LEFT:
        case TEXTURE_OFFSET__TOP_TO_MIDDLE__CENTER:
        case TEXTURE_OFFSET__TOP_TO_MIDDLE__RIGHT:
        case TEXTURE_OFFSET__TOP_TO_MIDDLE__LEFT_TO_CENTER:
        case TEXTURE_OFFSET__TOP_TO_MIDDLE__RIGHT_TO_CENTER:
            calculateTextureSizes();
            setTextureOffsetY(getCenteredOffset(0.5, textureSize.y));
            incrementTextureOffsetY(-0.5);
            break;
        case TEXTURE_OFFSET__BOTTOM_TO_MIDDLE__LEFT:
        case TEXTURE_OFFSET__BOTTOM_TO_MIDDLE__CENTER:
        case TEXTURE_OFFSET__BOTTOM_TO_MIDDLE__RIGHT:
        case TEXTURE_OFFSET__BOTTOM_TO_MIDDLE__LEFT_TO_CENTER:
        case TEXTURE_OFFSET__BOTTOM_TO_MIDDLE__RIGHT_TO_CENTER:
            calculateTextureSizes();
            setTextureOffsetY(getCenteredOffset(0.5, textureSize.y));
            incrementTextureOffsetY(0.5);
            break;
    }
}

void ofxTexturePlane::setTextureOffset(int offsetIndex) {
    setTextureOffset(offsets.at(offsetIndex));
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
    calculateTextureSizes();
    setTextureOffsetX(getCenteredOffset(positionX, textureSize.x));
}

void ofxTexturePlane::setTexturePositionY(float positionY) {
    calculateTextureSizes();
    setTextureOffsetY(getCenteredOffset(positionY, textureSize.y));
}

void ofxTexturePlane::setTextureScale(float _scale) {
    calculateTextureSizes();
    float x = textureSize.x;
    float y = textureSize.y;
    scale = _scale;
    calculateTextureSizes();
    incrementTextureOffsetX((x - textureSize.x) * 0.5);
    incrementTextureOffsetY((y - textureSize.y) * 0.5);
}

void ofxTexturePlane::incrementTextureScale(float amount) {
    setTextureScale(scale + amount);
}

void ofxTexturePlane::flipTexture(ofxTexturePlaneFlip flip) {
    switch(flip){
        case TEXTURE_FLIP_HORIZONTAL:
            swap(ty0, ty1);
            break;
        case TEXTURE_FLIP_VERTICAL:
            swap(tx0, tx1);
            break;
        case TEXTURE_FLIP_BOTH:
            swap(tx0, tx1);
            swap(ty0, ty1);
            break;
        default:
            break;
    }
}

void ofxTexturePlane::backup() {
    backup_planePosition = plane.getPosition();
    backup_tx0 = tx0;
    backup_ty0 = ty0;
    backup_tx1 = tx1;
    backup_ty1 = ty1;
}

void ofxTexturePlane::restore() {
    plane.setPosition(backup_planePosition);
    tx0 = backup_tx0;
    ty0 = backup_ty0;
    tx1 = backup_tx1;
    ty1 = backup_ty1;
}

void ofxTexturePlane::loadIndexableOffsets() {
    offsets.push_back(TEXTURE_OFFSET_TOP_LEFT);
    offsets.push_back(TEXTURE_OFFSET_TOP_CENTER);
    offsets.push_back(TEXTURE_OFFSET_TOP_RIGHT);
    offsets.push_back(TEXTURE_OFFSET_MIDDLE_LEFT);
    offsets.push_back(TEXTURE_OFFSET_MIDDLE_CENTER);
    offsets.push_back(TEXTURE_OFFSET_MIDDLE_RIGHT);
    offsets.push_back(TEXTURE_OFFSET_BOTTOM_LEFT);
    offsets.push_back(TEXTURE_OFFSET_BOTTOM_CENTER);
    offsets.push_back(TEXTURE_OFFSET_BOTTOM_RIGHT);
}

void ofxTexturePlane::setOffsetTextureSizeX() {
    calculateTextureSizes();
    tx1 = tx0 + textureSize.x;
}

void ofxTexturePlane::setOffsetTextureSizeY() {
    calculateTextureSizes();
    ty1 = ty0 + textureSize.y;
}

void ofxTexturePlane::calculateTextureSizes() {
    float combinedX = plane.getWidth() / image.getWidth();
    float combinedY = plane.getHeight() / image.getHeight();

    if(textureMode == TEXTURE_MODE_COVER){
        if(combinedX < combinedY){
            textureSize.x = combinedX / combinedY;
            textureSize.y = 1;
        }else{
            textureSize.x = 1;
            textureSize.y = combinedY / combinedX;
        }
    }else if(textureMode == TEXTURE_MODE_FIT){
        if(combinedX < combinedY){
            textureSize.x = 1;
            textureSize.y = combinedY / combinedX;
        }else{
            textureSize.x = combinedX / combinedY;
            textureSize.y = 1;
        }
    }
    textureSize.x /= scale;
    textureSize.y /= scale;
}

float ofxTexturePlane::getCenteredOffset(float normalizedPosition, float textureSize) {
    return normalizedPosition - textureSize * normalizedPosition;
}

void ofxTexturePlane::swap(float &val1, float &val2) {
    float temp = val1;
    val1 = val2;
    val2 = temp;
}
