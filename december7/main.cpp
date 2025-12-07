#include <iostream>

using namespace std;

int main()
{
    int n, k, x=2, s=0;
    cout << "Enter row count: ";
    cin>>n;
    cout << "Enter seats in the first row count: ";
    cin>>k;

    for(int i=1; i<=n; i++){
        s+=k;   //add the number of seats in a row to the total number
        k+=x;   //increase the number of seats in the next row
    }
    cout<<"Total number of seats: "<<s;
    return 0;
}
