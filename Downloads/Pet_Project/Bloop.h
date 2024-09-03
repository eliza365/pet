#ifndef BLOOP_H
#define BLOOP_H
#include "Pet.h"

class Bloop : public Pet{
  public:
    Bloop();
    void deleteData(string filename) override;
    void loadData(string filename) override;
    void saveData(string filename) override;
    void gameScreen() override;
    void evoSta() override;
    void drawPlant();
    void changePlantType();
    bool isAsleep() override;
    string getType() const override;
    void checkExp() override;
    void options() override;
    bool checkOption(int x) override;
    void checkStatus() override;
    void nextHour() override; 
    void giveFood() override;
    void setBed() override;
    void giveToy() override;
    void listenMusic();
    void sunBath(); 
  private:
    int plant;
};
#endif