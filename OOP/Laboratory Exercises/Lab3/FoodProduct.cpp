(1) Да се дефинира класа FoodProduct во која ќе се чуваат информации за:
    Име на продуктот (низа од карактери со максимална должина 50)
    Количина на продуктот (int)
    Цена на продуктот (int)
Класата треба да ги има следните методи:
    конструктор (default, copy и со параметри)
    set и get методи за количина и цена
    print() метод
Печатењето да е според следниот формат:
/*Name: [Name of product]
Amount available: [Amount]
Price: [Price of product]
При што вредностите во [] треба да се заменат со вредностите во класата!
(2) Следно треба да се имплементира класата Menu која ќе ги чува следните информации:
    Име на ресторанот (низа од карактери со максимална должина 50)
    Број на продукти (int)
    Низа од продукти (низа од FoodProduct со максимална должина 50)
За класата да се имплементираат следните методи:
    Конструктор (default, copy и конструктор со еден параметар за име)
    Set и get методи (за името на ресторанот и бројот на продукти)
    void addProduct(FoodProduct p) - додава продукт во низата, при што не може да се додат повеќе од 50 продукти во низата
    print() метод
Печатењето да е според следниот формат:
Name: [Name of restaurant]
Products:
[Product 1]
[Product 2]
 …
[Product N]
При што вредностите во [] треба да се заменат со вредностите во класата!
    int totalIncome() - која ќе го враќа збирот на заработувачката на секој продукт, така што заработувачката на продуктот е производ од неговата количина и цена (income = amount * price)
(3) Надвор од класата треба да се напише следната функција:
    void printWorstMenu(Menu * menus, int n) - од дадените n менија го печати менито со најмала вкупна заработувачка
!!! ДА НЕ СЕ ПРАВАТ ПРОМЕНИ ВО MAIN() ФУНКЦИЈАТА !!!
*/
#include <iostream>
#include <cstring>

using namespace std;

class FoodProduct {
private:
    char name[50];
    int amount;
    int price;

public:
    FoodProduct() {
        std::strcpy(this->name, "");
        this->amount = 0;
        this->price = 0;
    }

    FoodProduct(char *name, int amount, int price) {
        std::strcpy(this->name, name);
        this->amount = amount;
        this->price = price;
    }

    FoodProduct(const FoodProduct & other) {
        std::strcpy(this->name, other.name);
        this->amount = other.amount;
        this->price = other.price;
    }

    ~FoodProduct() {}

    int getAmount() const {
        return amount;
    }

    void setAmount(int amount) {
        this->amount = amount;
    }

    int getPrice() const {
        return price;
    }

    void setPrice(int price) {
        this->price = price;
    }

    int income() const {
        return amount * price;
    }

    void print() const {
        std::cout << "Name: " << name << '\n';
        std::cout << "Amount available: " << amount << '\n';
        std::cout << "Price: " << price << '\n';
    }
};

class Menu {
private:
    char name[50];
    int numberOfProducts;
    FoodProduct products[50];

public:
    Menu() {
        std::strcpy(name, "");
        this->numberOfProducts = 0;
    }

    Menu(char * name) {
        std::strcpy(this->name, name);
        this->numberOfProducts = 0;
    }

    Menu(const Menu & other) {
        std::strcpy(this->name, other.name);
        this->numberOfProducts = other.numberOfProducts;

        for(int i = 0; i < numberOfProducts; i++) {
            products[i] = other.products[i];
        }
    }

    ~Menu() {}

    const char *getName() const {
        return name;
    }

    int getNumberOfProducts() const {
        return numberOfProducts;
    }

    void setNumberOfProducts(int numberOfProducts) {
        this->numberOfProducts = numberOfProducts;
    }

    void setName(char * name) {
        std::strcpy(this->name, name);
    }

    void addProduct(FoodProduct product) {
        products[numberOfProducts++] = product;
    }

    void print() const {
        cout << "Name: " << this->name << "\n";
        cout << "Products:\n";

        for (int i = 0; i < numberOfProducts; i++)
            products[i].print();
    }

    int totalIncome() const {
        int total = 0;

        for(int i = 0; i < numberOfProducts; i++)
            total += products[i].income();

        return total;
    }
};

void printWorstMenu(Menu * menus, int & n) {
    Menu worst = menus[0];

    for (int i = 0; i < n; i++) {
        if(worst.totalIncome() > menus[i].totalIncome())
            worst = menus[i];
    }

    worst.print();
}


//DO NOT CHANGE main() FUNCTION

int main() {
    int n;
    cin >> n;

    /// BASIC INPUT & ADD PRODUCT
    Menu menus[n];

    for(int i = 0; i < n; i++) {
        int m;
        char name[50];

        cin >> name >> m;
        menus[i] = Menu(name);

        for(int j = 0; j < m; j++) {
            char itemName[50];
            int amount, price;

            cin >> itemName >> amount >> price;

            FoodProduct product(itemName, amount, price);
            menus[i].addProduct(product);
        }
    }

    /// TESTING ADD PRODUCT

    cout << "-- Testing add product & getNumberOfProducts() --\n\n";

    char tempName[50] = "test";
    Menu temp(tempName);

    cout << "Number of products before adding: " << temp.getNumberOfProducts() << '\n';

    temp.addProduct(FoodProduct(tempName, 0, 0));

    cout << "Number of products after adding: " << temp.getNumberOfProducts() << '\n';
    temp.print();

    /// TESTING COPY CONSTRUCTOR

    Menu tester(menus[0]);
    std::strcpy(tempName, "Tester Name");
    tester.setName(tempName);

    cout << "\n-- Testing copy constructor & setName() --\n";
    cout << "-------------\n";
    cout << "Source:\n";
    cout << "-------------\n";
    menus[0].print();

    cout << "\n-------------\n";
    cout << "Copied and edited:\n";
    cout << "-------------\n";
    tester.print();

    /// TESTING WORST PRODUCT

    cout << "\n-- Testing printWorstMenu() --\n";
    printWorstMenu(menus, n);
    return 0;
}
