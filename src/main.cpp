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
#include "ofMain.h"
#include "ofApp.h"

int main()
{
// #ifdef __linux__
	ofGLESWindowSettings settings;
	settings.glesVersion=2;
	// settings.windowMode=OF_GAME_MODE;
// #else
// 	ofGLWindowSettings settings;
// 	settings.setGLVersion(3,2);
	settings.windowMode=OF_WINDOW;
// #endif
	settings.setSize(480, 320);
	ofCreateWindow(settings);
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
}
