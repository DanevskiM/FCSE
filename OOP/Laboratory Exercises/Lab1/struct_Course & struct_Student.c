//vtorata zadacha beshe da se napravat dve strukturi Course i Student i da se vnesat podatoci za studentite i kursevite
//ama vo Course strukturata imash promenliva num_of_students i spored taa treba da go najdesh kursot so najmnogu studenti
//lesno beshe
#include<stdio.h>
#include<string.h>
#include<ctype.h>
typedef struct Courses
{
    char name[100];
    int num_of_students;

}Courses;

typedef struct Student
{
    char first_name[100];
    char last_name[100];
    int number;
    int num_of_courses;
}Student;



int main()
{
    int n;
    int m;
    scanf("%d", &n);//Vnesuvame broj na studenti.
    for(int i=0;i<n;i++)
    {
        Student s;
        scanf("%s %s %d %d", &s.first_name, &s.last_name, &s.number, &s.num_of_courses);
        int m = s.num_of_courses
        for(int j=0;j<m;j++)
        {
            Courses c;
            scanf("%s", &c.name);

        }
    }
    for(int i=0;i<n;i++)
    {
        Courses c;
    }
}
