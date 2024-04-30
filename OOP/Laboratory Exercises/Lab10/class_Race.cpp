#include <iostream>
#include <cstring>
using namespace std;
class InvalidTimeException
{
public:
    void print()
    {
        cout<<"The time is not valid"<<endl;
    }
};
class Race
{
protected:
    char grad[40];
    int godina;
    int mesec;
    float bestTime;
    float dolzina;
public:
    Race()
    {
        strcpy(this->grad, "empty");
        this->godina = 0;
        this->mesec = 0;
        this->bestTime = 0;
        this->dolzina = 0;
    }

    Race(char *grad, int godina, int mesesc, float bestTime, float dolzina)
    {
        strcpy(this->grad, grad);
        this->godina = godina;
        this->mesec = mesesc;
        this->bestTime = bestTime;
        this->dolzina = dolzina;
    }

    virtual float heaviness()
    {
        return bestTime/dolzina;
    }

    friend ostream &operator<<(ostream &os, Race &race)
    {
        os<<race.grad<<" "<<race.mesec<<"."<<race.godina<<" "<<race.heaviness()<<endl;
        return os;
    }
};

class CarRace : public Race
{
private:
    float *pripremi;
    int brNaj;
    int krugovi;
    static float CAR_COEF;
public:
    CarRace(char *grad = "", int godina = 0, int mesesc = 0, float bestTime = 0, float dolzina = 0)
    : Race(grad, godina, mesesc, bestTime, dolzina)
    {
        this->pripremi = new float[0];
        this->brNaj = 0;
        this->krugovi = 0;
    }

    CarRace(char *grad, int godina, int mesesc, float bestTime, float dolzina,
            float *pripremi, int brNaj, int krugovi)
    :Race(grad, godina, mesesc, bestTime, dolzina)
    {
        this->pripremi = new float[brNaj];
        for(int i=0;i<brNaj;i++)
        {
            this->pripremi[i] = pripremi[i];
        }
        this->brNaj = brNaj;
        this->krugovi = krugovi;
    }

    CarRace(const CarRace &cr)
    {
        this->pripremi = new float[cr.brNaj];
        for(int i=0;i<cr.brNaj;i++)
        {
            this->pripremi[i] = cr.pripremi[i];
        }
        this->brNaj = cr.brNaj;
        this->krugovi = cr.krugovi;
    }

    CarRace &operator=(const CarRace & cr)
    {
        if(this!=&cr)
        {
            delete [] pripremi;
            this->pripremi = new float[cr.brNaj];
            for(int i=0;i<cr.brNaj;i++)
            {
                this->pripremi[i] = cr.pripremi[i];
            }
            this->brNaj = cr.brNaj;
            this->krugovi = cr.krugovi;
        }
        return *this;
    }

    void setNumberLaps(int k)
    {
        krugovi = k;
    }

    float heaviness()
    {
        float bestTime = 0;
        for(int i=0;i<brNaj;i++)
        {
            bestTime += pripremi[i];
        }
        float averageBestTime = (bestTime/(float)brNaj);
        float heavy = Race::heaviness() + (averageBestTime * CAR_COEF);
        if(krugovi > 15)
        {
            return (float)heavy * 1.1;
        }
        else
        {
            return heavy;
        }
    }

    CarRace&operator+=(float p)
    {
        if(p<10)
        {
            throw InvalidTimeException();
        }
        float *tmp = new float[brNaj + 1];
        for(int i=0;i<brNaj;i++)
        {
            tmp[i] = pripremi[i];
        }
        tmp[brNaj++] = p;
        delete[] pripremi;
        pripremi = tmp;
        return *this;
    }

    static void setKoeficient(float k)
    {
        CAR_COEF = k;
    }
    ~CarRace()
    {
        delete [] pripremi;
    }
};

float CarRace::CAR_COEF = 0.3;

int main(){
    int testCase;
    cin >> testCase;
    char city[50];
    int year;
    int month;
    float bestTime;
    float length;
    float bestTimes[50];
    int n;
    int m;
    int izbor;
    int numberLaps;

    if (testCase == 1){
        cout << "===== Testiranje na klasite ======" << endl;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin>>length;
        Race t(city, year, month, bestTime, length);
        cout<<t;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin>>length;
        cin>>numberLaps;
        cin>>n;
        for (int j = 0; j < n; j++)
            cin >> bestTimes[j];
        CarRace mgt(city, year, month, bestTime, length, bestTimes, n, numberLaps);
        cout << mgt;
        CarRace mgt2;
    }
    if (testCase == 2){
        cout << "===== Testiranje na operatorot += ======" << endl;
        Race **niza;
        cin >> m;
        niza = new Race *[m];
        for (int i = 0; i<m; i++){
            cin >> izbor;
            cin >> city;
            cin >> year;
            cin >> month;
            cin >> bestTime;
            cin >>length;
            if (izbor == 1){
                niza[i] = new Race(city, year, month, bestTime, length);
            }
            else{
                cin>>numberLaps;
                cin>>n;
                for (int j = 0; j < n; j++)
                    cin >> bestTimes[j];
                niza[i] = new CarRace(city, year, month, bestTime, length, bestTimes, n, numberLaps);
            }
        }
        // pecatenje na site Trki
        cout << "\nLista na site Trki:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        // dodavanje novo najdobro vreme za prvata CarRace
        float best;
        cin >> best;
        int flag = 1;
        for (int i = 0; i < m; i++){
            CarRace* nn = dynamic_cast<CarRace*>(niza[i]);
            if (nn != 0){
                flag = 0;
                (*nn) += best;
                break;
            }
        }


        // pecatenje na site Trki
        cout << "\nLista na site Trki:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }
    if (testCase == 3){
        cout << "===== Testiranje na isklucoci ======" << endl;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin>>length;
        cin>>numberLaps;
        CarRace mgt(city, year, month, bestTime, length);
        mgt.setNumberLaps(numberLaps);
        float vreme1,vreme2;
        cin>>vreme1>>vreme2;
        try{
            mgt+=vreme1;
            mgt+=vreme2;
        }
        catch(InvalidTimeException e)
        {
            e.print();
        }
        cout<<mgt;
    }

    if (testCase == 5){
        cout << "===== Testiranje na static clenovi ======" << endl;
        Race **niza;
        cin >> m;
        niza = new Race *[m];
        for (int i = 0; i<m; i++){
            cin >> izbor;
            cin >> city;
            cin >> year;
            cin >> month;
            cin >> bestTime;
            cin >>length;
            if (izbor == 1){
                niza[i] = new Race(city, year, month, bestTime, length);
            }
            else{
                cin>>numberLaps;
                cin>>n;
                for (int j = 0; j < n; j++)
                    cin >> bestTimes[j];
                niza[i] = new CarRace(city, year, month, bestTime, length, bestTimes, n, numberLaps);
            }
        }
        // pecatenje na site Trki
        cout << "\nLista na site Trki:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        CarRace::setKoeficient(0.7);
        // pecatenje na site Trki
        cout << "\nLista na site Trki:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }



    return 0;
}