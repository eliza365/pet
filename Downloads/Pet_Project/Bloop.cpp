#include "Bloop.h"

Bloop::Bloop() : Pet(){
  type = "Bloop";
  plant = 0;
}
void Bloop::deleteData(string filename) {
  filename = filename + ".txt";
  ofstream fout;
  fout.open(filename);
  fout.close();
}
void Bloop::loadData(string filename) {
  string filenamet = filename + ".txt";
  ifstream fin;
  fin.open(filenamet);
  fin >> type >> name;
  fin >> id >> stage >> exp >> full >> awake >> excitement >> stress >> sleepStage >> plant;
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
void Bloop::saveData(string filename) {
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
  fout << sleepStage << endl;
  fout << plant << endl;
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
void Bloop::gameScreen(){
  cout << "\n\n+====================================================+\n\n"<< endl;
  cout <<      "  Name:" << name << "    Thirst:" << full << "    Drowsiness:" << awake;
  cout <<      "    Happy:" << excitement << endl;
  cout << "\n\n";
  evoSta();
  cout << "\n\n                        1: Menu                    " << endl;
  cout << "\n\n+====================================================+\n\n"<< endl;
}
void Bloop::evoSta(){
  if(getStage() == 1){
    drawPlant();
  }
  else if(getStage() == 2){
    drawPlant();
  }
}
void Bloop::drawPlant(){
  if(getStage() == 1){
    if(plant == 0){
      cout <<      "\n                            ︵      " << endl;
      cout <<      "                        ︵ |  ✧       " << endl;
      cout <<      "                       *  ||৲       " << endl;
      cout <<      "                       ___||_☆_    " << endl;
      cout <<      "                      |________|     " << endl;
      cout <<      "                       \\_____/           " << endl;
    }
    else if(plant == 1){
      cout <<      "\n                            ︵      " << endl;
      cout <<      "                        ︵ |  ♡       " << endl;
      cout <<      "                       ♥  ||৲       " << endl;
      cout <<      "                       ___||_❦_    " << endl;
      cout <<      "                      |________|     " << endl;
      cout <<      "                       \\_____/           " << endl;
    }
    else if(plant == 2){
      cout <<      "\n                            ︵      " << endl;
      cout <<      "                        ︵ |  ♩       " << endl;
      cout <<      "                       ♫  ||৲       " << endl;
      cout <<      "                       ___||_♬_    " << endl;
      cout <<      "                      |________|     " << endl;
      cout <<      "                       \\_____/           " << endl;
    }
  }
  else if(getStage() == 2){
   if(plant == 0){
      cout <<      "\n                      ︵   _   ︵     " << endl;
      cout <<      "                   ︵     ✧       ৲       " << endl;
      cout <<      "                  (   *      ☆   )         " << endl;
      cout <<      "                    ︶  | ︶ |  ︶           " << endl;
      cout <<      "                        |    |             " << endl;
      cout <<      "                       /      \\             " << endl;
    }
    else if(plant == 1){
      cout <<      "\n                       ︵   _   ︵     " << endl;
      cout <<      "                    ︵      ♥      ৲       " << endl;
      cout <<      "                   (    ❦     ♡    )         " << endl;
      cout <<      "                     ︶  | ︶ |  ︶           " << endl;
      cout <<      "                         |    |             " << endl;
      cout <<      "                        /      \\             " << endl;
    }
    else if(plant == 2){
      cout <<      "\n                       ︵   _   ︵     " << endl;
      cout <<      "                    ︵     ♬       ৲       " << endl;
      cout <<      "                   (   ♫       ♩   )         " << endl;
      cout <<      "                    ︶  | ︶ |  ︶           " << endl;
      cout <<      "                        |    |             " << endl;
      cout <<      "                       /      \\             " << endl;
    }
  }
}
void Bloop::changePlantType(){
  bool isDone = false;
  int inp = 0;
  while(!isDone){
    cout << "\n\n+====================================================+\n\n"<< endl;
    cout <<      "         What type of plant is " << name << "?\n" << endl;
    cout <<      "       ☆              ❦                 ♬           " << endl;
    cout <<      "          ✧              ♡                 ♩        " << endl;
    cout <<      "    *                ♥               ♫              \n" << endl;
    cout <<      "    11: Star       12: Heart        13: Note  " << endl;
    cout << "\n\n+====================================================+\n\n"<< endl; 
    string tem;
    cin >> tem;
    try {
      inp = stoi(tem);
    } 
    catch (invalid_argument &err) {}
    if(inp == 11){
      isDone = true;
    }
    else if(inp == 12){
      isDone = true;
    }
    else if(inp == 13){
      isDone = true;
    }
    else{
      cout << "\n                   Invalid Input\n" << endl;
      isDone = false;
    }
  }
  plant = inp - 11;
}
bool Bloop::isAsleep(){
  if (sleepStage != 0) {
    cout << name << " is hibernating!" << endl;
    return true;
  }
  return false;
}
string Bloop::getType() const{return "Bloop";}
void Bloop::checkExp(){
  if (exp >= 1250 && stage == 1) {
    cout << name << " has evolved!" << endl;
    stage++;
    string contin = "";
    while(contin == ""){
      cout << "\n\n+====================================================+\n\n" << endl;
      cout <<      "      Congratulations! You've beaten the game!      \n\n" << endl;
      evoSta();
      cout <<      "\n You have earned your certification for exotic pets!" << endl;
      cout <<      "You can choose to continue your care of your current" << endl;
      cout <<      "  pet or start anew. The choice is yours to make!   " << endl;
      cout << "\n\n+====================================================+\n" << endl;
      cout << "Type and press Enter to continue....\n\n" << endl;
      cin >> contin;
    }
  }
}
void Bloop::options(){
  bool isCorrect = false;
  while(!isCorrect){
    cout << "\n\n+====================================================+\n\n" << endl;
    cout <<     "                        Options                       \n" << endl;
    cout <<     "                     1: Give Water                     " << endl;
    cout <<     "                     2: Give Toy                     " << endl;
    cout <<     "                     3: Listen to Music                     " << endl;
    cout <<     "                     4: Sun Bath                " << endl;
    cout <<     "                     5: Hibernate                     " << endl;
    cout <<     "                     6: Change Type                " << endl;
    cout <<     "                     7: Next Hour                " << endl;
    cout <<     "                     8: Save Game                    " << endl;
    cout <<     "                     9: Exit                     " << endl;
    cout << "\n\n+====================================================+\n\n" << endl;
    int input = 0;
    string temp;
    cin >> temp;
    try {
      input = stoi(temp);
    } 
    catch (invalid_argument &err) {}
    isCorrect = checkOption(input);
  }
}
bool Bloop::checkOption(int x){
  if(x == 1){giveFood(); return true;}
  else if(x == 2){giveToy(); return true;}
  else if(x == 3){listenMusic(); return true;}
  else if(x == 4){sunBath(); return true;}
  else if(x == 5){setBed(); return true;}
  else if(x == 6){changePlantType(); return true;}
  else if(x == 7){nextHour(); return true;}
  else if(x == 8){saveData(id); return true;}
  else if(x == 9){exit(1); return true;}
  cout << "\n                   Invalid Input\n" << endl;
  return false;
}
void Bloop::checkStatus() {
  checkStat(full);
  if (full < 20) {
    cout << name << " is thirsty!" << endl;
  }
  checkStat(excitement);
  if (excitement < 20) {
    cout << name << " is bored" << endl;
  }
  checkStat(awake);
  if (awake < 20) {
    cout << name << " wants to hibernate!" << endl;
  }
  checkStat(stress);
  if (stress >= 80 && stress < 100) {
    cout << name << " is unhappy! It might leave you!" << endl;
  } else if (stress == 100) {
    cout << "\n\n+====================================================+\n\n" << endl;
    cout << "    You failed to care for " << name << ". " << name << " has left.\n" << endl;
    evoSta();
    cout <<      "\n        This save file will now be deleted." << endl;
    cout <<      " To retry for your certification, start a new game." << endl;
    cout << "\n\n+====================================================+\n\n" << endl;
    deleteData(id);
    exit(1);
  }
  checkExp();
}
void Bloop::nextHour(){
  if(isAsleep()){
    sleepStage--;
    checkStatus();
    if(sleepStage == 0){
      cout << name << " finished hibernation!" << endl;
    }
  }
  else{
    stress += 15;
    full -= 15;
    awake -= 10;
    excitement -= 10;
    checkStatus();
  }
}
void Bloop::giveFood() {
  if (isAsleep()) {
    return;
  }
  else if (full < 100) {
    cout << "You gave some water!" << endl;
    full += 10;
    awake -= 5;
    excitement -= 5;
    stress -= 5;
    cout << name << " gained 10 EXP!";
    exp += 10;
    cout << " Current EXP: " << exp << endl;
    checkStatus();
  } 
  else {
    cout << name << " is hydrated!" << endl;
  }
}
void Bloop::setBed() {
  if (isAsleep()) {
    return;
  }
  else if (awake > 20) {
    cout << name << " does not want to hibernate!" << endl;
    checkStatus();
  } 
  else {
    cout << name << " is now hibernating!" << endl;
    awake = 50;
    stress -= 15;
    cout << name << " gained 60 EXP!";
    exp += 60;
    cout << " Current EXP: " << exp << endl;
    sleepStage = 3;
    checkStatus();
  }
}
void Bloop::giveToy() {
  if (isAsleep()) {
    return;
  }
  else if (excitement < 100) {
    cout << "You gave a toy!" << endl;
    full -= 5;
    awake -= 5;
    excitement += 10;
    stress -= 5;
    cout << name << " gained 10 EXP!";
    exp += 10;
    cout << " Current EXP: " << exp << endl;
    checkStatus();
  } else {
    cout << name << " does not want to play anymore!" << endl;
  }
}
void Bloop::listenMusic(){
  if (isAsleep()) {
    return;
  }
  if (excitement < 50) {
    cout << "You and " << name << " listened to music!" << endl;
    full -= 5;
    awake -= 10;
    excitement += 20;
    stress -= 10;
    cout << name << " gained 15 EXP!";
    exp += 15;
    cout << " Current EXP: " << exp << endl;
    checkStatus();
  } 
  else {
    cout << name << " is not in the mood to listen to music!" << endl;
  }
}
void Bloop::sunBath(){
  if (isAsleep()) {
    return;
  }
  else if (full < 50) {
    cout << "You and " << name << " enjoyed the sun!" << endl;
    full += 20;
    awake -= 10;
    excitement -= 5;
    stress -= 10;
    cout << name << " gained 15 EXP!";
    exp += 15;
    cout << " Current EXP: " << exp << endl;
    checkStatus();
  } 
  else {
    cout << name << " is already full of glucose!" << endl;
  }
}