//
//  Ticket.h
//  Final Project
//
//  Created by Ainur Aman on 2021. 03. 19..
//

#ifndef Ticket_h
#define Ticket_h
#include "airplane.h"

class Ticket{

public:
    int ticketid;
    int fnum;
    string name;
    string surname;
    string passportID;
    string dateofbirth;
    string phonenumber;
    string email;
    

    Ticket(); //Default constructor of Ticket class
    
    Ticket(int tid, int fn, string n, string s, string pid, string dob, string pn, string e): ticketid(tid), fnum(fn), name(n), surname(s), passportID(pid), dateofbirth(dob), phonenumber(pn), email(e){
    };
    Ticket(const Ticket& theOther); //CopyConstructor of Ticket class
    
     Ticket& operator = ( Ticket &theOther); //operator overloading to assign one ticket to another easily
    
};

std::istream& operator>>(istream& is, Ticket& t); //operator overloading to get ticket info easily
std::ostream& operator<<(ostream& is, Ticket& t); //operator overloading to print ticket info easily
#endif /* Ticket_h */


