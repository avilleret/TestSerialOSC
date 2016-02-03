#pragma once

#include "ofMain.h"
#include "ofxSerial.h"
#include "ofxOsc.h"
#include "ofxGui.h"

class SerialMessage
{
public:
    SerialMessage(): fade(0)
    {
    }

    SerialMessage(const std::string& _message,
                  const std::string& _exception,
                  int _fade):
        message(_message),
        exception(_exception),
        fade(_fade)
    {
    }

    std::string message;
    std::string exception;
    int fade;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();

        void mouseDragged(int x, int y, int btn);
        int state;

        void onSerialBuffer(const ofx::IO::SerialBufferEventArgs& args);
        void onSerialError(const ofx::IO::SerialBufferErrorEventArgs& args);

        // ofx::IO::SLIPPacketSerialDevice device;
        ofx::IO::PacketSerialDevice_<ofx::IO::SLIPEncoding, ofx::IO::SLIPEncoding::END, 16384> device;

        std::vector<SerialMessage> serialMessages;

        ofxPanel gui;
        ofParameter<int> ledNumber;
        vector<int> mouse;
    private:
        void appendMessage( ofxOscMessage& message, osc::OutboundPacketStream& p );
};
