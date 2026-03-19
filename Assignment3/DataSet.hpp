#ifndef DATASET_HPP
#define DATASET_HPP

#include <iostream>

class DataSet {

private:
    int *data;
    int size;

public:

    DataSet();
    ~DataSet();

    int* getData();
    int getSize();

    void printData();
};

#endif
