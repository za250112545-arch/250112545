#include "DataSet.hpp"
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

DataSet::DataSet() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(50, 80); // valores entre 1 y 10
    for (int i = 0; i < 40; i++) 
        data.push_back(dist(gen));
    std::sort(data.begin(),data.end());
}

DataSet::DataSet(const vector<int>& values) : data(values) {
}

DataSet::~DataSet() {
}

void DataSet::setData(const vector<int>& values) {
    data = values;
}

vector<int> DataSet::getData() const {
    return data;
}
void DataSet::printData() const {
    cout << "Muestra de datos: ";
    for (size_t i = 0; i < data.size(); i++) 
        cout << data[i] << " ";

    cout << endl;
}
