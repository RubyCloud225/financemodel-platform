#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H

#include <vector>
#include <string>
#include <nlohmann/json.hpp>
#include <map>

using json = nlohmann::json;

//Function declarations
json fetchDataFromAPI(const std::string& apiUrl);
json fetchAccountingStandards(const std::string& apiUrl);
json fetchNominalTypes(const std::string& apiUrl);
json fetchNominalAccounts(const std ::string& apiUrl);
json fetchSalesInvoices(const std::string& apiUrl);
json fetchPurchaseInvoices(const std::string& apiUrl);
json fetchBankReciepts(const std::string& apiUrl);
json fetchBankPayments(const std::string& apiUrl);
json fetchJournals(const std::string& apiUrl);

#endif