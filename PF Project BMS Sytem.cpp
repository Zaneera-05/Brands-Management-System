#include<iostream>
#include<string>
#include<cstring>
#include<windows.h>
using namespace std;

//Constant for Login Manual
const string Username="Programmer";
const string Password="123bms";
bool login();


// for color in output text
void setColor(int color) 
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}


// Structure for sales records
struct Sale {
    int saleID;
    string customerName;
    float amount;
    float tax;
    float totalAmount;
};

// Structure for customer records
struct Customer {
    int customerID;
    string name;
    string contact;
};

// Structure for discounts
struct Discount {
    int discountID;
    string description;
    float percentage; // Discount percentage
};

// Arrays to store data
Sale sales[100] = {
	{1,"Sana Khan",400,60,460},
	{2,"Hina Ali",300,45,345},
	{3,"Ali Ahmed",1000,150,1150},
	{4,"Laraib Shah",2000,300,2300},
	{5,"Maria Saleem",500,75,575}
};
int saleCount = 5;

Customer customers[100] = {
    {1,"Umaima Arif","03046578231"},
    {2,"Usama Khan","03245769843"},
    {3,"Nimra Ali","03424578564"},
    {4,"Saima Butt","03216543210"},
    {5,"Nazir Ahmed","03129654709"}
};
int customerCount = 5;

Discount discounts[100] ={
    {1,"Get 10% off on each product",10},
    {2,"Flat 20% off",20},
    {3,"By 1 Get 1 Free",50},
    {4,"Exclusive upto 30% off on all items.",30},
    {5,"Seasonal Offer: Save 15%",15},
};
int discountCount = 5;

// Function declarations
void addSale();
void viewSales();
void searchSale();
void updateSale();
void deleteSale();

void addCustomer();
void viewCustomers();
void searchCustomer();
void updateCustomer();
void deleteCustomer();

void addDiscount();
void viewDiscounts();
void updateDiscount();
void deleteDiscount();

int main()
{
    if (!login())
	{
		return 0;
	}
    int choice;
    
    do { 
        setColor(1);
    	cout << "\t\t\t\t\t****************************************";
        cout << "\n\t\t\t\t\tWelcome to Brand Sales Management System\n";
        cout << "\t\t\t\t\t****************************************\n";
        setColor(6);
		cout << "1. Sales Management\n";
        cout << "2. Customer Management\n";
        cout << "3. Discount Management\n";
        cout << "4. Exit\n";
        setColor(7);
        cout << "Enter your choice: ";
        cin >> choice;
        system("Cls");

        switch (choice) 
		{
            case 1: 
			{
				setColor(5);
                int salesChoice;
                cout << "\t\t\t\t\t\t*************************";
                cout << "\n\t\t\t\t\t\t Sales Management System \n"; 
				cout << "\t\t\t\t\t\t*************************\n";
                setColor(3);
				cout << "1. Add Sale\n";
                cout << "2. View Sales\n";
                cout << "3. Search Sale\n";
                cout << "4. Update Sale\n";
                cout << "5. Delete Sale\n";
                setColor(7);
                cout << "Enter your choice: ";
				cin >> salesChoice;
                system("Cls");
                switch (salesChoice) 
				{
                    case 1: 
					    addSale(); 
						break;
                    case 2: 
					    viewSales(); 
						break;
                    case 3: 
					    searchSale(); 
						break;
                    case 4: 
					    updateSale();  
						break;
                    case 5: 
					    deleteSale(); 
						break;
                    default: 
					    setColor(4);
					    cout << "Invalid choice!\n";
                }
                break;
            }
            case 2: 
			{
				setColor(5);
                int customerChoice;
                cout << "\n\t\t\t\t\t\t  *******************\n";
				cout << "\t\t\t\t\t\t  Customer Management\n";
				cout << "\t\t\t\t\t\t  *******************\n";
                setColor(3);
				cout << "1. Add Customer\n";
                cout << "2. View Customers\n";
                cout << "3. Search Customer\n";
                cout << "4. Update Customer\n";
                cout << "5. Delete Customer\n";
                setColor(7);
                cout << "Enter your choice: ";
				cin >> customerChoice;
                system("Cls");
                switch (customerChoice) 
				{
                    case 1: 
					    addCustomer(); 
						break;
                    case 2: 
					    viewCustomers(); 
						break;
                    case 3: 
					    searchCustomer(); 
						break;
                    case 4: 
					    updateCustomer(); 
						break;
                    case 5: 
					    deleteCustomer(); 
						break;
                    default: 
					    setColor(4);
					    cout << "Invalid choice!\n";
                }
                break;
            }
            case 3:
			{
				setColor(5);
			    int discountChoice;
			    cout << "\n\t\t\t\t\t\t  *******************";
				cout << "\n\t\t\t\t\t\t  Discount Management\n";
				cout << "\t\t\t\t\t\t  *******************\n";
			    setColor(3);
				cout << "1. Add Discount\n";
                cout << "2. View Discount\n";
                cout << "3. Update Discount\n";
                cout << "4. Delete Discount\n";
                setColor(7);
                cout << "Enter your choice: ";
				cin >> discountChoice;
                system("Cls");
                switch (discountChoice) 
				{
                    case 1: 
					    addDiscount(); 
						break;
                    case 2: 
					    viewDiscounts(); 
						break;
                    case 3: 
					    updateDiscount(); 
						break;
                    case 4: 
					    deleteDiscount(); 
						break;
			        default: 
			            setColor(4);
					    cout <<"Invalid choice!\n";
					    break;
			    } break;
            }
			case 4:
			{
				setColor(2);
			    cout <<"\n\t\t\t\t\t\tExiting system...\n";
				setColor(7); 
				break;
		    }
            default:
			{
				setColor(4);
			    cout <<"Invalid choice!\n";
		    }
        }
    } while (choice != 4);

    return 0;
}

// Login function
bool login() 
{
    string inputUsername, inputPassword;
    setColor(9);
	cout <<"Enter username: ";
	setColor(7);
    cin >> inputUsername;
    setColor(9);
    cout <<"Enter password: ";
    setColor(7);
	cin >> inputPassword;
    system("Cls");
    if (inputUsername == Username && inputPassword == Password) {
        setColor(2);
		cout << "Login successful!\n" ;
		setColor(7);
        return true;
    } 
	else
	{
		setColor(4);
        cout << "Invalid username or password.\n";
        setColor(7);
        return false;
    }
}
// Sales Management Functions
void addSale() 
{
	setColor(1);
    cout << "\nEnter Sale ID: ";
    setColor(7);
    cin >> sales[saleCount].saleID;
    cin.ignore();
    setColor(1);
	cout << "Enter Customer Name: ";
	setColor(7);
    getline(cin, sales[saleCount].customerName);
    setColor(1);
    cout <<"Enter Sale Amount: ";
    setColor(7);
    cin >> sales[saleCount].amount;
    sales[saleCount].tax = sales[saleCount].amount * 0.15; // 15% tax
    sales[saleCount].totalAmount = sales[saleCount].amount + sales[saleCount].tax;
    saleCount++;
    setColor(2);
	cout <<"Sale record added successfully!\n";
	setColor(7);
}

void viewSales() 
{
    if (saleCount == 0) 
	{
		setColor(4);
        cout <<"\nNo Sales record available!\n";
        setColor(7);
        return;
    }
    setColor(3);
	cout <<"\nSales Records\n";
	setColor(7);
    for (int i = 0; i < saleCount; i++) {
        setColor(6);
		cout << "Sale ID: " << sales[i].saleID;
        cout << ", Customer: " << sales[i].customerName;
        cout << ", Amount:Rs. " <<sales[i].amount; 
        cout << ", Tax:Rs. " << sales[i].tax;
        cout <<  ", Total:Rs." << sales[i].totalAmount << endl;
        setColor(7);
    }
}

void searchSale() {
    int id;
    setColor(1);
    cout <<"\nEnter Sale ID to search: ";
    setColor(7);
    cin >> id;
    for (int i = 0; i < saleCount; i++) 
	{
        if (sales[i].saleID == id)
		 {  setColor(2);
            cout << "Sale Found! ";
            setColor(7);
            cout << "Customer: " << sales[i].customerName;
            cout << ", Total: " << sales[i].totalAmount << endl;
            return;
        }
    }
    setColor(4);
    cout << "Sale not found!\n";
    setColor(7);
}

void updateSale() {
    int id;
    setColor(1);
    cout <<"\nEnter Sale ID to update: ";
    setColor(7);
    cin >> id;
    for (int i = 0; i < saleCount; i++) {
        if (sales[i].saleID == id) {
            cin.ignore();
            setColor(1);
            cout <<"Enter New Customer Name: ";
            setColor(7);
            getline(cin, sales[i].customerName);
            setColor(1);
            cout <<"Enter New Sale Amount: ";
            setColor(7);
            cin >> sales[i].amount;
            sales[i].tax = sales[i].amount * 0.15;
            sales[i].totalAmount = sales[i].amount + sales[i].tax;
            setColor(2);
			cout << "Sale record updated successfully!\n";
			setColor(7);
            return;
        }
    }setColor(4);
    cout <<  "Sale not found!\n";
    setColor(7);
}

void deleteSale() 
{
    int id;
    setColor(1);
    cout << "\nEnter Sale ID to delete: ";
    setColor(7);
    cin >> id;
    for (int i = 0; i < saleCount; i++) 
	{
        if (sales[i].saleID == id) 
		{
            for (int j = i; j < saleCount - 1; j++) 
			{
                sales[j] = sales[j + 1];
            }
            saleCount--;
            setColor(2);
            cout <<"Sale record deleted successfully!\n";
            setColor(7);
            return;
        }
    }
    setColor(4);
    cout << "Sale not found!\n";
    setColor(7);
}

// Customer Management Functions
void addCustomer() 
{
	setColor(1);
    cout << "\nEnter Customer ID: ";
    setColor(7);
    cin >> customers[customerCount].customerID;
    cin.ignore();
    setColor(1);
    cout << "Enter Customer Name: ";
    setColor(7);
    getline(cin, customers[customerCount].name);
    setColor(1);
    cout << "Enter Contact Info: ";
    setColor(7);
    getline(cin, customers[customerCount].contact);
    customerCount++;
    setColor(2);
    cout << "Customer added successfully!\n";
    setColor(7);
}

void viewCustomers() 
{
	if (customerCount == 0) 
	{
		setColor(4);
        cout << "\nNo Customer record available!\n";
        setColor(7);
        return;
    }
    setColor(3);
    cout << "\n Customer Records\n";
    setColor(7);
    for (int i = 0; i < customerCount; i++) 
	{
		setColor(6);
        cout << "Customer ID: " << customers[i].customerID ;
        cout << ", Name: " << customers[i].name ;
        cout << ", Contact: " << customers[i].contact << endl;
        setColor(7);
    }
}

void searchCustomer() 
{
    int id;
    setColor(1);
    cout << "\nEnter Customer ID to search: ";
    setColor(7);
    cin >> id;
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].customerID == id) {
            setColor(2);
			cout <<"Customer Found! ";
			setColor(7);
            cout << "Name: " << customers[i].name;
            cout << ", Contact: " << customers[i].contact << endl;
            return;
        }
    }
    setColor(4);
    cout << "Customer not found!\n";
    setColor(7);
}

void updateCustomer() 
{
    int id;
    setColor(1);
    cout << "\nEnter Customer ID to update: ";
    setColor(7);
    cin >> id;
    for (int i = 0; i < customerCount; i++) 
	{
        if (customers[i].customerID == id) 
		{
            cin.ignore();
            setColor(1);
            cout << "Enter New Name: ";
            setColor(7);
            getline(cin, customers[i].name);
            setColor(1);
            cout << "Enter New Contact Info: ";
            setColor(7);
            getline(cin, customers[i].contact);
            setColor(2);
            cout << "Customer record updated successfully!\n";
            setColor(7);
            return;
        }
    }
    setColor(4);
    cout << "Customer not found!\n";
    setColor(7);
}

void deleteCustomer() 
{
    int id;
    setColor(1);
    cout << "\nEnter Customer ID to delete: ";
    setColor(7);
    cin >> id;
    for (int i = 0; i < customerCount; i++) 
	{
        if (customers[i].customerID == id) 
		{
            for (int j = i; j < customerCount - 1; j++) 
			{
                customers[j] = customers[j + 1];
            }
            customerCount--;
            setColor(2);
            cout << "Customer record deleted successfully!\n";
            setColor(7);
            return;
        }
    }
    setColor(4);
    cout << "Customer not found!\n";
    setColor(7);
}

//Discount Functions
void addDiscount() 
{
	setColor(1);
    cout << "\nEnter Discount ID: ";
    setColor(7);
    cin >> discounts[discountCount].discountID;
    cin.ignore();
    setColor(1);
    cout << "Enter Discount Description: ";
    setColor(7);
    getline(cin, discounts[discountCount].description);
    setColor(1);
    cout << "Enter Discount Percentage: ";
    setColor(7);
    cin >> discounts[discountCount].percentage;
    discountCount++;
    setColor(2);
    cout << "Discount added successfully!\n";
    setColor(7);
}

void viewDiscounts() 
{
    if (discountCount == 0) 
	{
		setColor(4);
        cout <<"\nNo discounts available!\n";
        setColor(7);
        return;
    }
    setColor(3);
    cout << "\nDiscount Records\n";
    setColor(7);
    for (int i = 0; i < discountCount; i++) 
	{
		setColor(6);
        cout << "Discount ID: " << discounts[i].discountID;
        cout << ", Description: " << discounts[i].description;
        cout << ", Percentage: " << discounts[i].percentage << "%" << endl;
        setColor(7);
    }
}

void updateDiscount() 
{
    int id;
    setColor(1);
    cout << "\nEnter Discount ID to update: ";
    setColor(7);
    cin >> id;

    for (int i = 0; i < discountCount; i++) {
        if (discounts[i].discountID == id) {
            cin.ignore();
            setColor(1);
            cout << "Enter New Discount Description: ";
            setColor(7);
            getline(cin, discounts[i].description);
            setColor(1);
            cout <<"Enter New Discount Percentage: ";
            setColor(7);
            cin >> discounts[i].percentage;
            setColor(2);
            cout << "Discount updated successfully!\n";
            setColor(7);
            return;
        }
    }
    setColor(4);
    cout << "Discount not found!\n";
    setColor(7);
}

void deleteDiscount() 
{
    int id;
    setColor(1);
    cout << "\nEnter Discount ID to delete: ";
    setColor(7);
    cin >> id;

    for (int i = 0; i < discountCount; i++) 
	{
        if (discounts[i].discountID == id) 
		{
            for (int j = i; j < discountCount - 1; j++)
			{
                discounts[j] = discounts[j + 1];
            }
            discountCount--;
            setColor(2);
            cout << "Discount deleted successfully!\n";
            setColor(7);
            return;
        }
    }
    setColor(4);
    cout << "Discount not found!\n";
    setColor(7);
}
