#include "DataSet.hpp"

DataSet::DataSet() {

    size = 5;
    data = new int[size];

    data[0] = 4;
    data[1] = 7;
    data[2] = 7;
    data[3] = 10;
    data[4] = 15;
}

DataSet::~DataSet() {
    delete[] data;
}

int* DataSet::getData() {
    return data;
}

int DataSet::getSize() {
    return size;
}

void DataSet::printData() {

    std::cout << "DataSet: ";

    for(int i = 0; i < size; i++)
        std::cout << data[i] << " ";

    std::cout << std::endl;
}
