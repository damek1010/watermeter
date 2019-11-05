#include "QueryExecutor.h"

int QueryExecutor::exec(char* sql) {

  sqlite3 *connection = ConnectionProvider::getConnection();
  
  Serial.println(sql);
  long start = micros();
  int rc = sqlite3_exec(connection, sql, nullptr, nullptr, nullptr);
  if (rc != SQLITE_OK) {
//    Serial.printf("SQL error: %s\n", zErrMsg);
//    sqlite3_free(zErrMsg);
  } else {
    Serial.printf("Operation done successfully\n");
  }
  Serial.print(F("Time taken:"));
  Serial.println(micros() - start);
  return rc;
}

int QueryExecutor::createDatabase() {



  int rc;





  rc = exec("CREATE TABLE IF NOT EXISTS test1 (id INTEGER, content);");
  //  rc = db_exec(database, createDatabaseString);
  if (rc != SQLITE_OK) {
    Serial.println("Something went wrong!!!!");

  }
  return rc;





}
