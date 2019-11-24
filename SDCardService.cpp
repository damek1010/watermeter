#include "SDCardService.h"

void writeMeasurementToFile(CSVFile &csv, uint32_t &time, uint32_t &value){
    csv.addField(time);
    csv.addField(value);
    csv.addLine();
}

CSVFile* createFile(const char* fileName){
    CSVFile csv;
    if (!csv.open(fileName, O_RDWR | O_CREAT)) {
        Serial.println("Failed open file");
        return nullptr;
    }
    return &csv;
}

CSVFile* openFileToAppend(const char* filename){
    CSVFile csv;
    if (!csv.open(filename, O_RDWR | O_APPEND)) {
        Serial.println("Failed open file");
        return nullptr;
    }
    return &csv;
}

void readValuesOfCurrentRow(CSVFile &csv, uint32_t &time, uint32_t &value){
    char buffer[BUFFER_SIZE + 1];
    buffer[BUFFER_SIZE] = '\0';
    
    csv.readField(buffer, BUFFER_SIZE);
    time = atol(buffer);
    csv.nextField();

    csv.readField(buffer, BUFFER_SIZE);
    value = atol(buffer);
    csv.nextLine();
}