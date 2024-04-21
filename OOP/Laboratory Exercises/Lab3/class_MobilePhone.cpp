#include <iostream>
#include <cstring>
using namespace std;
class MobilePhone
{
private:
    char model[20];
    int brModel;
    int year;
public:
    MobilePhone(char *_model="", int _brModel=0, int _year=0)
    {
        strcpy(model, _model);
        brModel = _brModel;
        year = _year;
    }
    MobilePhone(const MobilePhone &mob)
    {
        strcpy(model, mob.model);
        brModel = mob.brModel;
        year = mob.year;
        cout<<"mjau"<<endl;
    }
    ~MobilePhone(){}

    void print()
    {
        cout<<model<<","<<brModel<<", release year: "<<year<<endl;
    }
};

class Owner
{
private:
    char firstName[20];
    char secondName[20];
    MobilePhone mobile;
public:
    Owner(){}
    Owner(char *firstName, char *secondName, MobilePhone & mob)
    {
        strcpy(this->firstName, firstName);
        strcpy(this->secondName, secondName);
        mobile = mob;
    }
    ~Owner(){}

    char *getfirstName()
    {
        return firstName;
    }
    char *getsecondName()
    {
        return secondName;
    }
    MobilePhone getmobile()
    {
        return mobile;
    }

    void print()
    {
        cout<<firstName<<" "<<secondName<<" has a mobile phone:"<<endl;
        mobile.print();
    }
};

int main()
{
    int n;
    int brModel;
    int godina;
    char ime[20];
    char prezime[20];
    char imeNaModel[20];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>imeNaModel>>brModel>>godina>>ime>>prezime;
        MobilePhone m1(imeNaModel, brModel, godina);
        MobilePhone mobile(m1);
        Owner o(ime,prezime,m1);
        Owner owner(o);
        o.print();
    }
    return 0;
}