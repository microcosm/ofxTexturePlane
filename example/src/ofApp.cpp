#include "ofApp.h"

//Image credits:
//http://10ravens.deviantart.com/art/Seamless-wood-planks-texture-196937389
//https://www.flickr.com/photos/davelau/1061502581/in/photolist-2BNtJD-f9cyrp-4EWzrD-mf3ohG-6SL4K8-rpZhhi-cR2Y4-oRbHQ3-74HphA-axqy86-6oLop8-sfB4Rm-6vyv87-jweENe-pDokBh-pnLYyF-bUjwNe-nbj5x5-c2rYhC-5Keqs4-prZanK-naWAfw-byiPp8-AvNPk-4wp1yJ-ctBgSh-4SfP8f-4Jq1jU-7RFL1k-2UxfS4-cJtdjq-r1tp1d-6XpF6b-8tkzM8-oLG9TD-hjJG7Y-8jSwxn-qtjPtk-4KVpE5-bzuJjM-4RKuvi-p5eB82-edWUd7-dFGA8c-8FqgLP-naW9EA-gK7JC9-4VddEM-9vNY5B-dLzkef
//https://www.flickr.com/photos/garryknight/7651797988/in/photolist-cEasXw-qhnBmB-sujXPh-qEjktg-dV3zUH-dDpDbP-sfSEUm-sfZunV-pZWCXc-pZWDQz-sfZw8P-rTi2E5-pkBTcz-qhnB3v-dXtCsw-qWqcnE-aqaCep-fLxfdy-a6dghg-o57YmE-9yWbQp-faSZar-dqAeEF-o4mVQW-nhiwzN-jJbVVU-cpHhjj-kQ2UTZ-oDujpf-aWG7mc-bBZ6fw-9SwQCw-oGaFfs-kSnrqv-kAouvv-eujDe5-eAVNME-ofVKfT-oUrZVg-snfgJh-nF1U6b-pC53ar-gqjF2k-aJDhST-cpHiyj-rwbEGo-nwKi7N-rsiRbv-ecL35L-qmw2Ca

void ofApp::setup(){
    ofSetWindowShape(680, 744);

    seamlessPlane1.setup("seamless.jpg", 200, 200);
    buildingPlane1.setup("building.png", 200, 200);
    landscapePlane1.setup("landscape.png", 200, 200);
    
    seamlessPlane2.setup("seamless.jpg", 200, 200);
    buildingPlane2.setup("building.png", 200, 200);
    landscapePlane2.setup("landscape.png", 200, 200);
    
    seamlessPlane3.setup("seamless.jpg", 200, 200);
    buildingPlane3.setup("building.png", 200, 200);
    landscapePlane3.setup("landscape.png", 200, 200);
}

void ofApp::update(){
    seamlessPlane1.incrementOffsetX(0.001);
    buildingPlane1.incrementOffsetY(0.001);
    landscapePlane1.incrementOffsetX(0.001);
    
    seamlessPlane2.setOffsetX(mouseX * 0.001);
    seamlessPlane2.setOffsetY(mouseY * 0.001);
    buildingPlane2.setOffsetX(mouseX * 0.001);
    buildingPlane2.setOffsetY(mouseY * 0.001);
    landscapePlane2.setOffsetX(mouseX * 0.001);
    landscapePlane2.setOffsetY(mouseY * 0.001);
    
    seamlessPlane3.incrementOffsetX(-0.001);
    buildingPlane3.incrementOffsetY(-0.001);
    landscapePlane3.incrementOffsetX(-0.001);
}

void ofApp::draw(){
    ofSetColor(ofColor::white);
    
    seamlessPlane1.draw(20, 20);
    buildingPlane1.draw(240, 20);
    landscapePlane1.draw(460, 20);
    
    seamlessPlane2.draw(20, 240);
    buildingPlane2.draw(240, 240);
    landscapePlane2.draw(460, 240);
    
    seamlessPlane3.draw(20, 460);
    buildingPlane3.draw(240, 460);
    landscapePlane3.draw(460, 460);
    
    ofSetColor(ofColor::black);
    ofDrawBitmapString("Image credits:\nhttp://10ravens.deviantart.com/art/Seamless-wood-planks-texture-196937389\nhttps://www.flickr.com/photos/davelau/1061502581/in/photolist-2BNtJD-f9cyrp-4EWzrD-mf3ohG-6SL4K8-rpZhhi-cR2Y4-oRbHQ3-74HphA-axqy86-6oLop8-sfB4Rm-6vyv87-jweENe-pDokBh-pnLYyF-bUjwNe-nbj5x5-c2rYhC-5Keqs4-prZanK-naWAfw-byiPp8-AvNPk-4wp1yJ-ctBgSh-4SfP8f-4Jq1jU-7RFL1k-2UxfS4-cJtdjq-r1tp1d-6XpF6b-8tkzM8-oLG9TD-hjJG7Y-8jSwxn-qtjPtk-4KVpE5-bzuJjM-4RKuvi-p5eB82-edWUd7-dFGA8c-8FqgLP-naW9EA-gK7JC9-4VddEM-9vNY5B-dLzkef\nhttps://www.flickr.com/photos/garryknight/7651797988/in/photolist-cEasXw-qhnBmB-sujXPh-qEjktg-dV3zUH-dDpDbP-sfSEUm-sfZunV-pZWCXc-pZWDQz-sfZw8P-rTi2E5-pkBTcz-qhnB3v-dXtCsw-qWqcnE-aqaCep-fLxfdy-a6dghg-o57YmE-9yWbQp-faSZar-dqAeEF-o4mVQW-nhiwzN-jJbVVU-cpHhjj-kQ2UTZ-oDujpf-aWG7mc-bBZ6fw-9SwQCw-oGaFfs-kSnrqv-kAouvv-eujDe5-eAVNME-ofVKfT-oUrZVg-snfgJh-nF1U6b-pC53ar-gqjF2k-aJDhST-cpHiyj-rwbEGo-nwKi7N-rsiRbv-ecL35L-qmw2Ca", 20, 686);
}

void ofApp::keyPressed(int key){

}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y ){

}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){

}

void ofApp::mouseReleased(int x, int y, int button){

}

void ofApp::windowResized(int w, int h){

}

void ofApp::gotMessage(ofMessage msg){

}

void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
