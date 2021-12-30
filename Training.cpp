#include <iostream>
#include "Training.h"
#include <windows.h>
using namespace std;

void Training_Random(vector<string>& en, vector<string>& ch){
    size_t Flash_Size = en.size();
    vector<int> Random_Record;
    vector<int> Random(Flash_Size);
    srand(time(NULL));
    char s;             // shortcut key
    size_t i = 0;       // index of random flash card

    // create a random list
    for(size_t i = 0; i < Flash_Size; i++){
        Random[i] = i;
    }
    for(size_t i = 0; i< Flash_Size ; i++){
        size_t counts = rand()% Random.size();
        Random_Record.push_back(Random[counts]);
        Random.erase(Random.begin() + counts);
    }

    while(1){
        system("cls");
        cout << "-------------------- Training (Random mode) ---------------------" << endl;
        cout << "Previous(p)" << setw(25) << "next(n)" << setw(30) << "stop(s)" << endl;
        cout << endl;
        cin >> s;
        size_t n = 0;
        if( s == 'n'){
            if(i == Flash_Size-1){
                i = 0;
            }
            else{
                i++;
            }
        }
        if( s == 'p'){
            if(i == 0){
                i = Flash_Size-1;
            }
            else{
                i--;
            }
        }
        if(s == 's')
            break;
        n = Random_Record[i];
        cout << en[n] << setw(15) << ch[n] << endl;
        system("pause");
    }
    return;
}

void Training_Sequential(vector<string>& en, vector<string>& ch){
    char s;
    size_t i = 0;
    while(s!= 's'){
            system("cls");
            cout << "------------------ Training (Sequential mode) -------------------" << endl;
            cout << "Previous(p)" << setw(25) << "next(n)" << setw(30) << "stop(s)" << endl;
            cin >> s;
            cout << endl;
            if(s == 'p'){
                if(i == 0){
                    i = en.size()-1;
                }
                else{
                    i--;
                }
            }
            if( s == 'n'){
                if(i == en.size()-1){
                    i = 0;
                }
                else{
                    i++;
                }
            }
            if(s == 's')
                break;
            cout << en[i] << setw(15) << ch[i] << endl;
            system("pause");
    }
    return;
}

void Training_Automatic(vector<string>& en, vector<string>& ch){
    char s;
    while(s!= 'b'){
            system("cls");
            cout << "------------------ Training (Automatic mode) -------------------" << endl;
            cout <<  "run(r)" << setw(30) << "back(b)" << endl;
            cin >> s;
            cout << endl;
            if( s == 'r'){
                size_t i = 0;
                while(i!= en.size()){
                    system("cls");
                    cout << endl << endl << endl;
                    cout << setw(30) << en[i] << setw(60) << ch[i] << endl;
                    Sleep(2*1000);
                    i++;
                }
            }

    }
    return;
}

void Training(vector<string>& en, vector<string>& ch){


    if(en.size() == 0){
        cout << "The flash card is empty. Please add or load a flash card." << endl;
        return;
    }
    char s;
    do{
        system("cls");
        cout << "-------------------------- Training ----------------------------" << endl;
        cout << "random mode(r)" << setw(28) << "sequential mode(s)" << setw(23) << "back(b)" << endl;
        cout << "automatic mode(a)" << endl;
        cin >> s;
        switch(s){
            case 'r':
                Training_Random(en, ch);
                break;
            case 's':
                Training_Sequential(en, ch);
                break;
            case 'a':
                Training_Automatic(en,ch);
            default:
                system("cls");
                break;
        }

    }while(s != 'b');

    return;
}
