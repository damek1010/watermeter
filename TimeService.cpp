#include "TimeService.h"
#include "TimeAdapter.h"
#include <stdio.h>

TimeService* TimeService::instance = nullptr;
DS1302* TimeService::rtc = nullptr;

TimeService::TimeService() {
  WiFiUDP ntpUDP;
  NTPClient timeClient(ntpUDP);
  delay(0);

  rtc = new DS1302(kCePin, kIoPin, kSclkPin);
  delay(0);

  timeClient.begin();
  delay(0);

  timeClient.update();

  delay(500);
  delay(0);

  fetchTime = new TimeAdapter(timeClient.getEpochTime());
  delay(0);

  rtc->time(*fetchTime);
}

TimeService& TimeService::getInstance() {
    delay(0);


  static TimeService instance;
    delay(0);

  return instance;
}

Time TimeService::getFetchTime() {
    delay(0);

  return *fetchTime;
}

Time TimeService::getCurrentTime() {
  return rtc->time();
  delay(0);
}

char* TimeService::getDateAsString() {
  char dateString[11];
    delay(0);

  Time currentTime = getCurrentTime();
    delay(0);

  sprintf(dateString, "%04d-%02d-%02d \0", currentTime.yr, currentTime.mon, currentTime.date);
    delay(0);

  Serial.println(dateString);
    delay(0);

  return dateString;
}

short TimeService::getDayNumber(){
    delay(0);
    return getCurrentTime().date;
}
