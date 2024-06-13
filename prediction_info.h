//
// Created by Samet AZABOĞLU on 13.06.2024.
//

#ifndef SECWE_CLIENT_C_PREDICTION_INFO_H
#define SECWE_CLIENT_C_PREDICTION_INFO_H

#include <iostream>
using namespace std;

class prediction_info {
private:
    string _domain;
    string _prediction;

public:
    prediction_info(const string& domain, const string& prediction);
    void print();
};


#endif //SECWE_CLIENT_C_PREDICTION_INFO_H
