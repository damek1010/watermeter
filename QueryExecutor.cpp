#include "QueryExecutor.h"
#include "ConnectionProvider.h"

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
    rc = exec("CREATE TABLE IF NOT EXISTS measurement (id INTEGER PRIMARY KEY AUTOINCREMENT, value INTEGER, measurement_date INTEGER);");
    //  rc = db_exec(database, createDatabaseString);
    if (rc != SQLITE_OK) {
        Serial.println("Something went wrong!!!!\n");
    }
    rc = exec("CREATE UNIQUE INDEX date_index on measurement (measurement_date);");
    //  rc = db_exec(database, createDatabaseString);
    if (rc != SQLITE_OK) {
        Serial.println("Something went wrong!!!!\n");
    }
    return rc;
}

int QueryExecutor::createAndObtainId(char* sql) {

    if (create(sql) == SQLITE_OK){
        /*
        String sql = "Select year, state, name, total_babies, primary_sex, primary_sex_ratio, \
                    per_100k_in_state from gendered_names \
                    where name between 'Bob' and 'Bobby'";
        rc = sqlite3_prepare_v2(db1, sql.c_str(), 1000, &res, &tail);
        if (rc != SQLITE_OK) {
            String resp = "Failed to fetch data: ";
            resp += sqlite3_errmsg(db1);
            resp += "<br><br><a href='/'>back</a>";
            Serial.println(resp.c_str());
            return;
        }

        while (sqlite3_step(res) == SQLITE_ROW) {
            Serial.printf("Year: %d\n", sqlite3_column_int(res, 0));
            Serial.printf("State: %s\n", (const char *) sqlite3_column_text(res, 1));
            Serial.printf("Name: %s\n", (const char *) sqlite3_column_text(res, 2));
            Serial.printf("Total babies: %d\n", sqlite3_column_int(res, 3));
            Serial.printf("Primary sex: %s\n", (const char *) sqlite3_column_text(res, 4));
            Serial.printf("Ratio: %lf\n", sqlite3_column_double(res, 5));
            Serial.printf("Per 100k in state: %lf\n\n", sqlite3_column_double(res, 6));
            rec_count++;
        }
        Serial.printf("No. of records: %d", rec_count);

        sqlite3_finalize(res);

        sqlite3_close(db1);
        */
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
}