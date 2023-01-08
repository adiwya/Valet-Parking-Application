// Name: Aparajeeta Diwya

#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__
#include <iostream>
#include "ReadWritable.h"
namespace sdds{
	class Vehicle : public ReadWritable {
		char givenPlate[8 + 1]{};
		char* givenModel;
		int givenNum =0;
		protected:                            
		void setEmpty();
		bool isEmpty() const;
		void setMakeModel(const char* value);
		char* getMakeModel() const;

	public:
		Vehicle();
		Vehicle(const char* plate, const char* makemodel);
		Vehicle(const Vehicle& toCopyFrom);
		Vehicle& operator=(const Vehicle& toCopyFrom);
		~Vehicle();
		const char* getLicensePlate() const;
		void setParkingSpot(int value);
		int getParkingSpot() const;
		bool operator==(const char* plateValue);
		std::istream& read(std::istream& is);
		virtual std::ostream& writeType(std::ostream& ostr) const = 0;
		std::ostream& write(std::ostream& ostr) const;
	};
	bool operator==(const Vehicle& v1, const Vehicle& v2);
}
#endif // !
