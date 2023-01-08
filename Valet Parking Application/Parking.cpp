// Name: Aparajeeta Diwya

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <fstream>
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Parking.h"
#include "Utils.h"
#include "Menu.h"


using namespace std;
namespace sdds {

    Parking::Parking() {
        this->givenFile = nullptr;

    }
     Parking::Parking(const char* filename, int noOfSpots){
        if (filename != nullptr && filename[0] != '\0'  && !(noOfSpots < 10 || noOfSpots > MAX_NO_OF_PARKING_SPOTS)) {
            this->givenFile = new char[strlen(filename) + 1];
            strcpy(this->givenFile, filename);
             this->spotNumbers = noOfSpots;
             if (loadDataFile()) {                                      
                this->givenParking << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Find Vehicle" << "Close Parking (End of day)" << "Exit Program";
                this->givenVehicle << "Car" << "Motorcycle" << "Cancel";
         }
     }
        else{
            cout << "Error in data file" << endl;
            this->givenFile = nullptr;
            this->spotNumbers = 0;
        }
    }

    Parking::~Parking(){
        savaDataFile();
         delete[] this->givenFile;
        this->givenFile = nullptr;
        int i;
		for ( i = 0;i < this->spotNumbers;i++){
			  delete this->p_parkingSpots[i];
			  this->p_parkingSpots[i] = nullptr;
		  }
    }
    bool Parking::isEmpty()const{
        if (this->givenFile == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }
    void Parking::parkStatus()const{
        cout << "****** Valet Parking ******" << endl;
        cout << "*****  Available spots: ";
        cout.width(4);
        cout.setf(ios::left);
        cout << this->spotNumbers - this->parkedVehicles;
        cout << " *****" << endl;
    }
     void Parking::parkVehicle(){
        if (this->spotNumbers == this->parkedVehicles) {
            cout << "Parking is full" << endl;
      }
        else{
            switch (this->givenVehicle.run()){          
            case 1:
                {
                    Vehicle* newVehicle = new Car;
                    newVehicle->setCsv(false);
                    newVehicle->read(cin);
                    for (int i = 0; i < this->spotNumbers; i++) {
                        if (this->p_parkingSpots[i] == nullptr) {
                            this->p_parkingSpots[i] = newVehicle;
                            this->p_parkingSpots[i]->setParkingSpot(i + 1);
                            cout << endl << "Parking Ticket" << endl;
                            newVehicle->write(cout);
                            this->parkedVehicles++;
                        }
                    }
                    cout << endl;
                    cout << "Press <ENTER> to continue...." << endl;
                    break;
                }
                break;

                case 2:
                {
                    Vehicle* newVehicle2 = new Motorcycle;
                    newVehicle2->setCsv(false);
                    newVehicle2->read(cin);
                     for (int i = 0; i < this->spotNumbers; i++) {
                        if (this->p_parkingSpots[i] == nullptr) {
                            this->p_parkingSpots[i] = newVehicle2;
                            this->p_parkingSpots[i]->setParkingSpot(i + 1);
                             cout << endl << "Parking Ticket" << endl;
                            newVehicle2->write(cout);
                             this->parkedVehicles++;
                          
                            }
                    }
                 cout << endl;
                    cout << "Press <ENTER> to continue...." << endl;
                    
                }
                break;
               
                case 3: 
                  cout << "Cancelled parking" << endl;
                   cout << endl;
                    break; 
                default:
                     break;
            }
        }

    }

    void Parking::returnVehicle(){

        char plate[9];
        int givenVarFlag = false;
        bool vehicleGiven = false;
        int indexNo;
        cout << "Return Vehicle" << endl;
        cout << "Enter License Plate Number: ";
        do {
             cin >> plate;
             cin.clear();
             if (strlen(plate) < 1 || strlen(plate) > 8){
                cout << "Invalid License Plate, try again: ";
                cin.clear();
            }
            else
            {
                givenVarFlag = true;
            }
        } while (givenVarFlag == false);

        cout << endl;
        toUpperCase(plate);
        for (int i = 0; i < this->spotNumbers; i++) {
            if (this->p_parkingSpots[i] != nullptr) {
                if (strcmp(this->p_parkingSpots[i]->getLicensePlate(), plate) == 0) {
                    vehicleGiven = true;
                    indexNo = i;
                }

            }
        }
        if (vehicleGiven) {
            cout << "Returning:" << endl;
            this->p_parkingSpots[indexNo]->setCsv(false);
            this->p_parkingSpots[indexNo]->write(cout);
            delete this->p_parkingSpots[indexNo];    
            this->p_parkingSpots[indexNo]= nullptr;
            this->parkedVehicles--;
            cout << endl;

        }
        else {
            cout << "License plate " << toUpperCase(plate) << " Not found" << endl << endl;;

        }
        cout << "Press <ENTER> to continue...." << endl;

 }


    void Parking::parkListVehicle()const {
        cout << "*** List of parked vehicles ***" << endl;
        for (int i = 0; i < this->spotNumbers; i++) {
            if (this->p_parkingSpots[i] != nullptr) {
                this->p_parkingSpots[i]->setCsv(false);
                this->p_parkingSpots[i]->write(cout);
                    cout << "-------------------------------" << endl;
            }
        }
        cout << "Press <ENTER> to continue...." << endl;
    }


    void Parking::findVehicle(){
        char plate[9];
        int givenVarFlag = false;
        bool vehicleGiven = false;
        int indexNo;
        cout << "Vehicle Search" << endl;
        cout << "Enter Licence Plate Number: ";

        do{

            cin >> plate;
            cin.clear();
            if (strlen(plate) < 1 || strlen(plate) > 8){
                cout << "Invalid License Plate, try again: ";
                cin.clear();
            }
            else
            {
                givenVarFlag = true;
            }
        } while (givenVarFlag == false);

        cout << endl;
        toUpperCase(plate);

        for (int i = 0; i < this->spotNumbers; i++) {
            if (this->p_parkingSpots[i] != nullptr) {
                if (strcmp(this->p_parkingSpots[i]->getLicensePlate(), plate) == 0) {
                    vehicleGiven = true;
                    indexNo = i;
                }
                   
            }
        }
          if(vehicleGiven){
                cout << "Vehicle found:" << endl;
                this->p_parkingSpots[indexNo]->setCsv(false);
                this->p_parkingSpots[indexNo]->write(cout);
                cout << endl;

            }
            else {
              cout << "License plate " << toUpperCase(plate) << " Not found" << endl << endl;;

            }
          cout << "Press <ENTER> to continue...." << endl;

    }
    bool Parking::closeParking() {
        bool returnValue = false;
        char input;
        int flag = 0;
        if (isEmpty()) {
            cout << "Close Parking" << endl;
            return true; 
        }
        else {
            cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
            cout << "Are you sure? (Y)es/(N)o: ";
            
           for (int i = 0; flag == 0; i++)
            {
                cin >> input;
                if (input == 'Y' || input == 'y')
                {

                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Closing Parking" << endl;
                    cout << endl;

                    for (int i = 0; i < this->spotNumbers; i++){

                        if (this->p_parkingSpots[i] != nullptr) 
                        {
                            cout << "Towing request" << endl;
                            cout << "*********************" << endl;
                            this->p_parkingSpots[i]->setCsv(false);
                            this->p_parkingSpots[i]->write(cout);
                            delete this->p_parkingSpots[i];
                            this->p_parkingSpots[i] = nullptr;
                            this->parkedVehicles--;
                            if (i < this->spotNumbers - 1){
                                cout << endl;
                            }

                        }
                    }
                    returnValue = true;
                    flag = 1;
                }
                else if (input == 'N' || input == 'n') {
                    flag = 1;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    returnValue = false;
                }
                else
                {
                    cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                    cin.clear();
                    cin.ignore(1000, '\n');

                }
            }

        }
        return returnValue;
    }

    bool Parking::exitParking()const{
        cout << "This will terminate the program!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        char input;
        int flag = 0;
        bool returnValue = false;
        for (int i = 0; flag == 0; i++){
            cin >> input;
            if (input == 'Y' || input == 'y')
            {

                flag = 1;
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Exiting program!" << endl;
                returnValue = true;
            }
            else if (input == 'N' || input == 'n') {
                flag = 1;
                cin.clear();
                cin.ignore(1000, '\n');
                returnValue = false;
            }
            else
            {
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                cin.clear();
                cin.ignore(1000, '\n');

            }
        }

        return returnValue;
    }
    bool Parking::loadDataFile(){
         bool statusUpdate = false;
         char typeOfVehicle;
         Vehicle* vehicle{};
            if (!isEmpty()) {
            ifstream file(this->givenFile);

            if (!file) {                                                                    
                statusUpdate = true; 
            }
            else {
               
                while (!file.eof()) {                                                   
                   typeOfVehicle= file.get();                                             
                   file.ignore();

                   if (typeOfVehicle == 'M') {
                       vehicle = new Motorcycle;

                       vehicle->setCsv(true);
                       vehicle->read(file);                                            
                       if (!file.fail()) {                                             
                       this->p_parkingSpots[ vehicle->getParkingSpot() - 1] = vehicle;                
                       this->parkedVehicles++;                                
                       }
                       else
                       {
                           delete vehicle;
                           statusUpdate = false;
                      }
                   }
                  else if (typeOfVehicle == 'C') {
                       vehicle = new Car;
                       vehicle->setCsv(true);
                       vehicle->read(file);                                             
                      if (!file.fail()) {
                           this->p_parkingSpots[  vehicle->getParkingSpot() - 1] = vehicle;
                           this->parkedVehicles++;
                            }
                       else
                       {
                           delete vehicle;
                           statusUpdate = false;

                       }
                   }
                 }
                 //My friend also helped me in the placement for the statusUpdate as I placed it in a wrong place where it was not looping properly.
                 //I have also cited in my reflection.
                statusUpdate = true; 
                
            }
            file.close();
           
        }
       
        return statusUpdate;
    }


    void Parking::savaDataFile()const{
        ofstream file(this->givenFile);
        if (file) {
            for (int i = 0; i < this->spotNumbers; i++) {
                if (this->p_parkingSpots[i] != nullptr) {
                    this->p_parkingSpots[i]->setCsv(true);
                    this->p_parkingSpots[i]->write(file);
                }
            }
        }
        file.close();
    }
    int Parking::run(){
        int flag = 0;
        bool exit = false;
        bool close = false;
        if (!isEmpty()) {
          for (int i = 0; flag == 0; i++) {
                parkStatus();
               switch (this->givenParking.run())
                {
                case 1:
                    parkVehicle();
                    break;
                case 2:
                    returnVehicle();
                    break;
                case 3:
                    parkListVehicle();
                    break;
                case 4:
                    findVehicle();
                    break;
                case 5:
                    close = closeParking();
                    if (close == true) {
                        flag = 1;
                        break;
                    }
                    else
                    {
                        break;
                    }
                case 6:
                    exit = exitParking();
                    if (exit == true) { flag = 1; break; }
                    else
                    {
                        break;
                    }
                 }
            }
        }

        return flag;
    }
}



