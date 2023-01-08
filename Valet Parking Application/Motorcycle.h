// Name: Aparajeeta Diwya

#ifndef SDDS_MOTORCYCLE_H__
#define SDDS_MOTORCYCLE_H__
#include "Vehicle.h"

namespace sdds
{
	class Motorcycle :public Vehicle {
		bool givenCar;

	public:
		Motorcycle();
		Motorcycle(const char* plate, const char* makemodel);
		Motorcycle(const Motorcycle& toCopyFrom);
		Motorcycle& operator=(const Motorcycle& toCopyrom);
		~Motorcycle();
		std::ostream& writeType(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};


}
#endif // !
