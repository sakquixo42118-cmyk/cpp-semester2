#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;


class account {
   private:
   double balance;
   string accountNumber;
   
   public: 
   account (string d, double s):balance(s),accountNumber(d){};
   void deposit (double );
   bool withdraw (double );
   double getBalance ();
   string getAccountNumber();
   
};

class Bank {
    public :
    vector <account> accounts;
    void addAccount (string , double);
    void getAllAccountsInfo();
    bool deleteAccount(string);
};

void Bank::addAccount (string acc, double balan)
{
    accounts.push_back(account(acc,balan));
}
void Bank::getAllAccountsInfo()
{
    int quant=accounts.size();
    for (int i=0;i<quant;i++)
    {
        cout<<"账号"<<":"<<" "<<accounts[i].getAccountNumber();
        cout<<", "<<"余额"<<": "<<accounts[i].getBalance();
        cout<<endl;
    }
}
bool Bank::deleteAccount (string in)
{
    int quant= accounts.size();
    for (int i=0;i<quant;i++)
    {
        if ((accounts[i].getAccountNumber())==in)
        {
         for (int j=i;j<quant-1;j++)
         {
          accounts[j]=accounts[j+1];
         }
         accounts.pop_back();
         return 1;
        }
    }
    return 0;
}

string account::getAccountNumber()
{
  return accountNumber;
}

double account::getBalance(){
    return balance;
}

bool account::withdraw(double in)
{
    if (balance>=in)
    {
        balance-=in;
        return 1;
    }
    else{
        return 0;
    }
}

void account::deposit(double in){
   balance+=in;
}

int main() {
	Bank bank;
	bank.addAccount("123456", 1000.0);
	bank.addAccount("789012", 2000.0);
	bank.getAllAccountsInfo(); // 输出所有账户信息
	for (auto& account : bank.accounts) {
		if (account.getAccountNumber() == "123456") {
			account.deposit(500.0); // 向账号 123456 存款 500
			if (account.withdraw(200.0)) { // 从账号 123456 取款 200
				cout << "取款成功" << endl;
			}
			else {
				cout << "取款失败" << endl;
			}
			break;
		}
	}
	bank.getAllAccountsInfo(); // 再次输出所有账户信息
	if (bank.deleteAccount("789012")) { // 删除账号 789012
		cout << "账号删除成功" << endl;
	}
	else {
		cout << "账号删除失败" << endl;
	}
	bank.getAllAccountsInfo(); // 输出所有账户信息
	return 0;
}