#ifndef ROCKO_H
#define ROCKO_H
#include "Pet.h"

class Rocko : public Pet{
  public:
    Rocko();
    void deleteData(string filename) override;
    void loadData(string filename) override;
    void saveData(string filename) override;
    void gameScreen() override;
    void evoSta() override;
    void drawFace();
    void changeFace();
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
    void cupGame();  
    void takeWalk();
  private:
    int face;
};
#endif