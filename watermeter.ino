#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <vfs.h>
#include <SPI.h>
#include <FS.h>
#include <ESP8266WiFi.h>
#include "ConnectionProvider.h"
#include "Measurement.h"
#include "QueryExecutor.h"

//const char* data = "Callback function called";
//static int callback(void *data, int argc, char **argv, char **azColName) {
//  int i;
//  Serial.printf("%s: ", (const char*)data);
//  for (i = 0; i < argc; i++) {
//    Serial.printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//  }
//  Serial.printf("\n");
//  return 0;
//}
//
//int openDb(char *filename, sqlite3 **db) {
//  int rc = sqlite3_open(filename, db);
//  if (rc) {
//    Serial.printf("Can't open database: %s\n", sqlite3_errmsg(*db));
//    return rc;
//  } else {
//    Serial.printf("Opened database successfully\n");
//  }
//  return rc;
//}
//
//char *zErrMsg = 0;
//int db_exec(sqlite3 *db, const char *sql) {
//  Serial.println(sql);
//  long start = micros();
//  int rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
//  if (rc != SQLITE_OK) {
//    Serial.printf("SQL error: %s\n", zErrMsg);
//    sqlite3_free(zErrMsg);
//  } else {
//    Serial.printf("Operation done successfully\n");
//  }
//  Serial.print(F("Time taken:"));
//  Serial.println(micros() - start);
//  return rc;
//}

void setup() {
    Serial.begin(115200);
    while(!Serial);

    Serial.println("\nInit!");
//  sqlite3 *db1;
//  sqlite3 *db2;
//  char *zErrMsg = 0;
//  int rc;
//  char *sql;
//
    system_update_cpu_freq(SYS_CPU_160MHZ);
//
    SPI.begin();
    vfs_mount("/SD0", 2);

    ConnectionProvider::init();

    QueryExecutor::createDatabase();

    Measurement m = Measurement::create(10);

    ConnectionProvider::close();
//
//  sqlite3_initialize();
//
//  // Open database 1
//  if (openDb("/SD0/census2000names.db", &db1))
//    return;
//  if (openDb("/SD0/mdr512.db", &db2))
//    return;
//
//
//  rc = db_exec(db1, "CREATE TABLE IF NOT EXISTS test1 (id INTEGER, content);");
//  if (rc != SQLITE_OK) {
//    sqlite3_close(db1);
//    sqlite3_close(db2);
//    return;
//  }
//  rc = db_exec(db2, "CREATE TABLE IF NOT EXISTS test2 (id INTEGER, content);");
//  if (rc != SQLITE_OK) {
//    sqlite3_close(db1);
//    sqlite3_close(db2);
//    return;
//  }
//
//  rc = db_exec(db1, "INSERT INTO test1 VALUES (1, 'Hello, World from test1');");
//  if (rc != SQLITE_OK) {
//    sqlite3_close(db1);
//    sqlite3_close(db2);
//    return;
//  }
//  rc = db_exec(db2, "INSERT INTO test2 VALUES (1, 'Hello, World from test2');");
//  if (rc != SQLITE_OK) {
//    sqlite3_close(db1);
//    sqlite3_close(db2);
//    return;
//  }
//
//  rc = db_exec(db1, "SELECT * FROM test1");
//  if (rc != SQLITE_OK) {
//    sqlite3_close(db1);
//    sqlite3_close(db2);
//    return;
//  }
//  rc = db_exec(db2, "SELECT * FROM test2");
//  if (rc != SQLITE_OK) {
//    sqlite3_close(db1);
//    sqlite3_close(db2);
//    return;
//  }
//
//  sqlite3_close(db1);
//  sqlite3_close(db2);

}

void loop() {
}
