/*
Да се имплементира класа Employee за која се чува:

    име (низа од карактери)
    години (цел број)

Во класата да се имплементира виртуелна функција displayInfo() која на екран печати информации за вработениот.

Потоа да се имплементира класа Payable за која се чува:

    плата (децимален број)

За класата да се креира чисто виртуелна функција calculateSalary()

Од овие класи потребно е да се изведат Developer и Manager. 

За класата Developer дополнително се чува и програмскиот јазик (низа од карактери). Потребно е да се препокријат соодветните функции. Платата се пресметува така што од основната плата се одзема данок од 10%.

За класата Manager дополнително се чува и број на оддели за кои е одговорен. Потребно е да се препокријат соодветните функции. Платата се пресметува така што на основната плата се додава бонус од 5% за секој еден оддел. 
*/
#include <iostream>
#include <cstring>

using namespace std;
class Employee
{
protected:
    char name[30];
    int godini;
public:
    Employee()
    {
        strcpy(this->name, "empty");
        this->godini = 0;
    }

    Employee(char *name, int godini)
    {
        strcpy(this->name, name);
        this->godini = godini;
    }

    virtual void displayInfo(){}
};

class Payable
{
protected:
    float plata;
public:
    Payable()
    {
        this->plata = plata;
    }

    Payable(float plata)
    {
        this->plata = plata;
    }

    virtual float calculateSalary()=0;
};

class Developer : public Employee, public Payable
{
private:
    char progJazik[30];
public:
    Developer()
    {
        strcpy(this->progJazik, progJazik);
    }

    Developer(char *name, int godini, float plata, char *progJazik)
    : Employee(name,godini)
    , Payable(plata)
    {
        strcpy(this->progJazik, progJazik);
    }

    float calculateSalary()
    {
        return plata - (plata/10);
    }

    void displayInfo()
    {
        cout<<"-- Developer Information --"<<endl; 
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<godini<<endl;
        cout<<"Salary: $"<<calculateSalary()<<endl;
        cout<<"Programming Language: "<<progJazik<<endl;
    }
};

class Manager : public Employee, public Payable
{
private:
    int brOddeli;
public:
    Manager()
    {
        this->brOddeli = brOddeli;
    }

    Manager(char *name, int godini, float plata, int brOddeli)
    : Employee(name, godini)
    , Payable(plata)
    {
        this->brOddeli = brOddeli;
    }

    float calculateSalary()
    {
        return plata +(plata * 0.05 * brOddeli);
    }

    void displayInfo()
    {
        cout<<"-- Manager Information --"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<godini<<endl;
        cout<<"Salary: $"<<calculateSalary()<<endl;
        cout<<"Number of Departments: "<<brOddeli<<endl;
    }
};
double biggestSalary(Payable* payable[], int n) {
    Payable* maxSalaryEmployee = payable[0];

    for (int i = 1; i < n; i++) {
        if (payable[i]->calculateSalary() > maxSalaryEmployee->calculateSalary()) {
            maxSalaryEmployee = payable[i];
        }
    }

    return maxSalaryEmployee->calculateSalary();
}

int main()
{
    Payable* payable[5];
    Developer developers[5];
    Manager managers[5];
    int j=0, k=0;
    for(int i=0; i<5; i++)
    {
        char name[50];
        int age;
        double salary;
        cin>>name>>age>>salary;
        if(i%2==0)
        {
            char programmingLanguage[50];
            cin>>programmingLanguage;
            developers[j]=Developer(name, age, salary, programmingLanguage);
            developers[j].displayInfo();
            payable[i]=&developers[j];
            j++;
        }
        else {
            int numberOfDepartments;
            cin>>numberOfDepartments;
            managers[k]=Manager(name, age, salary, numberOfDepartments);
            managers[k].displayInfo();
            payable[i]=&managers[k];
            k++;
        }
    }
    cout<<endl<<"Biggest Salary: "<<biggestSalary(payable, 5);
    return 0;
}
