#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double price;
    double expensive_prices=0;
    int expensive_toys=0;
    int toys=1;
    while(price!=0){
        cout<<"Enter the price of the " <<toys<<" toy: ";
        cin>>price;

        if(price>10){
            expensive_prices+=price;
            expensive_toys++;
        }
        toys++;
    }
    cout<<"Total price of magical toys: "<<fixed<<setprecision(2)<<expensive_prices<< " EUR"<<endl;
    cout<<"Number of magical toys: "<<fixed<<setprecision(2)<<expensive_toys;
    return 0;
}
