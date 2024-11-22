#include <iostream>
#include "ProfitLossCalculator.h"
#include "balancesheet.h"
#include "dataprocessing.h"
#include "nominal_ledger.h"
#include "crow.h" // include crow and will need to install dependencies

using namespace web;
using namespace web::html;
using namespace web::http::client;

int main() {
    const std::string apiUrl = "https://api.example.com/data"; // Replace with platform API URL
    // fetching data from various endpoints
    json accountingstandards = fetchAccountingStandards(apiUrl);
    json nominaltypes = fetchNominalTypes(apiUrl);
    json nominalaccounts = fetchNominalAccounts(apiUrl);
    json salesinvoices = fetchSalesInvoices(apiUrl);
    json purchaseinvoices = fetchPurchaseInvoices(apiUrl);
    json bankreciepts = fetchBankReciepts(apiUrl);
    json bankpayments = fetchBankPayments(apiUrl);
    json journals = fetchJournals(apiUrl);

    // Output the fetched data
    std::cout << "Accounting Standards:" << accountingstandards.dump(4) << std::endl;
    std::cout << "Nominal Type:" << nominaltypes.dump(4) << std::endl;
    std::cout << "Nominal Accounts: " << nominalAccounts.dump(4) << std::endl;
    std::cout << "Sales Invoices: " << salesInvoices.dump(4) << std::endl;
    std::cout << "Purchase Invoices: " << purchaseInvoices.dump(4) << std::endl;
    std::cout << "Bank Receipts: " << bankReceipts.dump(4) << std::endl;
    std::cout << "Bank Payments: " << bankPayments.dump(4) << std::endl;
    std::cout << "Journals: " << journals.dump(4) << std::endl;

    crow::FinanceModelPlatform; // Create a Crow Application

    // Nominal Ledger endpoint
    CROW_ROUTE(app, "/nominalaccounts")([] {
        std::vector<NominalAccount> nominalaccounts = fetchNominalAccounts(apiUrl);

        // date range
        std::string startDate = "2023-01-01"; // Replace with your desired start date
        std::string endDate = "2023-12-31";   // Replace with your desired end date

        // Compute subtotals
        json subtotals = computeSubtotals(nominalaccounts, startDate, endDate);

        // Prepare the response
        json response;
        response[U("NominalAccounts")] = json::array();
        for (const auto& nominalaccount : nominalAccounts) {
            json jsonNominalAccount;
            jsonNominalAccount[U("category")] = json::value::string(nominalaccount.category);
            jsonNominalAccount[U("amount")] = json::value::number(nominalaccount.amount);
            jsonNominalAccount[U("type")] = nominalaccount.type == NominalAccountType::Credit ? U("Credit") : U("Debit");

            response[U("NominalAccounts")].as_array().push_back(jsonNominalAccount);
        }

        // Add subtotals to the response
        response[U("subtotals")] = subtotals;

        // Return the response as JSON
        return response;
    });

    // Call the function to create the balance sheet API
    createBalanceSheet(app);

    //calculate the profit and loss
    createProfitLossAPI(app);

    // start server on port 18080
    app.post(18080).multithreaded().run();

}