//
// Created by Samet AZABOĞLU on 13.06.2024.
//

#include "prediction_info.h"

void init_pred_info
(
        PREDICTION_INFO* pi,
        const string& domain,
        const string& prediction
)
{
    pi->domain = domain;
    pi->prediction = prediction;
}

string
get_domain (PREDICTION_INFO* pi)
{
    return pi->domain;
}

string
get_prediction (PREDICTION_INFO* pi)
{
    return pi->prediction;
}


void
print_prediction_info(PREDICTION_INFO* pi)
{
    cout << "Domain: " << get_domain(pi)
    << "\nPrediction: " << get_prediction(pi)
    << endl;
}
