/*Имате купено нова игра која ги има следните правила:
    Кога ќе заврши играта добивате P1 поени за секое поминато ниво
    Но, доколку имате поминато над C1 нивоа тогаш добивате P2 поени (наместо P1) за секое ниво
    Но, доколку имате поминато над C2 (C2>C1) нивоа тогаш добивате P3 поени (наместо P2) за секое ниво
На пример нека P1 = 100; C1 = 3; P2 = 150; C2 = 6; и P3 = 200. Тогаш за
    изиграни 2 нивоа ќе добиете 2*P1 = 200 поени
    изиграни 4 нивоа ќе добиете 4*P2 = 600 поени
    изиграни 6 нивоа ќе добиете 6*P2 = 900 поени
    изиграни 8 нивоа ќе добиете 8*P3 = 1600 поени
Вие ја играте играта 3 пати, при што сте поминале A нивоа првиот пат, потоа играјќи повторно од почеток сте поминале B нивоа вториот пат и третиот пат сте поминале C нивоа.
Напишете програма која за дадени вредности P1, C1, P2, C2, P3; и дадени A, B и C ќе пресмета и ќе отпечати колку вкупно поени имате добиено при играњето.*/
#include<stdio.h>
int main() {
    int p1, c1, p2, c2, p3;
    scanf("%d %d %d %d %d", &p1, &c1, &p2, &c2, &p3);
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int rez = 0;

    if (a > c2) rez += a * p3;
    else if (a > c1) rez += a * p2;
    else rez += a * p1;

    if (b > c2) rez += b * p3;
    else if (b > c1) rez += b * p2;
    else rez += b * p1;

    if (c > c2) rez += c * p3;
    else if (c > c1) rez += c * p2;
    else rez += c * p1;

    printf("%d", rez);
    return 0;
}