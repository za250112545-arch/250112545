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

public:
    FrequencyTable();
    FrequencyTable(const DataSet& ds);

    ~FrequencyTable();

    void setDataSet(const DataSet& ds);
    DataSet getDataSet() const;

    void calculateAbsoluteFrequencies();
    void calculateRelativeFrequencies();
    void calculatePercentages();
    void buildTable();

    void printTable() const;
};

