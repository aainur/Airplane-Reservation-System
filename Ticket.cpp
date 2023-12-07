//
//  Ticket.cpp
//  Final Project
//
//  Created by Ainur Aman on 2021. 04. 19..
//

#include <stdio.h>
#include "Ticket.h"
#include <fstream>
#include "airplane.h"


Ticket:: Ticket(){ //Default constructor of Ticket class
    ticketid=0;
    fnum=0;
    name="";
    surname="";
    passportID="";
    dateofbirth="";
    phonenumber="";
    email="";
}

Ticket:: Ticket(const Ticket& theOther){ //CopyConstructor of Ticket class
    ticketid=theOther.ticketid;
    fnum=theOther.fnum;
    name=theOther.name;
    surname=theOther.surname;
    passportID=theOther.passportID;
    dateofbirth=theOther.dateofbirth;
    phonenumber=theOther.phonenumber;
    email=theOther.email;
}

 Ticket& Ticket:: operator = ( Ticket &theOther){ //operator overloading to assign one ticket to another easily 
    Ticket t(theOther);
    return t;
}


std::istream& operator >> (istream& is, Ticket& t) //operator overloading to get ticket info easily
{
    t.ticketid=0;
    t.fnum=0;
    cout << "\t\t\t\tPlease enter your personal information to make a reservation" << endl;
    cout << "\t\t\t\tName: ";
    is >> t.name;
    cout << "\t\t\t\tSurname: ";
    is >> t.surname;
    cout << "\t\t\t\tPassport ID: ";
    is >> t.passportID;
    cout << "\t\t\t\tDate of birth: ";
    is >> t.dateofbirth;
    cout << "\t\t\t\tPhone number: ";
    is >> t.phonenumber;
    cout << "\t\t\t\tEmail: ";
    is >> t.email;
    cout<<endl;
    return is;
}


std::ostream& operator<<(ostream& os, Ticket& t){ //operator overloading to print ticket info easily
    if(t.ticketid==0 && t.fnum==0){
        os<<" "<<t.name<<" "<<t.surname <<" "<<t.passportID <<" "<<t.dateofbirth <<" "<<t.phonenumber <<" "<<t.email <<" "<<endl;
    }else{
        os<<" "<<t.ticketid <<" "<<t.fnum <<" "<<t.name<<" "<<t.surname <<" "<<t.passportID <<" "<<t.dateofbirth <<" "<<t.phonenumber <<" "<<t.email <<" "<<endl;
    }
    return os;
}


