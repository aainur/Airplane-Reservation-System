//
//  Storage.h
//  Final Project
//
//  Created by Ainur Aman on 2021. 04. 21..
//

#ifndef Storage_h
#define Storage_h
#include "airplane.h"
#include "Ticket.h"

class Database: public Airplane{
private:
    int position;
    Airplane *pData;
public:
    Database();
    ~Database();
    Database(const Database& theOther);
    
    int line_num();
    void getflightinfo();
    int selectcities();
    void print();
};


#endif /* Storage_h */
