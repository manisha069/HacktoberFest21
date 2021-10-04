# include <stdio.h>
# include <stdlib.h>
#include<time.h>
int main(){
    int number,guess,nguesses=1;
    srand(time(0));// this gives number between 1 to 100...
    number=rand()%100+1;//this gives a random number antime...
    // if we want number between 0 to 100 simply remove (+1) ...
//printf("the number is %d\n",number);
do{
printf("Guess the number between 1-100\n");
scanf("%d",&guess);
if(guess<number){
    printf("Enter the higher one!\n");
}
else if(guess>number){
    printf("Enter the lower one!\n");
}
else{
    printf("You guessed it in %d attempts\n",nguesses);
}    
nguesses++;

}while(guess!=number);
    return 0;
}
