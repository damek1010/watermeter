#ifndef CONNECTION_PROVIDER_H
#define CONNECTION_PROVIDER_H

#include <sqlite3.h>
#include <ESP8266WiFi.h>

class ConnectionProvider {
  static sqlite3* connection;

  public:
    static int init();

    static sqlite3* getConnection() {
      return connection;
    }

    static void close();
};

#endif
