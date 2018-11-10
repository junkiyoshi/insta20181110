#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(239, 39, 39);

	ofTrueTypeFontSettings font_settings("fonts/EmojiSymbols-Regular.ttf", 32);
	font_settings.antialiased = true;
	font_settings.addRanges(ofAlphabet::Emoji);
	this->font.load(font_settings);

	this->box2d.init();
	this->box2d.setGravity(0, 5);
	this->box2d.createBounds();
	this->box2d.setFPS(60);
	this->box2d.registerGrabbing();

}

//--------------------------------------------------------------
void ofApp::update() {

	if (ofGetFrameNum() % 10 == 0) {

		float radius = 16;
		auto circle = make_shared<ofxBox2dCircle>();
		circle->setPhysics(1.0, 0.63, 0.1);
		circle->setup(this->box2d.getWorld(), ofRandom(ofGetWidth() * 0.5 - 50, ofGetWidth() * 0.5 + 50), 15, radius);
		this->circles.push_back(circle);
	}

	this->box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (int i = 0; i < this->circles.size(); i++) {

		ofPushMatrix();
		ofTranslate(this->circles[i]->getPosition().x, this->circles[i]->getPosition().y);
		ofRotate(this->circles[i]->getRotation());

		this->font.drawString(u8"🍎", this->circles[i]->getRadius() * -1, this->circles[i]->getRadius());

		ofPopMatrix();
	}
}

//========================================================================
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}