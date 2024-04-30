#include <stdio.h>
#include<string.h>
#include <ctype.h>
void writeToFile() {
    FILE *f = fopen("text.txt", "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    writeToFile();
    char c;
    scanf("%c", &c);
    FILE *f = fopen("text.txt", "r");
    char znak;
    int overall=0;
    int counter=0;
    while ((znak=fgetc(f)) != EOF)
    {
        if (isalpha(znak))
        {
            overall++;
            if (tolower(znak)== tolower(c))
            {
                ++counter;
            }
        }
    }
    printf("%.4f", (float)counter/overall);
}
