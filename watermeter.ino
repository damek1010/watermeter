#include <stdio.h>
#include <stdlib.h>
//#include <sqlite3.h>
//#include <vfs.h>
//#include <SPI.h>
//#include <FS.h>
#include <ESP8266WiFi.h>
#include "Measurement.h"

#include "SDCardService.h"

#define PIN_CLK D5
#define PIN_MOSI D7
#define PIN_MISO D6
#define PIN_CS D8


SdFat sd;
CSVFile* csv;

uint32_t timeVar = 999999999;

uint32_t lastMeasurement = 999999999;

int i;

//zmienna na czas
//zmienne na piny podlaczonego zegarka




//pulse counter


//



void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("\nInit!");

  system_update_cpu_freq(SYS_CPU_160MHZ);



  pinMode(PIN_MOSI, OUTPUT);
  pinMode(PIN_MISO, INPUT);
  pinMode(PIN_CLK, OUTPUT);
  //Disable SPI devices
  pinMode(PIN_CS, OUTPUT);
  digitalWrite(PIN_CS, HIGH);
  Serial.println("sd begin");

  if (!sd.begin(PIN_CS, SD_CARD_SPEED))
  {
    Serial.println("SD card begin error");
    return;
  }

  //timeservice, get time and save
  //sdcardservice create/ open existing day file
  ////create www page





/*
  Serial.println("create file");

  csv = createFile("csvtest.csv");

  if (csv == nullptr) {
    Serial.println("File opening error");
  }

  Serial.println("writing to file");

  for (i = 0; i < 5; ++i, timeVar += 10, lastMeasurement += 20)
    writeMeasurementToFile(csv, timeVar, lastMeasurement);

  Serial.println("going to begining");

  csv->gotoBeginOfFile();

  uint32_t readTime;
  uint32_t readValue;

  Serial.println("reading");
  for (i = 0; i < 3; ++i) {
    readValuesOfCurrentRow(csv, readTime, readValue);

    Serial.println(readTime);
    Serial.println(readValue);
  }


  Serial.println("closinng-p--+-");

  closeFile(csv);

*/


  //    ConnectionProvider::init();
  //
  //    QueryExecutor::createDatabase();
  //
  //    Measurement m = Measurement::create(10);
  //
  //    ConnectionProvider::close();

}

void loop() {

  //obluga strony

  //ustawic f liczaca na przerwaninu (?)
  
  //jesli zmienil sie dzien, wywolaj zmiane pliku csv 


  
}
