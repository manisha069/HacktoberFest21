#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10

void swap(char *x, char *y) {
	char t = *x; *x = *y; *y = t;
}
void reverse(char str[], int length) 
{
	int start = 0;
	int end = length -1;
	while (start < end) 
	{
		swap((str+start), (str+end));
		start++;
		end--;
	} 
} 
char* itoa(int num, char* str, int base) 
{
	int i = 0;
	int isNegative = 0; 
	if (num == 0) 
    {
		str[i++] = '0'; 
		str[i] = '\0'; 
		return str; 
	}
	if (num < 0 && base == 10) 
	{
		isNegative = 1; 
		num = -num; 
	} 
	
	while (num != 0) 
    {
		int rem = num % base; 
		str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
		num = num/base; 
	} 
    if (isNegative) 
		str[i++] = '-'; 

	str[i] = '\0'; 
  
    reverse(str, i); 
  
    return str; 
} 
void string2hexString(char* input, char* output)
{
    int loop;
    int i; 
    
    i=0;
    loop=2;
    
    while(loop<strlen(input)-1)
    {
        sprintf((char*)(output+i),"%02X", input[loop]);
        loop+=1;
        i+=2;
    }
    output[i++] = '\0';
}
struct input
{
	char label[10],opcode[10],operand[10],mnemonic[5];
	int loc,locctr;
};
struct input table[MAX];
struct symtab
{
	char sym[10];
	int f,val,ref;
};
struct symtab symtb1[MAX];
void main()
{
	int f1,i=1,j=1,flag,locctr,x,starting;
	char add[10],code[10],mnemcode[5];
	FILE *fp1,*fp2,*fp3;
	printf("\nImplementation Of A Single Pass Assembler:");	
	printf("\n------------------------------------------\n\n");
	fp1=fopen("input.txt","r");
	fp2=fopen("optab.txt","r");


	fscanf(fp1,"%s%s%s",table[i].label,table[i].opcode,table[i].operand);
	if(strcmp(table[i].opcode,"START")==0)
	{
		strcpy(table[i].mnemonic,"00");
		table[i].loc=atoi(table[i].operand);
		locctr=atoi(table[i].operand);

		i++;
		fscanf(fp1,"%s%s%s",table[i].label,table[i].opcode,table[i].operand);
	}
    #include<stdio.h>
	else
		locctr=0;
	starting = locctr;

	while(!feof(fp1))
	{

		if(strcmp(table[i].label,"**")!=0)
		{
			for(x=1;x<j;x++)
			{
				f1=0;
				if((strcmp(symtb1[x].sym,table[i].label)==0) && (symtb1[x].f==1))
				{
					symtb1[x].val=locctr;
					symtb1[x].f=0;
					table[symtb1[x].ref].loc=locctr;
					f1=1;  break;
				}
			}
			if(f1==0)
			{
				strcpy(symtb1[j].sym,table[i].label);
				symtb1[j].val=locctr;
				symtb1[j].f=0; j++;
			}
		}
		fscanf(fp2,"%s%s",code,mnemcode);

		table[i].locctr=locctr;
		while(!feof(fp2))
		{
			if(strcmp(table[i].opcode,code)==0)
			{
				strcpy(table[i].mnemonic,mnemcode);
				locctr+=3;
				for(x=1;x<=j;x++)
				{
					flag=0;
					if(strcmp(table[i].operand,symtb1[x].sym)==0)
					{
						flag=1;
						if(symtb1[x].f==0)
							table[i].loc=symtb1[x].val;
							break;
					}
				}
				if(flag!=1)
				{
					strcpy(symtb1[j].sym,table[i].operand);
					symtb1[j].f=1;
					symtb1[j].ref=i; j++;
				}
			}
			fscanf(fp2,"%s%s",code,mnemcode);
		}
		rewind(fp2);
  		if(strcmp(table[i].opcode,"WORD")==0)
		{
			locctr+=3;
			strcpy(table[i].mnemonic,"00000");
			table[i].loc=atoi(table[i].operand);
		}
		else if(strcmp(table[i].opcode,"RESW")==0)
		{
			locctr+=(3*(atoi(table[i].operand)));
		}
		else if(strcmp(table[i].opcode,"RESB")==0)
		{
			locctr+=(atoi(table[i].operand));
		}
		else if(strcmp(table[i].opcode,"BYTE")==0)
		{
			locctr++;
			if((table[i].operand[0]=='C') || (table[i].operand[0]=='X'))
			{
				strcpy(table[i].mnemonic,"");
				for(int z=2;z<strlen(table[i].operand)-1;z++)
				{
					string2hexString(table[i].operand,table[i].mnemonic);
				}			
			}			
			else
				table[i].loc=locctr;
		}
		else if(strcmp(table[i].opcode,"END") == 0){
			table[i].loc = starting;
			strcpy(table[i].mnemonic,"E^00");
						
		}
		i++;
		fscanf(fp1,"%s%s%s",table[i].label,table[i].opcode,table[i].operand);
	}

	printf("\nObject Code\n=================================\n");
	for(x=1;x<i;x++)
	{
		if(strcmp(table[x].opcode,"START")==0){
			printf("H^%s^00%d^%d\nT^00%d^",table[i].label,starting,locctr-starting,starting);
		}
		else if(strcmp(table[x].opcode,"END")==0){
			printf("\n%s%s",table[x].mnemonic,itoa(table[x].loc,add,10));
		}
		else if(strcmp(table[x].opcode,"BYTE")==0){
			printf("%s^",table[x].mnemonic);
		}
		else{
			if(strcmp(table[x].opcode,"RESW")==0 || strcmp(table[x].opcode,"RESB") == 0)
				continue;
			printf("%s%s^",table[x].mnemonic,itoa(table[x].loc,add,10));
		}
	}
	
	printf("\n\nObject Code Mapping\n=================================\n");

	for(x=1;x<i;x++)
	{
		printf(
			"%i\t%s\t%s\t%s\t",
			table[x].locctr,
			table[x].label,
			table[x].opcode,
			table[x].operand
		);
		if(strcmp(table[x].opcode,"BYTE")==0){
			printf("%s\n\n\n",table[x].mnemonic);
		}
		else{		
			printf("%s%s\n\n\n",table[x].mnemonic,itoa(table[x].loc,add,10));
		}
	}

}
