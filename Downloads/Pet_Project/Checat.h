#ifndef CHECAT_H
#define CHECAT_H
#include "Pet.h"

class Checat : public Pet{
  public:
    Checat();
    void deleteData(string filename) override;
    void loadData(string filename) override;
    void saveData(string filename) override;
    void gameScreen() override;
    void evoSta() override;
    void drawDress();
    void changeDress();
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
    void cardGame(); 
    void teaTime();
  private:
    int dress;
};
#endif