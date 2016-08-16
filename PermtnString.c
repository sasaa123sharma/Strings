//Print all permutations of String(includes duplicates)
//Test cases
//1. NULL string
//2. Non NULL string

//complexity(n!.n)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *x, char *y)
{
	char ch = *x;
	*x = *y;
	*y = ch;
	return ;
}

void PermtnString(char *str, int start, int end, int *count)
{
	if(start == end)//nothing more left to permute 
	{
		(*count)++;	
		printf(" %d - %s\n", *count, str);
	}
	else
	{	
		int i = start;
		
		for(; i <= end	; i++)
		{
			swap(&str[start], &str[i]); 
			PermtnString(str, start+1, end, count);
			//swap again
			swap(&str[start], &str[i]); //backtrack step	
		} 
	}

	return ;	
}

int main()
{
	char str[50] = {0};
	int count = 0;

	printf("enter the string\n");
	
	gets(str);

	printf("Permutations of string - \n");

	PermtnString(str, 0, strlen(str)- 1, &count);

	return 0;
}
