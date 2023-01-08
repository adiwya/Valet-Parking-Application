// Name: Aparajeeta Diwya



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Car.h"
#include "Utils.h"
using namespace std;
namespace sdds{

	Car::Car():Vehicle(){
		this->flagWash = false; 
	}

	Car::Car(const char* plate, const char* makemodel):Vehicle(plate,makemodel){
		this->flagWash = false;

	}

	Car::Car(const Car& toCopyFrom):Vehicle(toCopyFrom){
		*this = toCopyFrom;
	}

	Car& Car::operator=(const Car& toCopyFrom){
		if (this != &toCopyFrom) {
			Vehicle::operator=(toCopyFrom);
			
			this->flagWash = toCopyFrom.flagWash;
		}
		return *this;
	}

	Car::~Car(){}

	std::ostream& Car::writeType(std::ostream& ostr) const{
		if (isCsv()) {
			ostr << "C,";
		}
		else {
			ostr << "Vehicle type: Car" << endl;
		}
		return ostr;
	}

	std::istream& Car::read(std::istream& istr){
		if (isCsv()){
			Vehicle::read(istr);
			istr >> flagWash;
			istr.ignore(1000, '\n');
		}
		else{
			cout << endl<< "Car information entry" << endl;
			Vehicle::read(istr);
			cout << "Carwash while parked? (Y)es/(N)o: ";
			char input[5];
			do {

				cin >> input;
				if (strlen(input) > 1){
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";

				}
				else if (input[0] == 'y'){
					this->flagWash = true;
					break;

				}
				else if (input[0] == 'n'){
					this->flagWash = false;
					break;
				}
				else{
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				}
			} while (this->flagWash == false);


		}
		return istr;
	}

	std::ostream& Car::write(std::ostream& ostr) const{
		if (isEmpty()) {
			ostr << "Invalid Car Object" <<endl;
		}

		else {
			Vehicle::write(ostr);
			if (isCsv()) {
				ostr << flagWash << endl;
			}
			else{
				if (this->flagWash) {
					ostr << "With Carwash" << endl;
				}
				else {
					ostr << "Without Carwash" << endl;
				}
			}

		}
		return ostr;
	}

}