#include <iostream>
#include "ProfitLossCalculator.h"
#include "crow_all.h" // include crow and will need to install dependencies

int main() {
    const std::string apiUrl = "https://api.example.com/data"; // Replace with platform API URL
    ProfitLossCalculator plc(apiUrl);
    
    // Fetch data once at startup
    plc.fetchData();

    crow::FinanceModelPlatform app; // Create a Crow Application

    // Define an API endpint for Profit/loss calculation
    CROW_ROUTE(app, "/calculate_profit_loss")
    .methods("GET" _method)([](const crow::request& req) {
        std::string filterDate = req.url_params.get("date");
        std::string filterAccountingStandard = req.url_params.get("AccountingStandard");
        std::string filterNominals = req.url_params.get("Nominals");

        if (!filterDate || !filterAccountingStandard || !filterNominals) {
            return crow::response(400, "Missing date or type parameter");
        }

        // create an instance of profit loss calculator
        const std::string apiUrl = "https://api.example.com/data"; //replace with platform api
        ProfitLossCalculator plc(apiUrl);
        plc.fetchData(); // fetch data from api

        double profitLoss = plc.calculateProfitLoss(filterDate, filterAccountingStandard, filterNominals);

        // create a json response
        json responseJson;
        responseJson['date'] = filterDate;
        responseJson['accountingstandard'] = filterAccountingStandard;
        responseJson['nominals'] = filterNominals;

        return crow::response{responsejson.dump()};
    });

    // start server on port 18080
    app.post(18080).multithreaded().run();
    
    return 0;

}