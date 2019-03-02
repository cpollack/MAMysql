#include <my_global.h>
#include <mysql.h>
#include "MAMysql.h"

bool mamysql_init(char* ip, char* user, char* password, char* database, int port) {
	con = mysql_init(NULL);
	//mysql_options(con, MYSQL_SET_CHARSET_NAME, "utf8");
	if (con == NULL)
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		return false;
	}

	if (mysql_real_connect(con, ip, user, password, database, port, NULL, 0) == NULL)
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		return false;
	}

	return true;
}


void mamysql_close() {
	mysql_close(con);
}

char* mamysql_queryGetValue(char* query) {
	char* value = new char(200);

	mysql_query(con, query);
	MYSQL_RES *result = mysql_store_result(con);
	if (result != NULL) {
		if (result->row_count > 0) {
			MYSQL_ROW row = mysql_fetch_row(result);
			strcpy(value, row[0]);
		}
		else printf("Query found no rows\n");
	}
	else fprintf(stderr, "%s\n", mysql_error(con));
	mysql_free_result(result);

	return value;
}


bool mamysql_queryExecute(char* query) {
	mysql_query(con, query);

	if (mysql_errno(con)) {
		printf("Query failed\n");
		return false;
	}
	return true;
}