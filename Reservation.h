//
//  Reservation.h
//  Final Project
//
//  Created by Ainur Aman on 2021. 05. 06..
//

#ifndef Reservation_h
#define Reservation_h
#include "Ticket.h"
#include "airplane.h"

class Reserve: public Ticket{
    
private:
    int position;
    Ticket *pData;
    
public:
    
    Reserve();
    ~Reserve();
    Reserve(const Reserve& theOther);
    int line_num();
    void getfromfile();
    void booking(int flightnum);
    void savetofile();
    
    void getflightinfo(int fnum, int tickid);
    void searchticket(int tickid);
    void cancel(int tickid);
    void del(int ticketid);

    
};


#endif /* Reservation_h */
