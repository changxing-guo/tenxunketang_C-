#include <iostream>
#include "Square_class.h"

using namespace std;


int main(void) {
	Square_class A, B;
	A.setLength(10.0);
	B.setLength(21.0);

	printf("a area = %lf, girth = %lf, length = %lf\n",
		A.getArea(), A.getGirth(), A.getLength());
	printf("b area = %lf, girth = %lf, length = %lf\n",
		B.getArea(), B.getGirth(), B.getLength());


}