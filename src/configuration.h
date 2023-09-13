#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <Arduino.h>
#include <FS.h>
#include <vector>

class Beacon {
public:
  String callsign;
  String symbol;
  String overlay;
  String comment;
  bool  smartBeaconState;
  int   slowRate;
  int   slowSpeed;
  int   fastRate;
  int   fastSpeed;
  int   minTxDist;
  int   minDeltaBeacon;
  int   turnMinDeg;
  int   turnSlope;
};

class LoraModule {
public:
  long  frequency;
  int   spreadingFactor;
  long  signalBandwidth;
  int   codingRate4;
  int   power;
};

class Ptt {
public:
  bool  active;
  int   pptPin;
  int   preDelay;
  int   postDelay;
  bool  reverse;
};

class BME {
public:
  bool    active;
};

class Notifications {
public:
  bool    ledTx;
  int     ledTxPin;
  bool    ledMessage;
  int     ledMessagePin;
  bool    buzzerActive;
  int     buzzerPin;
  bool    bootUpBeep;
  bool    gpsFixBeep;
  bool    txBeep;
  bool    messageRxBeep;
  bool    stationHeardBeep;
};



class Configuration {
public:

  std::vector<Beacon> beacons;  
  LoraModule          loramodule;
  Ptt                 ptt;
  BME                 bme;
  Notifications       notifications;
  
  bool    simplifiedTrackerMode;
  bool    showSymbolOnScreen;
  int     sendCommentAfterXBeacons;
  bool    displayEcoMode;
  int     displayTimeout;
  String  path;
  int     nonSmartBeaconRate;
  int     rememberStationTime;
  int     maxDistanceToTracker;
  int     standingUpdateTime;
  bool    sendAltitude;
  bool    sendBatteryInfo;
  bool    bluetooth;
  bool    disableGps;

  Configuration();
  void validateConfigFile(String currentBeaconCallsign);

private:
  void readFile(fs::FS &fs, const char *fileName) ;
  String _filePath;
};
#endif