#ifndef PROFIT_LOSS_H
#define PROFIT_LOSS_H

#include "crow_all.h"
#include <unordered_map>
#include <string>

// Structure to hold profit and loss accounts per accounting standard
struct ProfitLossAccount {
    double revenue;
    double cost_of_goods_sold;
    double operating_expenses;
    double interest_expense;
    double taxes;
};

// Function to create the profit and loss API
void createProfitLossAPI(crow::SimpleApp& app);

#endif // PROFIT_LOSS_H