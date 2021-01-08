#include "Square_class.h"

void Square_class::setLength(double len) 
{
	length = len; 
}

double Square_class::getLength()
{ 
	return length; 
}

double Square_class::getArea() 
{ 
	return length * length; 
}

double Square_class::getGirth() 
{
	return 4 * length;
}


