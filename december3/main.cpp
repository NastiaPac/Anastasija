#include <iostream>

using namespace std;

int main()
{
    int number, new_number;
    cout<<"Enter four-digit number: ";
    cin>>number;
    if(number>=1000 && number<10000){
        int first_digit=number/1000;
        int second_digit=number%10;
        new_number=first_digit*10+second_digit;
        cout<<"New number is: "<<new_number;
    }
    else{
        cout<<"You entered an incorrect number!";
    }
    return 0;
}
