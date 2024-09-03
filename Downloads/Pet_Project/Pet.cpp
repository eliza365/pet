#include "Pet.h"

Pet::Pet() {
  name = "Unknown";
  id = "";
  stage = 1;
  exp = 0;
  full = 50;
  awake = 50;
  excitement = 50;
  stress = 0;
  sleepStage = 0;
}
bool Pet::isInput(int x){
  bool good = true;
  if (x == 1 || x == 2 || x == 3) {
    return good;
  }
  cout << "\n                   Invalid Input\n" << endl;
  good = false;
  return good;
}
void Pet::fileMenu(){
  cout << "\n\n+====================================================+\n\n" << endl;
  cout << "Type the corresponding number to select the options!" << endl;
  cout << "\n\n                     1:Save File 1" << endl;
  cout << "                     2:Save File 2" << endl;
  cout << "                     3:Save File 3" << endl;
  cout << "\n\n+====================================================+\n\n" << endl;
}
string Pet::startGame(){
  bool canMove = false;
  int input;
  string option;
  while (!canMove) {
    cout << "\n\n+====================================================+\n\n" << endl;
    cout << "Type the corresponding number to select the options!" << endl;
    cout << "\n\n                     1:Start Game" << endl;
    cout << "                     2:Load Game" << endl;
    cout << "                     3:Exit Game" << endl;
    cout << "\n\n+====================================================+\n\n" << endl;
    cin >> option;
    try {
      input = stoi(option);
    } catch (invalid_argument &err) {
    }
    canMove = isInput(input);
  }
  if (input == 3) {
    return "exit";
  }
  if (input == 1) {
    return "start";
  }
  return "go";
}
string Pet::newGame(){
  string petType;
  bool canMove = false;
  int temp;
  string input = "";
  while(input == ""){
  cout << "\n\n+====================================================+\n\n" << endl;
  cout <<      "       Welcome to the Creatures of the House!       \n\n" << endl;
  cout <<      " You have been tasked to take care one of the pets" << endl;
  cout <<      "   found around the house of the Living Mansion." << endl;
  cout <<      "   This task will decide whether or not you will" << endl;
  cout <<      "   recieve the certification to take home one of" << endl;
  cout <<      "exclusive exotic pets said to make dreams come true!" << endl;
  cout << "\n\n+====================================================+\n" << endl;
  cout << "Type and press Enter to continue....\n\n" << endl;
  cin >> input;
  }
  input = "";
  while(input == ""){
  cout << "\n\n+====================================================+\n\n" << endl;
  cout <<      "                   Caring is Key!                   \n\n" << endl;
  cout <<      "        Succesfully take care of your pet and       " << endl;
  cout <<      "     it will evolve to meet your level of care.     " << endl;
  cout <<      "If you fail to treat your pet with kindness, it will" << endl;
  cout <<      " leave you and you will be booted from the mansion. \n" << endl;
  cout <<      "   Be the pet owner other pets will be jealous of!  " << endl;
  cout << "\n\n+====================================================+\n" << endl;
  cout << "Type and Press Enter to continue....\n\n" << endl;
  cin >> input;
  }
  input = "";
  while (!canMove) {
    cout << "\n\n+====================================================+\n\n" << endl;
    cout <<      "           It's Time to Select Your Companion       " << endl;
    cout <<      "  Type the corresponding number to select your pet! \n" << endl;
    cout <<      "CAREFUL: Once you make a choice, you cannot go back!\n" << endl;
    cout <<      "                      |¯¯¯|                        " << endl;
    cout <<      "                      |___|                 ︵      " << endl;
    cout <<      "        \\/          /\\└═══┘/\\    )      ︵ |  ✧       " << endl;
    cout <<      "        |\\         (= ^ ω ^ =)  (      *  ||৲       " << endl;
    cout <<      "     |¯¯¯¯¯¯|       \\       /    )     ___||_☆_    " << endl;
    cout <<      "     | ●  ● |       /   ^   \\   /     |________|     " << endl;
    cout <<      "     |______|      (__||_||__)⌣        \\_____/           " << endl;
    cout <<      "                                                   " << endl;
    cout <<      "     1:Rocko         2: Checat          3: Bloop   " << endl;
    cout << "\n\n+====================================================+\n\n" << endl;
    cin >> input;
    try {
      temp = stoi(input);
    } 
    catch (invalid_argument &err) {
    }
    canMove = isInput(temp);
    if (temp == 1) {
      petType = "Rocko";
    } 
    else if (temp == 2) {
      petType = "Checat";
    } 
    else if (temp == 3) {
      petType = "Bloop";
    }
  }
  return petType;
}
string Pet::fileType(){
  string save;
  bool canMove = false;
  int input;
  string temp;
  while (!canMove) {
    fileMenu();
    cin >> temp;
    try {
      input = stoi(temp);
    } 
    catch (invalid_argument &err) {
    }
    canMove = isInput(input);
    if (input == 1) {
      save = "file1";
    } else if (input == 2) {
      save = "file2";
    } else if (input == 3) {
      save = "file3";
    }
  }
  return save;
}
void Pet::deleteData(string filename) {
  cout << "Trying to delete " << filename << endl;
  string tempfile = filename + ".txt";
  cout << "Trying to delete " << tempfile << endl;
  ofstream fout;
  fout.open(filename);
  fout.close();
}
void Pet::loadData(string filename) {
  string filenamet = filename + ".txt";
  ifstream fin;
  fin.open(filenamet);
  fin >> type >> name;
  fin >> id >> stage >> exp >> full >> awake >> excitement >> stress >> sleepStage;
  cout << "\n\n+====================================================+\n\n"
         << endl;
  cout << "                   Data loaded successfully!              \n"
         << endl;
  cout << "                   " << name << " : " << type << "\n" << endl;
  cout << "                 Stage: " << stage << "   EXP: " << exp << endl;
  cout << "\n\n+====================================================+\n\n"
         << endl;
  fin.close();
}
void Pet::saveData(string filename) {
  string filenamet = filename + ".txt";
  id = filename;
  ofstream fout(filenamet);
  fout << type << endl;
  fout << name << endl;
  fout << id << endl;
  fout << stage << endl;
  fout << exp << endl;
  fout << full << endl;
  fout << awake << endl;
  fout << excitement << endl;
  fout << stress << endl;
  fout << sleepStage;
  cout << "\n\n+====================================================+\n\n"
       << endl;
  cout << "                   Data saved successfully!              \n"
       << endl;
  cout << "                   " << name << " : " << type << "\n" << endl;
  cout << "                 Stage: " << stage << "   EXP: " << exp << endl;
  cout << "\n\n+====================================================+\n\n"
       << endl;
  fout.close();
}
void Pet::setName(string n) { name = n; }
bool Pet::checkName(string me){
  if(me.size() <= 4){
    if(iscntrl(me[0])){
      return false;
    }
    for(int x = 0; x < me.size(); x++){
      if(isspace(me[x])){
        cout << "Space Detected. Invalid Name.\n" << endl;
        return false;
      }
    }
    return true;
  }
  else{
    cout << "Name exceeds limit. Invalid Name.\n" << endl;
    return false;
  }
}
string Pet::getName() const { return name; }
int Pet::getFullness() const { return full; }
int Pet::getAwakeness() const { return awake; }
int Pet::getExcitement() const { return excitement; }
int Pet::getEXP() const {return exp;}
int Pet::getStage() const {return stage;} 
bool Pet::isAsleep() {
  if (sleepStage != 0) {
    cout << name << " is asleep!" << endl;
    return true;
  }
  return false;
}
void Pet::checkStat(int &stat) {
  if (stat < 0) {
    stat = 0;
  }
  if (stat > 100) {
    stat = 100;
  }
}
void Pet::checkStatus() {
  checkStat(full);
  if (full < 20) {
    cout << name << " is hungry!" << endl;
  }
  checkStat(excitement);
  if (excitement < 20) {
    cout << name << " is bored" << endl;
  }
  checkStat(awake);
  if (awake < 20) {
    cout << name << " is sleepy!" << endl;
  }
  checkStat(stress);
  if (stress >= 80) {
    cout << name << " is unhappy! It might leave you!" << endl;
  } else if (stress == 100) {
    cout << name << " has left. You failed to care for " << name << endl;
    exit(1);
  }
}
void Pet::nextHour(){
  if(isAsleep()){
    sleepStage--;
    checkStatus();
    if(sleepStage == 0){
      cout << name << " is awake!" << endl;
    }
  }
  else{
    stress += 15;
    full -= 15;
    awake -= 5;
    excitement -= 10;
    checkStatus();
  }
}
void Pet::giveFood() {
  if (isAsleep()) {
    return;
  }
  if (full < 100) {
    cout << "You gave some food!" << endl;
    full += 10;
    awake -= 5;
    excitement -= 5;
    stress -= 5;
    exp += 10;
    checkStatus();
  } else {
    cout << name << " is full!" << endl;
  }
}
void Pet::setBed() {
  if (isAsleep()) {
    return;
  }
  else if (awake > 20) {
    cout << name << " is not sleepy!" << endl;
    checkStatus();
  } 
  else {
    cout << name << " is now asleep!" << endl;
    awake = 50;
    stress -= 15;
    exp += 30;
    sleepStage = 3;
    checkStatus();
  }
}
void Pet::giveToy() {
  if (isAsleep()) {
    return;
  }
  if (excitement < 100) {
    cout << "You gave a toy!" << endl;
    full -= 5;
    awake -= 5;
    excitement += 10;
    stress -= 5;
    exp += 10;
    checkStatus();
  } else {
    cout << name << " does not want to play anymore!" << endl;
  }
}