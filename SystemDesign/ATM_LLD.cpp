// Gathering the basic requirements
/*
 * - ATM
 * - Card
 * - Cash
 * - Request
 * - Account
 * - User
 *
 *
 */


class ATM {
    int atmID;
    Address address;
    Screen screen;
    CashDispenser caseDispenser;
    CardReader cardReader;
    CashDeposit cashDeposit;
    ChequeDeposit chequeDeposit;
    BankService bankService;
    // atm belongs to a bank
    // each bank has its bank service

};


class Address {
    int pinCode;
    string street;
    string city;
    string state;
    string country;
};


class cashDispenser {
    map<CashType, vector<Cash>> cashAvailable;
    void dispenseCash(int amount) {
        // will take the amount and try to
        // dispense the cash through cash dispenser terminal
    }
};


enum class CashType {
    FIFTY, HUNDRED, FIVE_HUNDRED, THOUSAND
};


class Cash {
    CashType  cashType;
    string serialNumber;
};


class Screen {
    void display(string message) {}
};

class CardReader {
    CardDetails fetchCardDetails();
};

class cardInfo {
    CardType cardType;
    string cardNumber;
    Date expiryDate;
    int cvv;
    BankID bankID;
    float withdrawLimit;
};

enum class cardType {
    DEBIT, CREDIT
};


class Keypad {
    string getInput();
};


class Bank {
    string name;
    Address address;
    vector<ATM> atmList;
    // we will not keep customer data in the bank
    // atm will use banks api to know customer data
    // and make transactions

};

class BankService {
    virtual bool isValidUser(string pin, CardInfo cardInfo) = 0;
    virtual bool getCustomerDetails(CardInfo cardInfo) = 0;
    virtual bool executeTransaction(Transaction transaction, Customer customer) = 0;
};

class BankA : BankService {
    // will have the implementation of the above functions
};

class BankB : BankService {
    // will have the implementation of the above functions
};

class BankServiceFactory {
    BankService getBankServiceObject(CardInfo cardInfo);
};









