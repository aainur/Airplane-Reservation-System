//
//  airplane.h
//  Final Project
//
//  Created by Ainur Aman on 2021. 03. 18..
//

#ifndef airplane_h
#define airplane_h
#include <iostream>
using namespace std;
class Airplane{
public:
    int planeid;
    int flightnum;
    string leavingfrom;
    string goingto;
    string depaturedate;
    int price;

    Airplane();
    Airplane(const Airplane &theOther);
    Airplane( int fnum, string lf, string gt, string dd, int p): flightnum(fnum), leavingfrom(lf),goingto(gt), depaturedate(dd), price(p) {};
    void selectcities();
    
};
std::ostream& operator<<(ostream& os, Airplane& t);
#endif
