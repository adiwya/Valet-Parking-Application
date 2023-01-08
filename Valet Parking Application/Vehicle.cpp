// Name: Aparajeeta Diwya

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Vehicle.h"
#include "Utils.h"
using namespace std;
namespace sdds{
	Vehicle::Vehicle(){
		setEmpty();
	}
	Vehicle::Vehicle(const char* plate, const char* makemodel){
		if (plate != nullptr && makemodel != nullptr && strlen(plate) <= 8 && strlen(makemodel) > 1) {
			strcpy(this->givenPlate, plate);
			this->givenModel = new char[strlen(makemodel) + 1];
			strcpy(this->givenModel, makemodel);
		}
		else{
			setEmpty();
		}
	}

	Vehicle::Vehicle(const Vehicle& toCopyFrom){
		*this = toCopyFrom;
	}

	Vehicle& Vehicle::operator=(const Vehicle& toCopyFrom){
		if (this != &toCopyFrom) {
				if(!isEmpty())
				delete[] this->givenModel;
				this->setCsv(toCopyFrom.isCsv()); 
				strcpy(this->givenPlate, toCopyFrom.givenPlate);
				this->givenNum = toCopyFrom.givenNum;
				this->givenModel = new char[strlen(toCopyFrom.givenModel) + 1];
				strcpy(this->givenModel, toCopyFrom.givenModel);
			}
		return *this;
	}
	Vehicle::~Vehicle(){
		delete[] this->givenModel;
		this->givenModel = nullptr;
	}

	void Vehicle::setEmpty(){

		this->givenPlate[0] = '\0';
		this->givenModel = nullptr;
		this->givenNum = 0;
	}

	bool Vehicle::isEmpty() const{
		if (this->givenPlate[0] == '\0' || this->givenModel == nullptr ||  this->givenNum < 0) {
			return true;
		}
		else { return false; }

	}

	const char* Vehicle::getLicensePlate() const{ 
			return this->givenPlate;
	}

	char* Vehicle::getMakeModel() const{
		return this->givenModel;
	}

	void Vehicle::setMakeModel(const char* value){
		if (value != nullptr) {
			delete[] this->givenModel;
			this->givenModel = new char[strlen(value) + 1];
			strcpy(this->givenModel, value);
		}
		else {
			this->givenModel = nullptr;
		}
	}

	int Vehicle::getParkingSpot() const{
		return this->givenNum;
	}

	void Vehicle::setParkingSpot(int value){

		this->givenNum = value;

	}

	bool Vehicle::operator==(const char* plateValue){
		char tempVarPlate[8 + 1];
		strcpy(tempVarPlate, plateValue);
		toUpperCase(tempVarPlate);
		if (strcmp(this->givenPlate, tempVarPlate)) {
			return true;
		}
		else { return false; }
		}
	std::istream& Vehicle::read(std::istream& is){
		char tempVarPlate[8 + 1];
		int tempVarSpot;
		char tempVarModel[60 + 1];
			if (isCsv()) {
			is >> tempVarSpot;
			is.ignore();
			is.getline(tempVarPlate, 8, ',');
			strcpy(this->givenPlate, toUpperCase(tempVarPlate));
			is.getline(tempVarModel, 60, ',');
			setParkingSpot(tempVarSpot);
			setMakeModel(tempVarModel);
			}
		else {

			cout << "Enter License Plate Number: ";
			is >> tempVarPlate;
			cin.clear();
			is.ignore(1000, '\n');
			for (int i = 0; strlen(tempVarPlate) > 8; i++){
				cout << "Invalid License Plate, try again: ";
				is >> tempVarPlate;

				is.ignore(1000, '\n');
			}

			strcpy(this->givenPlate, toUpperCase(tempVarPlate));
			cin.clear();
			cout << "Enter Make and Model: ";
			is.getline(tempVarModel,61,'\n');
			for (int i = 0; strlen(tempVarModel) < 2 || strlen(tempVarModel) > 60; i++) {
				cout << "Invalid Make and model, try again: ";
				is.getline(tempVarModel, 61, '\n');
				
			}

			if (is.fail()){
				setEmpty();

			}
			else{
				setMakeModel(tempVarModel);
				setParkingSpot(0);
			}
		}
		return is;
	}

	std::ostream& Vehicle::write(std::ostream& ostr) const{
		if (isEmpty()) {
			ostr << "Invalid Vehicle Object" << endl;
		}
		else{
			writeType(ostr);
			if (isCsv()) {
				ostr << getParkingSpot() << "," << getLicensePlate() << "," << getMakeModel() << ",";
			}
			else {
				ostr << "Parking Spot Number: ";
				if (getParkingSpot() == 0) {
					ostr << "N/A" << endl;
				}
				else {
					ostr << getParkingSpot() << endl;
				}
				ostr << "License Plate: " << getLicensePlate() << endl;
				ostr << "Make and Model: " << getMakeModel() << endl;
				}

		}
		return ostr;
	}


	bool operator==(const Vehicle& v1, const Vehicle& v2){
		char tempVarPlate[8 + 1];
		strcpy(tempVarPlate, v1.getLicensePlate());
		toUpperCase(tempVarPlate);	
		char tempVarPlate2[8 + 1];
		strcpy(tempVarPlate2, v2.getLicensePlate());
		toUpperCase(tempVarPlate2);
		if (strcmp(tempVarPlate, tempVarPlate2) == 0) {
			return true;
		}
		else { return false; }
	}
}