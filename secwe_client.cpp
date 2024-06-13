//
// Created by Samet AZABOĞLU on 13.06.2024.
//

#include "secwe_client.h"
#include "prediction_info.h"
#include <nlohmann/json.hpp>
#include <stdexcept>
#include <cerrno>
#include <iostream>
#include <utility>
using namespace std;

secwe_client::secwe_client
(std::string  username, std::string  apiKey)
:_username(std::move(username)),
_apiKey(std::move(apiKey))
{
    _curl = curl_easy_init();
    if (!_curl) {
        uint32_t dw_Error = errno;
        cerr << "[!] Failed to initialize curl: " << dw_Error << endl;
        throw;
    }
}


std::pair<std::string, std::string> secwe_client::Get
(const std::string& domain)
{
    CURLcode res;
    std::string readBuffer;

    struct curl_slist *headers = nullptr;
    headers = curl_slist_append(
            headers,
            ("X-User: " + _username).c_str()
            );
    headers = curl_slist_append(
            headers,
            ("Authorization: " + _apiKey).c_str()
            );

    curl_easy_setopt(_curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(_curl, CURLOPT_URL, (_baseUrl + domain).c_str());
    curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(_curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(_curl);

    curl_slist_free_all(headers);
    if(res != CURLE_OK) {
        uint32_t dwErr = errno;
        cerr << "[!] Error: " << dwErr << endl;
        cerr << "[!] curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        throw;
    }

    if (readBuffer[0] == '{') {
        nlohmann::json j = nlohmann::json::parse(readBuffer);
        if(j["domain"].is_null()) {
            cerr << "[!] Error: Domain is null" << endl;
            throw;
        }
        if(j["prediction"].is_null()) {
            cerr << "[!] Error: Prediction is null" << endl;
            throw;
        }
        std::string prediction = j["prediction"].get<std::string>();

        PREDICTION_INFO pi;
        init_pred_info(&pi, domain, prediction);
        print_prediction_info(&pi);

        return std::make_pair(domain, prediction);
    } else {
        uint32_t dwErr = errno;
        cerr << "[!] Error: " << dwErr << endl;
        cerr << "[!] Server response is not JSON: " << readBuffer << endl;
        throw;
    }
}