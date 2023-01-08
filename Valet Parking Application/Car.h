// Name: Aparajeeta Diwya

#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle{
		bool flagWash;

	public:
		Car();
		Car(const char* plate, const char* makemodel);
		Car(const Car& toCopyFrom);
		Car& operator=(const Car& toCopyFrom);
		~Car();
		std::ostream& writeType(std::ostream& ostr) const; 
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};
	

}
#endif // !
