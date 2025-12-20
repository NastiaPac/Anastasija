#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    const int elf_count=3;
    const int calls=2;
    string first_name[elf_count]={"Jingle", "Twinkle", "Pudding"};
    string last_name[elf_count]={"Sparkfoot", "Icicletoes", "Gumdrops"};
    string city[elf_count][calls]={{"London", "Paris"}, {"NewYork", "London"}, {"Paris", ""}};
    int minutes[elf_count][calls]={{12, 7}, {20, 5}, {15, 0}};

    double price_London=0.50;
    double price_Paris=0.40;
    double price_NewYork=0.70;
    double total_cost[elf_count]={0, 0, 0};
    double total=0.0;

    for(int i=0; i<elf_count; i++){
        for(int j=0; j<calls; j++){
            if(city[i][j]=="London"){
                total_cost[i]+=minutes[i][j]*price_London;
            }
            else if(city[i][j]=="Paris"){
                total_cost[i]+=minutes[i][j]*price_Paris;
            }
            else if(city[i][j]=="NewYork"){
                total_cost[i]+=minutes[i][j]*price_NewYork;
            }
        }
    }

    for(int i=0; i<elf_count-1; i++){
        for(int j=i+1; j<elf_count; j++){
            if(last_name[i]>last_name[j]){
                swap(last_name[i], last_name[j]);
                swap(first_name[i], first_name[j]);
                swap(total_cost[i], total_cost[j]);
            }
        }
    }

    for(int i=0; i<elf_count; i++){
        cout<<last_name[i]<<" "<<first_name[i]<<" "<<fixed<<setprecision(2)<<total_cost[i]<<endl;
        total+=total_cost[i];
    }
    cout<<"Total: "<<fixed<<setprecision(2)<<total;
    return 0;
}
