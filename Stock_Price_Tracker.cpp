#include <iostream>
#include <map>
#include <string>
#include <iomanip> // For std::setprecision
#include <limits>  // For std::numeric_limits

using namespace std;

// Class to manage stock prices
class StockTracker {
private:
    map<string, double> stockPrices;

public:
    // Add or update a stock price
    void setPrice(const string& stockName, double price) {
        stockPrices[stockName] = price;
    }

    // Display the current stock prices
    void displayPrices() const {
        cout << "Current Stock Prices:" << endl;
        cout << fixed << setprecision(2); // Set precision for currency format
        for (const auto& pair : stockPrices) {
            cout << pair.first << ": $" << pair.second << endl;
        }
    }

    // Find the price of a specific stock
    void getPrice(const string& stockName) const {
        auto it = stockPrices.find(stockName);
        if (it != stockPrices.end()) {
            cout << stockName << ": $" << it->second << endl;
        } else {
            cout << "Stock " << stockName << " not found." << endl;
        }
    }
};

int main() {
    StockTracker tracker;
    string command;
    string stockName;
    double price;

    while (true) {
        cout << "\nCommands:\n"
             << "1. Add/Update Stock Price (format: 'set <stock_name> <price>')\n"
             << "2. Display All Stock Prices (format: 'display')\n"
             << "3. Get Price of a Specific Stock (format: 'get <stock_name>')\n"
             << "4. Exit (format: 'exit')\n"
             << "Enter command: ";

        cin >> command;

        if (command == "set") {
            cin >> stockName >> price;
            tracker.setPrice(stockName, price);
        } else if (command == "display") {
            tracker.displayPrices();
        } else if (command == "get") {
            cin >> stockName;
            tracker.getPrice(stockName);
        } else if (command == "exit") {
            break;
        } else {
            cout << "Invalid command." << endl;
            // Clear the input buffer to handle invalid input gracefully
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}
