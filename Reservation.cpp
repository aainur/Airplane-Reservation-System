//
//  Reservation.cpp
//  Final Project
//
//  Created by Ainur Aman on 2021. 05. 06..
//

#include <stdio.h>
#include "Reservation.h"
#include "Ticket.h"
#include <fstream>
#include "airplane.h"


Reserve:: Reserve(){
    position=0;
    pData=NULL;
}

Reserve:: ~Reserve(){
    position=0;
    pData=NULL;
    delete [] pData;
}

Reserve:: Reserve(const Reserve& theOther){
    position=theOther.position;
    pData= new Ticket[theOther.position];
    for(int i=0; i<position; i++){
        pData[i] = theOther.pData[i];
    }
}


int Reserve:: line_num(){
    ifstream FFilein;
    FFilein.open("/Users/ainur/Desktop/programming labs/C++SecondSemester/my project/Final Project/Final Project/Ticketinfo.txt");
    int number_of_lines = 0;
        string line;
    while (getline(FFilein, line)){
        ++number_of_lines;}
    FFilein.close();
    return number_of_lines;
}


void Reserve:: getfromfile(){
    int ticketid;
    int fnum;
    string name;
    string surname;
    string passportID;
    string dateofbirth;
    string phonenumber;
    string email;
    
    int i=0;
    position=line_num();
    pData= new Ticket[position];
    
    ifstream FFilein;
    FFilein.open("/Users/ainur/Desktop/programming labs/C++SecondSemester/my project/Final Project/Final Project/Ticketinfo.txt");
    
    if(FFilein.is_open()){
        while(FFilein >> ticketid >>fnum>> name >> surname >> passportID >> dateofbirth>> phonenumber>> email){
            pData[i].ticketid=ticketid;
            pData[i].fnum=fnum;
            pData[i].name=name;
            pData[i].surname=surname;
            pData[i].passportID=passportID;
            pData[i].dateofbirth=dateofbirth;
            pData[i].phonenumber=phonenumber;
            pData[i].email=email;
            i++;
            }
    }else{
        cout<<"Error finding file"<<endl;
    }
    FFilein.close();
}



void Reserve:: booking(int flightnum){
    int i=position;
    int choice;
    cin>>pData[i];
    cout<<"Please check the entered informaiton before moving on"<<endl;
    cout<<pData[i]<<endl;
    cout<<"Is it correct? "<<endl;
    cout<<"1) Yes the data is correct. I am ready to book ticket"<<endl;
    cout<<"2) No something is wrong. I wanna enter data again"<<endl;

    cin >> choice;
    switch (choice)
    {
    case 1:
            pData[i].ticketid=i+1;
            pData[i].fnum=flightnum;
            position++;
        cout<<"Thank you for booking ticket!"<<endl;
            
        break;

    case 2:
            booking(flightnum);
        break;
    
    default:
            cout << "\n\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
            system("pause");
            booking(flightnum);
        }
    }




void Reserve:: savetofile(){
    ofstream FFilein;
    FFilein.open("/Users/ainur/Desktop/programming labs/C++SecondSemester/my project/Final Project/Final Project/Ticketinfo.txt");
        if(FFilein.is_open()){
            for(int i=0; i<position; i++){
                FFilein<<pData[i];
            }
                }else{
            cout<<"Error finding file"<<endl;
        }
        FFilein.close();
}



void Reserve:: searchticket(int tickid){
    int fnum=0;
    for(int i=0; i<position; i++){
        if(tickid==pData[i].ticketid){
            fnum=pData[i].fnum;
            getflightinfo(fnum, tickid);
        }
    }
    if(fnum==0){
        throw 0;
    }
}


void Reserve:: getflightinfo(int fnum, int tickid){
    Airplane plane;
        int temp;
        string leavingfrom;
        string goingto;
        string depaturedate;
        int price;
        ifstream FFilein;
        FFilein.open("/Users/ainur/Desktop/programming labs/C++SecondSemester/my project/Final Project/Final Project/Flight.txt");
        if(FFilein.is_open()){
            while(FFilein >> temp >> leavingfrom >> goingto >> depaturedate >> price){
                if(fnum==temp){
                    plane.flightnum=fnum;
                    plane.leavingfrom=leavingfrom;
                    plane.goingto=goingto;
                    plane.depaturedate=depaturedate;
                    plane.price=price;
                    for(int i=0; i<position; i++){
                            if(tickid==pData[i].ticketid){
    cout<<"---------------------------------------------------------------------------------------------------------|"<<endl;
                                cout<<"\t\t\t\t\t\t\t\t\t\t Ticket                                                          |\n";
    cout<<"---------------------------------------------------------------------------------------------------------|"<<endl;
cout << "\t\t\t\t\t Flight Number: "<<plane.flightnum<<"\t\t"<< "\t\t\t\t Ticket ID:"<< pData[i].ticketid<<"\t\t\n";
cout << "\t\t\t\t\t Leaving From: "<<plane.leavingfrom<<"\t\t"<< "\t\t\t Name:"<< pData[i].name<<" "<<pData[i].surname<<"\t\t\n";
cout << "\t\t\t\t\t Going To: "<<plane.goingto<<"\t\t"<< "\t\t\t     Passport ID:"<< pData[i].passportID<<"\t\t\n";
cout << "\t\t\t\t\t Departure Date: "<<plane.depaturedate<<"\t\t"<< "\t\t Date of birth:"<< pData[i].dateofbirth<<"\t\t\n";
cout << "\t\t\t\t\t Price: "<<plane.price<<"$"<<"\t\t"<< "\t\t\t\t\t\t Phone number:"<< pData[i].phonenumber<<"\t\t\n";
                
    cout<<"---------------------------------------------------------------------------------------------------------|"<<endl;
                    }
                    }
                }
                }
        }else{
            cout<<"Error finding ticket"<<endl;
        }
        FFilein.close();
}


