#include <iostream>

using namespace std;

int main()
{
    int h, m;
    cout<<"Enter hours: ";
    while(true){
        if(cin>>h && h>=0 && h<24){
            break;
        }
        else{
            cin.clear();
            cin.ignore(10000, '\n');
            cout<<"Error! Enter hours: ";
        }
    }
    cout<<"Enter minutes: ";
    while(true){
        if(cin>>m && m>=0 && m<60){
            break;
        }
        else{
            cin.clear();
            cin.ignore(10000, '\n');
            cout<<"Error! Enter minutes: ";
        }
    }
    h=h+1;
    h=h%24;
    cout<<h<<" : "<<m;
    return 0;
}
