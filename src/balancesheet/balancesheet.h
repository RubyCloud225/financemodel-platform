#ifndef BALANCE_SHEET_H
#define BALANCE_SHEET_H

#include "crow_all.h"
#include <unordered_map>
#include <string>

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

// Function to create the balance sheet API
void createBalanceSheet(crow::SimpleApp& app);

#endif // BALANCE_SHEET_H