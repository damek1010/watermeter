#include <stdio.h>
#include <stdlib.h>
//#include <sqlite3.h>
//#include <vfs.h>
//#include <SPI.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "Measurement.h"

#include "SDCardService.h"
#include "TimeService.h"
#include "HTMLLoader.h"

#define PIN_CLK 14
#define PIN_MOSI 13
#define PIN_MISO 12
#define PIN_CS 15

#define INTERRUPT_PIN D1
#define EXIT_PIN D2

//SdFat sd;
CSVFile* csv;

ESP8266WebServer server(80);
HTMLLoader loader;
uint32_t utime = 0;

uint32_t lastMeasurement = 0;

uint32_t pulseCounter = 0;

int i;

bool end_of_work = false;

//zmienna na czas




static unsigned long last_interrupt_time = 0;

void ICACHE_RAM_ATTR handleInterrupt() {
  unsigned long interrupt_time = millis();
  // If interrupts come faster than 100ms, assume it's a bounce and ignore
  if (interrupt_time - last_interrupt_time > 100)
  {
    ++pulseCounter;
    //Serial.println(pulseCounter);

    //Serial.println("writing to file");
  }
  last_interrupt_time = interrupt_time;
}

void ICACHE_RAM_ATTR stopProgram() {

  //Serial.println("Disabling Watermeter");
  end_of_work = true;
}





//



void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("\nInit!");

  system_update_cpu_freq(SYS_CPU_160MHZ);

  pinMode(INTERRUPT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), handleInterrupt, FALLING);

  pinMode(EXIT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(EXIT_PIN), stopProgram, FALLING);

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

  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), handleInterrupt, FALLING);

}

void handleRoot() {
  String content = loader.load("/web/index.html");
  server.send(200, "text/html", content);   // Send HTTP status 200 (Ok) and send some text to the browser/client
}

void handleNotFound() {
  server.send(404, "text/html", "404: Not found"); // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
}

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("\nInit!");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("writing to file");

  for (i = 0; i < 5; ++i, timeVar += 10, lastMeasurement += 20)
    writeMeasurementToFile(csv, timeVar, lastMeasurement);

  server.on("/", handleRoot);               // Call the 'handleRoot' function when a client requests URI "/"
  server.on("/style.css", []() {
    server.send(200, "text/css", loader.load("/web/style.css"));
  });   
  server.on("/js/canvasjs/canvasjs.min.js", []() {
    server.send(200, "application/javascript", loader.load("/web/js/canvasjs/canvasjs.min.js"));
  });   
  server.onNotFound(handleNotFound);        // When a client requests an unknown URI (i.e. something other than "/"), call function "handleNotFound"
  

  server.begin();
}

void loop() {

  //obluga strony

  //jesli zmienil sie dzien, wywolaj zmiane pliku csv

  delay(1000 * 3);


  server.handleClient();
  //get time

  noInterrupts();

  writeMeasurementToFile(csv, utime, pulseCounter, pulseCounter - lastMeasurement);
interrupts();
  //change this later
  utime += 3;

  lastMeasurement = pulseCounter;
 // Serial.println("Writing to file");
 // Serial.println(utime);

  if (end_of_work) {
      noInterrupts();

    closeFile(csv);
    while (1) {
      delay(1000);
    }
  }


}
