#include <stdio.h>
#include <stdlib.h>

struct Account {
    int account_number;
    float balance;
};

struct Account createAccount() {
    struct Account account;
    printf("Enter Account Number: ");
    scanf("%d", &account.account_number);
    account.balance = 0.0;
    printf("Account created successfully!\n");
    return account;
}

struct Account deposit(struct Account account) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    account.balance += amount;
    printf("Amount deposited successfully!\n");
    return account;
}

struct Account withdraw(struct Account account) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (account.balance >= amount) {
        account.balance -= amount;
        printf("Amount withdrawn successfully!\n");
    } else {
        printf("Insufficient balance!\n");
    }
    return account;
}

void displayBalance(struct Account account) {
    printf("Account Number: %d\n", account.account_number);
    printf("Account Balance: %.2f\n", account.balance);
}

int main(void) {
    struct Account account;
    int choice;
    int account_created = 0;

    while (1) {
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                account = createAccount();
                account_created = 1;
                break;
            case 2:
                if (!account_created) {
                    printf("Please create an account first.\n");
                    break;
                }
                account = deposit(account);
                break;
            case 3:
                if (!account_created) {
                    printf("Please create an account first.\n");
                    break;
                }
                account = withdraw(account);
                break;
            case 4:
                if (!account_created) {
                    printf("Please create an account first.\n");
                    break;
                }
                displayBalance(account);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
