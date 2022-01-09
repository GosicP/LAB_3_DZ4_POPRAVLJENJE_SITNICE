
#ifndef MAIN_CPP_PRIVILEGOVANI_H
#define MAIN_CPP_PRIVILEGOVANI_H
#include "Tim.h"

class GMinVrednost : public exception{
    const char* what() const noexcept override{
        return " ***Igrac nije dovoljno vredan";
    }
};

class Privilegovani : public Tim{
private:

    int minimalna_vrednost_igraca;

    virtual void pisi(ostream &os){
        os<<naziv<<"("<<minimalna_vrednost_igraca<<")"<<"[";
        for (int i=0; i<broj_igraca; i++){
            if(i!=broj_igraca-1){
                os<<*niz[i]<<",";
            }else{
                os<<*niz[i];
            }
        }
        os<<"]";
    }

public:

    Privilegovani(string name, int max_players, int min_value) : Tim(name, max_players){
        minimalna_vrednost_igraca=min_value;
    }

    void prikljuciPrivilegovanom(int i, Igrac *player){
        if(player->getVrednost()<minimalna_vrednost_igraca){
            throw GMinVrednost();
        }
        prikljuciIgraca(i, player);
    }

    friend ostream& operator<<(ostream &os, Privilegovani& ptim){
        ptim.pisi(os);
        return os;
    }


};


#endif
