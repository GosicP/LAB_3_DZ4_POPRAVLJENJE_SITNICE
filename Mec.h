
#ifndef MAIN_CPP_MEC_H
#define MAIN_CPP_MEC_H
#include "Par.h"

class Mec {

private:

    Par<Tim> par_timova;
    Par<long int> par_poena;
    enum stanje{POBEDA_DOMACIN, NERESENO, POBEDA_GOST};
    stanje ishod;

protected:

    virtual void pisi(ostream& os){
        os<<par_timova<<endl;
        if(proveriDaLiJeOdigranMec()){
            switch(ishod){
                case 0:
                    os<<"POBEDA_DOMACIN";
                    break;
                case 1:
                    os<<"NERESENO";
                    break;
                case 2:
                    os<<"POBEDA_GOST";
                    break;
            }
        }
    }

public:

    Mec(Tim tim_domacin, Tim tim_gost)
            : par_timova(tim_domacin, tim_gost), par_poena(0, 0) {}


    void odigrajMec();

    bool proveriDaLiJeOdigranMec(){
        if(this->ishod==POBEDA_DOMACIN || this->ishod==NERESENO || this->ishod==POBEDA_GOST){
            return true;
        }else{
            return false;
        }
    }

    Par<long int> dohvParPoena(){
        return par_poena;
    }

    friend ostream& operator << (ostream& os, Mec &m){
        m.pisi(os);

        return os;
    }

};


#endif //MAIN_CPP_MEC_H