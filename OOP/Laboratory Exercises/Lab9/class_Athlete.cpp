/*
Да се имплементира класа Athlete за која се чува:

    name (низа од карактери)
    age (int)

Во класата да се имплементира виртуелна функција void displayInfo() која на екран печати информации за дадениот атлетичар.

Потребно е да се имплементираат класите Runner и Jumper кои што ќе наследуваат од класата Athlete.

За класата Runner дополнително се чуваат:

    speed - брзина на играчот(double)

Функцијата displayInfo() ја вклучува и брзината.

За класата Jumper дополнително се чуваат:

    height- висина на скокачот (double)

Функцијата displayInfo() ја вклучува и висината.

Потребно е да се имплементира класата AllRoundAthlete која што ќе наследува од класите Runner и Jumper.

За класата AllRoundAthlete дополнително се чува:

    stamina - стамина на AllRound играчот(int)


Функцијата displayInfo() печати вклучувајќи го и нивото на стамина.
Да се направи глобална функцијаAthlete* findAthleteWithMaxValue(Athlete** athletes, int n) - најголема вредност за тркачите се одредува според брзина, додека кај скокачите според висина, треба да се најде играчот кој ќе има најголема вредност и да се врати покажувач кон него.
*/
#include <iostream>
#include <cstring>

using namespace std;
class Athlete
{
protected:
    char name[30];
    int age;
public:
    Athlete()
    {
        strcpy(this->name, "empty");
        this->age = 0;
    }

    Athlete(char *name, int age)
    {
        strcpy(this->name, name);
        this->age = age;
    }

    virtual void displayInfo(){}
};

class Runner : public Athlete
{
protected:
    double speed;
public:
    Runner()
    {
        this->speed = 0;
    }

    Runner(char *name, int age, double speed)
    : Athlete(name, age)
    {
        this->speed = speed;
    }

    void displayInfo()
    {
        cout<<"Athlete: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Speed: "<<speed<<" mph"<<endl;
    }
    
    double getBrzina()
    {
        return speed;
    }
};

class Jumper : public Athlete
{
protected:
    double height;
public:
    Jumper()
    {
        this->height = height;
    }

    Jumper(char *name, int age, double height)
    : Athlete(name, age)
    {
        this->height = height;
    }

    void displayInfo()
    {
        cout<<"Athlete: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Height: "<<height<<"m"<<endl;
    }
    
    double getHeight()
    {
        return height;
    }
};

class AllRoundAthlete : public Runner, public Jumper
{
private:
    int stamina;
public:
    AllRoundAthlete()
    {
        this->stamina = 0;
    }

    AllRoundAthlete(char *name, int age, double speed, double height, int stamina)
    : Runner(name, age, speed)
    , Jumper(name, age, height)
    {
        this->stamina = stamina;
    }

    void displayInfo()
    {
        cout<<"Athlete: "<<Runner::name<<endl;
        cout<<"Age: "<<Runner::age<<endl;
        cout<<"Speed: "<<Runner::speed<<" mph"<<endl;
        cout<<"Height: "<<height<<"m"<<endl;
        cout<<"Stamina: "<<stamina<<endl;
    }
};

Athlete* findAthleteWithMaxValue(Athlete** athletes, int n)
{
    Athlete *find = athletes[0];
    double max = 0;
    int ind;
    for(int i=0;i<n;i++)
    {
        Runner *r = dynamic_cast<Runner *>(athletes[i]);
        if(r != 0 && max < r->getBrzina())
        {
            ind = i;
            max = r->getBrzina();
        }
        else
        {
            Jumper *j = dynamic_cast<Jumper *>(athletes[i]);
            if(j != 0 && max <j->getHeight()) 
            {
                ind = i;
                max = j->getHeight();
            }
        }
    }
    return athletes[ind];
    
}


int main() {
    char name[50];
    int age;
    double speed;
    double height;
    int n;
    int choice;

    cin>>choice;
    if(choice==1)
    {
        cin>>name;
        cin>>age;
        AllRoundAthlete allRoundAthlete(name, age, 13.6, 1.80, 6);
        allRoundAthlete.displayInfo();
    }
    else {

        cin >> n;

        Athlete **athletes = new Athlete *[n];
        for (int i = 0; i < n; i++) {
            cin >> choice;
            if (choice == 1) {
                cin >> name >> age >> speed;

                athletes[i] = new Runner(name, age, speed);
            } else {
                cin >> name >> age >> height;

                athletes[i] = new Jumper(name, age, height);
            }

        }

        findAthleteWithMaxValue(athletes, n)->displayInfo();

    }


    return 0;
}