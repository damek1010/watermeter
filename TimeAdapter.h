#ifndef TIME_ADAPTER_H
#define TIME_ADAPTER_H

#include <DS1302.h>
#include <stdio.h>
#include <time.h>

class TimeAdapter : public Time {
  public:
    TimeAdapter(unsigned long epochTime)
      : Time(0, 0, 0, 0, 0, 0, Time::kSunday) {
      struct tm  ts;

      time_t rawtime = epochTime;
      ts = *localtime(&rawtime);
      char       buf[80];

      strftime(buf, sizeof(buf), "Pobrany czas: %a %Y-%m-%d %H:%M:%S %Z", &ts);
      Serial.println(buf);

      yr = 1900 + ts.tm_year;
      mon = ts.tm_mon + 1;
      date = ts.tm_mday + 1;
      day = static_cast<Day>(ts.tm_wday + 1);
      hr = ts.tm_hour;
      min = ts.tm_min;
      sec = ts.tm_sec;
    }
};

#endif
