//
// Created by Samet AZABOĞLU on 13.06.2024.
//

#ifndef SECWE_CLIENT_C_SECWE_CLIENT_H
#define SECWE_CLIENT_C_SECWE_CLIENT_H


#include <string>
#include <curl/curl.h>

class secwe_client {
private:
    std::string _username;
    std::string _apiKey;
    std::string _baseUrl = "https://secwe.com.tr/api/predict/";
    CURL* _curl;

public:

    // Initialize the secwe api client with the given username and apiKey
    secwe_client(const std::string& username, const std::string& apiKey);

    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
        std::string* s = static_cast<std::string*>(userp);
        size_t newLength = size*nmemb;
        size_t oldLength = s->size();
        try {
            s->resize(oldLength + newLength);
        }
        catch(std::bad_alloc &e) {
            return 0;
        }

        std::copy((char*)contents,(char*)contents+newLength,s->begin()+oldLength);
        return size*nmemb;
    }

    std::pair<std::string, std::string> Get(const std::string& domain);
};


#endif //SECWE_CLIENT_C_SECWE_CLIENT_H
