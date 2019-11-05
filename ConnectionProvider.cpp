#include "ConnectionProvider.h"

sqlite3* ConnectionProvider::connection = nullptr;

int ConnectionProvider::init() {
  sqlite3_initialize();

  int rc = sqlite3_open("/SD0/watermeter.sqlite", &connection);
  if (rc) {
    Serial.printf("Can't open database: %s\n", sqlite3_errmsg(connection));
    return rc;
  }
  
  Serial.printf("Opened database successfully\n");
  return rc;
}

void ConnectionProvider::close() {
  sqlite3_close(connection);
}
