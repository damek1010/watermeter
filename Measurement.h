#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <ESP8266WiFi.h>
#include <Time.h>
#include <TimeLib.h>

#include "Measurement.h"
#include "SDCardService.h"
/*
 * Model pomiaru w bazie danych
 */
class Measurement {

  uint32_t value;
  uint32_t utime; 
  
  public:
    static Measurement* createAndSaveToFile(uint32_t value, CSVFile* csv);

};

#endif
