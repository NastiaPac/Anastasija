#include <iostream>

using namespace std;

int main()
{
    int x, y, m, s;
    cout<<"Enter hours: ";
    cin>>x;
    cout<<"Enter minutes: ";
    cin>>y;

    m=x*60+y;   //calculate minutes since midnight
    s=m*60;     //calculcate seconds since midnight

    cout<<"Minutes passed: "<<m<<endl;
    cout<<"Seconds passed: "<<s;
    return 0;
}
