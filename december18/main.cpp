#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int store_count=3;
    int item_count=5;

    double stores[store_count][item_count]={
    {1.07, 2.92, 3.45, 1.09, 0.89},
    {1.08, 2.35, 3.75, 1.12, 0.69},
    {0.98, 2.48, 3.62, 1.10, 0.72}
    };
    double total_all_stores=0.0;

    for(int i=0; i<store_count; i++){
        double store_sum=0.0;
        for(int j=0; j<item_count; j++){
            store_sum+=stores[i][j];
        }
        total_all_stores+=store_sum;
        cout<<i+1<<" "<<item_count<<" "<<fixed<<setprecision(2)<<store_sum<<endl;
    }
    cout<<fixed<<setprecision(2)<<total_all_stores;
    return 0;
}
