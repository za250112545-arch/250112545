#include <iostream>
#include "DataSet.hpp"
#include "CentralTendencyM.hpp"

using namespace std;

int main() {

    DataSet *data = new DataSet();
    data->printData();

    CentralTendencyM *ct = new CentralTendencyM(data);

    cout << "Mean: " << ct->mean() << endl;
    cout << "Median: " << ct->median() << endl;
    cout << "Mode: " << ct->mode() << endl;

    delete ct;
    delete data;

    return 0;
}
