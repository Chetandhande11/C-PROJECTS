#include <stdio.h>


int money;
int balance=0;
int choice;
int acc_no= 12345;
int pin_number=123;

int withdraw(void);
int Deposit(void);
int Balance(void);

int main(void)
{
	puts("*--------------ATM MANAGEMENT SYSTEM----------------*");
	int i;
	for(i=0;i!=4;i = i+1)
	{
		printf("1.Withdraw\n2.Deposit\n3.check balance\n4.Exit\n");
	printf("Enter a choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			withdraw();
			break;
		
		case 2:
			Deposit();
			break;
		case 3:
			Balance();
			break;
		case 4:
			break;
		default:
			printf("Please enter valid choice:-");
			break;
		
	}
	
	}
	
	
	
}
int Deposit(void)
{
	
   printf("Enter money you want to deposit = ");
   scanf("%d",&money);
   
   printf("Enter pin number = ");
   scanf("%d",&pin_number);
   
   if(pin_number==123)
   {
   	balance=balance+money;
   	printf("%d money will be deposited in account\n",money);
   }
   else
   {
   	printf("Enter valid pin");
   }
   
   
}


int withdraw(void)
{
	printf("how many money you want to withdraw? ");
	scanf("%d",&money);
	   printf("Enter pin number = ");
   scanf("%d",&pin_number);
	if (pin_number != 123)
{
    printf("pin is wrong\n");
}
	else if (money < 0)
{
    printf("you cannot with because balance is 0\n");
}
else if (money > balance)
{
    printf("Insufficent balance\n");
}
else
{
    balance = balance - money;
    printf("%d Money is withdraw\n",balance);
}

	
}

int Balance(void)
{
	printf("Enter account number = ");
	scanf("%d",&acc_no);
	
	if(acc_no==12345)
	{
	printf("balance is %d\n",balance);
	}
	else
	{
		printf("Enter valid account number\n");
	}
}

