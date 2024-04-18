#include <iostream>
#include <cstring>
using namespace std;
class BasketballPlayer
{
private:
    char ime[20]{};
    char prezime[20]{};
    int dres;
    int poeni1;
    int poeni2;
    int poeni3;
public:
    //BasketballPlayer();
    BasketballPlayer(char name[20], char surname[20], int num, int p1, int p2, int p3)
    {
        strcpy(ime,name);
        strcpy(prezime, surname);
        dres = num;
        poeni1 = p1;
        poeni2 = p2;
        poeni3 = p3;
    }

    int avg_pts()
    {
        return (poeni1+poeni2+poeni3)/3;
    }
    void printInfo()
    {
        cout<<"Player: "<<ime<<" "<<prezime<<" with number: "<<dres<<" has "<<avg_pts()<<" points on average"<<endl;
    }

};

int main()
{
    char ime[20]{};
    char prezime[20]{};
    int dres;
    int poeni1;
    int poeni2;
    int poeni3;
    cin>>ime>>prezime>>dres>>poeni1>>poeni2>>poeni3;
    BasketballPlayer b1(ime, prezime, dres, poeni1, poeni2, poeni3);
    b1.printInfo();
    return 0;
}