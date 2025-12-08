#include <iostream>

using namespace std;

int main()
{
    int N;
    cout<<"Enter N: ";
    while(!(cin>>N)){
        cin.clear();
        cin.ignore(10000, '\n');
        cout<<"Error! Enter N: ";
    }
    for(int i=0; i<=N*2+2; i++){
        cout<<"#";
    }
    cout<<endl;
    for (int i=1; i<=N; i++){
        cout<<"# ";
        for(int j=1; j<=N; j++){
            int suma=i+j;

            if(suma%3==0 && suma%5==0){
                cout<<"G ";
            }
            else if(suma%3==0){
                cout<<"T ";
            }
            else if(suma%5==0){
                cout<<"S ";
            }
            else{
                cout<<". ";
            }
        }
        cout<<"# ";
        cout<<endl;
    }
    for(int i=0; i<=N*2+2; i++){
        cout<<"#";
    }
    return 0;
}
