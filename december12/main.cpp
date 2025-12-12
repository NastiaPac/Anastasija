#include <iostream>

using namespace std;

int main()
{
    const int max_words=100;                //maximum number of words
    int n;
    cout<<"Enter the number of words: ";
    while(!(cin>>n) || n>max_words){
        cin.clear();
        cin.ignore(10000, '\n');
        cout<<"Error! Enter the number of words: ";
    }

    string words[n];
    bool used[n]={false};

    cout<<"Enter "<<n<<" words."<<endl;
    for(int i=0; i<n; i++){
        cout<<"Enter the "<<i+1<<" word: ";
        cin>>words[i];
    }
    string groups[max_words][max_words];    //array to store groups in a group
    int group_sizes[max_words];             //number of the words in each group
    int group_count=0;                      //total number of groups

    for(int i=0; i<n; i++){
        if(used[i]){
            continue;
        }
        int freq_i[26]={0};                 //count frequency of each letter in the current word
        for(char ch : words[i]){
            freq_i[ch-'a']++;
        }

        int current_group=group_count;
        groups[current_group][0]=words[i];
        group_sizes[current_group]=1;
        used[i]=true;

        for(int j=0; j<n; j++){
            if(used[j]){
                continue;
            }

            int freq_j[26]={0};
            for(char ch : words[j]){
                freq_j[ch - 'a']++;
            }
            bool equal_freq=true;           //check if two words have identical letter frequencies
            for(int x=0; x<26; x++){
                if(freq_i[x]!=freq_j[x]){
                    equal_freq=false;
                    break;
                }
            }                               //if it is anagrams, add word to the group
            if(equal_freq){
                groups[current_group][group_sizes[current_group]]=words[j];
                group_sizes[current_group]++;
                used[j]=true;
            }
        }
        group_count++;
    }
    //sort each group alphabetically
    for(int i=0; i<group_count; i++){
        for(int x=0; x<group_sizes[i]-1; x++){
            for(int y=x+1; y<group_sizes[i]; y++){
                if(groups[i][x]>groups[i][y]){
                    string temp=groups[i][x];
                    groups[i][x]=groups[i][y];
                    groups[i][y]=temp;
                }
            }
        }

    }
    //sort all groups by group size
    for(int i=0; i<group_count-1; i++){
        for(int j=i+1; j<group_count; j++){
            if(group_sizes[i]<group_sizes[j]){
                int temp_size=group_sizes[i];
                group_sizes[i]=group_sizes[j];
                group_sizes[j]=temp_size;

                for(int x=0; x<n; x++){
                    string temp=groups[i][x];
                    groups[i][x]=groups[j][x];
                    groups[j][x]=temp;
                }
            }
        }
    }
    cout<<endl;
    cout<<"Grouped anagrams: "<<endl;
    cout<<"[ "<<endl;

    for(int i=0; i<group_count; i++){
        cout<<"   [ ";
        for(int j=0; j<group_sizes[i]; j++){
            cout<<"\""<<groups[i][j]<<"\"";
            if(j!=group_sizes[i]-1){
                cout<<", ";
            }
            else{
                cout<<" ";
            }
        }
        cout<<"]";
        if(i!=group_count-1){
            cout<<",";
        }
        cout<<endl;
    }
    cout<<"]";
    return 0;
}
