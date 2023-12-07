//
//  main.cpp
//  Final Project
//
//  Created by Ainur Aman on 2021. 04. 13..
//

#include <iostream>
#include <fstream>
#include "airplane.h"
#include "Ticket.h"
#include "Storage.h"
#include "Reservation.h"
#include <string.h>

using namespace std;


int line_num(){ //function to identify the line number of file
    ifstream FFilein;
    FFilein.open("/Users/ainur/Desktop/programming labs/C++SecondSemester/my project/Final Project/Final Project/Flight.txt");
    int number_of_lines = 0;
        string line;
    while (getline(FFilein, line)){
        ++number_of_lines;}
    cout<<number_of_lines<<endl;
    FFilein.close();
    return number_of_lines;
}

void Continue(){ //function to ask after tasks weather user wants to continue working with the program
    int choice;
        cout<< "\n\n\n";
        cout << "\t\t\t\t\t\t\t\t\t\t ================================================\n";
        cout << "\t\t\t\t\t\t\t\t\t\t               Do You want to continue?                   \n";
        cout << "\t\t\t\t\t\t\t\t\t\t ================================================\n\n\n";

        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t|\t1. Go back to Menu                   \t\t|\n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\t\t|\t2. Finish            \t\t|\n";
        cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        
        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter your choice:-> ";

        cin >> choice;

        switch (choice)

        {

        case 1:
                throw 0;
            break;

        case 2:
            cout << "Goodby:)";
            break;
        default:
                cout << "\n\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
                system("pause");
                Continue();
    }
    
}


    

void Menu() //Menu of the program containing all necessery functions

{
    Database dt;
    Reserve r;
    int fnum, ticketid;
    dt.getflightinfo(); //gets info from file and puts to dynamic memory
    r.getfromfile(); //gets info from file and puts to dynamic memory
int choice;

    // MENU ITEMS
    cout << "\n\n\n";
    cout << "\t\t\t\t\t\t\t\t\t\t ================================================\n";
    cout << "\t\t\t\t\t\t\t\t\t\t\t################::Menu::################\n";
    cout << "\t\t\t\t\t\t\t\t\t\t ================================================\n\n\n";

    cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t\t\t\t|\t1. Reserve Ticket                    \t\t|\n";
    cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t\t\t\t|\t2. View available flights            \t\t|\n";
    cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t\t\t\t|\t3. View Booked Ticket              \t\t\t|\n";
    cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t\t\t\t|\t4. BACK                            \t\t\t|\n";
    cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t\t\t\t|\t5. Finish                          \t\t\t|\n";
    cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n\n";

    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter your choice:-> ";

    cin >> choice;

    switch (choice)

    {

    case 1:
            try{
                fnum= dt.selectcities();
                r.booking(fnum);
                r.savetofile();
                    try{
                        Continue();
                    }catch(int e){
                        Menu();
                    }
            }catch(int e){
                cout<<"No results found. Please try again!";
                Menu();
            }
        
        break;

    case 2:
        dt.print(); //prints all available flight info
        cout << "\n\n";
            try{
                Continue();
            }catch(int e){
                Menu();
            }
        break;

    case 3:
        cout<<"Please enter your ticket ID: ";
        cin>>ticketid;
            try{
                r.searchticket(ticketid);
                try{
                    Continue();
                }catch(int e){
                    Menu();
                }
            }catch(int e){
                if(e==0){
                    cout<<"\t\t\t\t\t\t\t\t\t\t No match with this Ticket Id! Please try again "<<endl;
                }
                Menu();
            }
            
        break;

    case 4:
            
            Menu();
            break;

    case 5:
            system("cls");
            break;
    default:
        cout << "\n\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
        system("pause");
        Menu();
    }
}

int main(){
    cout << "\n\n";
    cout<<"\t\t\t\t\t******************** Welcome to the Airplane Reservation system! ********************"<<endl;
    Menu();
        return 0;
    }

  

    
    
    
