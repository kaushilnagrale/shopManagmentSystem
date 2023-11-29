// shop_code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <mysql.h>

using namespace std;


//Defining the Constants to connect to the database
const char* HOST = "127.0.0.1";
const char* USER = "root";
const char* PASS = "password";
const char* DATABASE = "shop_management_system";
const int PORT = 3306;

MYSQL* conn;
MYSQL_RES * res_set;
MYSQL_ROW row;
const char * q;
string query;
// my_bool result;


//Classes
class items
{
	int id;			// Primary Key
	string item_name;
	float cost_price;
	float selling_price;
	float discount;
public:
	void add();

};

//Member Functions
void items::add()
{
	cout << "Enter the name of the item : ";
	cin >> item_name;
	cout << "Enter the Cost Price : ";
	cin >> cost_price;
	cout << "Enter the Selling Price : ";
	cin >> selling_price;



}

int main()
{
	std::cout << "Hello World!\n";
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, HOST, USER, PASS, DATABASE, PORT, NULL, 0);
	int choice;
	if (conn)
	{
		while (1)
		{
			cout << "Connected Successfully\n";
			system("cls");
		}
	}
	else
	{
		system("cls");
		cout << "Error While connection to database." << endl << "Contact Tech Expert." << endl;
	}
	return 0;
}

