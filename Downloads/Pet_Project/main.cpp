#include "Pet.h"
#include "Rocko.h"
#include "Bloop.h"
#include "Checat.h"

int main() {
  Pet* h;
  bool isStartActive = true;
  bool newGame = false;
  string type = "";
  string file;
  while (isStartActive) {
    file = h->startGame();
    if (file != "exit") {
      if (file == "go") {
        file = h->fileType();
        string filename = file + ".txt";
        ifstream fin(filename);
        if (!fin.is_open()) {
          cout << "ERROR: FILE NOT FOUND";
          exit(1);
        }
        string temp = type;
        getline(fin, type);
        fin.close();
        if(temp == type){
          cout << "This file has no save data. Please start a new game on this file." << endl;
          newGame = false;
        }
        else{
          if(type == "Rocko"){
            h = new Rocko;
          }
          else if(type == "Checat"){
            h = new Checat;
          }
          else if(type == "Bloop"){
            h = new Bloop;
          }
          h->loadData(file);
          newGame = false;
          isStartActive = false;
        }
      }
      if (file == "start") {
        file = h->fileType();
        string filename = file + ".txt";
        ifstream fin(filename);
        if (!fin.is_open()) {
          cout << "ERROR: FILE NOT FOUND";
          exit(1);
        }
        string temp = type;
        getline(fin, type);
        fin.close();
        if(temp != type){
          bool cont = false;
            while (!cont) {
              cout << "\n\n+====================================================+\n\n" << endl;
              cout << "  There is currently save data already in this file." << endl;
              cout << "\n   Starting a new game will delete the save file." << endl;
              cout << "\n    Are you sure you want to start a new game?" << endl;
              cout << "\n                 1:Yes    2:No" << endl;
              cout << "\n\n+====================================================+\n\n" << endl;
              int input;
              string temp;
              cin >> temp;
              try {
                input = stoi(temp);
              } 
              catch (invalid_argument &err) {
              }
              cont = h->isInput(input);
              //if(cont){
                //cout << "Input is good!" << endl; 
              //}
              if (input == 1) {
                cout << "Attempting to delete: " << file << endl;
                if(type == "Rocko"){
                  h = new Rocko;
                }
                else if(type == "Checat"){
                  h = new Checat;
                }
                else if(type == "Bloop"){
                  h = new Bloop;
                }
                /*
                switch(type){
                  case "Rocko":
                    h = new Rocko;
                    break;
                  case "Checat":
                    h = new Checat;
                    break;
                  case "Bloop":
                    h = new Bloop;
                    break;
                }
                */
                h->deleteData(file);
                cout << "\n                   File deleted!\n" << endl;
                newGame = true;
                isStartActive = false;
              } 
              else if (input == 2) {
                cout << "\n                Please load a save file.\n" << endl;
                newGame = false;
                type = "";
              }
            }
        }
        else{
            newGame = true;
            isStartActive = false;
        }
      }
    } 
    else {
      cout << "\n\n+====================================================+\n" << endl;
      cout << "\n                       Goodbye!\n" << endl;
      cout << "\n+====================================================+\n\n" << endl;
      exit(1);
    }
  }
  if(newGame){
    string petTypo = h->newGame();
    if(petTypo == "Rocko"){
      h = new Rocko;
    }
    else if(petTypo == "Checat"){
      h = new Checat;
    }
    else if(petTypo == "Bloop"){
      h = new Bloop;
    }
    bool isName = false;
    string mayName;
    while(!isName){
      cout << "Enter the name of your Pet(Max 4 Characters, No Space):" << endl;
      getline(cin, mayName);
      if(iscntrl(mayName[0])){
        getline(cin, mayName);
      }
        isName = h->checkName(mayName);
    }
    h->setName(mayName);
    h->saveData(file);
  }
  bool isActive = true;
  
  while(isActive){
    h->gameScreen();
    int input;
    string temp;
    cin >> temp;
    try {
      input = stoi(temp);
    } 
    catch (invalid_argument &err) {}
    if(input == 1){
      h->options();
    }
    else{
      cout << "\n                   Invalid Input\n" << endl;
    }

  }
  return 0;
}