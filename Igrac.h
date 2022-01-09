#ifndef LAB_3_DZ4_IGRAC_H
#define LAB_3_DZ4_IGRAC_H
using namespace std;
#include <iostream>
class Igrac {
protected:
    string ime;
    int vrednost=1000;

    virtual void pisi(ostream& os){
        os<<ime<<"#"<<vrednost;
    }
public:

    Igrac(string name, int value){
        ime=name;
        vrednost=value;
    }

    int getVrednost() const{
        return vrednost;
    };

    void promeniVrednost(double procenat){
        vrednost=vrednost+vrednost*(procenat/100);
    }


    bool operator == (Igrac& i){
        if(this->vrednost==i.vrednost && this->ime==i.ime){
            return true;
        }else{
            return false;
        }
    }

    friend ostream& operator<<(ostream& os, Igrac i){
        i.pisi(os);
        return os;
    }
};


#endif



