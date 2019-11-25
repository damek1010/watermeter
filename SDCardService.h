#include <CSVFile.h>
#include <CSVFileConfig.h>

#ifndef GIT_SDCARDSERVICE_H
#define GIT_SDCARDSERVICE_H

#include <SdFat.h>
#include <CSVFile.h>

#define SD_CARD_SPEED SPI_FULL_SPEED
#define BUFFER_SIZE 32


CSVFile* createFile(const char* fileName);

void writeMeasurementToFile(CSVFile *csv, uint32_t utime, uint32_t value);

void readValuesOfCurrentRow(CSVFile *csv, uint32_t &utime, uint32_t &value);

void closeFile(CSVFile *csv);

void changeFileToNextDayFile(CSVFile *csv, const char * newFileName);

CSVFile* openFile(const char* filename);




#endif //GIT_SDCARDSERVICE_H
