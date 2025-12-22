#include <iostream>
#include <windows.h>
#include <string>
using namespace std;


//A function that count the actual number of letters(added because there are Lithuanian letters that count as 2 bytes)
int utf8_length(const string& s){
    int count_l=0;
    for(unsigned char c:s){
        if((c & 0b11000000) !=0b10000000){
            count_l++;
        }
    }
    return count_l;
}


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    string text="Dega Kalėdų žvakutė,\n"
    "Virpa liepsnelė šilta.\n"
    "Linksma vaikams prie eglutės-\n"
    "Šventė atėjo laukta.\n"
    "Beldžias Kalėdų Senelis,\n"
    "Žengia orus pro duris.\n"
    "Spindi mažylių akelės,\n"
    "Spurda iš laimės širdis.\n"
    "Liejasi posmai, dainelės,\n"
    "Sukasi kaukės ratu,\n"
    "Tiesiasi mažos rankelės\n"
    "Prie dovanų atneštų.\n";


    string words[1000];
    int word_count=0;
    string current="";

    for(size_t i=0; i<=text.length(); i++){
        if(i==text.length() || text[i]==' ' || text[i]== '\n'){
            if(current!=""){
                words[word_count]=current;
                word_count++;
                current="";
            }
        }
        else{
            current+=text[i];
        }
    }

    int max_length=0;
    for(int i=0; i<word_count; i++){
        if((int)words[i].length()>max_length){
            max_length=words[i].length();
        }
    }

    int levels=0;
    int sum=0;
    while(sum<word_count){
        levels++;
        sum+=levels;
    }
    int center=100;

    int index=0;

    for(int level=1; level<=levels && index<word_count; level++){
        int start_index=index;
        int end_index=min(index+level-1, word_count-1);
        int trunk_pos_in_line=0;
        if(level%2!=0){
            trunk_pos_in_line=0;
        }
        else{
            trunk_pos_in_line=0;
            for(int i=start_index; i<end_index; i++){
                trunk_pos_in_line+=utf8_length(words[i])+1;
            }
            trunk_pos_in_line+=utf8_length(words[end_index])-1;
        }
        int indent=center-trunk_pos_in_line;
        if(indent<0){
            indent=0;
        }

        cout<<string(indent, ' ');
        for(int i=start_index; i<=end_index; i++){
            cout<<words[i];
            if(i<end_index){
                cout<<" ";
            }
        }
        cout<<endl;
        index+=level;
    }
    return 0;
}
