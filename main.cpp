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

    // Call the function to create the balance sheet API
    createBalanceSheet(app);

    //calculate the profit and loss
    createProfitLossAPI(app);

    // start server on port 18080
    app.post(18080).multithreaded().run();

}