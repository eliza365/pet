#ifndef PET_H
#define PET_H
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

class FileIOError{
  
};
class EmptyFileError{
private: 
    bool empty;
  public:
    EmptyFileError(bool w = false){empty = w;};
    bool isEmpty(){return empty;};
};

class Pet{
  public:
    Pet();
    bool isInput(int x);
    void fileMenu();
    string startGame();
    string newGame();
    string fileType();
    virtual void deleteData(string filename);
    //The load and save files may become virtual becomes the dervided has to have a save and load too
    virtual void loadData(string filename);
    virtual void saveData(string filename);
    void setName(string n);
    bool checkName(string me);
    string getName() const;
    int getFullness() const;
    int getAwakeness() const;
    int getExcitement() const;
    int getEXP() const;
    int getStage() const; 
    virtual void evoSta() = 0;
    virtual bool isAsleep();
    virtual string getType() const = 0;
    virtual void checkExp() = 0;
    void checkStat(int& stat);
    virtual void options() = 0;
    virtual void gameScreen() = 0;
    virtual bool checkOption(int x) = 0;
    virtual void checkStatus();
    virtual void nextHour(); 
    virtual void giveFood();
    virtual void setBed();
    virtual void giveToy();

  protected:
    string name, type, id;
    int stage, exp, full, awake, excitement, stress, sleepStage;
};
#endif