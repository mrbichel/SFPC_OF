#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    searchChaos = true;
    fbo.allocate(ofGetWidth()*2, ofGetHeight()*2);
    //fbo.setActiveDrawBuffer(4);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i=0; i<1000; i++) {
    
    attractor.iterate();
    
        if (attractor.type == "chaotic") {
            
            i+=100;
            
        }
        
    /*if(attractor.I % 200 == 0 && attractor.I > 40000) {
        mesh.clear();
        for(int i=0; i<attractor.d.size(); i++){
            float x = ofGetWidth() * (attractor.d[i].x - attractor.xmin) / (attractor.xmax-attractor.xmin);
            float y = ofGetHeight() * (attractor.d[i].y - attractor.ymin) / (attractor.ymax-attractor.ymin);
            mesh.addVertex(ofVec2f(x,y));
        }

    }*/
    
    
   // if(attractor.I > 100 && attractor.drawIt) {
    
     //   if(mesh.getNumVertices() > attractor.I) {
       //     mesh.clear();
       // }
        
        /*float x = ofGetWidth() * (attractor.d[i].x - attractor.xmin) / (attractor.xmax-attractor.xmin);
        float y = ofGetHeight() * (attractor.d[i].y - attractor.ymin) / (attractor.ymax-attractor.ymin);
        */
        
       // mesh.addVertex(attractor.d[attractor.I]);
        
    //}

    
        
        
    if( !attractor.drawIt || attractor.I > 400000) {
        //cout<<attractor.type<<endl;
        /*if(searchChaos)*/ attractor = Attractor();
    }
        
    if(attractor.type == "chaotic") {
        searchChaos = false;
    }
        
        
        
    }
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //if(attractor.drawIt && attractor.I > 200) {
    //if(attractor.drawIt) {
    
    fbo.begin();
    ofBackground(2,32,2);
        ofSetColor(255,255,255,255);
    
    
    
    //ofTranslate(<#float x#>, <#float y#>)
        
    ofPushMatrix();
    ofTranslate(fbo.getWidth()/2, fbo.getHeight()/2);
    ofScale(600,600);
    
    
    attractor.draw();
    ofPopMatrix();
        
        //ofDrawBitmapString(ofToString(attractor.I) + " " + attractor.type + " " + ofToString(attractor.seed), 20,20);
    fbo.end();
    
    
    ofSetColor(255,255,255,255);
    
    fbo.draw(0,0,ofGetWidth(),ofGetHeight());
    //}
    //}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    cout<<key<<endl;
    if(key == 32) {
        searchChaos = true;
    }
    

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}



