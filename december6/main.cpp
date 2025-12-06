#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cout<<"Enter takeoff hour: ";
    cin>>a;
    cout<<"Enter takeoff minutes: ";
    cin>>b;
    cout<<"Enter flight duration in minutes: ";
    cin>>c;

    int all_minutes = a*60 + b + c;

    int v = all_minutes/60 % 24;
    int m = all_minutes % 60;
    cout<<"Santa will land at "<<v<<":"<<m;
    return 0;
}
