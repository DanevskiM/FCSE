#include <iostream>
#include <cstring>
using namespace std;
class Film
{
private:
    char name[100];
    float rating;
    float revenue;
public:
    Film(){}
    Film(char *_name, float rat, float rev)
    {
        strcpy(name, _name);
        rating = rat;
        revenue = rev;
    }
    ~Film(){}
    void setName(char *_name)
    {
        strcpy(name, _name);
    }
    void setRating(float rat)
    {
        rating = rat;
    }
    void setRevenue(float rev)
    {
        revenue = rev;
    }
    char *getIme()
    {
        return name;
    }
    float getRating()
    {
        return rating;
    }
    float getRevenue()
    {
        return revenue;
    }
    void display()
    {
        cout<<"Name of film: "<<name<<endl;
        cout<<"Rating: "<<rating<<endl;
        cout<<"Revenue: "<<revenue<<endl;
    }
};

void printMostPopularFilm(Film *films, int n)
{
    int najvekje=0;
    int pom = 0;
    for(int i=0;i<n;i++)
    {
            if(films[i].getRevenue()>najvekje)
            {
                najvekje = films[i].getRevenue();
                pom = i;
            }
    }
    cout<<"Name of film: "<<films[pom].getIme()<<endl;
    cout<<"Rating: "<<films[pom].getRating()<<endl;
    cout<<"Revenue: "<<films[pom].getRevenue()<<endl;
}

int main() {
    int n;
    cin >> n;
    Film films[100];

    char name[100];
    double rating;
    double revenue;

    for (int i = 0; i < n-1; i++)  {
        cin>>name;
        cin >> rating;
        cin >> revenue;

        // testing constructor with arguments
        films[i] = Film(name, rating, revenue);

    }


    // testing set methods and display for last element
    cin>>name;
    cin >> rating;
    cin >> revenue;
    films[n-1].setName(name);
    films[n-1].setRating(rating);
    films[n-1].setRevenue(revenue);

    cout<<"-->Testing set methods and display()"<<endl;
    films[n-1].display();
    cout<<endl;

    cout<<"-->Testing printMostPopularFilm()"<<endl;
    printMostPopularFilm(films , n);
    return 0;
}