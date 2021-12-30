#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Training.h"
using namespace std;

void Load_Flash_Card(vector<string>& en, vector<string>& ch){
    system("cls");
    string file_name;
    cout << "----------------------- Load a flash card -------------------------" << endl;
    cout << "Please enter the file name to load flash card. ex. flashcard.csv" << endl;
    cin >> file_name;
    ifstream file;
    //open a file
    file.open(file_name);
    string str, data;

    cout << "loading a flash card..." << endl;

    if(file.is_open()){
        while(getline(file,str)){
            istringstream iss(str);
            int counts = 0;
            while(getline(iss, data, ',')){
                counts++;
                if(counts%2 == 1){
                    en.push_back(data);
                }
                else{
                    ch.push_back(data);
                }
            }
        }

        for(size_t i=0; i< en.size(); i++){
            cout << i << setw(20) << en[i] << setw(20) << ch[i] << endl;
        }
    }
    else{
        cout << "Error!!!" << endl;
    }

    file.close();
    return;
}

void Add_Flash_Card(vector<string>& en, vector<string>& ch){

    char s;
    do{
        system("cls");
        cout << "------------------------ Add a flash card ---------------------------" << endl;
        cout << "Please press the key below." << endl;
        cout << "1.Back(b)" << setw(30) << "2.Add a card(a)" << setw(30) << "3.print the list(p)"<< endl;
        cin >> s;
        string english, chinese;
        switch(s){
            case 'a':
                cout << "Please key in a pair of English and Chinese." << endl;
                cin >> english >> chinese;
                en.push_back(english);
                ch.push_back(chinese);
                break;
            case 'p':
                for(size_t i=0; i<en.size(); i++){
                    cout << setw(5) << "#" << i << setw(20) << en[i] << setw(20) << ch[i] << endl;
                }
                system("pause");
                break;
            default:

                break;
        }
    }while(s !='b');

    return;
}

void Save_Flash_Card(vector<string>& en, vector<string>& ch){
    ofstream file;
    string file_name;
    cout << "Please enter a file name to save all flash cards. ex. flashcard_1.csv" << endl;
    cin >> file_name;
    file.open(file_name);
    size_t Flash_size = en.size();

    if(file.is_open()){
        for(size_t i = 0; i< Flash_size; i++){
            file << en[i] << ',' << ch[i] << ',' << '\n';
        }
    }
    else{
        cout << "Error!!!" << endl;
    }
    return;
}

int main()
{

    vector<string> en_words, ch_words;

    char s;

    do{
        cout << "This is a simple flash card app. Please press the shortcut key below." << endl;
        cout << "此為簡易型單字卡app，請按下以下的快捷鍵" << endl;
        cout << "-------------------------------------------------- " << endl;
        cout << endl;
        cout << "load a flash card(l)" << endl;
        cout << "add a flash card(a)" << endl;
        cout << "practice with flash card(p)" << endl;
        cout << "save the flash card to csv file(s)" << endl;
        cout << "quit(q)" << endl;
        cin >> s;

        switch(s){
            case 'l':
                Load_Flash_Card(en_words, ch_words);
                break;
            case 'a':
                Add_Flash_Card(en_words , ch_words);
                break;
            case 'p':
                Training(en_words, ch_words);
                break;
            case 's':
                Save_Flash_Card(en_words, ch_words);
                break;
        }
        system("pause");
        system("cls");
    }while(s != 'q');

    return 0;
}
