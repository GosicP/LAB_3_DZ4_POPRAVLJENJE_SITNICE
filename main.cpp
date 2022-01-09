#include <iostream>
using namespace std;

#include "Mec.h"

int main() {
    Par<long int> par_poenaa(0,0);
    double vrednost_igraca, vrednost_tima;
    bool stanje;
    int broj_igraca;
    Igrac *i1=new Igrac("Pavle", 600);
    Igrac *i2=new Igrac("Petar", 800);
    Igrac *i3=new Igrac("Anastasija", 1000);
    Igrac *i4=new Igrac("Djordje", 1200);


    Privilegovani pt("Privilegovani tim 1", 5, 500);


    i1->promeniVrednost(10);
    vrednost_igraca=i1->getVrednost();

    cout<<vrednost_igraca<<endl;

    cout<<*i1<<endl;

    //stanje=(i1==i2);

    //cout << stanje <<endl;

    Tim *t1=new Tim("Tim Domacin", 5);
    Tim *t2=new Tim("Tim Gost", 5);

    t1->prikljuciIgraca(0, i2);
    t1->prikljuciIgraca(2, i1);
    t1->prikljuciIgraca(3, i4);

    t2->prikljuciIgraca(0, i2);
    t2->prikljuciIgraca(2, i1);
    t2->prikljuciIgraca(1, i3);

    broj_igraca=t1->getBrojIgraca();

    //*igrac_proba=t1->dohvIgraca(0);

    cout<<broj_igraca<<endl;

    //cout<<*igrac_proba<<endl;

    //stanje=(*t1==*t2);

    //cout<<stanje<<endl;

    vrednost_tima=t1->dohvVrednostTima();

    double vrednost_tima2=t2->dohvVrednostTima();

    cout<<vrednost_tima<<endl;

    pt.prikljuciPrivilegovanom(0, i2);
    pt.prikljuciPrivilegovanom(2, i1);
    pt.prikljuciPrivilegovanom(1, i3);
    cout<<pt<<endl;


    Mec *m=new Mec(*t1, *t2);

    m->odigrajMec();

    par_poenaa=m->dohvParPoena();

    cout<<par_poenaa;

    cout<<*m;


    return 0;
}
