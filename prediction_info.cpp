//
// Created by Samet AZABOĞLU on 13.06.2024.
//

#include "prediction_info.h"

prediction_info::prediction_info
(const string &domain, const string &prediction) :
_domain(domain),
_prediction(prediction)
{
}

void prediction_info::print()
{
    cout << "Domain: " << _domain
    << "\nPrediction: " << _prediction
    << endl;
}