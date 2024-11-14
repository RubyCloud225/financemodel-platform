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


