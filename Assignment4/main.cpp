#include <iostream>
#include "CalculoProb.hpp"
using namespace std;

int main(){
	CalculoProb calc(7,3,2,6);
	calc.calcMarginal();
	calc.calcConjunta();
	calc.calcCondicional();
	return 0;
}
