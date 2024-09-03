#include "Checat.h"

Checat::Checat() : Pet(){
  type = "Checat";
  dress = 0;
}
void Checat::deleteData(string filename) {
  filename = filename + ".txt";
  ofstream fout;
  fout.open(filename);
  fout.close();
}
void Checat::loadData(string filename) {
  string filenamet = filename + ".txt";
  ifstream fin;
  fin.open(filenamet);
  fin >> type >> name;
  fin >> id >> stage >> exp >> full >> awake >> excitement >> stress >> sleepStage >> dress;
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
void Checat::saveData(string filename) {
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
  fout << dress << endl;
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
void Checat::gameScreen(){
  cout << "\n\n+====================================================+\n\n"<< endl;
  cout <<      "  Name:" << name << "    Hunger:" << full << "    Drowsiness:" << awake;
  cout <<      "    Happy:" << excitement << endl;
  cout << "\n\n";
  drawDress();
  cout << "\n\n                        1: Menu                    " << endl;
  cout << "\n\n+====================================================+\n\n"<< endl;
}
void Checat::evoSta(){
  if(getStage() == 1){
    cout <<      "                   (= ^ ω ^ =)  (" << endl;
  }
  else if(getStage() == 2){
    cout <<      "                   (= 0 ◡ 0 =)  (" << endl;
  }
  else if(getStage() == 3){
    cout <<      "                   (= ◕ ᴥ ◕ =)  (" << endl;
  }
}
void Checat::drawDress(){
  if(dress == 0){
    cout <<      "\n                      |¯¯¯|                       " << endl;
    cout <<      "                      |___|                       " << endl;
    cout <<      "                    /\\└═══┘/\\    )                " << endl;
    evoSta();
    cout <<      "                    \\       /    )                " << endl;
    cout <<      "                    /   ^   \\   /                 " << endl;
    cout <<      "                   (_| |_| |_)⌣             " << endl;
  }
  else if(dress == 1){
    cout <<      "\n                                             " << endl;
    cout <<      "                                             " << endl;
    cout <<      "                    /\\__︵__/\\    )                " << endl;
    evoSta();
    cout <<      "                    \\       /    )                " << endl;
    cout <<      "                    / |>o<| \\   /                 " << endl;
    cout <<      "                   (_| |_| |_)⌣             " << endl;
  }
  else if(dress == 2){
    cout <<      "\n                                  _                  " << endl;
    cout <<      "                                 (                " << endl;
    cout <<      "                    /\\__︵__/\\  |>☆<|                " << endl;
    evoSta();
    cout <<      "                    \\       /    )                " << endl;
    cout <<      "                    /   ^   \\   /                 " << endl;
    cout <<      "                   (_| |_| |_)⌣             " << endl;
  }
}
void Checat::changeDress(){
  bool isDone = false;
  int inp = 0;
  while(!isDone){
    cout << "\n\n+====================================================+\n\n"<< endl;
    cout <<      "   How would you like " << name << " to dress up?\n" << endl;
    cout <<      "        |¯¯¯|                                       " << endl;
    cout <<      "        |___|            |>o<|             |>☆<|    " << endl;
    cout <<      "        └═══┘                                       \n" << endl;
    cout <<      "    11: Top Hat       12: Bowtie        13: Ribbon  " << endl;
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
  dress = inp - 11;
}
bool Checat::isAsleep(){
  if (sleepStage != 0) {
    cout << name << " is asleep!" << endl;
    return true;
  }
  return false;
}
string Checat::getType() const{return "Checat";}
void Checat::checkExp(){
  if (exp >= 100 && stage == 1) {
    cout << name << " has evolved!" << endl;
    stage++;
  }
  else if (exp >= 2000 && stage == 2) {
    cout << name << " has evolved!" << endl;
    stage++;
    string contin = "";
    while(contin == ""){
      cout << "\n\n+====================================================+\n\n" << endl;
      cout <<      "      Congratulations! You've beaten the game!      \n\n" << endl;
      drawDress();
      cout <<      "\n You have earned your certification for exotic pets!" << endl;
      cout <<      "You can choose to continue your care of your current" << endl;
      cout <<      "  pet or start anew. The choice is yours to make!   " << endl;
      cout << "\n\n+====================================================+\n" << endl;
      cout << "Type and press Enter to continue....\n\n" << endl;
      cin >> contin;
    }
  }
}
void Checat::options(){
  bool isCorrect = false;
  while(!isCorrect){
    cout << "\n\n+====================================================+\n\n" << endl;
    cout <<     "                        Options                       \n" << endl;
    cout <<     "                     1: Give Food                     " << endl;
    cout <<     "                     2: Give Toy                     " << endl;
    cout <<     "                     3: Tea Time                     " << endl;
    cout <<     "                     4: Card Game                 " << endl;
    cout <<     "                     5: Set Bed                     " << endl;
    cout <<     "                     6: Change Wear                " << endl;
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
bool Checat::checkOption(int x){
  if(x == 1){giveFood(); return true;}
  else if(x == 2){giveToy(); return true;}
  else if(x == 3){teaTime(); return true;}
  else if(x == 4){cardGame(); return true;}
  else if(x == 5){setBed(); return true;}
  else if(x == 6){changeDress(); return true;}
  else if(x == 7){nextHour(); return true;}
  else if(x == 8){saveData(id); return true;}
  else if(x == 9){exit(1); return true;}
  cout << "\n                   Invalid Input\n" << endl;
  return false;
}
void Checat::checkStatus() {
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
  if (stress >= 80 && stress < 100) {
    cout << name << " is unhappy! It might leave you!" << endl;
  } else if (stress == 100) {
    cout << "\n\n+====================================================+\n\n" << endl;
    cout << "    You failed to care for " << name << ". " << name << " has left.\n" << endl;
    drawDress();
    cout <<      "\n        This save file will now be deleted." << endl;
    cout <<      " To retry for your certification, start a new game." << endl;
    cout << "\n\n+====================================================+\n\n" << endl;
    deleteData(id);
    exit(1);
  }
  checkExp();
}
void Checat::nextHour(){
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
void Checat::giveFood() {
  if (isAsleep()) {
    return;
  }
  if (full < 100) {
    cout << "You gave some food!" << endl;
    full += 10;
    awake -= 5;
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
void Checat::setBed() {
  if (isAsleep()) {
    return;
  }
  else if (awake > 20) {
    cout << name << " is not sleepy!" << endl;
    checkStatus();
  } 
  else {
    cout << name << " is now sleeping!" << endl;
    awake = 50;
    stress -= 15;
    cout << name << " gained 30 EXP!";
    exp += 30;
    cout << " Current EXP: " << exp << endl;
    sleepStage = 3;
    checkStatus();
  }
}
void Checat::giveToy() {
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
void Checat::cardGame(){
  if (isAsleep()) {
    return;
  }
  int catNum = (rand() % 13) + 1;
  int ourNum = (rand() % 13) + 1;
  bool isDone = false;
  while(!isDone){
    int inp;
    int answer;
    cout << "\n\n+====================================================+\n\n"<< endl;
    cout <<      "         Guess! Does " << name << " have a number" << endl;
    cout <<      "              higher or lower than yours?     " << endl;
    drawDress();
    cout <<      "\n     |¯¯¯¯¯|           21: Higher     22: Lower  " << endl; 
    cout <<      "        " << ourNum << "                    23: Equal       " << endl;
    cout <<      "     |_____|                                           " << endl; 
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
    inp -= 21;
    if(catNum > ourNum){answer = 0;}
    else if(catNum < ourNum){answer = 1;}
    else if(catNum == ourNum){answer = 2;}
    if(answer == inp){
      cout << "\n\n+====================================================+\n\n"<< endl;
      cout <<      "                    You're Correct!                 \n" << endl;
      drawDress();
      cout <<      "     |¯¯¯¯¯|                           |¯¯¯¯¯|" << endl; 
      cout <<      "        " << ourNum << "                                 " << catNum  << "  " << endl;
      cout <<      "     |_____|                           |_____|        \n" << endl; 
      cout << "\n\n+====================================================+\n\n"<< endl; 
      cout << name << " gained 50 EXP!";
      exp += 50;
      cout << " Current EXP: " << exp << endl;
      checkStatus();
    }
    else{
      cout << "\n\n+====================================================+\n\n"<< endl;
      cout <<      "                    You're Wrong!                 \n" << endl;
      drawDress();
      cout <<      "     |¯¯¯¯¯|                           |¯¯¯¯¯|" << endl; 
      cout <<      "        " << ourNum << "                                 " << catNum  << "   " << endl;
      cout <<      "     |_____|                           |_____|        \n" << endl; 
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
}
void Checat::teaTime(){
  if (isAsleep()) {
    return;
  }
  else if (excitement < 70 && full < 75) {
    cout << "You partook in tea time with " << name << "!" << endl;
    full += 20;
    awake -= 15;
    excitement += 20;
    stress -= 10;
    cout << name << " gained 20 EXP!";
    exp += 20;
    cout << " Current EXP: " << exp << endl;
    checkStatus();
  } 
  else {
    if(full >= 75){
     cout << name << " is too full for tea time!" << endl;
    }
    else if(excitement >= 70){
      cout << name << " has too much energy for tea time!" << endl;
    }
  }
}