#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double xc, yc, x, y, r1, r2,r3, r4;
    int p1, p2, p3, p4;
    cout<<"Enter the x coordinate of the target’s center: ";
    while(!(cin>>xc)){
        cin.clear();
        cin.ignore(10000, '\n');
        cout<<"Error! Enter the x coordinate of the target’s center: ";
    }
    cout<<"Enter the y coordinate of the target’s center: ";
    while(!(cin>>yc )){
        cin.clear();
        cin.ignore(10000, '\n');
        cout<<"Error! Enter the x coordinate of the target’s center: ";
    }

    cout << "Enter radius r1 (inner black circle): ";
    while (!(cin>>r1) || r1 <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error! Enter radius r1: ";
    }
    cout << "Enter radius r2: ";
    while (!(cin>>r2) || r2 <= r1) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error! Enter radius r2: ";
    }
    cout << "Enter radius r3: ";
    while (!(cin>>r3) || r3 <= r2) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error! Enter radius r3: ";
    }
    cout << "Enter radius r4: ";
    while (!(cin>> r4) || r4 <= r3) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error! Enter radius r4: ";
    }

    cout << "Enter x coordinate of the arrow: ";
    while (!(cin>>x)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error! Enter x coordinate of the arrow: ";
    }
    cout << "Enter y coordinate of the arrow: ";
    while (!(cin>>y)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error! Enter y coordinate of the arrow: ";
    }

    cout << "Enter points for ring 1: ";
    while (!(cin>>p1) || p1 < 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error! Enter points for ring 1: ";
    }

    cout << "Enter points for ring 2: ";
    while (!(cin>>p2) || p2 < 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error! Enter points for ring 2: ";
    }

    cout << "Enter points for ring 3: ";
    while (!(cin>>p3) || p3 < 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error! Enter points for ring 3: ";
    }

    cout << "Enter points for ring 4: ";
    while (!(cin>>p4) || p4 < 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error! Enter points for ring 4: ";
    }

    double d=sqrt((x-xc)*(x-xc) + (y-yc)*(y-yc));

    double score;
    if(d==r1){
        score=p1/2;
    }
    else if(d<r1){
        score=p1;
    }
    else if(d==r2){
        score=p2/2.0;
    }
    else if(d<r2){
        score=p2;
    }
    else if(d==r3){
        score=p3/2.0;
    }
    else if(d<r3){
        score=p3;
    }
    else if(d==r4){
        score=p4/2.0;
    }
    else if(d<r3){
        score=p4;
    }
    cout<<score;
    return 0;
}
