#ifndef SQLITE_HELPER_H_INCLUDED_
#define SQLITE_HELPER_H_INCLUDED_

#include "sqlite3.h"
#include <vector>
#include <string>

#define DB_FILE_PATH "./iot.s3db"

typedef int (*callback)(void*,int,char**,char**);

class db_helper
{
public:
    db_helper(std::string s_path);
    ~db_helper();
    int sql_exec_with_return(std::string s_sql);
    std::vector<std::string> getsqlresult();

private:
    sqlite3 *m_db;
    std::string m_path;
    int db_open();
    int db_close();
    int db_exec(const char *sql);
    // int sql_exec_with_return_callback(void* data, int argc, char **argv, char**azColName);
    std::vector<std::string> m_resultvec;
};

#endif