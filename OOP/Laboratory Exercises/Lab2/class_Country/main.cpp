#include <iostream>
#include <cstring>
using namespace std;
class Country
{
private:
    char name[100];
    char capital[100];
    float area;
    float population;
public:
    Country(){}
    Country(char *_name, char *_capital, float a, float p)
    {
        strcpy(name,_name);
        strcpy(capital,_capital);
        area = a;
        population = p;
    }
    ~Country(){}
    void setName(char *_name)
    {
        strcpy(name,_name);
    }
    void setCapital(char *_capital)
    {
        strcpy(capital,_capital);
    }
    void setArea(float a)
    {
        area = a;
    }
    void setPopulation(float p)
    {
        population = p;
    }
    char *getName()
    {
        return name;
    }
    char *getCapital()
    {
        return capital;
    }
    float getArea()
    {
        return area;
    }
    float getPopulation()
    {
        return population;
    }
    void display()
    {
        cout<<"Country: "<<name<<endl;
        cout<<"Capital: "<<capital<<endl;
        cout<<"Area: "<<area<<endl;
        cout<<"Population: "<<population<<endl;
    }
};
void sortCountries(Country *countries, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(countries[i].getArea()>countries[j].getArea())
            {
                Country pom = countries[i];
                countries[i] = countries[j];
                countries[j] = pom;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<"Country: "<<countries[i].getName()<<endl;
        cout<<"Capita: "<<countries[i].getCapital()<<endl;
        cout<<"Area: "<<countries[i].getArea()<<endl;
        cout<<"Population: "<<countries[i].getPopulation()<<endl;
    }
}

int main() {
    int n;
    cin >> n;
    Country countries[100];

    char name[100];
    char capital[100];
    double area;
    double population;

    for (int i = 0; i < n-1; i++)  {
        cin>>name;
        cin >> capital;
        cin >> area;
        cin>>population;

        // testing constructor with arguments
        countries[i] = Country(name, capital, area, population);

    }


    // testing set methods and display for last element
    cin>>name;
    cin >> capital;
    cin >> area;
    cin>>population;
    countries[n-1].setName(name);
    countries[n-1].setCapital(capital);
    countries[n-1].setArea(area);
    countries[n-1].setPopulation(population);

    cout<<"-->Testing set methods and display()"<<endl;
    countries[n-1].display();
    cout<<endl;

    cout<<"-->Testing sortCountries()"<<endl;
    sortCountries(countries,n);
    return 0;
}