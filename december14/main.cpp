#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int gifts_max=100;
string ids[gifts_max];
double prices[gifts_max];
int gifts_count=0;
double discount=0.0;


void add(string id, double price){
    if(price<0){
        return;
    }
    for(int i=0; i<gifts_count; i++){
        if(ids[i]==id){
            return;
        }
    }
    ids[gifts_count]=id;
    prices[gifts_count]=price;
    gifts_count++;
}
void remove_gift(string id){
    for(int i=0; i<gifts_count; i++){
        if(ids[i]==id){
            for(int j=i; j<gifts_count-1; j++){
                ids[j]=ids[j+1];
                prices[j]=prices[j+1];
            }
            gifts_count--;
            return;
        }
    }
}
void apply_discount(string code){
    if(code=="PROMO10"){
        discount=0.10;
    }
    else if(code=="PROMO25"){
        discount=0.25;
    }
    else if(code=="SANTA50"){
        discount=0.50;
    }
}
double total(){
    double sum=0;
    for(int i=0; i<gifts_count; i++){
        sum+=prices[i];
    }
    return sum*(1.0-discount);
}
void list_gifts(){
    for(int i=0; i<gifts_count; i++){
        cout<<ids[i]<<" "<<fixed<<setprecision(2)<<prices[i]<<endl;
    }
}
void gifts_clear(){
    gifts_count=0;
    discount=0.0;
}

int main()
{
    string command;
    while(true){
        cout<<"Enter command: ";
        cin>>command;
        if(command=="cart.add" ||command=="add"){
            string id;
            double price;
            cin>>id;
            cin>>price;
            add(id, price);
        }
        else if (command=="cart.remove" ||command=="remove"){
            string id;
            cin>>id;
            remove_gift(id);
        }
        else if (command=="cart.applyDiscount" ||command=="apply discount" || command=="discount" ){
            string code;
            cin>>code;
            apply_discount(code);
        }
        else if (command=="cart.total" ||command=="total"){
            cout<<fixed<<setprecision(2)<<total()<<endl;
        }
        else if(command=="cart.list" || command=="list"){
            list_gifts();
        }
        else if(command=="cart.clear" || command=="clear"){
            gifts_clear();
        }
        else if(command=="cart.exit" || command=="exit"){
            break;
        }
        else {
            cout<<"Incorrect command!";
        }
    }
    return 0;
}
