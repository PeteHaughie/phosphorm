/*
 * Copyright (c) 2013 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 * See https://github.com/danomatika/ofxMidi for documentation
 *
 */
#pragma once

#include "ofMain.h"
#include "ofxMidi.h"
#include "ofxNDI.h" // NDI classes

class ofApp : public ofBaseApp, public ofxMidiListener
{

public:
    ~ofApp() noexcept override = default;
    void setup();
    void update();
    void draw();
    void exit();

    void keyPressed(int key);
    void keyReleased(int key);

    void newMidiMessage(ofxMidiMessage &eventArgs);

    float quantize(float sample, float quantize_amount, float quantize_mix);

    void midibiz();

    ofxMidiIn midiIn;
    std::vector<ofxMidiMessage> midiMessages;
    std::size_t maxMessages = 8; //< max number of messages to keep track of

    void audioOut(ofSoundBuffer &buffer);

    ofSoundStream soundStream;

    float pan;
    int sampleRate;
    bool bNoise;
    float volume;

    vector<float> lAudio;
    vector<float> rAudio;

    // this will contain non granularized audio buffer info
    vector<float> lAudio_c;
    vector<float> rAudio_c;

    //------------------- for the simple sine wave synthesis
    // audio
    float phase_l1;
    float phaseAdder_l1;
    float phaseAdderTarget_l1;

    float phase_l2;
    float phaseAdder_l2;
    float phaseAdderTarget_l2;

    float phase_r1;
    float phaseAdder_r1;
    float phaseAdderTarget_r1;

    float phase_r2;
    float phaseAdder_r2;
    float phaseAdderTarget_r2;

    // ampmod
    float ampmod_phase_l1;
    float ampmod_phaseAdder_l1;
    float ampmod_phaseAdderTarget_l1;

    float ampmod_phase_l2;
    float ampmod_phaseAdder_l2;
    float ampmod_phaseAdderTarget_l2;

    float ampmod_phase_r1;
    float ampmod_phaseAdder_r1;
    float ampmod_phaseAdderTarget_r1;

    float ampmod_phase_r2;
    float ampmod_phaseAdder_r2;
    float ampmod_phaseAdderTarget_r2;

    // phasemod
    float phasemod_phase_l1;
    float phasemod_phaseAdder_l1;
    float phasemod_phaseAdderTarget_l1;

    float phasemod_phase_l2;
    float phasemod_phaseAdder_l2;
    float phasemod_phaseAdderTarget_l2;

    float phasemod_phase_r1;
    float phasemod_phaseAdder_r1;
    float phasemod_phaseAdderTarget_r1;

    float phasemod_phase_r2;
    float phasemod_phaseAdder_r2;
    float phasemod_phaseAdderTarget_r2;

    float osc(float arg, float amp, int shape);

    // for the phosphor styles
    ofFbo fb0;
    ofFbo fb1;

    ofShader shader_phosphor;

    unsigned int long midiID = 0, prevMidiID = 0;
    unsigned int long audioID = 0, prevAudioID = 0;

    // NDI
    ofxNDIsender ndiSender;        // NDI sender
    std::string senderName;        // Sender name
    unsigned int senderWidth = 0;  // Width of the sender output
    unsigned int senderHeight = 0; // Height of the sender output
    bool bInitialized = false;
    ofFbo m_fbo;                   // Fbo used for graphics and sending
    ofImage textureImage;          // Texture image for the 3D cube graphics

    bool bReadback = true;
    bool bAsync = true;
    double framerate = 60.0;

};
