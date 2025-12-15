#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double x,y,z;
    cin>>x>>y>>z;
    if(x<y && x<z){
        cout<<fixed<<setprecision(2)<<x;
    }
    else if(x>y && y<z){
        cout<<fixed<<setprecision(2)<<y;
    }
    else if(x>z && y>z){
        cout<<fixed<<setprecision(2)<<z;
    }

    return 0;
}
