//Print first non repeated character from String

//Test cases -
//1. NULL string
//2. One character string
//3. All are same characters
//4. All are different character
//5. First character is non repetitive
//6. Lat Character is non repetitive

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void NonRepeatChar(char *str)
{
	int i = 0;
	char count[127] = {0};
	
	for(i = 0 ; str[i] ; i++)
		count[(int)str[i]]++;

	for(i = 0 ; str[i] ; i++)
	{
		if(count[(int)str[i]] == 1)
		{
			printf("first non repetitive letter %c\n", str[i]);	
			break;
		}
	}
	return;
}

//In Above approach we are scanning string two times, that is not good in practical scenarios
//For example DAN string its quite long
//Is there a way we do not need to scan string second time
//In another approach, we will scan the count array second time
void NonRepeatChar2(char *str)
{
	typedef struct
	{
		int index;
		int count; 
	}COUNT;

	int i = 0;
	COUNT arr[127] = {0};	

	for(i = 0 ; str[i] ; i++)
	{
		arr[(int)str[i]].count++;
		arr[(int)str[i]].index = i;
	}

	int indx = INT_MAX;

	for(i = 0 ; i < 127 ; i++)
	{
		if( arr[i].count == 1 && indx > arr[i].index)
			indx = arr[i].index;
	}

	printf("(%s) - (%d) - first non repetitive letter %c\n", __func__,__LINE__, str[indx]);	

	return ;
}

int main()
{
	char str[20] = {0};
	puts("please enter string");

	fgets(str, 20, stdin);

	if(str[strlen(str) -1] == '\n')
		str[strlen(str) -1] = '\0';
		
	NonRepeatChar(str);
	NonRepeatChar2(str);

	return 0;
}
