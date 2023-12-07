//
//  Storage.cpp
//  Final Project
//
//  Created by Ainur Aman on 2021. 04. 21..
//

#include <stdio.h>
#include <fstream>
#include "Storage.h"
#include "Ticket.h"
#include "airplane.h"


Database:: Database(){ 
    position=0;
    pData=NULL;
}

Database:: ~Database(){
    position=0;
    pData=NULL;
    delete [] pData;
}

Database:: Database(const Database& theOther){
    position=theOther.position;
    pData= new Airplane[theOther.position];
    for(int i=0; i<position; i++){
        pData[i] = theOther.pData[i];
    }
}

int Database:: line_num(){
    ifstream FFilein;
    FFilein.open("/Users/ainur/Desktop/programming labs/C++SecondSemester/my project/Final Project/Final Project/Flight.txt");
    int number_of_lines = 0;
        string line;
    while (getline(FFilein, line)){
        ++number_of_lines;}
    FFilein.close();
    return number_of_lines;
}

void Database:: getflightinfo(){
    int fnum;
    string leavingfrom;
    string goingto;
    string depaturedate;
    int price;
    
    int i=0;
    position=line_num();
    pData= new Airplane[position];
    
    ifstream FFilein;
    FFilein.open("/Users/ainur/Desktop/programming labs/C++SecondSemester/my project/Final Project/Final Project/Flight.txt");
    
    if(FFilein.is_open()){
        while(FFilein >> fnum >> leavingfrom >> goingto >> depaturedate >> price){
            pData[i].flightnum=fnum;
            pData[i].leavingfrom=leavingfrom;
            pData[i].goingto=goingto;
            pData[i].depaturedate=depaturedate;
            pData[i].price=price;
            i++;
            }
    }else{
        cout<<"Error finding file"<<endl;
    }
    FFilein.close();
}

void Database:: print(){
    position=line_num();
    cout<<endl;
    cout<<"\t\t\t\t\t\t******************** Available Flights: ********************"<<endl;
    cout<<endl;
    for(int i=0; i<position; i++){
        cout<<pData[i];
    }
}

int Database::selectcities(){
    string lfinput, gtinput;
    
    cout<<"Please select cities: "<<endl;
    cout<<"Leaving From: ";
    cin>>lfinput;
    cout<<"Going to: ";
    cin>>gtinput;
    position=line_num();
    int p=0;
    
    for(int i=0; i<position; i++){
        if(pData[i].leavingfrom==lfinput && pData[i].goingto==gtinput){
            cout<<"Avalible flight dates for choosed destination "<< lfinput<< "->>" << gtinput<<endl;
            cout<<pData[i].flightnum<<") "<<pData[i].depaturedate<< "  Price for one ticket:" << pData[i].price<<endl;
        }else{
            p=p+1;
        }
    }
    if(p==position){
        throw 0;
    }else{
        int innum;
            cout<<"Please select your choice: ";
            cin>>innum;
            return innum;
    }
}
