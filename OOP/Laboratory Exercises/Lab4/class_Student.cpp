/*Да се дефинира класа Student за која се чува:
    name(низа од карактери, динамички алоцирана) - неговото име
    age (цел број) - колку години има
    major (низа од карактери, динамички алоцирана) - што студира
За класата да се дефинира default конструктор, конструктор со аргументи и copy конструктор.
Потоа да се дефинира класа Classroom за која се чува:
    students (динамички алоцирана низа од Студенти)
    numStudents(int)
    capacity(int)
За класата да се дефинира  default конструктор и конструктор со аргументи. 
Треба за класата Classroom да се дефинираат следните методи:
    add - да се додаде нов студент
    remove - да се отстрани некој студент со дадено име name
    findMedianAge - наоѓа која е медијаната за години на стидентите во дадениот Classroom. 
Пример: 2 4 5 6 7 8 10
Медијана: 6
Пример: 2 4 5 7 8 10 12 20
Медијана: (7 + 8)/2
Мора да е растечки редослед!
По потреба може да се креираат get и set методи.
Сите студенти имаат уникатно име.
Да не се менува main функцијата.*/
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

class Student
{
private:
    char * ime;
    int godini;
    char * major;
public:

    Student (char * ime = " ", int godini = 0, char * major = " ")
    {
        this -> ime = new char [strlen(ime) + 1];
        strcpy(this->ime, ime);
        this -> godini = godini;
        this -> major = new char [strlen(major) + 1];
        strcpy(this->major, major);
    }
    Student (const Student & copy)
    {
        ime = new char [strlen(copy.ime) + 1];
        strcpy(ime, copy.ime);
        godini = copy.godini;
        major = new char [strlen(copy.major) + 1];
        strcpy(major, copy.major);
    }
    Student &operator=(const Student & over)
    {
        if(this == &over){
            return * this;
        }
        delete [] ime;
        delete [] major;
        ime = new char [strlen(over.ime) + 1];
        strcpy(ime, over.ime);
        godini = over.godini;
        major = new char [strlen(over.major) + 1];
        strcpy(major, over.major);
        return * this;
    }

    ~Student ()
    {
        delete [] ime;
        delete [] major;
    }

    char *getIme() const 
    {
        return ime;
    }

    int getGodini() const 
    {
        return godini;
    }

    char *getMajor() const 
    {
        return major;
    }


};

class Classroom
{
private:
    Student * students;
    int brojStudenti;
    int capacity;
public:
    Classroom(Student * students = 0, int brojStudenti = 0, int capacity = 0)
    {
        this -> students = new Student [brojStudenti];
        this -> brojStudenti = brojStudenti;
        this -> capacity = capacity;
        for(int i=0; i<brojStudenti; i++)
        {
            this -> students[i] = students[i];
        }
    }

    Student *getStudents() const 
    {
        return students;
    }

    int getBrojStudenti() const 
    {
        return brojStudenti;
    }
    void add(Student student)
    {
        Student *temp = new Student[brojStudenti+1];
        for(int i=0; i<brojStudenti; i++)
        {
            temp[i]=students[i];
        }
        temp[brojStudenti]=student;
        delete [] students;
        students=temp;
        brojStudenti++;
    }
    void remove(char* name) 
    {
        int index = -1;
        for(int i = 0; i < brojStudenti; i++) 
        {
            if(strcmp(students[i].getIme(), name) == 0) 
            {
                index = i;
                break;
            }
        }

        if(index == -1) return;

        for(int i = index ; i < brojStudenti - 1; i++) 
        {
            students[i] = students[i + 1];
        }

        brojStudenti--;
    }
    void printStudents(){
        for(int i=0; i<brojStudenti; i++)
        {
            cout<<students[i].getIme()<<" ("<<students[i].getGodini()<<","<<" "<<students[i].getMajor()<<")"<<endl;
        }
        cout<<endl;
    }
    ~Classroom(){}
};

double findMedianAge(Classroom classroom) 
{
    Student* students = classroom.getStudents();
    int n = classroom.getBrojStudenti() / 2;
    double median = students[n].getGodini();

    if(classroom.getBrojStudenti() % 2 == 0)
        median = (students[n].getGodini() + students[n - 1].getGodini()) / 2.0;

    return median;
}
int main() {
    int numClassrooms, numStudents;
    cin >> numClassrooms;
    Classroom classrooms[100];
    Student students[100];

    // Testing add method
    for (int i = 0; i < numClassrooms; i++) {
        cin >> numStudents;
        for (int j = 0; j < numStudents; j++) {
            char name[100], major[100];
            int age;
            cin >> name >> age >> major;
            Student student(name, age, major);
            classrooms[i].add(student);
            students[i*numStudents + j] = student;
        }
        cout<<"Classroom "<<i<<endl;
        classrooms[i].printStudents();
    }


    // Testing findMedianAge method
    int targetClassroom;
    cin >> targetClassroom;
    double medianAge = findMedianAge(classrooms[targetClassroom]);
    cout << "The median age in classroom " << targetClassroom << " is: " << medianAge << endl;
    cout<<"After removing the elements:"<<endl; /// Added 
    // Testing remove method
    cin >> numStudents;
    for (int j = 0; j < numStudents; j++) {
        char name[100];
        cin >> name;
        for (int i = 0; i < numClassrooms; i++) {
            classrooms[i].remove(name);
        }
    }
    for (int i = 0; i < numClassrooms; i++) {
        cout<<"Classroom "<<i<<endl;
        classrooms[i].printStudents();
    }

    return 0;
}