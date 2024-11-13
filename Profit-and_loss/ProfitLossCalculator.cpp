#include "ProfitLossCalculator.h"
#include <curl/curl.h>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

ProfitLossCalculator::ProfitLossCalculator(const std::string& apiUrl)
    : apiUrl(apiUrl) {}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// fetching and parsing the data

void ProfitLossCalculator::fetchData() {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed:" << curl_easy_strerror(res) << std::endl;
            return;
        }

        // Parse JSON data
        try {
            auto jsonData = json::parse(readBuffer);

            // Assume jsonData is an array of nominal data
            for (const auto& item : jsonData) {
                NominalData nominal;
                nominal.date = item["date"];
                nominal.accountingstandards = item["accountingstandards"];
                nominal.Nominals = item["Nominals"];
                nominal.amount = item["amount"];
                nominalDataList.push_back(nominal);
            }
        } catch (const json::parse_error& e) {
            std::cerr << "JSON parse error: " << e.what() << std::endl;
        }
    }
}

double ProfitLossCalculator::calculateProfitLoss(const std::string& filterdate, const std::string& filteraccountingstandard, const std::string& filternominal) {
    double totalAmount = 0.0;

    for (const auto& nominal :nominalDataList) {
        // filter by date, standard and nominal
        if (nominal.date == filterdate && nominal.accountingstandards == filteraccountingstandard && nominal.Nominals == filternominal) {
            totalAmount += nominal.amount;
        }
    }

    return totalAmount;
}