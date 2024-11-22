#include "nominal_ledger.h"

void computeSubtotals(const std::vector<NominalAccount>& nominalaccount, const std::string& startDate, const std::string&endDate) {
    std::map<std::string, double> creditSubtotals;
    std::map<std::string, double> debitSubtotals;

    for (const auto& nominalaccount : nominalaccounts) {
        // Filter Nominal account by date range
        if (nominalaccount.date >= startDate && nominalaccount.date <= endDate) {
            if (nominalaccount.type == NominalAccountType::Credit) {
                creditSubtotals[nominalaccount.account] += nominalaccount.amount;
            } else {
                debitSubtotals[nominalaccount.account] += nominalaccount.amount;
            }
        }
    }

    json result = json::object();
    for (const auto& pair : creditSubtotals) {
        result[U(pair.first + " Credit")] = json::value::number(pair.second);
    }
    for (const auto& pair : debitSubtotals) {
        result[U(pair.first + " Debit")] = json::value::number(pair.second);
    }

    return result;
}