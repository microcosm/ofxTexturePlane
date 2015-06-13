#include "ofxTexturePlane.h"

void ofxTexturePlane::setup(string filename){
    ofDisableArbTex();
    image.loadImage(filename);
    texture = image.getTextureReference();
    texture.setTextureWrap(GL_MIRRORED_REPEAT, GL_MIRRORED_REPEAT);
}