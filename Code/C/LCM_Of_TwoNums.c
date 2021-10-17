#include <stdio.h>

void main(){
    int n1,n2,max,lcm;
    printf("Enter number1 and number2 to find LCM:\n");
    scanf("%d%d",&n1,&n2);
    
    if(n1>n2){
        max=n1;
    }else{
        max=n2;
    }

    while(1>0){
        if(max%n1==0 && max%n2==0){
            lcm=max;
            break;
        }else{
            max++;
        }
    }

    printf("LCM of %d and %d is %d",n1,n2,lcm);
}