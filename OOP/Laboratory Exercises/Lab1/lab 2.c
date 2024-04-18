/*Da se kreira struktura Student vo koja se cuvaat podatoci za eden student.
Za studentot se cuvaat informacii za imeto na student(niza od karakteri)
brojot na indeks na studentot, broj na kursevi koi gi slusa,
nizo od kodovi na kursevite koi gi slusa

Potoa da se kreira structura Course vo koja se cuvaat podatoci za imeto na kursto
(niza od karakteri), kod na kursot(cel broj) i broj na studenti koi go slusaat

Da se napravi funkcija:

int get_most_popular_course(struct course courses[], int num_courses)
koja sto go vrakja kodot na najpopularniot kurs

Prvo od tastatura se cita brojot na studenti, potoa brojot na kursevi.
Potoa se vnesuvaat kursevite i studentite, pritoa za sekoj student se citaat
i kodovite na kursevite koi gi sluza

Input:
3 3
OOP 1
SP 2
APS 3
Dobrinka 202020 1
1
Marko 202022 2
1 2
Stojce 222222 1
1

Result:
Najpopularen kurs e: OOP
*/
#include<stdio.h>
typedef struct Student
{
    char name[100];
    int index;
    int num_courses;
    int course_index[100];
}Student;

typedef struct Course
{
    char course_name[100];
    int index_course;
    int num_of_students;
}Course;

int get_most_popular_course(struct Course Course[], int num_courses)
{
    for(int i=0;i<num_courses;i++)
    {
        if(Course.index_course[i]==)
        Course->num_of_students++;
    }
}
int main()
{
    int n;//Num of students
    int m;//Num of courses
    scanf("%d", &n);
    scanf("%d", &m);

    for(int i=0;i<m;i++)
    {
        Course c;
        scanf("%s %d", &c.course_name, &c.index_course);
    }

    for(int i=0;i<n;i++)
    {
        Student s;
        scanf("%s %d %d %d", &s.name, &s.index, &s.num_courses, &s.course_index);
        Course c;
        c.num_of_students++;
    }


    return 0;
}
