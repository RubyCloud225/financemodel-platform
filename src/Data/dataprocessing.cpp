#include <iostream>
#include <string>
#include <curl/curl.h>
#include "dataprocessing.h"

// Callback function to write the response data
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// Function to fetch data from a given API URL
json fetchDataFromAPI(const std::string& apiUrl) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    // parse the json response
    return json::parse(readBuffer);
    for(const auto& item : jsonResponse.as_array()) {
        NominalAccount nominalAccount;
        nominalAccount.date = item.at(U("date")).as_string();
        nominalAvvount.nominal = item.at(U("nominal")).as_string();
        transaction.amount = item.at(U("amount")).as_double();

        // Determin if the transaction is a debit or credit
        if (transaction.amount >= 0) {
            transaction.type = TransactionType::Debit;
        } else {
            transaction.type = TransactionType::Credit;
        }

        transactions.push_back(transaction);
    }
}

void fetchDatesFromAPI(std::string& startDate, std::string& endDate) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.example.com/dates");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if(res == CURLE_OK) {
            // Parse the JSON response
            auto jsonResponse = nlohmann::json::parse(readBuffer);
            startDate = jsonResponse["startDate"];
            endDate = jsonResponse["endDate"];
        } else {
            std::cerr << "Error fetching data: " << curl_easy_strerror(res) << std::endl;
        }
    }
}

json fetchAccountingStandards(const std::string& apiUrl) {
    return fetchDataFromAPI(apiUrl + "/accountingstandards");
}

json fetchNominalTypes(const std::string& apiUrl) {
    return fetchDataFromAPI(apiUrl + "/NominalTypes");
}

json fetchNominalAccounts(const std::string& apiUrl) {
    return fetchDataFromAPI(apiUrl + "/NominalAccounts");
}

json fetchSalesInvoices(const std::string& apiUrl) {
    return fetchDataFromAPI(apiUrl + "/SalesInvoices");
}

json fetchPurchaseInvoices(const std::string& apiUrl) {
    return fetchDataFromAPI(apiUrl + "/PurchaseInvoices");
}

json fetchBankReciepts(const std::string& apiUrl) {
    return fetchDataFromAPI(apiUrl + "/BankReciepts");
}

json fetchBankPayments(const std::string& apiUrl) {
    return fetchDataFromAPI(apiUrl + "/bankpayments");
}

json fetchJournals(const std::string& apiUrl) {
    return fetchDataFromAPI(apiUrl + "/journals");
}


