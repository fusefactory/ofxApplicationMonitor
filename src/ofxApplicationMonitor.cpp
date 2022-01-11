#include "ofxApplicationMonitor.h"

void ofxApplicationMonitor::setup(const std::string& host, int port) {
	oscSender.setup(host, port);
}

void ofxApplicationMonitor::setPidTimeMillis(const int millis) {
    if (millis > 0) pidTimeMillis = millis;
}

void ofxApplicationMonitor::update() {
    if (ofGetElapsedTimeMillis() - lastTimePid > pidTimeMillis) {
        lastTimePid = ofGetElapsedTimeMillis();
        sendAppPID();
    }
}

void ofxApplicationMonitor::sendAppPID() {
    std::string pid = getPid();

    ofxOscMessage m;
    m.setAddress("/pid");
    m.addStringArg(pid);
    oscSender.sendMessage(m);

    ofLogVerbose("ofxApplicationMonitor") << "send osc:  " << m;
}

std::string ofxApplicationMonitor::getPid() {

#ifdef __APPLE__
    return ofToString(getpid());
#else
    DWORD id = GetCurrentProcessId();
    char buf[sizeof(DWORD) * 8 + 1];
    ultoa(id, buf, 2);

    std::ostringstream stream;
    stream << id;

    std::string pid = stream.str();

    return pid;
#endif
}