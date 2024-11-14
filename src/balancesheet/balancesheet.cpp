#include <iostream>
#include <string>
#include "balancesheet.h"
#include <unordered_map>
#include <algorithm>
#include "crow.h"

using namespace financemodel;

// Structure to hold nominal accounts per accounting standard
struct NominalAccount {
    double fixed_assets;
    double inventory;
    double debtors;
    double creditors;
    double cash_in_bank;
    double share_capital;
    double equity;
};

// sample representation 
unordered_map<string, NominalAccount> balanceSheets = {
    {"USGAAP", {100000, 50000, 30000, 20000, 25000, 150000, 50000}},
    {"UKGAAP", {95000, 52000, 28000, 22000, 30000, 140000, 60000}},
    {"IFRS", {105000, 48000, 31000, 21000, 27000, 160000, 55000}}
};

// Function to create the balance sheet API
void createBalanceSheet(crow::financemodel& app) {
    // Define the API endpoint for fetching balance sheet data 
    CROW_ROUTE(app, "/api/balance-sheet/<string>/<string>")([&](const crow::request& req, string accountingStandard, string date) {
        transform(accountingStandard.begin(), accountingStandard.end(), accountingStandard.begin(), ::toupper);
        // Check if the accounting standard is valid
        auto it = balanceSheets.find(accountingStandard);
        if (it != balanceSheets.end()) {
            NominalAccount account = it->second;

            // Calculate Total Assets and Net Assets
            double totalAssets = account.fixed_assets + account.inventory + account.cash_in_bank + account.debtors;
            double netAssets = totalAssets - account.creditors;

            // Create a JSON response
            return crow::json::wvalue{
                {"accounting_standard", accountingStandard},
                {"date", date},
                {"balance_sheet", {
                    {"fixed_assets", account.fixed_assets},
                    {"inventory", account.inventory},
                    {"debtors", account.debtors},
                    {"creditors", account.creditors},
                    {"cash_in_bank", account.cash_in_bank},
                    {"share_capital", account.share_capital},
                    {"equity", account.equity},
                    {"total_assets", totalAssets},
                    {"net_assets", netAssets}
                }}
            };
        } else {
            return crow::response(404, crow::json::wvalue{
                {"error", "Accounting standard not found"}
            });
        }
    });
}
