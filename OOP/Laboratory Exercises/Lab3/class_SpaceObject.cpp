#include <iostream>
#include <cstring>
using namespace std;
class SpaceObject
{
private:
    char name[100];
    char type[100];
    int distanceFromEarth;
public:
    SpaceObject(){}
    SpaceObject(char *_name, char *_type, int dist)
    {
        strcpy(this->name,_name);
        strcpy(this->type, _type);
        this->distanceFromEarth = dist;
    }
    SpaceObject(const SpaceObject &ob)
    {
        strcpy(name, ob.name);
        strcpy(type, ob.type);
        distanceFromEarth=ob.distanceFromEarth;
    }
    char *getName()
    {
        return name;
    }
    char *getType()
    {
        return type;
    }
    int getDistance()
    {
        return distanceFromEarth;
    }

    void print()
    {
        cout<<getName()<<getType()<<" - distance: "<<getDistance()<<" light years away from Earth"<<endl;
    }
};

class Alien
{
private:
    char name[100];
    int age;
    char homePlanet[100];
    int numObj;
    SpaceObject spaceObjects[100];
public:
    Alien(){}
    Alien(char *_name, int god, char *_domPlanet, int brObj, SpaceObject objects[100])
    {
        strcpy(name, _name);
        age = god;
        strcpy(homePlanet, _domPlanet);
        numObj = brObj;
        for(int i=0;i<numObj;i++)
        {
            spaceObjects[i]=objects[i];
        }
    }
    Alien(const Alien &alien)
    {
        strcpy(name, alien.name);
        age = alien.age;
        strcpy(homePlanet, alien.homePlanet);
        numObj = alien.numObj;
        for(int i=0;i<numObj;i++)
        {
            spaceObjects[i]=alien.spaceObjects[i];
        }
    }
    ~Alien(){}

    char *getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    char *getGomePlanet()
    {
        return homePlanet;
    }

    SpaceObject getObjectClosestToEarth()
    {
        SpaceObject max = spaceObjects[0];
        for(int i=1;i<numObj;i++)
        {
            if(spaceObjects[i].getDistance()<max.getDistance())
            {
                max = spaceObjects[i];
            }
        }
        return max;
    }

    void print()
    {
        cout<<"Alien name: "<<getName()<<endl;
        cout<<"Alien age: "<<getAge()<<endl;
        cout<<"Alien homePlanet: "<<getGomePlanet()<<endl;
        cout<<"Favourite space object closest to earth: ";
        getObjectClosestToEarth().print();
    }
};

int main()
{
    char name[100], homePlanet[100];
    int age, numObj;
    cin>>name>>age>>homePlanet>>numObj;

    SpaceObject spaceObjects[100];
    for(int i=0; i<numObj; i++)
    {
        char spaceObjectName[100], spaceObjectType[100];
        int distanceFromEarth;
        cin>>spaceObjectName>>spaceObjectType>>distanceFromEarth;

        spaceObjects[i]=SpaceObject(spaceObjectName, spaceObjectType, distanceFromEarth);
    }

    Alien alien;

    alien=Alien(name, age, homePlanet, numObj, spaceObjects);
    Alien alien2 = Alien(alien);

    alien2.print();
    return 0;
}