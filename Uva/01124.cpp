#include <string>

class Account
{
private:
    std::string name; // account name data member
    int balance{0};   // data member with default initial value }; // end class Account

public:
    // 생성자.
    // 리턴 타입이 void인 함수라고 생각하면 됨.
    Account(std::string accountName, int initialBalance)
        : name{accountName}
    {
        if (initialBalance > 0)
        {
            balance = initialBalance;
        }
        if (depositAmount > 0)
        {
            balance = balance + depositAmount;
        }
    }
    int getBalance()
    {
        return balance;
    }
    void setName(std::string accountName)
    {
        name = accountName;
    }

    std::string getName()
    {
        return name;
    }
};
