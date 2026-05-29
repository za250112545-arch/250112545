	#include <iostream>
	#include "CalculoProb.hpp"
	using namespace std;
	CalculoProb::CalculoProb(int a,int b,int c,int d){
		A1B1 = a;
		A2B1 = b;
		A1B2 = c;
		A2B2 = d;
		total = a+b+c+d;
	}
	void CalculoProb::calcMarginal(){
		cout << "-----Probabilidades Marginales-----" << endl << endl;
		cout << "Probabilidad de que este nublado: " << A2B1+A2B2 << "/" << total << endl << endl;
		cout << "Probabilidad de que llueva: " << A1B2+A2B2 << "/" << total << endl << endl;
		cout << "Probabilidad de que no este nublado: " << A1B1+A1B2 << "/" << total << endl << endl;
		cout << "Probabilidad de que no llueva: " << A1B1+A2B1 << "/" << total << endl << endl << endl;
	}
	void CalculoProb::calcCondicional(){
		cout << "-----Probabilidades Condicionales-----" << endl << endl;
		cout << "Probabilidad de que llueva dado que esta nublado: " << A1B1 << "/" << A1B1+A1B2 << endl << endl;
		cout << "Probabilidad de que llueva dado que no esta nublado: " << A2B1 << "/" << A1B1+A1B2 << endl << endl;
		cout << "Probabilidad de que no llueva dado que esta nublado: " << A1B2 << "/" << A2B1+A2B2 << endl << endl;
		cout << "Probabilidad de que no llueva dado que no esta nublado: " << A2B2 << "/" << A2B1+A2B2 << endl << endl;
		cout << "Probabilidad de que este nublado dado que llueva: " << A1B1 << "/" << A1B1+A2B1 << endl << endl;
		cout << "Probabilidad de que este nublado dado que no llueva: " << A1B2 << "/" << A1B2+A2B2 << endl << endl;
	}
	void CalculoProb::calcConjunta(){
		cout << "-----Probabilidades Conjuntas-----" << endl << endl;
		cout << "Probabilidad de que este nublado y llueva: " << A1B1 << "/" << total << endl << endl;
		cout << "Probabilidad de que este nublado y no llueva: " << A1B2 << "/" << total << endl << endl;
		cout << "Probabilidad de que no este nublado y llueva: " << A2B1 << "/" << total << endl << endl;
		cout << "Probabilidad de que no este nublado y no llueva: " << A2B2 << "/" << total << endl << endl;
	}
	CalculoProb::~CalculoProb(){
	}
