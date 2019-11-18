#include "QueryExecutor.h"
#include "ConnectionProvider.h"

int QueryExecutor::exec(char* sql) {

  sqlite3 *connection = ConnectionProvider::getConnection();
  char *zErrMsg = 0;

  Serial.println(sql);
  long start = micros();
  int rc = sqlite3_exec(connection, sql, nullptr, nullptr, &zErrMsg);
  if (rc != SQLITE_OK) {
    Serial.printf("SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    Serial.printf("Operation done successfully\n");
  }
  Serial.print(F("Time taken:"));
  Serial.println(micros() - start);
  return rc;
}

int QueryExecutor::createDatabase() {
  int rc;
  //wyciagnac sqle do zmiennych statycznych const
  rc = exec("CREATE TABLE IF NOT EXISTS measurement (id INTEGER PRIMARY KEY, value INTEGER, date INTEGER);");
  //  rc = db_exec(database, createDatabaseString);
  if (rc != SQLITE_OK) {
    Serial.println("Something went wrong!!!!\n");
  }
  rc = exec("CREATE UNIQUE INDEX date_index on measurement (date);");
  //  rc = db_exec(database, createDatabaseString);
  if (rc != SQLITE_OK) {
    Serial.println("Something went wrong!!!!\n");
  }
  return rc;
}

int QueryExecutor::createAndObtainId(char* sql) {

  if (create(sql) == SQLITE_OK) {
    //get id
  }
  return -1;
}

int QueryExecutor::create(char* sql) {
  int rc = exec(sql);
  if (rc != SQLITE_OK) {
    Serial.println("Something went wrong!!!!\n");
  }
  return rc;
}
