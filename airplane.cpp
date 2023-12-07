//  airplane.cpp
//  Final Project
//
//  Created by Ainur Aman on 2021. 04. 18..

#include <stdio.h>
#include "airplane.h"
#include <iostream>
#include <string>
using namespace std;

Airplane:: Airplane(){ //Default Constructor of Airplane class
    flightnum=0;
    leavingfrom="";
    goingto="";
    depaturedate="";
    price=0;
}

Airplane:: Airplane(const Airplane &theOther){ //Copy Constructor of Airplane class
    flightnum = theOther.flightnum;
    leavingfrom= theOther.leavingfrom;
    goingto= theOther.goingto;
    depaturedate= theOther.depaturedate;
    price= theOther.price;
}


std::ostream& operator<<(ostream& os, Airplane& t){ //operator overloading to print airplane info easily
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    os<<"\t\t "<<t.flightnum <<") "<<t.leavingfrom <<" ---> "<<t.goingto<<" :"<<endl;
    os<<"\t\tDeparture date: "<<t.depaturedate <<"  "<<endl;
    os<<"\t\tPrice: "<<t.price <<"$ "<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    return os;
}



