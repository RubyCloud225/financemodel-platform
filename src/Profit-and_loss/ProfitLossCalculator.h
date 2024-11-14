#include <vector>
#ifndef PROFIT_LOSS_CALCULATOR_H
#define PROFIT_LOSS_CALCULATOR_H

struct NominalData {
    std::string date;
    std::string accountingstandards; // UKGAAP, USGAAP, IFRS
    std::string Nominals;
    double amount;

};

class ProfitLossCalculator {
    public:
        ProfitLossCalculator(const std::string& apiUrl);
        double calculateProfitLoss(const std::string& filterdate, const std::string& filteraccountingstandards, const std::string& filterNominals);
        void fetchData();
    private:
        std::string apiUrl;
        std::vector<NominalData> nominalDataList;
};

#endif //PROFIT_LOSS_CALCULATOR_H