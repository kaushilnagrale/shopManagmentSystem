// shop_code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <windows.h>
#include <mysql.h>
#include <conio.h>

using namespace std;


//Defining the Constants to connect to the database
const char* HOST = "127.0.0.1";
const char* USER = "root";
const char* PASS = "password";
const char* DATABASE = "shop_management_system";
const int PORT = 3306;
const int PASSWORD = 7777;

MYSQL* conn;
MYSQL_RES * res_set;
MYSQL_ROW row;
stringstream stmt;
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
	void display();
	void item_search();
};

class cart
{

	string mobile_number;			// Primary Key
	string item_name;
	long qty;

public:
	void generate_bill_id();
	string get_bill_id();
	void add_item();
	void remove_item();
	void checkout();
	void payment();
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
	cout << "Enter the discount : ";
	cin >> discount;
	stmt.str("");
	stmt << "Insert into item(item_name,cost_price,selling_price,discount) values('" << item_name << "','" << cost_price << "'," << selling_price << "," << discount << ");";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if (!(res_set))
		cout << endl << endl << "Item Inserted Successfully" << endl << endl << endl;
	else
		cout << endl << endl << "ERROR while inserting the item!" << endl << "Contact Technical Team " << endl << endl << endl;

}

void items::display()
{
	int i = 0;
	query = "Select * from item;";
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	cout << endl;
	while ((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << ++i << "  " << row[1] << endl;
		cout << "Price : " << row[3] << endl;
		cout << endl;
	}
}

void items::item_search()
{
	cout << "Enter item id : ";
	cin >> id;
	stmt.str("");
	stmt << "Select * from item where item_id = " << id << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if ((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << "The Name of the item is : " << row[1] << endl;
		cout << "The Price of the item is : " << row[3] << endl;
	}
	else
	{
		cout << "No record Found" << endl;
	}
}

//Customer Cart member function
void cart::generate_bill_id()
{
	cout << "Enter your mobile number : ";
	cin >> mobile_number;
	//add the SP here which initiates the cart (Initiate Stored Procedure)

	//If mobile number not in existing customer then demand the customer details
	// call add customer details from here

	stmt.str("");
	stmt << "CALL SP_initiateCustomerBill(" << mobile_number << ");";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	
	
}

string cart::get_bill_id() 
{
	stmt.str("");
	stmt << "select max(bill_id) from bill";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	row = mysql_fetch_row(res_set);
	cout << row[0];
	return row[0];
}

void cart::add_item()
{
	// printing your order ID is specific
	// Loop to add items 
	//Logic to add the item with given quantity
}

void cart::remove_item()
{
	// show all the order and option to remove the items from the order
	//Logic to remove the item with given quantity
}

void cart::checkout()
{
	//Finalised cart looped with SP to add items (add item Stored procedure)
}

void cart::payment()
{
	//Add payment method for the respective Bill
}

//Function declaration
void main_menu();
void item_menu();
void manager_access();

//Function Definition
// main menu

void main_menu()
{
	int c;
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "         SHOP MANGEMENT SYSTEM" << endl;
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "   1. Purchase Items / Manage Items" << endl;
	cout << "   2. My Purchases" << endl;
	cout << "   3. Customers (Manager Access) " << endl;
	cout << "   4. Customer Bills (Manager Access)" << endl;
	cout << "   5. Suppliers (Manager Access)" << endl;	
	cout << "   6. Supplier Orders (Manager Access)" << endl;
	cout << "   7. EXIT" << endl << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
	case 1:
		system("cls");
		item_menu();
		_getch();
		break;

	case 2:
		system("cls");
		item_menu();
		_getch();
		break;

	case 3:
		system("cls");
		manager_access();
		item_menu();
		_getch();
		break;

	case 4:
		system("cls");
		manager_access();
		item_menu();
		_getch();
		break;
     
	case 5:
		system("cls");
		manager_access();
		item_menu();
		_getch();
		break;

	case 6:
		system("cls");
		manager_access();
		item_menu();
		_getch();
		break;

	case 7:
		exit(1);
	default:
		system("cls");
		cout << "Wrong Input" << endl << endl << "Invalid input";
		_getch();
		break;
	}
	return;
}

// book menu

void item_menu()
{
	int c;
	items b;
	cart car;
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "                  ITEM MENU" << endl;
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "   1. DISPLAY ALL PRODUCTS" << endl;
	cout << "   2. SEARCH and ADD to CART" << endl;
	cout << "   3. ADD (Manager Access)" << endl;
	cout << "   4. UPDATE STATUS (Manager Access)" << endl;
	cout << "   5. RETURN TO MAIN MENU" << endl << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
	case 1:
		b.display();
		break;
	case 2:
		car.generate_bill_id();
		car.get_bill_id();
		b.item_search();
		break;
	case 3:
		manager_access();
		b.add();
		break;
	case 4:
		manager_access();
		b.item_search();
		break;
	case 5:
		return;
		break;
	default:
		cout << "Wrong Input" << endl << "Invalid input";
		break;
	}
	return;
}

// Manager Access 

void manager_access()
{
	int num = 0;
	cout << "Enter password : ";
	for (int i = 0; i < 4; i++)
	{
		num = num * 10 + (_getch() - 48);
		cout << "*";
	}
	if (num == PASSWORD)
	{
		cout << endl << endl << "Correct Password" << endl << endl;
		cout << "Press any key...";
		_getch();
	}
	else
	{
		cout << endl << endl << "Incorrect Password" << endl << endl;
		cout << "Press any key...";
		_getch();
		exit(1);
		cout << endl;
	}
	return;
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
			system("cls");
			main_menu();
		}
	}
	else
	{
		system("cls");
		cout << "Error While connecting to database." << endl << "Contact Tech Expert." << endl;
	}
	return 0;
}

