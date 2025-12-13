#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int n=7;
    string students[n]={
        "Petraitis Rokas",
        "Augė Artūras",
        "Mikalauskaitė Aušra",
        "Šlivka Donatas",
        "Stakėnaitė Ieva",
        "Skrėbė Domas",
        "Bruzgaitė Akvilė"
    };
    int girls=0;
    for(int i=0; i<n; i++){
        string student=students[i];
        int len=student.size();
        if(student[len-1]=='a' || student[len-2]==(char)0xC4 && student[len - 1] == (char)0x97){//ė
            girls++;
        }
    }
    cout<<girls<<endl;
    for(int i=0; i<n; i++){
        string student=students[i];
        int len=student.size();
        if(student[len-1]=='a' || student[len-2]==(char)0xC4 && student[len - 1] == (char)0x97){//ė
            cout<<student<<endl;
        }
    }
    return 0;
}
