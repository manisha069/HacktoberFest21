#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int main()
{
 int i=0,j=0,n;
 void *p;
 char ch,a[15],c;
 printf("Enter the expression with $ at the end:");
 while((c=getchar())!='$')
 {
  a[i]=c;
  i++;
 }
 n=i-1;
 printf("Expression:");
 i=0;
 while(i<=n)
 {
  printf("%c",a[i]);
  i++;
 }
 printf("\n SymbolTable\n");
 printf("Symbol \t Address \t Type");
 while(j<=n)
 {
  c=a[j];
  if(isalpha(toascii(c)))
  {
   p=malloc(c);
   printf("\n%c \t %d \t identifier\n",c,p);
   j++;
  }
  else
  {
   ch=c;
   if(ch=='+'||ch=='-'||ch=='*'||ch=='=')
   {
    p=malloc(ch);
    printf("\n %c \t %d \t operator\n",ch,p);
    j++;
   }}}
    return 0;
}
