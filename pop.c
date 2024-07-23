#include <stdio.h>
#include <stdlib.h>

/* set number of required arguments in command line */
#define ARGC 2
/* set values of coins */
#define COIN1 5
#define COIN2 10
#define COIN3 20
/* used for test_price function */
#define MIN 30
#define MAX 105
#define MULTIPLE 5

int test_price(int price)
{
  /* check if the price is valid */
  /* return 1 if the price can be used */
  if (price>=MIN && price<=MAX)
  {
    if (price%MULTIPLE==0)
    {
      return 1;
    }
    else
    {
      printf("Price must be a multiple of %d.\n",MULTIPLE);
      return 0;
    }
  }
  else
  {
    printf("Price must be from %d to %d centimes inclusive.\n",MIN,MAX);
    return 0;
  }
}

void welcome_message(int price)
{
  /* display welcome message stating pop price and commands accepted */
  printf("Pop is %d centimes. Please insert any combination of nickels [N or n], dimes [D or d] or Pentes [P or p]. You can also press R or r for coin return.\n",price);
}

int change(int money)
{
  /* calculate change with the given amount of money */
  int change = money;
  /* amount of coins that will be returned */
  /* in this case, coin2 is dime, coin1 is nickel */
  int coin2 = 0;
  int coin1 = 0;

  while (change > 0 )
  {
    /* for least amount of coins, count the biggest-valued coins first */
    if (change >= COIN2)
    {
      coin2 +=1;
      change -= COIN2;
    }
    else
    {
      coin1 +=1;
      change -= COIN1;
    }
  }
  printf("Change given: %d centimes as %d dime(s) and %d nickel(s).\n",money,coin2,coin1);
  return(0);
}

int user(int price)
{
  /*
   * after the price is set, it will be used in this function
   * this function is responsible for any input from the user and maintainer
  */

  /* initialize the amount of input money by each user as 0 */
  int money = 0;
  /* take input of user */
  char user;

  printf("Welcome to my C Pop Machine!\n");
  welcome_message(price);

  while (money < price)
  {
    printf("Enter coin (NDPR):");
    scanf(" %c", &user);
    if ((user == 'N') || (user == 'n'))
    {
      money += COIN1;
      printf("Nickel detected.\n");
    }
    else if ((user == 'D') || (user == 'd'))
    {
      money += COIN2;
      printf("Dime detected.\n");
    }
    else if ((user == 'P') || (user == 'p'))
    {
      money += COIN3;
      printf("Pente detected.\n");
    }
    else if ((user == 'R') || (user == 'r'))
    {
      /* calculate change with the money the user has put in */
      change(money);
      /* set money = 0 before a new use */
      money = 0;
      welcome_message(price);
    }
    else if ((user == 'E') || (user == 'e'))
    {
      change(money);
      printf("Shutting down. Goodbye.\n");
      exit(0);
    }
    else
    {
      printf("Unknown coin rejected.\n");
    }

    printf("You have inserted a total of %d centimes.\n",money);

    if (money >= price)
    {
      printf("Pop is dispensed. Thank you for your business! Please come again.\n");
      /* minus the price of pop before calculating change */
      change(money - price);
      money = 0;
      welcome_message(price);
    }
    /* if the input money is insufficient */
    else
    {
      printf("Please insert %d more centimes.\n", price - money);
    }
  }
  return(0);
}

int main(int argc, char *argv[])
{
  /* if there is the correct number of arguments from command line */
  if (argc == ARGC)
  {
    /* convert argv[1] to int to check the price */
    int price = atoi(argv[1]);
    if (test_price(price))
    {
      /* call the user() function if price is valid */
      user(price);
    }
  }
  else
  {
    printf("Please specify selling price as a command line argument.\nUsage: pop [price]\n");
  }

return(0);
}
