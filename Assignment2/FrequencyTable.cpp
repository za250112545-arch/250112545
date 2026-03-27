#include "FrequencyTable.hpp"
#include "DataSet.hpp"
#include <iostream>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;

FrequencyTable::FrequencyTable() : data() {
}

FrequencyTable::FrequencyTable(const DataSet& ds) : data(ds) {
	k = (1+3.322*std::log10(40));
}

FrequencyTable::~FrequencyTable() {
}
void FrequencyTable::setDataSet(const DataSet& ds) {
    data = ds;
}
void FrequencyTable::sortClass(){
	int counter=0;			
	vector<int> rawData = data.getData();
	int lowerbound = rawData.front();
	r = rawData.back() - rawData.front();
	c = r/k + 1;
	dataClass.clear();
	dataClass.resize(k);
	for (int i:rawData) {
            while(i >= lowerbound + c && counter < k -1){
            	lowerbound += c;
            	counter++;
			}
			dataClass[counter].push_back(i);
        }
        lowerbound = rawData.front();
        int fi = 0;
        int Mc = 0;
        for (int i = 0; i < k; ++i) {
            std::cout << "[" << lowerbound << " - " << (lowerbound + c - 1) << "]: ";
            Mc = (lowerbound + (lowerbound + c -1))/2;
            for (int val : dataClass[i]) {
                
				fi++;
            } 
            std::cout << fi << " " << Mc << "\n";
            fi = 0;
            lowerbound += c;
        }
}

DataSet FrequencyTable::getDataSet() const {
    return data;
}

void FrequencyTable::calculateAbsoluteFrequencies() {
    values.clear();
    absoluteFrequency.clear();

    vector<int> rawData = data.getData();
    map<int, int> counter;

    for (size_t i = 0; i < rawData.size(); i++) 
        counter[rawData[i]]++;
    

    for (map<int, int>::iterator it = counter.begin(); it != counter.end(); ++it) {
        values.push_back(it->first);
        absoluteFrequency.push_back(it->second);
    }
}

void FrequencyTable::calculateRelativeFrequencies() {
    relativeFrequency.clear();

    int n = data.getData().size();

    for (size_t i = 0; i < absoluteFrequency.size(); i++) 
        relativeFrequency.push_back(static_cast<double>(absoluteFrequency[i]) / n);
    
}

void FrequencyTable::calculateAccumulatedRF(){
	accumulatedRelativeFrequency.clear();
	double sum = 0;
	for (double n:relativeFrequency){
	sum += n;
	accumulatedRelativeFrequency.push_back(static_cast<double>(sum));
	}
}
void FrequencyTable::calculateAccumulatedAF(){
	accumulatedAbsoluteFrequency.clear();
	int sum = 0;
	for (int n:absoluteFrequency){
	sum += n;
	accumulatedAbsoluteFrequency.push_back(static_cast<int>(sum));
	}
}
void FrequencyTable::calculatePercentages() {
    percentage.clear();
    for (size_t i = 0; i < relativeFrequency.size(); i++) 
        percentage.push_back(relativeFrequency[i] * 100.0);
    
}

void FrequencyTable::buildTable() {
    calculateAbsoluteFrequencies();
    calculateRelativeFrequencies();
    calculateAccumulatedAF();
    calculateAccumulatedRF();
    calculatePercentages();
}

void FrequencyTable::printTable() const {
    cout << "\nTABLA DE FRECUENCIAS\n";
    cout << "----------------------------------------------\n";
    cout << left << setw(10) << "Dato"
         << setw(20) << "Frec. Absoluta"
         << setw(20) << "Frec. Relativa"
         << setw(20) << "Frec. Absolute Acumulada"
         << setw(25) << "Frec. Relativa Acumulada"
		 << setw(15) << "Porcentaje" << endl;
    cout << "----------------------------------------------\n";

    for (size_t i = 0; i < values.size(); i++) {
        cout << left << setw(10) << values[i]
             << setw(20) << absoluteFrequency[i]
             << setw(20) << fixed << setprecision(4) << relativeFrequency[i]
             << setw(25) << accumulatedAbsoluteFrequency[i]
             << setw(30) << fixed << setprecision(4) << accumulatedRelativeFrequency[i]
             << setw(0) << fixed << setprecision(2) << percentage[i] << "%" << endl;
    }

    cout << "----------------------------------------------\n";
}
