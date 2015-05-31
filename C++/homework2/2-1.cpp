// compile with "g++ -std=c++11"
// to_string in C++11 is used
using namespace std;
#include <iostream>
#include <string>
#include <stdexcept>

class Date {
    private:
        int year;
        int month;
        int day;

    public:
        Date(int year, int month, int day) {
            cout << "I'm in constructor of Date" << endl;
            this->year = year;
            if (month <= 0 || month > 12)
                throw out_of_range("Bad month value " + to_string(month)); 
            this->month = month;
            if (day <= 0 || day > 31)
                throw out_of_range("Bad day value " + to_string(day));
            this->day = day;
        }

        Date(const Date &date) {
            cout << "I'm in copy constructor of Date" << endl;
            year = date.year;
            month = date.month;
            day = date.day;
        }

        Date(void) {} // default constructor

        ~Date(void) {
            cout << "I'm in destructor of Date" << endl;
        }

        Date& operator=(const Date &date) {
            cout << "I'm in assignment operator of Date" << endl;
            year = date.year;
            month = date.month;
            day = date.day;
        }

        string to_str(void) {
            return to_string(year) + "-" + to_string(month) + "-" + to_string(day);
        }
};

class Employee {
    private:
        int no;
        string name;
        bool gender;
        Date birthdate;

    public:
        Employee(int no, string name, bool gender, int birthyear, int birthmonth, int birthday) {
            cout << "I'm in constructor of Employee" << endl;
            this->no = no;
            this->name = name;
            this->gender = gender;
            birthdate = Date(birthyear, birthmonth, birthday);
        }

        Employee(const Employee &employee) {
            cout << "I'm in copy constructor of Employee" << endl;
            this->no = employee.no;
            this->name = employee.name;
            this->gender = employee.gender;
            birthdate = employee.birthdate;
        }

        ~Employee(void) {
            cout << "I'm in destructor of Employee" << endl;
        }

        Employee& operator=(const Employee &employee) {
            cout << "I'm in assignment operator of Employee" << endl;
            no = employee.no;
            name = employee.name;
            gender = employee.gender;
            birthdate = employee.birthdate;
        }

        string to_str(void) {
            return "<Employee #" + to_string(no)
                + "> Name: " + name
                + ", Gender: " + (gender ? "male" : "female")
                + ", Birth: " + birthdate.to_str();
        }
};

int main() {
    try {
        Employee e1(1000, string("Alice"), false, 2015, 1, 1);
        cout << "e1: " << e1.to_str() << endl;
        Employee e2 = e1;
        cout << "e2: " << e2.to_str() << endl;
        Employee e3(1001, string("Bob"), true, 2015, 2, 2);
        cout << "e3: " << e3.to_str() << endl;
        e2 = e3;
        cout << "e2: " << e2.to_str() << endl;
        cout << "Trigger exception..." << endl;
        Employee e4(1002, string("Evil"), true, 2015, 15, 32);
        // should never reach here
        cout << "e4: " << e4.to_str() << endl;
    } catch(out_of_range& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
