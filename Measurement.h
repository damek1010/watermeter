#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <ESP8266WiFi.h>

/*
 * Model pomiaru w bazie danych
 */
class Measurement {

  int value;
  char* date; 

  static char* TABLE_NAME;
  
  public:
    static Measurement create(int value);
};

#endif
