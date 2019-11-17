#include <Time.h>
#include <TimeLib.h>

#include "Measurement.h"
#include "QueryExecutor.h"

char* Measurement::TABLE_NAME = "measurement";

Measurement Measurement::create(int value) {
    char insertSql[255];
    time_t t = now();
    sprintf(insertSql, "INSERT INTO %s (value, measurement_date) VALUES (%d, %lld);\n", Measurement::TABLE_NAME, value, t);
    QueryExecutor::create(insertSql);
}