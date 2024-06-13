//
// Created by Samet AZABOĞLU on 13.06.2024.
//

#ifndef SECWE_CLIENT_C_PREDICTION_INFO_H
#define SECWE_CLIENT_C_PREDICTION_INFO_H

#include <iostream>
using namespace std;

struct
PREDICTION_INFO {
    string domain;
    string prediction;
};

void init_pred_info
(
        PREDICTION_INFO* pi,
        const string& domain,
        const string& prediction
);


string get_domain(PREDICTION_INFO* pi);
string get_prediction(PREDICTION_INFO* pi);
void print_prediction_info(PREDICTION_INFO* pi);


#endif //SECWE_CLIENT_C_PREDICTION_INFO_H
