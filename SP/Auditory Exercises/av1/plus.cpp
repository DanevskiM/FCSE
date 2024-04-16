//
// Created by User on 1/31/2024.
//Write a C++ program to find the largest word in a given string.
//Example:
//Sample Input: C++ is a general-purpose programming language.
//Sample Output: programming
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char str[100];
    cin.getline(str,100);
    char max=CHAR_MIN;
    for(int i=0;i < strlen(str);i++){
        if(strlen(str[i])>max){
            max=str[i];
        }
    }
    cout<<max;

    return 0;
}