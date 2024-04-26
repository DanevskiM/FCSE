#include <iostream>
#include <cstring>
using namespace std;

enum state{
    AVAILABLE, REPAIRING, NOT_AVAILABLE
};

class Book{
    private:
        char ISBN[13];
        char *title;
        char publishing_house[20];
        int total_rents;
        state s;
    public:
        Book(char *ISBN="", char *title="", char *publishing_house="", int total_rents=0, int ss = 0){
            this->title = new char[strlen(title)+1];
            strcpy(this->title, title);
            strcpy(this->ISBN, ISBN);
            strcpy(this->publishing_house, publishing_house);
            this->total_rents=total_rents;
            s=(state)ss;
        }
        Book(const Book &a){
            this->title = new char[strlen(a.title)+1];
            strcpy(this->title, a.title);
            strcpy(this->ISBN, a.ISBN);
            strcpy(this->publishing_house, a.publishing_house);
            this->total_rents=a.total_rents;
            s=a.s;
        }
        Book &operator=(const Book &a){
            if(this!=&a){
                delete [] title;
                this->title = new char[strlen(a.title)+1];
                strcpy(this->title, a.title);
                strcpy(this->ISBN, a.ISBN);
                strcpy(this->publishing_house, a.publishing_house);
                this->total_rents=a.total_rents;
                s=a.s;
            }
            return *this;
        }
        ~Book(){
            delete [] title;
        }
        void print(){
            cout<<"ISBN: "<<ISBN<<" - ";
            if(s==0)
            {
                cout<<"AVAILABLE ";
            }
            else if(s==1)
            {
                cout<<"REPAIRING ";
            }
            else cout <<"NOT AVAILABLE ";
            cout<<title<<", "<<total_rents<<", "<<publishing_house<<endl;
        }
        state get_state(){
            return s;
        }
        char *get_publishing_house(){
            return publishing_house;
        }
        int get_total_rents(){
            return total_rents;
        }
        void set_state(int k){
            s = (state)k;
        }
};

class BookService{
    private:
        char library_name[20];
        Book *arr;
        int n;
    public:
        BookService(char *library_name=""){
            strcpy(this->library_name, library_name);
            arr = new Book[0];
            n=0;
        }
        BookService(const BookService &a){
            strcpy(this->library_name, a.library_name);
            n=a.n;
            arr = new Book[n];
            for(int i=0; i<n; i++){
            arr[i] = a.arr[i];
            }
        }
        BookService &operator=(const BookService &a){
            if(this!=&a){
                delete [] arr;
                strcpy(this->library_name, a.library_name);
                n=a.n;
                arr = new Book[n];
                for(int i=0; i<n; i++){
                    arr[i] = a.arr[i];
                }
            }
            return *this;
        }
        ~BookService(){
            delete [] arr;
        }
        void print(){
            cout<<library_name<<endl;
            if(n>0){
                for(int i=0; i<n; i++){
                    arr[i].print();
                }
            }else{
                cout<<"-- EMPTY --"<<endl;
            }
        }
        void addBook(Book p){
            if(p.get_state()==0){
                p.set_state(1);
                for(int i=0; i<n; i++){
                    if(strcmp(arr[i].get_publishing_house(),p.get_publishing_house())==0){
                        if(p.get_total_rents()>arr[i].get_total_rents()){
                            arr[i]=p;
                        }
                        return;
                    }
                }
                Book *tmp = new Book[n+1];
                for(int i=0; i<n; i++){
                    tmp[i] = arr[i];
                }
                tmp[n++] = p;
                delete [] arr;
                arr = tmp;
            }
        }
        Book repairNewestBook(){
            Book newest = arr[0];
            int index = 0;
            for(int i=1; i<n; i++){
                if(arr[i].get_total_rents()<newest.get_total_rents()){
                    newest=arr[i];
                    index=i;
                }else if(arr[i].get_total_rents()==newest.get_total_rents()){
                    if(strcmp(arr[i].get_publishing_house(), library_name)==0){
                        newest=arr[i];
                        index=i;
                    }
                }
            }
            Book *tmp = new Book[n-1];
            for(int i=0, j=0; i<n; i++){
                if(i!=index){
                    tmp[j++] = arr[i];
                }
            }
            n--;
            delete [] arr;
            arr = tmp;
            newest.set_state(0);
            return newest;
        }
};

int main() {
    int testCase;
    cin >> testCase;
    char ISBN[13];
    char title[20];
    char publishing_house[20];
    int total_rents;
    int state;
    if (testCase == 1) {
        cout << "TESTING CONSTRUCTOR FOR BOOK" << endl;
        Book a;
        cout << "TEST FOR DEFAULT CONSTRUCTOR PASSED" << endl;
        Book a1("966-13-43-72", "FINKI-ONWD", "FINKI", 25);
        cout << "TEST FOR CONSTRUCTOR WITH 3 ARGUMENTS PASSED" << endl;
        Book a2("966-13-43-11", "FINKI-OOP", "FINKI", 20, 0);
        cout << "TEST FOR CONSTRUCTOR WITH 4 ARGUMENTS PASSED" << endl;
    } else if (testCase == 2) {
        cout << "TESTING COPY-CONSTRUCTOR AND OPERATOR = (ASSIGNMENT) FOR BOOK" << endl;
        Book a("966-13-43-11", "FINKI-OOP", "FINKI", 20, 0);
        Book a1(a);
        cout << "TEST FOR COPY CONSTRUCTOR PASSED" << endl;
        Book a2;
        a2 = a;
        cout << "TEST FOR OPERATOR = (ASSIGNMENT) PASSED" << endl;
    } else if (testCase == 3) {
        cout << "TESTING PRINT() FOR BOOK" << endl;
        cin>>ISBN>>title>>publishing_house>>total_rents>>state;
        Book a(ISBN, title, publishing_house, total_rents, state);
        a.print();
    } else if (testCase == 4) {
        cout << "TESTING CONSTRUCTOR FOR BOOKSERVICE" << endl;
        BookService as("FINKI");
        cout << "TEST PASSED" << endl;
    } else if (testCase == 5) {
        cout << "TESTING ADD() AND PRINT() FOR BOOKSERVICE" << endl;
        BookService as("FINKI");
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>ISBN>>title>>publishing_house>>total_rents>>state;
            Book a(ISBN, title, publishing_house, total_rents, state);
            as.addBook(a);
        }
        as.print();
    } else if (testCase == 6) {
        cout << "TESTING repairNewestBook() AND PRINT() FOR BOOKSERVICE" << endl;
        BookService as("FINKI");
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>ISBN>>title>>publishing_house>>total_rents>>state;
            Book a(ISBN, title, publishing_house, total_rents, state);
            as.addBook(a);
        }
        Book p = as.repairNewestBook();
        cout<<"Repaired book:"<<endl;
        p.print();
        cout<<"-----------------"<<endl;
        as.print();
    }  else if (testCase == 7) {
        cout << "TESTING COPY CONSTRUCTOR AND OPERATOR = FOR BOOKSERVICE" << endl;
        BookService as("FINKI");
        Book a2("966-13-43-11", "FINKI-OOP", "FINKI", 20, 0);
        as.addBook(a2);

        BookService s1 = as; //copy constructor
        BookService s2;
        s2 = s1; //operator =
        s1.print();
        s2.print();
    }
    return 0;
}
