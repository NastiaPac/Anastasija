#include <iostream>

using namespace std;

int main()
{
    int elves=3;
    int juice_amounts[elves]={45,92,33};

    for(int i=0; i<elves; i++){
        int liters=juice_amounts[i];

        int five_liters=liters/5;
        int temp=liters%5;

        int two_liters=temp/2;
        int one_liter=temp%2;

        cout<<five_liters<<" "<<two_liters<<" "<<one_liter<<endl;
    }
    return 0;
}
