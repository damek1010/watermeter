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
  delay(0);

      time_t rawtime = epochTime;
      ts = *localtime(&rawtime);
      char       buf[80];
  delay(0);

      strftime(buf, sizeof(buf), "Pobrany czas: %a %Y-%m-%d %H:%M:%S %Z", &ts);
      Serial.println(buf);
  delay(0);

      yr = 1900 + ts.tm_year;
      mon = ts.tm_mon + 1;
      date = ts.tm_mday + 1;
        delay(0);

      day = static_cast<Day>(ts.tm_wday + 1);
      hr = ts.tm_hour;
      min = ts.tm_min;
      sec = ts.tm_sec;
        delay(0);

    }
};

#endif
