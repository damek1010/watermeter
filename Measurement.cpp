#include "Measurement.h"


Measurement* Measurement::createAndSaveToFile(uint32_t value, CSVFile* csv) {
    Measurement* m = new Measurement();
    m->value = value;
    //m->utime = Timeservice::getTime(); //czy cos...
    writeMeasurementToFile(csv, m->utime, m->value);
    return m;
}
