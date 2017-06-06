
class Bank{
private:
	int acctnum[10];
public:
	void deposit(int num, int value);
	void withdraw(int num, int value);
	void balance(int num);
	void transfer(int num1, int num2, int value);
	Bank();
};


