#include <iostream>
#include <cstring>
#include <windows.h>

using std :: cin;
using std :: cout;
using std :: string;
using std :: endl;

class Admin;
class Jersey;
class customer_info;
class employee;

int no_of_Jersey = 0;
int employee_count = 0;

class Jersey
{
private:
    string Jersey_name;
    string Jersey_id;
    int Jersey_quantity;
    float Jersey_price;
    string Jersey_size;


public:
    void Jersey_set()
    {
        cout << "enter Jersey name:";
        cin >> Jersey_name;
        cout << "enter Jersey id:";
        cin >> Jersey_id;
        cout << "enter Jersey quantity:";
        cin >> Jersey_quantity;
        cout << "enter Jersey price:";
        cin >> Jersey_price;
        cout << "enter Jersey size:";
        cin >> Jersey_size;
    }
    void Jersey_get()
    {
        cout << "___________" << endl
             << endl;
        cout << "Jersey name: " << Jersey_name << endl;
        cout << "Jersey id: " << Jersey_id << endl;
        cout << "Jersey quantity:" << Jersey_quantity << endl;
        cout << "Jersey price:" << Jersey_price << endl;
        cout << "Jersey size:" << Jersey_size << endl;
        cout << "___________" << endl;
    }

    friend class Admin;
};
int no_of_customer=0;

class customer_info{
    private:
        string customer_name;
        string customer_mobile_no;
    public:
        void customer_set(string cn,string cmn){
            customer_name=cn;
            customer_mobile_no=cmn;
        }
        void customer_get(){
            cout<<"_________"<<endl<<endl;
            cout<<"Customer name :"<<customer_name<<endl;
            cout<<"Customer mobile no :"<<customer_mobile_no<<endl;
            cout<<"_________"<<endl;

        }
        friend class Admin;




};

class employee
{
    private:

        string employee_name;
        int employee_id;
        string employee_num;
        string employee_address;
        string employee_salary;
        friend class Admin;


    public:

        void add_employee()
        {
            cout << "Employee Name: ";
            cin >> employee_name;
            cout << endl;

            cout << "Employee ID : ";
            cin >> employee_id;
            cout << endl;

            cout << "Employee Number: ";
            cin >> employee_num;
            cout << endl;

            cout << "Employee Address: ";
            cin >> employee_address;
            cout << endl;

            cout << "Employee Salary: ";
            cin >> employee_salary;
            cout << endl;

            cout << "Successful" << endl;
        }

        void show_employee()
        {
            cout << "Employee Name    : " << employee_name << endl;
            cout << "Employee ID      : " << employee_id << endl;
            cout << "Employee Number  : " << employee_num << endl;
            cout << "Employee Address : " << employee_address << endl;
            cout << "Employee Salary  : " << employee_salary << endl;
        }

};


class Admin
{
private:
    Jersey Jersey_arr[101];
    customer_info customer_arr[101];
    employee employee_arr[101];

public:
    void add_Jersey()
    {
        Jersey_arr[no_of_Jersey].Jersey_set();
        no_of_Jersey++;
    }

    void dispaly_all_Jersey()
    {
        cout << "Our collection : " << endl;
        for (int i = 0; i < no_of_Jersey; i++)
        {
            Jersey_arr[i].Jersey_get();
        }
    }


    void search_a_Jersey(string j_n)
    {
        int x = 0;
        for (int i = 0; i < no_of_Jersey; i++)
        {
            if (Jersey_arr[i].Jersey_name == j_n)
            {
                Jersey_arr[i].Jersey_get();
                x++;
                break;
            }
        }
        if (x == 0)
        {
            cout << "Sorry for it's recent unavailability." << endl;
        }
    }

    void add_employee()
    {
        employee_arr[employee_count++].add_employee();
    }

    void search_employee(int e_n)
    {
        int flag = 0;
        for(int i=0 ; i<employee_count ; i++){
            if(employee_arr[i].employee_id == e_n)
            {
                employee_arr[i].show_employee();
                flag = 1;
                break;
            }
        }

        if(flag == 0)
            cout << "No Employees Found." << endl;
    }

    void display_all_employee()
    {
        cout << "Employee List :" << endl;
        for(int i=0 ; i<employee_count ; i++){
            employee_arr[i].show_employee();
        }
    }

    void buy_a_Jersey(string j_m){
        int x=0;
        for(int i=0;i<no_of_Jersey;i++){
            if(Jersey_arr[i].Jersey_name==j_m){
                x++;
                Jersey_arr[i].Jersey_get();
                if(Jersey_arr[i].Jersey_quantity==0){
                    cout<<"Out Of stock."<<endl;
                }else{
                string customer_name;
                string phone_number;
                char op;
                int quantity;
                cout<<"We have this one."<<endl;
                cout<<"place your order :"<<endl;
                cout<<"Customer Name : ";
                cin>>customer_name;
                cout<<"Customer Phone Number : ";
                cin>>phone_number;
                cout<<"Enter quantity (as per written in the Jersey List):";
                cin>>quantity;
                cout<<"bill: "<<(Jersey_arr[i].Jersey_price*quantity)<<endl;

                cout<<"Are you sure? (y/n): ";
                cin>>op;





                if(op=='y'){
                    cout<<"Succesful."<<endl;
                    customer_arr[no_of_customer].customer_set(customer_name,phone_number);
                    no_of_customer++;
                    Jersey_arr[i].Jersey_quantity=Jersey_arr[i].Jersey_quantity-quantity;
                    break;
                }else{
                    cout<<"Something went wrong."<<endl;
                    break;
                }
            }

          }

        }
        if(x==0){
            cout << "Sorry for it's recent unavailability." << endl;
        }

    }

    void show_all_customer(){
        cout<<"Customer Record :"<<endl;
        int x=0;
        for(int i=0;i<no_of_customer;i++){
            cout<<"customer "<<i+1<<":"<<endl;
            customer_arr[i].customer_get();
            x++;
        }
        if(x==0){
            cout<<"No customers yet."<<endl;
        }
    }

};


int main()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    Admin sm;
    char choice;
    int operation;

    do
    {
        SetConsoleTextAttribute(h,7);

        cout << "  LXTER " << endl;
        cout << "Get ready to level up your style..\n\n\n\n" << endl;

        SetConsoleTextAttribute(h,4);

        cout << "#1   Admin." << endl;

        SetConsoleTextAttribute(h,8);

        cout << "#2   Search Kits." << endl;
        cout << "#3   Buy Kits." << endl;
        cout << "#4   Show Collection." << endl;
        cout << "#5   About us." << endl;
        cout << "#6   Exit.\n" << endl;

        cout << "Press (1~6)" << endl;
        cin >> operation;

        switch (operation)
        {
        case 1:

        {
            SetConsoleTextAttribute(h,4);

            cout << "Password:";
            string password{"78651524"};

            string key;
            cin >> key;
            cout << endl;

            if(key == password){
            SetConsoleTextAttribute(h,7);

            cout << "#1    Add Kits." << endl;
            cout << "#2    Show Customer records" << endl;
            cout << "#3    Add Employee" << endl;
            cout << "#4    Search Employee" << endl;
            cout << "#5    Display all Employee\n" << endl;

            cout << "Press (1~5)";

            cout << endl;

            int admin_n;
            cin >> admin_n;

            switch(admin_n)
            {
                case 1:
                    int num;
                    cout << "How many kits to add?" << endl;;
                    cin >> num;
                    for (int i = 0; i < num; i++)
                    {
                        cout << "Jersey " << i + 1 << " :" << endl;
                    sm.add_Jersey();
                    }
                    cout << "Successful.\n";
                    break;

                case 2:
                    sm.show_all_customer();
                    break;

                case 3:
                    sm.add_employee();
                    break;

                case 4:
                    int e_n;
                    cout << "Input employee ID : ";
                    cin >> e_n;
                    sm.search_employee(e_n);
                    break;

                case 5:
                    sm.display_all_employee();
                    break;

                default:
                    cout << "Invalid Operation";
            }

        }

        else{
            cout << "Incorrect Password" << endl;
        }
        break;
}


        case 2:
            {
            string j_m;
            cout << "Team names like this. ";
            cout << "(Manchester_United ,Bayern_Munich...)" << endl;
            cout << "Enter :";

            cin >> j_m;
            sm.search_a_Jersey(j_m);
            break;
            }

        case 3:
        {
            string jn;
            cout<<"Kit name:";
            cin>>jn;
            sm.buy_a_Jersey(jn);
            break;
        }

        case 4:

            sm.dispaly_all_Jersey();
            break;


        case 5:

            SetConsoleTextAttribute(h,12);


            cout << "Welcome to LXTER. \nReady to gear up your outook? Just at the perfect place. \nExplore and grab your desired quality product.\n"<< endl;
            cout << "Helpline :\nTelephone : +880442856056\nPhone   :   +8801746734906\n" << endl;
            cout << "Owner : Andrew Lenon\nPhone : +8801845786542" << endl;

            break;

        SetConsoleTextAttribute(h,7);

        case 6:
            SetConsoleTextAttribute(h,3);


            cout << " \tThank you for visiting.\t " << endl;

            SetConsoleTextAttribute(h,7);

            return 0;
            break;



        default:
            cout << "Invalid operation selected. " << endl;


        }


        cout << "Explore other options? (y/n): ";
        cin >> choice;
        system("cls");
    } while (choice == 'y' || choice == 'Y');

    SetConsoleTextAttribute(h,7);

    return 0;
}



