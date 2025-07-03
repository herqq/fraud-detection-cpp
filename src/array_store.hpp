#ifndef ARRAY_STORE_HPP
#define ARRAY_STORE_HPP

#include <string>
#include "../lib/json.hpp" // For JSON export

// Structure to represent a single financial transaction
struct Transaction {
    std::string transaction_id;
    std::string timestamp;
    std::string sender_account;
    std::string receiver_account;
    double amount;
    std::string transaction_type;
    std::string merchant_category;
    std::string location;
    std::string device_used;
    std::string is_fraud;
    std::string fraud_type;
    std::string time_since_last_transaction;
    std::string spending_deviation;
    std::string velocity_score;
    std::string geo_anomaly;
    std::string payment_channel;
    std::string ip_address;
    std::string device_hash;
};

// Array-based class to store and manage transactions
class ArrayStore {
private:
    Transaction* transactions; // Raw array of transactions
    int capacity;              // Maximum number of transactions
    int size;                  // Current number of transactions

public:
    // Constructor and destructor
    ArrayStore(int max_size = 1000);
    ~ArrayStore();

    // Add a transaction to the array
    void addTransaction(const Transaction& t);

    // Group transactions by payment channel (returns a new ArrayStore)
    ArrayStore groupByPaymentChannel(const std::string& channel) const;

    // Sort transactions by location (ascending)
    void sortByLocation();

    // Search for transactions by type (returns a new ArrayStore)
    ArrayStore searchByTransactionType(const std::string& type) const;

    // Export transactions to JSON
    nlohmann::json toJSON() const;

    // Display transactions to console
    void display() const;

    // Get the number of transactions
    int getSize() const;
};

#endif // ARRAY_STORE_HPP 