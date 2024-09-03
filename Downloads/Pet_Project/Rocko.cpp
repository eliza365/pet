#include "Rocko.h"

Rocko::Rocko() : Pet(){
  type = "Rocko";
  face = 0;
}
void Rocko::deleteData(string filename) {
  filename = filename + ".txt";
  ofstream fout;
  fout.open(filename);
  fout.close();
}
void Rocko::loadData(string filename) {
  string filenamet = filename + ".txt";
  ifstream fin;
  fin.open(filenamet);
  fin >> type >> name;
  fin >> id >> stage >> exp >> full >> awake >> excitement >> stress >> sleepStage >> face;
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
void Rocko::saveData(string filename) {
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
  fout << face << endl;
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
void Rocko::gameScreen(){
  cout << "\n\n+====================================================+\n\n"<< endl;
  cout <<      "  Name:" << name << "    Hunger:" << full << "    Luster:" << awake;
  cout <<      "    Happy:" << excitement << endl;
  cout << "\n\n";
  evoSta();
  cout << "\n\n                        1: Menu                    " << endl;
  cout << "\n\n+====================================================+\n\n"<< endl;
}
void Rocko::evoSta(){
  if(getStage() == 1){
    cout <<      "                          \\/                     " << endl;
    cout <<      "                          |\\                    " << endl;
    cout <<      "                       |¯¯¯¯¯¯|                  " << endl;
    drawFace();
    cout <<      "                       |______|            " << endl;
  }
  else if(getStage() == 2){
    cout <<      "                     ¯\\__    __/¯                   " << endl;
    cout <<      "                     _/  |  |  \\_                 " << endl;
    cout <<      "                       |¯¯¯¯¯¯|                  " << endl;
    drawFace();
    cout <<      "                       |______|            " << endl;
  }
  else if(getStage() == 3){
    cout <<      "                    *¯\\__☆  ☆__/¯*                   " << endl;
    cout <<      "                    ✧_/  |  |  \\_✧                 " << endl;
    cout <<      "                       |¯¯¯¯¯¯|                  " << endl;
    drawFace();
    cout <<      "                       |______|            " << endl;
  }
}
void Rocko::drawFace(){
  if(face == 0){
    cout <<      "                       | ●  ● |" << endl;
  }
  else if(face == 1){
    cout <<      "                       | ఠ  ఠ |" << endl;
  }
  else if(face == 2){
   cout <<      "                       | 皿皿 |" << endl;
  }
}
void Rocko::changeFace(){
  bool isDone = false;
  int inp = 0;
  while(!isDone){
    cout << "\n\n+====================================================+\n\n"<< endl;
    cout <<      "   Which face would you like " << name << " to have?\n" << endl;
    cout <<      "     | ●  ● |          | ఠ  ఠ |          | 皿皿 |     \n" << endl; 
    cout <<      "     11: Dots          12: Wide          13: Bars     " << endl;
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
  face = inp - 11;
}
bool Rocko::isAsleep(){
  if (sleepStage != 0) {
    cout << name << " is waiting for the polish to dry!" << endl;
    return true;
  }
  return false;
}
string Rocko::getType() const{return "Rocko";}
void Rocko::checkExp(){
  if (exp >= 200 && stage == 1) {
    cout << name << " has evolved!" << endl;
    stage++;
  }
  else if (exp >= 1500 && stage == 2) {
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
void Rocko::options(){
  bool isCorrect = false;
  while(!isCorrect){
    cout << "\n\n+====================================================+\n\n" << endl;
    cout <<     "                        Options                       \n" << endl;
    cout <<     "                     1: Give Food                     " << endl;
    cout <<     "                     2: Give Toy                     " << endl;
    cout <<     "                     3: Walk                     " << endl;
    cout <<     "                     4: Cup Game                 " << endl;
    cout <<     "                     5: Polish                     " << endl;
    cout <<     "                     6: Change Face                " << endl;
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
bool Rocko::checkOption(int x){
  if(x == 1){giveFood(); return true;}
  else if(x == 2){giveToy(); return true;}
  else if(x == 3){takeWalk(); return true;}
  else if(x == 4){cupGame(); return true;}
  else if(x == 5){setBed(); return true;}
  else if(x == 6){changeFace(); return true;}
  else if(x == 7){nextHour(); return true;}
  else if(x == 8){saveData(id); return true;}
  else if(x == 9){exit(1); return true;}
  cout << "\n                   Invalid Input\n" << endl;
  return false;
}
void Rocko::checkStatus() {
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
    cout << name << " is getting dull!" << endl;
  }
  checkStat(stress);
  if (stress >= 80 && stress < 100) {
    cout << name << " is unhappy! It might leave you!" << endl;
  } 
  else if (stress == 100) {
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
void Rocko::nextHour(){
  if(isAsleep()){
    sleepStage--;
    checkStatus();
    if(sleepStage == 0){
      cout << name << " is dry!" << endl;
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
void Rocko::giveFood() {
  if (isAsleep()) {
    return;
  }
  if (full < 100) {
    cout << "You gave some food!" << endl;
    full += 10;
    awake -= 2;
    excitement -= 5;
    stress -= 5;
    cout << name << " gained 10 EXP!";
    exp += 10;
    cout << " Current EXP: " << exp << endl;
    checkStatus();
  } else {
    cout << name << " is full!" << endl;
  }
}
void Rocko::setBed() {
  if (isAsleep()) {
    return;
  }
  if (awake > 20) {
    cout << name << " is not dull!" << endl;
    checkStatus();
  } 
  else {
    cout << name << " has been polished!" << endl;
    awake = 50;
    stress -= 15;
    cout << name << " gained 30 EXP!";
    exp += 30;
    cout << " Current EXP: " << exp << endl;
    sleepStage = 3;
    checkStatus();
  }
}
void Rocko::giveToy() {
  if (isAsleep()) {
    return;
  }
  if (excitement < 100) {
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
void Rocko::cupGame(){
  if (isAsleep()) {
    return;
  }
  bool isDone = false;
  int inp = 0;
  int answer = rand() % 3;
  while(!isDone){
    cout << "\n\n+====================================================+\n\n"<< endl;
    cout <<      "       Which cup is " << name << " underneath?      \n" << endl;
    cout <<      "      /¯¯¯\\            /¯¯¯\\            /¯¯¯\\      " << endl; 
    cout <<      "     |     |          |     |          |     |      " << endl; 
    cout <<      "     |     |          |     |          |     |      " << endl;
    cout <<      "     |_____|          |_____|          |_____|      \n" << endl; 
    cout <<      "     21: One          22: Two         23: Three     " << endl;
    cout << "\n\n+====================================================+\n\n"<< endl; 
    string tem;
    cin >> tem;
    try {
      inp = stoi(tem);
    } 
    catch (invalid_argument &err) {}
    if(inp == 21){
      isDone = true;
    }
    else if(inp == 22){
      isDone = true;
    }
    else if(inp == 23){
      isDone = true;
    }
    else{
      cout << "\n                   Invalid Input\n" << endl;
      isDone = false;
    }
  }
  inp -= 21;
  if(answer == inp){
    cout << "\n\n+====================================================+\n\n"<< endl;
    cout <<      "                    You're Correct!                 \n" << endl;
    evoSta();
    cout <<    "\n              " << name << " was underneath cup " << answer + 1 << "!" << endl;
    cout << "\n\n+====================================================+\n\n"<< endl; 
    cout << name << " gained 50 EXP!";
    exp += 50;
    cout << " Current EXP: " << exp << endl;
    checkStatus();
  }
  else{
    cout << "\n\n+====================================================+\n\n"<< endl;
    cout <<      "                     You're Wrong!                  \n" << endl;
    evoSta();
    cout <<    "\n              " << name << " was underneath cup " << answer + 1 << "!" << endl;
    cout << "\n\n+====================================================+\n\n"<< endl; 
    full -= 10;
    awake -= 10;
    excitement += 15;
    stress -= 5;
    cout << name << " gained 10 EXP!";
    exp += 10;
    cout << " Current EXP: " << exp << endl;
    checkStatus();
  }
}  
void Rocko::takeWalk(){
  if (isAsleep()) {
    return;
  }
  if (awake > 20) {
    cout << "You took " << name << " for a walk!" << endl;
    full -= 10;
    awake -= 10;
    excitement += 15;
    stress -= 5;
    cout << name << " gained 15 EXP!";
    exp += 15;
    cout << " Current EXP: " << exp << endl;
    checkStatus();
  } else {
    cout << name << " is too tired for a walk!" << endl;
  }
}