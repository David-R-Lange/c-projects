#include <stdlib.h>
#include <stdio.h>

void swap(int *firstNumber, int *secondNumber)
{
  int temp = *firstNumber;
  *firstNumber = *secondNumber;
  *secondNumber = temp;
}

void linearSort(int *sortingArray, int size)
{
  int flag = 1;
  int *firstNumber;
  int *secondNumber;
  while(flag)
  {
    flag = 0;
    for(int i = 0; i < size-1; i++)
    {
      firstNumber = sortingArray+i;
      secondNumber = sortingArray+(i+1);
      if(*firstNumber > *secondNumber)
      {
        flag = 1;
        swap(firstNumber, secondNumber);
      }
    }
  }
}

void printArray(int* array, int size)
{
  for(int i = 0; i < size; i++)
  {
    printf("%d\n", *(array+i));
  }
}

int main(void)
{
  printf("Hello, Master. How can I help you today?\n");
  int array[10] = {10, 3, 4, 5, 2, 7, 7, 3, 2, 1};
  int size = sizeof(array) / sizeof(int);
  printArray(array, size);
  linearSort(array, size);
  printf("Very well.\n");
  printArray(array, size);
  return 0;
}
