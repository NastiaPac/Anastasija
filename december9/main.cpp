#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, melon_number;
    double average_weight, sum=0;
    cout<<"Enter number of melons: ";
    while(!(cin>>n)){
        cin.clear();
        cin.ignore(10000, '\n');
        cout<<"Error! Enter number of melons: ";
    }
    double melons[n];
    for(int i=0; i<n; i++){
        cout<<"Enter the weight of the "<<i+1<<" melon: ";
        cin>>melons[i];
        sum+=melons[i];
    }
    average_weight=sum/n;
    double difference[n];
    melon_number=0;
    for(int i=0; i<n; i++){
        difference[i]=average_weight - melons[i];
        if(difference[i]<0){
            difference[i]*=-1;
        }
        if(difference[i]<difference[melon_number]){
            melon_number=i;
        }
    }
    cout<<melon_number+1<<" "<<fixed<<setprecision(2)<<average_weight;
    return 0;
}
