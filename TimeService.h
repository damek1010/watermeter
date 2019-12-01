
#ifndef TIME_SERVICE_H
#define TIME_SERVICE_H

#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <DS1302.h>

const int kCePin   = 4;  // Chip Enable
const int kIoPin   = 2;  // Input/Output
const int kSclkPin = 14;  // Serial Clock

class TimeService {
    static TimeService* instance;

    Time* fetchTime;

    TimeService ();
    TimeService (const TimeService& ts) {}

    static DS1302* rtc;

  public:
    static TimeService& getInstance();

    static void init();

    Time getFetchTime();

    Time getCurrentTime();

    char* getDateAsString();
};


#endif
