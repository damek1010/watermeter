#include "TimeService.h"
#include "TimeAdapter.h"
#include <stdio.h>

TimeService* TimeService::instance = nullptr;
DS1302* TimeService::rtc = nullptr;

TimeService::TimeService() {
  WiFiUDP ntpUDP;
  NTPClient timeClient(ntpUDP);

  rtc = new DS1302(kCePin, kIoPin, kSclkPin);

  timeClient.begin();

  timeClient.update();

  delay(500);

  fetchTime = new TimeAdapter(timeClient.getEpochTime());

  rtc->time(*fetchTime);
}

TimeService& TimeService::getInstance() {
  static TimeService instance;
  return instance;
}

Time TimeService::getFetchTime() {
  return *fetchTime;
}

Time TimeService::getCurrentTime() {
  return rtc->time();
}

char* TimeService::getDateAsString() {
  char dateString[11];
  Time currentTime = getCurrentTime();
  sprintf(dateString, "%04d-%02d-%02d \0", currentTime.yr, currentTime.mon, currentTime.date);
  Serial.println(dateString);
  return dateString;
}

short TimeService::getDayNumber(){
    return getCurrentTime().date;
}
