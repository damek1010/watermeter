#ifndef QUERY_EXECUTOR_H
#define QUERY_EXECUTOR_H

#include "ConnectionProvider.h"
#include <sqlite3.h>

class QueryExecutor{

  int exec(char* sql);

  public:

    char* createDatabaseString = "create table if not exists measurements(id INTEGER, time DATE, value INTEGER);";
    //tutaj prawdopodobnie dac jeszcze ustawienie indeksu na date

    int createDatabase();

    int select() {}

    int insert() {}

   






  
};


#endif
