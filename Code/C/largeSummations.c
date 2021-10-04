#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 100

/*
Program that takes two large integer values as input, displays its sum. 
The integer value so large such that it exceeds the range of max value of integer/float type.]
*/

const char * addition(char string_a[MAX], char string_B[MAX]){

  char string_A[MAX] = {'0'};
  //Concats a zero if there's a carry.
  strcat(string_A, string_a);

  int no_of_zeroes = abs(strlen(string_A) - strlen(string_B));
  // printf("%d\n", no_of_zeroes);

  char string_temp[MAX];
  //Keeps track of leading zeroes
  for (int i = 0; i < no_of_zeroes; i++){
    string_temp[i] = '0';
  }
  string_temp[no_of_zeroes] = '\0';

  strlen(string_A) > strlen(string_B) ? 
  strcat(string_temp, string_B) : strcat(string_temp, string_A);

  strlen(string_A) > strlen(string_B) ? 
  sprintf(string_B, "%s" , string_temp) : sprintf(string_A, "%s" , string_temp);
  // printf("A:%s B:%s\n", string_A, string_B);

  static char result[MAX]; int carry = 0;

  for (int i = strlen(string_A) - 1; i != -1; i--){

    if (string_A[i] + string_B[i] + carry - 48 > 57){
      result[i] = (int)string_A[i] + (int)string_B[i] + carry - 58;
      carry = 1;  
    } else {
      result[i] = (int)string_A[i] + (int)string_B[i] + carry - 48;
      carry = 0;
    }
    // printf("%c\n", result[i]); 
  }

  result[strlen(string_A)] = '\0';

  if (result[0] == 48){
    for (int i = 0; i < strlen(result); i++){
      result[i] = result[i+1];
    }

    result[strlen(string_A) - 1] = '\0';
  };

  return result;
}


int main(){

  // Enter values in terminal or clear comment on line 69 for large values in input.txt.

  char string_A[MAX];
  char string_B[MAX];

  // freopen("input.txt", "r", stdin);

  printf("Enter first number: ");
  scanf("%s", string_A);
  printf("Enter second number: ");
  scanf("%s", string_B);
  printf("Check output.txt\n");

  freopen("output.txt", "w", stdout);

  printf("Sum: %s\n\n", addition(string_A, string_B));

  return 0;
}