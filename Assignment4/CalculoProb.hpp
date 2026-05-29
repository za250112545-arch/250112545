#ifndef CalculoProb_hpp
#define CalculoProb_hpp
class CalculoProb{
	int A1B1;
	int A2B1;
	int A1B2;
	int A2B2;
	int total;
	public:
	CalculoProb(int,int,int,int);
	void calcMarginal();
	void calcCondicional();
	void calcConjunta();
	~CalculoProb();
};
#endif
