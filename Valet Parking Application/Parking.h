// Name: Aparajeeta Diwya

#ifndef SDDS_PARKING_H__
#define SDDS_PARKING_H__#include <iostream>
#include "Menu.h"
#include "Vehicle.h"
const int MAX_NO_OF_PARKING_SPOTS = 100;

namespace sdds
{
	class Parking {
		char* givenFile;
		Menu givenParking{ "Parking Menu, select an action:", 0 };  
		Menu givenVehicle{ "Select type of the vehicle:", 1 };

		bool isEmpty() const;
		void parkStatus()const;
		void parkVehicle();
		void returnVehicle();
		void parkListVehicle()const;
		void findVehicle();
		bool closeParking();
		bool exitParking()const;
		bool loadDataFile();
		void savaDataFile()const;
		//Milestone 5 add ons
		int spotNumbers=0;
		Vehicle* p_parkingSpots[MAX_NO_OF_PARKING_SPOTS]{};
		int parkedVehicles = 0; 
public:
		Parking();
		Parking(const char* filename, int noOfSpots);
		~Parking();
		Parking(const Parking& toCopyFrom) = delete;
		Parking operator=(const Parking& toCopyFrom) = delete;
		int run();
	};
}
#endif // !
