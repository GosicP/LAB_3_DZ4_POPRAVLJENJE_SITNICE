
#define MAIN_CPP_TIM_H
#include "Igrac.h"

class Tim {
protected:

    string naziv;
    int maks_broj_igraca, broj_igraca=0;
    double vrednost_tima=0;



    virtual void pisi(ostream &os){
        int br=0;
        os<<naziv<<"[";
        for (int i=0; i<maks_broj_igraca; i++){
            if (niz[i]!=nullptr){
                if (br!=broj_igraca-1) { // proveri nekako da ne ispisuje prazna polja ako igrac ne postoji, izbacuje problem ako je mesto u nizu prazno
                    os << *niz[i] << ",";
                } else {
                    os << *niz[i];
                }
                br++;
            }
        }
        os<<"]";
    }

public:

    Igrac** niz; //=nullptr; // mozda ovo treba da se inicijalizuje

    Tim(string name, int max_players);

    Tim(const Tim& t);
    Tim( Tim&& t);
    //~Tim();

    void prikljuciIgraca(int i, Igrac *player){
        niz[i]=player;
        broj_igraca++;
    }

    int getBrojIgraca() const;

    Igrac dohvIgraca(int i){
        Igrac player=*niz[i];
        return player;
    }

    double dohvVrednostTima();

    bool operator==(Tim& t);

    friend ostream& operator << (ostream& os, Tim& t){
        t.pisi(os);
        return os;
    }


};