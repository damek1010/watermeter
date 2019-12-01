#include "Measurement.h"


Measurement* Measurement::createAndSaveToFile(uint32_t value, uint32_t delta, CSVFile* csv) {
    Measurement* m = new Measurement();
    m->value = value;
    m->delta = delta;
    //m->utime = Timeservice::getTime(); //czy cos...
    writeMeasurementToFile(csv, m->utime, m->value, m->delta);
    return m;
}
