#ifndef DATASET_HPP
#define DATASET_HPP

#include <vector>

class DataSet {
private:
    std::vector<int> data;

public:
    DataSet();
    DataSet(const std::vector<int>& values);

    // Destructor
    ~DataSet();

    void setData(const std::vector<int>& values);
    std::vector<int> getData() const;

    void printData() const;
};

#endif
