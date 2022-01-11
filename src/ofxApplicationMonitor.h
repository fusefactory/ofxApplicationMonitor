#pragma once
#include "ofxOsc.h"

class ofxApplicationMonitor{
public:
    void setup(const std::string& host, int port);
    void update();
    void setPidTimeMillis(const int millis);

protected:
	ofxOscSender oscSender;
    long lastTimePid = -1;
    int pidTimeMillis = 1000;
    void sendAppPID();
    std::string getPid();
};