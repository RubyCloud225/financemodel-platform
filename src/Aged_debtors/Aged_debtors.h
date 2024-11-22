#ifndef AGED_DEBTORS_REPORT_H
#define AGED_DEBTORS_REPORT_H

#include <string>
#include <vector>
#include <map>

// Structure to hold customer data
struct Customer {
    std::string name;
    double totalDue;
    double oneToTwoMonths;
    double threeToFiveMonths;
    double sixToTwelveMonths;
    double overTwelveMonths;
};

// Class to generate aged debtors report
class AgedDebtorsReport {
    public:
    AgedDebtorsReport(const std::string& apiUrl);
    void fetchData();
    void generateReport();
    void displayReport() const;

    private:
    std::string apiUrl;
    std::vector<Customer> customers;

    void parseSalesData(const std::string& jsonData);
    void parseRecieptsData(const std::string& jsonData);
};

#endif // AGED_DEBTORS_REPORT_H