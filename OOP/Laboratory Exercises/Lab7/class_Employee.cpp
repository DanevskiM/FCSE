#include <iostream>
#include <cstring>
using namespace std;
class Employee
{
protected:
    char *ime;
    int plata;
    int bonus;
    int iskustvo;
public:
    Employee(){}

    Employee(char *ime, int plata, int bonus, int iskustvo)
    {
        this->ime = new char[strlen(ime)+1];
        strcpy(this->ime, ime);
        this->plata = plata;
        this->bonus = bonus;
        this->iskustvo = iskustvo;
    }

    Employee(const Employee &e)
    {
        this->ime = new char[strlen(e.ime)+1];
        strcpy(this->ime, e.ime);
        this->plata = e.plata;
        this->bonus = e.bonus;
        this->iskustvo = e.iskustvo;
    }

    Employee &operator=(const Employee &e)
    {
        if(this!=&e)
        {
            delete [] ime;
            this->ime = new char[strlen(e.ime)+1];
            strcpy(this->ime, e.ime);
            this->plata = e.plata;
            this->bonus = e.bonus;
            this->iskustvo = e.iskustvo;
        }
        return *this;
    }

    ~Employee()
    {
        delete [] ime;
    }

    double getTotalSalary()
    {
        return plata+(bonus*iskustvo);
    }

    void print()
    {
        cout<<"Employee name: "<<ime<<endl;
        cout<<"Salary: "<<getTotalSalary()<<endl;
        cout<<"Experience: "<<iskustvo<<endl;
    }

    char *getIme()
    {
        return ime;
    }
};

class Manager : public Employee
{
private:
    char *oddel;
    int menBonus;
public:
    Manager() : Employee(){}

    Manager(char *ime, int plata, int bonus, int iskustvo, char *oddel, int menBonus)
            :Employee(ime, plata, bonus, iskustvo)
    {
        this->oddel = new char[strlen(oddel)+1];
        strcpy(this->oddel, oddel);
        this->menBonus = menBonus;
    }

    Manager(const Manager &m)
            :Employee(m)
    {
        this->oddel = new char[strlen(m.oddel)+1];
        strcpy(this->oddel, m.oddel);
        this->menBonus = m.menBonus;
    }

    Manager &operator=(const Manager &m)
    {
        if(this!=&m)
        {
            Employee::operator=(m);
            
            delete [] oddel;
            this->oddel = new char[strlen(m.oddel)+1];
            strcpy(this->oddel, m.oddel);
            this->menBonus = m.menBonus;
        }
        return *this;
    }

    Manager(const Employee &e, char *oddel, int menBonus)
            :Employee(e)
    {
        this->oddel = new char[strlen(oddel)+1];
        strcpy(this->oddel, oddel);
        this->menBonus = menBonus;
    }
    ~Manager()
    {
        delete [] oddel;
    }

    double getTotalManagerBonus()
    {
        return bonus+menBonus;
    }

    double getTotalSalary()
    {
        return plata+(getTotalManagerBonus()*iskustvo);
    }

    void print()
    {
        cout<<"Manager name: "<<getIme()<<endl;
        cout<<"Department: "<<oddel<<endl;
        cout<<"Salary: "<<getTotalSalary()<<endl;
        cout<<"Experience: "<<iskustvo<<endl;
    }
};
int main() {

    char name[20];
    int salary;
    int bonus;
    int experience;
    char department[50];
    int managerBonus;

    Employee * employees = new Employee[5];
    Manager * managers = new Manager[5];
    int n;
    cin >> n;

    if (n == 1) {

        cout << "EMPLOYEES:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i) {
            cin >> name >> salary >> bonus >> experience;
            employees[i] = Employee(name, salary, bonus, experience);
            employees[i].print();
            cout<<endl;
        }
    }
    else if (n == 2) {

        for (int i=0; i < 5; ++i){
            cin >> name >> salary >> bonus >> experience;
            cin >> department >> managerBonus;
            employees[i] = Employee(name, salary, bonus, experience);
            managers[i] = Manager(employees[i], department, managerBonus);
        }

        cout << "EMPLOYEES:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i) {
            employees[i].print();
            cout<<endl;
        }


        cout << "MANAGERS:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i) {
            managers[i].print();
            cout<<endl;
        }

    }
    else if (n == 3) {

        for (int i=0; i < 5; ++i){
            cin >> name >> salary >> bonus >> experience;
            cin >> department >> managerBonus;
            managers[i] = Manager(name, salary, bonus, experience, department, managerBonus);
        }
        cout << "MANAGERS:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i) {
            managers[i].print();
            cout<<endl;
        }

    }

    delete [] employees;
    delete [] managers;
}
