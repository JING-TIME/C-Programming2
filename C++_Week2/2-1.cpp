#include <iostream>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date(int year, int month, int day) {
        this->year = year;
        this->month = month;
        this->day = day;
    }
    Date() {}
    ~Date() {}
    Date(const Date &date) {
        year = date.year;
        month = date.month;
        day = date.day;
    }
    Date& operator=(const Date &date) {
        year = date.year;
        month = date.month;
        day = date.day;
        return *this;
    }
    void show(){
        cout << year << month << day << endl;
    }
};

class Employee {
private:
    int id;
    string name;
    bool gender;
    Date birthdate;

public:
    Employee(int id, string name, bool gender, Date &birthdate) {
        this->id = id;
        this->name = name;
        this->gender = gender;
        this->birthdate = birthdate;
    }
    void show() {
        cout << id << endl;
        cout << name << endl;
        if (gender) cout << "male" << endl;
        else cout << "female" << endl;
        birthdate.show();
    }
};

int main()
{
    Date my_birthdate(1995, 12, 06);
    Employee jenny42(1, "jenny42", false, my_birthdate);
    jenny42.show();
    return 0;
}
