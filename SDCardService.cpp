#include "SDCardService.h"


void writeMeasurementToFile(CSVFile* csv, uint32_t utime, uint32_t value, uint32_t delta) {
  csv->addField(utime);
  csv->addField(value);
    csv->addField(delta);
  csv->addLine();
}

CSVFile* createFile(const char* fileName) {
  CSVFile* csv = new CSVFile();
  if (!csv->open(fileName, O_RDWR | O_CREAT)) {
    Serial.println("Failed creating file");
    return nullptr;
  }
  return csv;
}

CSVFile* openFile(const char* filename, SdFat sd) {
  if (!sd.exists(filename)){
    return createFile(filename);
  }
  CSVFile* csv = new CSVFile();
  if (!csv->open(filename, O_RDWR | O_APPEND)) {
    Serial.println("Failed opening file");
    return nullptr;
  }
  return csv;
}


void readValuesOfCurrentRow(CSVFile *csv, uint32_t &utime, uint32_t &value, uint32_t &delta) {
  char buffer[BUFFER_SIZE + 1];
  buffer[BUFFER_SIZE] = '\0';

  csv->readField(buffer, BUFFER_SIZE);
  utime = atol(buffer);
  csv->nextField();

  csv->readField(buffer, BUFFER_SIZE);
  value = atol(buffer);
  csv->nextField();

  csv->readField(buffer, BUFFER_SIZE);
  delta = atol(buffer);
  csv->nextLine();
}

void closeFile(CSVFile *csv) {
  csv->close();
  delete csv;
}

void changeFileToNextDayFile(CSVFile *csv, const char * newFileName) {
  closeFile(csv);
  csv = createFile(newFileName);
}
