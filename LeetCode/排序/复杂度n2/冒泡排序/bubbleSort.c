#include <stdio.h>
void doubbleSort(int arr[], int lenght)
{
  for (int i = 0; i < lenght - 1; i++)
  {
    for (int j = 0; j < lenght - 1 - i; j++)
    {
      if (arr[i] > arr[j])
      {
        swap(arr, i, j);
      }
    }
  }
}

void swap(int arr[], int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}