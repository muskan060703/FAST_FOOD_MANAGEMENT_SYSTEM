#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <ctime>

using namespace std;

// Global variables for inventory
// Purchasing variables 
int p_p = 0, p_b = 0, p_s = 0, p_i = 0, p_c = 0; 

//sales variables
int s_p=0,s_b=0,s_s=0,s_i=0,s_c=0;

//total pricing of today's sales of each items 
int p=0,b=0,s=0,i=0,c=0;

void adminLogin();
void updateUserOrder();
void updateInventory();
void generateBill();
string getCurrentDateTime();
void first();
void menu_for_admin();
void today_sales();

string getHiddenInput() {
    string password = "";
    char ch;
    while (true) {
        ch = _getch();
        if (ch == 13) { 
            cout << endl;
            break;
        }
        if (ch == '\b' && !password.empty()) { 
            cout << "\b \b";
            password.pop_back();
        } else if (ch != '\b') {
            cout << "*";
            password.push_back(ch);
        }
    }
    return password;
}

void adminLogin() {
    string username, password;
    cout << "\nEnter admin username: ";
    cin >> username;
    cout << "Enter admin password: ";
    password = getHiddenInput(); 

    if (username == "admin" && password == "admin123") 
    {
        cout<<"Login successfully press enter ";
        cin.ignore();
        cin.get(); 
        
        menu_for_admin();
    }
     else 
    {
        cout << "Invalid username or password.";
        cin.ignore();
        cin.get(); 
        first();
    }
}

void menu_for_admin()
{   
    system("cls");
    cout << "\t\t\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|            CONTROL PANEL  :                |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n\n\n\n";

    cout << "\t\t\t\t\t|--------------------------------------------|\n";
    cout << "\t\t\t\t\t|          1)UPDATE TODAY'S INVENTORY        |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|          2)TODAY'S SALE                    |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|          3)EXIT                            |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|          4)MAIN MENU                       |\n";
    cout << "\t\t\t\t\t|--------------------------------------------|\n";

    int choice;
    cout << "\t\t\t\t\t ____________________________________________ \n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|            ENTER YOUR CHOICE :             |\n";
    cout << "\t\t\t\t\t|____________________________________________|\n\n\n\n";
    cin>>choice;

    switch (choice)
    {
    case 1:
        updateInventory();
        break;
    
    case 2:
        today_sales();
        break;
    
    case 3: 
        cout << "\n\nExiting...\n";
        exit(0);
        break;
    case 4:
        first();
        break;
    default:
    cout<<"Invalid input logging out ..... ";
    cin.ignore();
    cin.get(); 
    first();
    break;
    }
}

void today_sales()
{
    system("cls");

    cout << "\t\t\t\t\t ____________________________________________ \n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|    TODAYS'S INVENTORY & SALES DETAILS :    |\n";
    cout << "\t\t\t\t\t|____________________________________________|\n\n\n\n";

    cout<<"\n\n Purchased Pizza Quantity : "<<p_p;
    cout<<"\n Sales Pizza Quantity : "<<s_p;
    cout<<"\n Remaining Pizza Quantity : "<<p_p-s_p;
    cout<<"\n Total Pizza Price in a Whole Day :"<<p;

    cout<<"\n\n Purchased Burger Quantity : "<<p_b;
    cout<<"\n Sales Burger Quantity : "<<s_b;
    cout<<"\n Remaining Burger Quantity : "<<p_b-s_b;
    cout<<"\n Total Burger Price in a Whole Day :"<<b;

    cout<<"\n\n Purchased Sandwich Quantity : "<<p_s;
    cout<<"\n Sales Sandwich Quantity : "<<s_s;
    cout<<"\n\n Remaining Sandwich Quantity : "<<p_s-s_s;
    cout<<"\n\n Total Sandwich Price in a Whole Day :"<<s;

    cout<<"\n\n Purchased Ice-Cream Quantity : "<<p_i;
    cout<<"\n\n Sales Ice-Cream Quantity : "<<s_i;
    cout<<"\n\n Remaining Ice-Cream Quantity : "<<p_i-s_i;
    cout<<"\n\n Total Ice-Cream Price in a Whole Day :"<<i;

    cout<<"\n\n Purchased Cake Quantity : "<<p_c;
    cout<<"\n\n Sales Cake Quantity : "<<s_c;
    cout<<"\n\n Remaining Cake Quantity : "<<p_c-s_c;
    cout<<"\n\n Total Cake Price in a Whole Day :"<<c;

    cout<<"\n\n\n \t\t\t Total Day Price: "<<p+b+s+i+c;
    cin.ignore();
    cin.get(); 
    first();      
}

void updateInventory() 
{
    system("cls");
    cout << "\t\t\t\t\t ____________________________________________ \n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|   ENTER TODAYS'S INVENTORY DETAILS :       |\n";
    cout << "\t\t\t\t\t|____________________________________________|\n\n\n\n";

    cout << "\nNumber of Pizza: ";
    cin >> p_p;
    cout << "Number of Burger: ";
    cin >> p_b;
    cout << "Number of Sandwich: ";
    cin >> p_s;
    cout << "Number of Ice-Cream: ";
    cin >> p_i;
    cout << "Number of Cakes: ";
    cin >> p_c;

    // Save inventory to file with current date and time
     ofstream inventoryFile("inventory.txt", ios::app); // Append mode
    if (inventoryFile.is_open()) {
        inventoryFile << "\n\nInventory Update (" << getCurrentDateTime() << "):\n";
        inventoryFile << "Pizza: " << p_p << "\n";
        inventoryFile << "Burger: " << p_b << "\n";
        inventoryFile << "Sandwich: " << p_s << "\n";
        inventoryFile << "Ice-Cream: " << p_i << "\n";
        inventoryFile << "Cakes: " << p_c << "\n";
        inventoryFile.close();
        cout << "\nInventory updated successfully!";
    } else {
        cout << "\nUnable to open file for writing.";
    }

    cin.ignore();
    cin.get(); 

    first();

}

//FOR CURRENT DATE AND TIME 
string getCurrentDateTime() {
    time_t now = time(0); //object of time  this will recive the time in second passed from 1970
    tm *ltm = localtime(&now); //to get the local time stored into the pointer 
    string dateTime = to_string(1900 + ltm->tm_year) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(ltm->tm_mday) + " " +
                      to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
    return dateTime;
}

void userLogin() {
    system("cls");
    cout << "\nUser login successful!";

    string name;
    string phone;
    int choice;
    int q;
    cout<<"Enter your Name:      ";
    cin>>name;
    cout<<"Enter your Phone-no:     ";
    cin>>phone;
    cout<<"\n\n\n";

    p:
    cout << "\t\t\t\t\t ____________________________________________ \n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|                  YOUR ORDER                |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|____________________________________________|\n\n\n";


    cout << "\t\t\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|            CONTROL PANEL  :                |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n\n\n\n";

    cout << "\t\t\t\t\t|--------------------------------------------|\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|          1)PIZZA                           |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|          2)BURGER                          |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|          3)SANDWICH                        |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|          4)ICE-CREAM                       |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|          5)CAKE                            |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|          6)YOUR ORDER DETAILS              |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|          7)EXIT                            |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|          8)MAIN MENU                       |\n";
    cout << "\t\t\t\t\t|--------------------------------------------|\n";

    cout << "\t\t\t\t\t ____________________________________________ \n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|            ENTER YOUR CHOICE :             |\n";
    cout << "\t\t\t\t\t|____________________________________________|\n\n\n\n";
    cin>>choice;


    switch (choice)
    {
    case 1:
        cout<<"\n\nEnter Pizza Quantity : ";
        cin>>q;
        if((p_p-s_p)>=q)
        {
        s_p += q;
         p += q*700;
        cout<<"\n\n\n\t\t\t"<<q<<" Pizza Sales Thank You for Your Order !!!!!!!!";
        cin.ignore();
        cin.get(); 
        }
        else
            {
                cout<<"\n\n\n\t\t\t\t SORRY! "<<p_p-s_p<<" Pizza Remaining in Restaurant....... ";
                cin.ignore();
                cin.get(); 
            }
        break;
    case 2:
        cout<<"\n\nEnter Burger Quantity : ";
            cin>>q;
            if((p_b-s_b)>=q)
            {
            s_b += q;
            b += q*100;
            cout<<"\n\n\n\t\t\t"<<q<<" Burger Sales Thank You for Your Order !!!!!!!!";
            cin.ignore();
            cin.get(); 
            }
            else
            {
             cout<<"\n\n\n\t\t\t\t SORRY! "<<p_b-s_b<<" Burger Remaining in Restaurant....... ";
            cin.ignore();
            cin.get(); 
            }
        break;
    case 3:
        cout<<"\n\nEnter Sandwich Quantity : ";
            cin>>q;
            if((p_s-s_s)>=q)
            {
            s_s += q;
            s += q*150;
            cout<<"\n\n\n\t\t\t"<<q<<" Sandwich Sales Thank You for Your Order !!!!!!!!";
            cin.ignore();
            cin.get();
            }
            else
            {
            cout<<"\n\n\n\t\t\t\t SORRY! "<<p_s-s_s<<" Sandwich Remaining in Restaurant....... ";
            cin.ignore();
            cin.get();
            }
        break;
    case 4:
        cout<<"\n\nEnter Ice-Cream Quantity : ";
            cin>>q;
            if((p_i-s_i)>=q)
            {
            s_i += q;
            i += q*120;
            cout<<"\n\n\n\t\t\t"<<q<<" Ice-Cream Sales Thank You for Your Order !!!!!!!!";
            cin.ignore();
            cin.get();
            }
            else
            {
            cout<<"\n\n\n\t\t\t\t SORRY! "<<p_i-s_i<<" Ice-Cream Remaining in Restaurant....... ";
            cin.ignore();
            cin.get();
            }
        break;
    case 5:
        cout<<"\n\nEnter Cake Quantity : ";
            cin>>q;
            if((p_c-s_c)>=q)
            {
            s_c += q;
            c += q*600;
            cout<<"\n\n\n\t\t\t"<<q<<" Cake Sales Thank You for Your Order !!!!!!!!";
            cin.ignore();
            cin.get();
            }
            else
            {
            cout<<"\n\n\n\t\t\t\t SORRY! "<<p_c-s_c<<" Cake Remaining in Restaurant....... ";
            cin.ignore();
            cin.get();
            }
    break;
    case 7:
                // Exit
                cout << "\n\nExiting...\n";
                exit(0);
                break;
    case 8:
            first();
            break;
    case 6:
                // Display order details
        cout << "\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        cout << "\t\t\t\t\t^           YOUR ORDER DETAILS               ^\n";
        cout << "\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n\n";
        cout << "\t\t\t\t-------------------\n";
        cout << "\t\t\t\tPizza: " << s_p << "\n";
        cout << "\t\t\t\tBurger: " << s_b << "\n";
        cout << "\t\t\t\tSandwich: " << s_s << "\n";
        cout << "\t\t\t\tIce-Cream: " << s_i << "\n";
        cout << "\t\t\t\tCake: " << s_c << "\n";
        cout << "\t\t\t\tTotal Amount: " << (p + b + s + i + c) << "\n";
                
            // Generate a copy of the bill
        ofstream userBill("bill.txt", ios::app); // Append mode
        if (userBill.is_open())
         { 
            userBill << "\n\n\n\t\t\t\tYOUR ORDER DETAILS\n";
            userBill << "\t\t\t\t-------------------\n";
            userBill << "\t\t\t\tPizza: " << s_p << "\n";
            userBill << "\t\t\t\tBurger: " << s_b << "\n";
            userBill << "\t\t\t\tSandwich: " << s_s << "\n";
            userBill << "\t\t\t\tIce-Cream: " << s_i << "\n";
            userBill << "\t\t\t\tCake: " << s_c << "\n";
            
            userBill << "\t\t\t\tTotal Amount: " << (p + b + s + i + c) << "\n";
            cout << "\n\nBill generated successfully!";
        } 
        else 
        {
            cout << "\n\nUnable to generate bill.";
        }
 
        cout << "\n\nPress Enter to continue...";
        cin.ignore();
        cin.get(); 
        break;
    }
    goto p;
}

void first()
{
    system("cls");
    cout << "\t\t\t\t\t ____________________________________________ \n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|  FAST FOOD RESTAURANT MANAGEMENT SYSTEM    |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|____________________________________________|\n\n\n\n";


    cout << "\t\t\t\t\t**********************************************\n";
    cout << "\t\t\t\t\t*                                            *\n";
    cout << "\t\t\t\t\t*                LOGIN PANEL:                *\n";
    cout << "\t\t\t\t\t*      1. ADMIN                              *\n";
    cout << "\t\t\t\t\t*      2.USER                                *\n";
    cout << "\t\t\t\t\t**********************************************\n\n\n\n";

    cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\t\t\t\t\t@                                            @\n";
    cout << "\t\t\t\t\t@            ENTER YOUR CHOICE :             @\n";
    cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n";
    int choice;
    cin >> choice;

    if (choice == 1) 
    { 
        // Admin login
        adminLogin();
    } 
    
    else if (choice == 2)
     { 
        // User login
        userLogin();
    } 
    
    else 
    {
        cout << "Invalid choice. Please try again.";
    }

}
int main() {
    
    first();
    getch(); 
    return 0; 
}
