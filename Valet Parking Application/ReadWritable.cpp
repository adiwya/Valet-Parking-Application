// Name: Aparajeeta Diwya

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ReadWritable.h"

using namespace std;
namespace sdds{
	ReadWritable::ReadWritable(){
		this->givenFlag = false;
	}
	ReadWritable::~ReadWritable(){}

	bool ReadWritable::isCsv() const{
		return this->givenFlag;
	}
	void ReadWritable::setCsv(bool value){
		this->givenFlag = value;

	}
	std::ostream& operator<<(std::ostream& ostr, const ReadWritable& r){
		r.write(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& is, ReadWritable& r){
		r.read(is);
		return is;
	}

}