/* main.c */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool IsPalindrome(int number)
{
  int temp = number; 
  int sum = 0;
  int r = 0;
  
  while(number > 0)    
  {
    r = number % 10;    
    sum = (sum * 10) + r;    
    number = number / 10;    
  }
  
  if (temp == sum)
  {
    return true;
  }   
  return false;
}

int NumberOfPalindroms(int* numbers, int amount)
{
  int counter = 0;
  for(int i = 0; i < amount; i++)
  {
    if(IsPalindrome(numbers[i]))
    {
      counter++;
    }
  }
  return counter;
}

int main(void)
{
	printf("Enter a number of elements in array:\n");
  int numberOfElements = 0;
  
  if(scanf("%d", &numberOfElements) != 1 || numberOfElements <= 0)
  {
    printf("Bad input! Operation failed!\n");
    return 0;
  }

  printf("Enter elements:\n");
  int* array = (int*)malloc(sizeof(int) * numberOfElements);

  int temp = 0;
  for (int i = 0; i < numberOfElements; i++)
  {
    if(scanf("%d", &temp) != 1 || temp <= 0)
    {
      printf("Bad input! Operation failed!\n");
      return 0;
    }
    else
    {
      array[i] = temp;
    }
  }

  printf("Amount of palindromes: %d\n", NumberOfPalindroms(array, numberOfElements));

  free(array);
  return 0;
}
