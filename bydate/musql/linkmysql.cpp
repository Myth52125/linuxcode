#include <iostream>
#include <mysql.h>

using namespace std;

int main()
{
	cout<<"test"<<endl;
	
	MYSQL conn;
	int res;

	cout<<"init result: "<<mysql_init(&conn)<<endl;
	cout<<"connect result"<<mysql_real_connect(&conn,"localhost","root","521521","websearcher",0,NULL,CLIENT_FOUND_ROWS)<<endl;
	cout<<"query reault: "<<mysql_query(&conn,"CREATE TABLE linktest(id2 int )")<<endl;

	

	return 0;
}
