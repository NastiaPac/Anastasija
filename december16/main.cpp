#include <iostream>

using namespace std;

int main()
{
    const int workshops_count=3;
    int elves[3]={3, 4, 2};
    int workshops[workshops_count][4]={ {5, 7, 3}, {6, 4, 4, 5}, {10, 2}};
    int total_gifts=0;
    for(int i=0; i<workshops_count; i++){
        int workshops_gifts=0;
        for(int j=0; j<elves[i]; j++){
            workshops_gifts+=workshops[i][j];
        }
        cout<<"Workshop "<<i+1<<" made "<<workshops_gifts<<" gifts"<<endl;
        total_gifts+=workshops_gifts;
    }
    cout<<"Santa's total gift count is "<<total_gifts;
    return 0;
}
