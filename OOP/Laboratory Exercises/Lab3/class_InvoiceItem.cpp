//Да се дефинира класа InvoiceItem во која што ќе се чуваат податоци за една ставка во фактура:
//    име на ставка (низа од максимум 100 карактери)
//    цена на ставка (цел број)
//За класата да се дефинира copy конструктор, default конструктор и конструктор со аргументи.
//Доколку е потребно да се креира и get методи.
//Потоа да се креира класа Invoice во која што се чуваат следните податоци:
//    број на фактура (низа од максимум 10 карактери)
//    број на ставки во фактурата (цел број)
//    низа од ставки во фактурата (низа од објекти од InvoiceItem класата, max 100)
//Да се креира конструктор со аргументи за класата. 
//Доколку е потребно да се креира и get методи.
//Во класата да се креира метода totalPrice што ќе го пресметува вкупниот износ на фактурата. Вкупниот износ на фактурата се пресметува како збир од цените на сите ставки во нејзе.
//ДА НЕ СЕ МЕНУВА MAIN ФУНКЦИЈАТА.
#include <iostream>
#include <cstring>

using namespace std;

// your code here
class InvoiceItem
{
private:
    char name[100];
    int price;
public:
    InvoiceItem(){}
    InvoiceItem(char *ime, int cena)
    {
        strcpy(name, ime);
        price = cena;
    }
    InvoiceItem(const InvoiceItem &it)
    {
        strcpy(name,it.name);
        price = it.price;
    }
    ~InvoiceItem(){}

    int getCena()
    {
        return price;
    }
};

class Invoice
{
private:
    char numFakt[10];
    int numStavki;
    InvoiceItem stavki[100];
public:
    Invoice(char *brojFaktura, int brStavki, InvoiceItem stavkii[100])
    {
        strcpy(numFakt, brojFaktura);
        numStavki = brStavki;
        for(int i=0;i<numStavki;i++)
        {
            stavki[i]=stavkii[i];
        }
    }
    ~Invoice(){}

    int totalPrice()
    {
        int suma = stavki[0].getCena();
        for(int i=1;i<numStavki;i++)
        {
            suma=suma+stavki[i].getCena();
        }
        return suma;
    }

    char *getInvoiceNumber() {
        return numFakt;
    }
};
// DO NOT CHANGE THE MAIN FUNCTION
int main()
{
    char number[10];
    int n;
    // testing default constructor
    InvoiceItem items[100];
    cin >> number >> n;
    for (int i = 0; i < n; i++) {
        char name[100];
        int price;
        cin >> name;
        cin >> price;
        
        // testing constructor with parameters
        InvoiceItem item(name, price);
        
        // testing copy constructor
        items[i] = InvoiceItem(item);
    }
    // testing constructor with parameters for Invoice
    Invoice invoice(number, n, items);
    
    // testing totalPrice function
    cout << "Total price for invoice number " << invoice.getInvoiceNumber() << " is " << invoice.totalPrice() << endl;

    return 0;
}