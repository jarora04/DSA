#include<stdio.h>
int main()
{
   int pin=1802;
   int operation;
   int number=1234;
   int amount;
   int withdraw;
 	while(pin==1802)
   	{   
   printf("enter the 4 digit pin:");
   scanf("%d",&pin);
   
   if(pin==1802)
   { 
   printf("enter the operaion(1-3):");
   scanf("%d",&operation);
   switch(operation)
   {
   case 1: printf("balance checking\n");
   { 
   printf("enter the 4 digit bank account number:");
   scanf("%d",&number);
   if(number==1234)
   {
   	printf("the amount in your account is:20000\n");
   }
   else if(number==5678)
   {
   	printf("the amount in your account is:1000\n");
   }
   else if(number==1357)
   {
   	printf("insufficient balance\n");
   }
   
   else
   {
   	printf("invalid bank account number");
   }
   
   }
   break;
   case 2: printf("cash withdrawl\n");
   {
   	printf("enter the amount to withdraw:");
   	scanf("%d",&withdraw);
   	printf("money being withdrawn\n");
	   	printf("take the reciept\n");
   
   }
   break;
   case 3: printf("cash deposit\n");
   {
       printf("enter the amount\n");
       scanf("%d",&amount);
       printf("transaction completed\ntake the reciept\n");
            
   }
   break;
   default: printf("invalid input");
   }
}
else
{
printf("incorrect pin\n");
}
printf("thanks\n");
printf("\n");
}

return 0;
}
