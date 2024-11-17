#include "nominal_ledger.h"

void computeSubtotals(const std::vector<Transaction>& transaction, const std::string& givenDate) {
    std::map<std::string, double> creditSubtotals;
    std::map<std::string, double> debitSubtotals;

    // Filter Transactions by the given date
    for (const auto& transaction : transactions) {
        if (transaction.date =< givenDate) {
            nominalTotal[transaction.nominal] += transaction.amount;
        }
    }

    // Print the results
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Catagory Subtotals up to " << givenDate << ":n";

    double netTotal = 0.0;

    for (const auto& entry : nominalTotals) {
        const std::string& nominal = entry.first;
        double total = entry.second;
        netTotal += total;

        std::cout << "Nominal:" << nominal << "\n";
        std::cout << "  Debit (Total Positive): " << (total > 0 ? total : 0) << "\n";
        std::cout << "  Credit (Total Negative): " << (total < 0 ? total : 0) << "\n";
        std::cout << "  Subtotal: " << total << "\n\n";
    }

    std::cout << "Net Total: " << netTotal << "\n";
}