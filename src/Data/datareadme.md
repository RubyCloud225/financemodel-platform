# Data Processing - Finance Data

This function is to fetch accounting related data from the platforms API. this application retrieves data for accounting standards, nominal types,  nominal accounts, sales invoices, purchase invoices, bank receipts, bank payments, and journals. It uses `libcurl` for HTTP requests and `nlohmann/json` for JSON parsing

## Requirements

following needs to be installed
- C++ complier
- CMake( for bulding)
- 'libcurl' library
- 'nlohmann/json' library

## Code Overview
dataprocessing.h contains a function declarations for fetching data from the API
dataprocessing.cpp contains the function implementations for fetching data from the API
main.cpp contains the main function to test the dataprocessing functions

## API Endpoints expected

- /accountingstandards
- /Nominaltypes
- /Nominalaccounts
- /Salesinvoices
- /Purchaseinvoices
- /Bankreceipts
- /Bankpayments
- /Journals
