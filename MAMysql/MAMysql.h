// MAMYSQL.h - Contains declarations of Mam->Mysql functions
#pragma once

#ifdef MAMYSQL_EXPORT
#define MAMYSQL_API __declspec(dllexport)
#else
#define MAMYSQL_API __declspec(dllimport)
#endif

extern MYSQL *con = NULL;

extern "C" MAMYSQL_API bool mamysql_init(char* ip, char* user, char* password, char* database, int port);
extern "C" MAMYSQL_API void mamysql_close();
extern "C" MAMYSQL_API char* mamysql_queryGetValue(char* query);
extern "C" MAMYSQL_API bool mamysql_queryExecute(char* query);