// shop_code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <windows.h>
#include <mysql.h>
#include <conio.h>
#include <ctime>

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

class customer_cart
{

	string mobile_number;			// Primary Key
	string item_no;
	string payment_method;
	long qty;

public:
	void generate_bill_id(string n);
	string get_bill_id();
	void add_item(string n);
	void remove_item();
	void checkout(string n);
	void payment(string n);
};

class supplier_cart
{

	string mobile_number;			// Primary Key
	string item_name;
	long qty;

public:
	//void generate_purchase_id();
	//string get_purchase_id();
	//void add_item();
	//void remove_item();
	//void checkout();
	//void payment()

};

class customer 
{
	string first_name;			// Primary Key
	string last_name;
	string email_id;
	string address;
	string phone_number;
	string city;
	string state;
	string post_code;
public:
	void display_customer();
	void add_customer();
	void update_customer();
};

class supplier
{
	string name;
	string phone_number;
	string address;
	string city;
	string state;
	string post_code;
	string email_id;
};

//Item Member Functions
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
void customer_cart::generate_bill_id(string n)
{

	stmt.str("");
	stmt << "CALL SP_initiateCustomerBill(" << n << ");";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	
	
}

string customer_cart::get_bill_id()
{
	stmt.str("");
	stmt << "select max(bill_id) from bill";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	row = mysql_fetch_row(res_set);
	//cout << row[0];
	system("cls");
	// printing your order ID is specific
	cout << "Your Bill ID is " << row[0] << endl;
	return row[0];
}

void customer_cart::add_item(string n)
{

	cout << "Add an item" << endl;
	cin >> item_no;
	cout << "Add Quantity" << endl;
	cin >> qty;

	stmt.str("");
	stmt << "CALL SP_addBillItems("<< n << "," << item_no << "," << qty << ");";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);


}

void customer_cart::remove_item()
{
	// show all the order and option to remove the items from the order
	//Logic to remove the item with given quantity
}

void customer_cart::checkout(string n)
{
	//Finalised cart looped with SP to add items (add item Stored procedure)
	system("cls");
	cout << "Your Total Amount is" << endl;

	stmt.str("");
	stmt << "select sum(price*quantity) from bill_item where bill_id =" << n <<";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	cout << endl;
	row = mysql_fetch_row(res_set);
	cout << row[0] << endl;	
}

void customer_cart::payment(string n)
{
	//Add payment method for the respective Bill
	cout << "Enter your Payment Method" << endl;
	cin >> payment_method;

	stmt.str("");
	stmt << "call SP_customerPayment(" << n << ",'" << payment_method << "'); ";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);

	system("cls");
	cout << "Payment done Sucessfully!";
	
}

//Customer Member Functions

void customer::display_customer()
{
	//display customer
	int i = 0;
	query = "Select * from customer;";
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	cout << endl;
	while ((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << ++i << "  " << row[1] << " " << row[2] << endl;
		cout << "Mobile : " << row[5] << endl;
		cout << endl;
	}

}

void customer::add_customer()
{
	cout << "Enter the first_name  : ";
	cin >> first_name;
	cout << "Enter the last_name  : ";
	cin >> last_name;
	cout << "Enter the email_id  : ";
	cin >> email_id;
	cout << "Enter the address  : ";
	cin >> address;
	cout << "Enter the phone_number  : ";
	cin >> phone_number;
	cout << "Enter the city  : ";
	cin >> city;
	cout << "Enter the state  : ";
	cin >> state;
	cout << "Enter the post_code  : ";
	cin >> post_code;


	stmt.str("");
	stmt << "Insert into customer(first_name,last_name,email_id,address,phone_number,city,state,post_code,start_date) values('" << first_name << "','" << last_name << "','" << email_id << "','" << address << "'," << phone_number << ",'" << city << "','" << state << "'," << post_code << ",CURRENT_TIMESTAMP());";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if (!(res_set))
		cout << endl << endl << "Customer Inserted Successfully" << endl << endl << endl;
	else
		cout << endl << endl << "ERROR while inserting the Customer!" << endl << "Contact Technical Team " << endl << endl << endl;

}

void customer::update_customer()
{
	//update customer
}

//Function declaration
void main_menu();
void item_menu();
void manager_access();
void customer_menu();
void display_customer_purchase(string n);
void display_supplier_purchase();

//Function Definition
// main menu

void main_menu()
{
	int c;
	string mobno;
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
		cout << "Enter your mobile No. :  ";
		cin >> mobno;
		//If new number then add customer details
		display_customer_purchase(mobno);
		_getch();
		break;

	case 3:
		system("cls");
		manager_access();
		customer_menu();
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

// Item menu

void item_menu()
{
	system("cls");
	int c;
	string bill;
	items b;
	char s = 'y';
	string mobile_number;
	customer_cart car;
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
		cout << "Enter your mobile number : ";
		cin >> mobile_number;
        //If new number then add customer 
        //If mobile number not in existing customer then demand the customer details
        // call add customer details from here
		car.generate_bill_id(mobile_number);
		bill = car.get_bill_id();
		while (s != 'n' || s!= 'N')
		{	
			cout << "Do you want to add item? (y/n)" << endl;
			cin >> s;
			if (s == 89 || s == 121) 
			{
				b.display();		
				car.add_item(bill);
			}
			else
			{
				break;
			}
		}
		car.checkout(bill);
		car.payment(bill);

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

//Customer menu
void customer_menu()
{
	system("cls");
	int c;
	customer d;
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "                  CUSTOMER MENU" << endl;
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "   1. DISPLAY ALL CUSTOMER" << endl;
	cout << "   2. ADD CUSTOMER" << endl;
	cout << "   3. UPDATE CUSTOMER " << endl;
	cout << "   4. RETURN TO MAIN MENU" << endl << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
	case 1:
		d.display_customer();
		break;
	case 2:
		d.add_customer();
		break;
	case 3:
		d.update_customer();
		break;
	case 4:
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
	cout << "Enter the manager password : ";
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

void display_customer_purchase(string n) 
{
	int i = 0;
	query = "SELECT * FROM bill a join customer b on a.customer_id = b.customer_id where b.phone_number = '" + n + "';";
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	cout << endl;
	while ((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << ++i << "  " << row[5] << endl;
		cout << "Date : " << row[3] << endl;
		cout << "Amount : " << row[2] << endl;
		cout << endl;
	}
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

