#include <iostream>

using namespace std;

int main()
{
    int length, width;
    double m2price, totalCost;
    cout<<"Enter room length in meters: ";
    cin>>length;
    cout<<"Enter room width in meters: ";
    cin>>width;
    cout<<"Enter price of one square meter: ";
    cin>>m2price;

    double tiles=length*width*1.05;
    totalCost=tiles*m2price;

    cout<<"Santa needs to pay "<< totalCost<<" coins.";
    return 0;
}
