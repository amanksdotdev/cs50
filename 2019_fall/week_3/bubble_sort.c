#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

#define N 10

void bubble_sort(int* arr);
void swap(int i, int j, int* arr);
void printArray(int* arr);

int main(int argc, char* argv[])
{
  int arr[N];
  if(argc == 11) {
    for(int i = 1; i <= N; i++) {
      if(isdigit(argv[i]) != 0){
        printf("Invalid number found in given array! %s\n", argv[i]);
        return 1;
      }
      arr[i-1] = atoi(argv[i]);
    }
  } else if(argc == 1){
    printf("Usage: ./bubble_sort 1...10\n");
    return 1;
  } else {
    printf("Array items should be 10 numbers\n");
    return  1;
  }

  bubble_sort(&arr[0]);
  printArray(&arr[0]);
}

void bubble_sort(int* arr)
{
  bool swap_flag = false;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N - 1 - i; j++){
      int c = arr[j];
      int n = arr[j+1];
      if(c > n){
        swap(j, j+1 , arr);
        swap_flag = true;
      }
    }
    if(!swap_flag)
      break;
  }
}


void swap(int i, int j, int* arr)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void printArray(int* arr){
  for(int i = 0; i < N; i++){
    printf("%i, ", arr[i]);
  }
  printf("\n");
}