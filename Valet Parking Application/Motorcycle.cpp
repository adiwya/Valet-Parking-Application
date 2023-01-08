// Name: Aparajeeta Diwya

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Motorcycle.h"
#include "Utils.h"
using namespace std;
namespace sdds{
	Motorcycle::Motorcycle(){
		this->givenCar = false;
	}

	Motorcycle::Motorcycle(const char* plate, const char* makemodel):Vehicle(plate,makemodel){
		this->givenCar = false;
	}

	Motorcycle::Motorcycle(const Motorcycle& toCopyFrom):Vehicle(toCopyFrom){
		*this = toCopyFrom;
	}

	Motorcycle& Motorcycle::operator=(const Motorcycle& toCopyrom){
		if (this != &toCopyrom) {
			Vehicle::operator=(toCopyrom);
			this->givenCar = toCopyrom.givenCar;
		}
		return *this;
	}

	Motorcycle::~Motorcycle(){}

	std::ostream& Motorcycle::writeType(std::ostream& ostr) const{
		if (isCsv()) {
			ostr << "M,";
		}
		else {
			ostr << "Vehicle type: Motorcycle" << endl;
		}
		return ostr;
	}

	std::istream& Motorcycle::read(std::istream& istr){
		if (isCsv()) {
			Vehicle::read(istr);
			istr >> this->givenCar;
			istr.ignore(1000, '\n');
		}
		else{
			cout <<endl<< "Motorcycle information entry" << endl;
			Vehicle::read(istr);
			this->givenCar = false;
			char input[5];
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			do {
				cin >> input;
				if (strlen(input) > 1) {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";

				}
				else if (input[0] == 'y') {
					this->givenCar = true;
					break;

				}
				else if (input[0] == 'n') {
					this->givenCar = false;
					break;
				}
				else {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				}
			} while (this->givenCar == false);

		}
		return istr;
	}

	std::ostream& Motorcycle::write(std::ostream& ostr) const{
		if (isEmpty()) {
			ostr << "Invalid Motorcycle Object" << endl;
		}
		else {
			Vehicle::write(ostr);
			if (isCsv()) {
				ostr << this->givenCar << endl;
			}
			else if (this->givenCar) 
			{
				ostr << "With Sidecar" << endl;
			}
		}
		return ostr;
	}

}