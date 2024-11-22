#ifndef NOMINAL_LEDGER_H
```cpp
#define NOMINAL_LEDGER_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>

// Define an enum for Transaction Type
enum class NominalAccountType {
    Credit,
    Debit
}

struct NominalAccount {
    std::string date; // Format: YYYY-MM-DD
    std::string nominal; // Nominal Catagory
    double amount; // positive for debit, negative for credit
    NominalAccountType type; // Transaction type (Credit or Debit)
};

// Function to split transactions by nominal and compute subtotals
void computeSubtotals(const std::vector<NominalAmount>& nominalAccount, const std::string& givenDate);

#endif // NOMINAL_LEDGER_H
