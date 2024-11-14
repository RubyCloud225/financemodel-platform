#include "ProfitLossCalculator.h"
#include <algorithm>

// Sample data representing profit and loss accounts for different accounting standards
std::unordered_map<std::string, ProfitLossAccount> profitLossAccounts = {
    {"USGAAP", {500000, 300000, 100000, 20000, 50000}},
    {"UKGAAP", {480000, 290000, 110000, 25000, 45000}},
    {"IFRS", {520000, 310000, 120000, 30000, 60000}}
};

// Function to create the profit and loss API
void createProfitLossAPI(crow::SimpleApp& app) {
    // Define the API endpoint for fetching profit and loss data
    CROW_ROUTE(app, "/api/profit-loss/<string>/<string>")([&](const crow::request& req, std::string accountingStandard, std::string date) {
        // Convert accounting standard to uppercase for case-insensitivity
        std::transform(accountingStandard.begin(), accountingStandard.end(), accountingStandard.begin(), ::toupper);

        // Check if the accounting standard is valid
        auto it = profitLossAccounts.find(accountingStandard);
        if (it != profitLossAccounts.end()) {
            ProfitLossAccount account = it->second;

            // Calculate Gross Profit, Operating Profit, and Net Profit
            double grossProfit = account.revenue - account.cost_of_goods_sold;
            double operatingProfit = grossProfit - account.operating_expenses;
            double netProfit = operatingProfit - account.interest_expense - account.taxes;

            // Create a JSON response
            return crow::json::wvalue{
                {"accounting_standard", accountingStandard},
                {"date", date},
                {"profit_loss", {
                    {"revenue", account.revenue},
                    {"cost_of_goods_sold", account.cost_of_goods_sold},
                    {"gross_profit", grossProfit},
                    {"operating_expenses", account.operating_expenses},
                    {"operating_profit", operatingProfit},
                    {"interest_expense", account.interest_expense},
                    {"taxes", account.taxes},
                    {"net_profit", netProfit}
                }}
            };
        } else {
            return crow::response(404, crow::json::wvalue{
                {"error", "Accounting standard not found"}
            });
        }
    });
}

