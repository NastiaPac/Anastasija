#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of toys in Binky Frostynose's box: ";
    while(!(cin>>n) || n<0){
        cin.clear();
        cin.ignore(10000, '\n');
        cout<<"Error! Enter the number of toys in Binky Frostynose's box: ";
    }
    int toys[101]={0};
    for(int i=0; i<n; i++){
        int x;
        cout<<"Enter the toy number: ";
        while(!(cin>>x) || x<1 || x>100){
            cin.clear();
            cin.ignore(10000, '\n');
            cout<<"Error! Enter the toy number (between 1 and 100): ";
        }
        toys[x]++;
    }

    for(int i=1; i<=100; i++){
        if(toys[i]>1){
            cout<<i<<" ";
        }
    }
    return 0;
}
