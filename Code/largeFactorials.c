/*
Program that takes two integer values as input, displays its product. 
The integer value are so large such that it exceeds range of max value of any integer.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 700

/*
300! goes as long as 614 digits. So taken upper limit as 700. Highest factorial call can go upto 333!
Increase the MAX above to go higher than 333!
Enter the values in terminal or clear comment on line 143 for very large values in input.txt.
*/

const char * multiplication(char A[MAX], char B[MAX]){

  char string_A[MAX];  
  memset(string_A, '\0', MAX);

  static char result[MAX];
  memset(result, '\0', MAX); //Resets value of static variable;

  //Starting Zero Cleanup --start
  int ind; 
  ind = -1;
  for (int i = 0; i < MAX; i++) {
    if (A[i] != '0') {
      ind = i; break;
    }
  }

  for (int i = 0; i < MAX - ind; i++){
    string_A[i] = A[ind + i];
  }

  char string_B[MAX];
  memset(string_B, '\0', MAX);

  ind = -1;
  for (int i = 0; i < MAX; i++) {
    if (B[i] != '0') {
      ind = i; break;
    }
  }

  for (int i = 0; i < MAX - ind; i++){
    string_B[i] = B[ind + i];
  }
  //Starting Zero Cleanup --end

  // printf("A: %s B: %s\n", string_A, string_B);

  int i_n1 = 0;
  int i_n2 = 0;

  for (int i = strlen(string_A) - 1; i >= 0; i--){
    int carry = 0;
    int n1 = string_A[i] - '0';


    i_n2 = 0;
    
    for (int j = strlen(string_B) - 1; j >= 0; j--){
      int n2 = string_B[j] - '0';
      // printf("Previous Carry: %d\n", carry);

      int sum;
      if (result[i_n1 + i_n2]) 
        sum = n1 * n2 + (result[i_n1 + i_n2] - 48) + carry;
      else 
        sum = n1 * n2 + carry;

      carry = sum / 10;

      result[i_n1 + i_n2] = sum % 10 + 48;

      i_n2++;
    }

    if (carry > 0) 
      result[i_n1 + i_n2] += carry + 48;

    i_n1++;
  }

  //Reversing the result array
  int j = strlen(result) - 1; int i = 0; int _temp;
  while (i < j){
    _temp = result[i];
    result[i] = result[j];
    result[j] = _temp;
    i++; j--;
  }
 
  return result;
}


const char * factorial (char string[MAX]){

  static char buffer[MAX];
  memset(buffer, '\0', MAX);

  char temp[MAX]; 
  memset(temp, '\0', MAX);

  strcpy(buffer, string);

  for (int i = strlen(string) - 1; *temp != '1' || strlen(temp) != 1; i){
    // printf("Start: %s\n", buffer);

    if (string[i] == '0'){
      for (int j = i; j >= 0; j--){
        string[j] = '9';

        if (string[j-1] != '0'){
          string[j-1]--;
          strcpy(temp, multiplication(string, "1"));
          strcpy(buffer, multiplication(buffer, string));
          break;
        }
      }
    }

    if (string[i] != '0'){
      string[i]--;
    }

    strcpy(temp, multiplication(string, "1"));
    strcpy(buffer, multiplication(buffer, string));
  }

  return buffer;
} 


int main(){

  char string_A[MAX];
  char string_B[MAX];

  // freopen("input.txt", "r", stdin);

  printf("Enter first number: ");
  scanf("%s", string_A);
  printf("Enter second number: ");
  scanf("%s", string_B);
  printf("Check output.txt\n");


  freopen("output.txt", "w", stdout);

  printf("Product: %s\n\n", multiplication(string_A, string_B));
  // printf("Factorial of %s:\n%s", string_A, factorial(string_A));
  // printf("Factorial of %s:\n%s", string_B, factorial(string_B));

  return 0;
}