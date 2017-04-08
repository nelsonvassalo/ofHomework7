#include "ofApp.h"
ofFbo fbo;
vector<wave> wavy;

wave::wave(){
}

void wave::setup(){
    loc = ofPoint(ofRandom(0,ofGetWindowWidth()),ofRandom(0, ofGetWindowHeight()),0);
    weight= ofRandom(1,3);
    noise= ofRandom(0.1,2);
    
    a=ofRandom(0.2,0.3);
    b=ofRandom(0.3,0.4);
    c=ofRandom(0.4,0.5);
    
    rX = ofRandom(45);
    rY = ofRandom(60);
    rZ = ofRandom(30);
    
    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
    
    fbo.allocate(ofGetWindowWidth(),ofGetWindowHeight(), GL_RGBA32F);
    fbo.begin();
    ofClear(255,255,255,0);
    fbo.end();
}


void wave::update(){
    time= ofGetElapsedTimef()*noise;

    rX= ofSignedNoise(time*0.3)*400;
    rY= ofSignedNoise(time*0.2)*400;
    rZ= ofSignedNoise(time*0.1)*400;
    
    
    scale= (1-ofNoise(time))*weight;

    
    moveX= ofSignedNoise(time*a)*ofRandom(1,10);
    moveY= ofSignedNoise(time*b)*ofRandom(1,10);
    moveZ= ofSignedNoise(time*c)*ofRandom(1,10);
    
    loc+= ofPoint(moveX, moveY,moveZ);
}

void wave::draw(){
    ofBackground(255);
    
    fbo.begin();
    
    ofSetColor(255,255,255, 1);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    ofPushMatrix();
    ofTranslate(loc.x, loc.y, loc.z);
    ofScale(scale,scale,scale);
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    ofSetColor(color);
    ofDrawLine(-40,0,40,0);
    ofPopMatrix();
    
 
    
    ofSetColor(255);
       fbo.end();
    fbo.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::setup(){
    for(int i=0; i<5; i++){
        wave waveyBaby;
        waveyBaby.setup();
        wavy.push_back(waveyBaby);
        
        }
}

//--------------------------------------------------------------
void ofApp::update(){
    //wavy.update();
    for(int i=0; i<wavy.size(); i++){
        wavy[i].update();


        if(wavy[i].loc.y<0||wavy[i].loc.y>ofGetWindowHeight()||wavy[i].loc.x<0||wavy[i].loc.x>ofGetWindowWidth()){
            wavy.erase(wavy.begin()+i);
            wave waveyBaby;
            waveyBaby.setup();
            wavy.push_back(waveyBaby);
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    //wavy.draw();
    for(int i=0; i<wavy.size(); i++){
        wavy[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
