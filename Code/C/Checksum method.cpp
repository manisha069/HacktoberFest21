#include<stdio.h>
#include<string.h>
 
int main()
{
    char a[20],b[20];
    char sum[20],complement[20];
    int i,length;
    
printf("Enter first binary string\n");
    scanf("%s",&a);
    printf("Enter second binary string\n");
    scanf("%s",&b);
    
    if(strlen(a)==strlen(b)){
length = strlen(a);
char carry='0';
        
for(i=length-1;i>=0;i--)
        {
if(a[i]=='0' && b[i]=='0' && carry=='0')
            {
                sum[i]='0';
                carry='0';
            }
            else if(a[i]=='0' && b[i]=='0' && carry=='1')
            {
                sum[i]='1';
                carry='0';
 
            }
            else if(a[i]=='0' && b[i]=='1' && carry=='0')
            {
                sum[i]='1';
                carry='0';
 
            }
            else if(a[i]=='0' && b[i]=='1' && carry=='1')
            {
                sum[i]='0';
                carry='1';
 
            }
            else if(a[i]=='1' && b[i]=='0' && carry=='0')
            {
                sum[i]='1';
                carry='0';
 
            }
            else if(a[i]=='1' && b[i]=='0' && carry=='1')
            {
                sum[i]='0';
                carry='1';
 
            }
            else if(a[i]=='1' && b[i]=='1' && carry=='0')
            {
                sum[i]='0';
                carry='1';
 
            }
            else if(a[i]=='1' && b[i]=='1' && carry=='1')
            {
                sum[i]='1';
                carry='1';
 
            }
            else
                break;
        }
        
printf("\nSum=%c%s",carry,sum);
for(i=0;i<length;i++)
        {
            if(sum[i]=='0')
                complement[i]='1';
            else
                complement[i]='0';
        }
        
        if(carry=='1')
            carry='0';
        else
            carry='1';
        
printf("\nChecksum=%c%s",carry,complement);
}
else {
printf("\nWrong input strings");
}
}
