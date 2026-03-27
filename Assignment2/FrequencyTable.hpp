#ifndef FREQUENCYTABLE_HPP
#define FREQUENCYTABLE_HPP

#include "DataSet.hpp"
#include <vector>

class FrequencyTable {
private:
    DataSet data;
    std::vector<int> values;              // valores distintos
    std::vector<int> absoluteFrequency;   // frecuencia absoluta
    std::vector<double> relativeFrequency; // frecuencia relativa
    std::vector<double> percentage;       // porcentaje
    std::vector<double> accumulatedAbsoluteFrequency;
    std::vector<double> accumulatedRelativeFrequency; 
	int k;
	int c;
	int r;
	std::vector<std::vector <int>> dataClass;
	
public:
	void sortClass();
    FrequencyTable();
    FrequencyTable(const DataSet& ds);

    ~FrequencyTable();

    void setDataSet(const DataSet& ds);
    DataSet getDataSet() const;

    void calculateAbsoluteFrequencies();
    void calculateRelativeFrequencies();
    void calculatePercentages();
    void calculateAccumulatedAF();
    void calculateAccumulatedRF();
    void buildTable();

    void printTable() const;
};
#endif
