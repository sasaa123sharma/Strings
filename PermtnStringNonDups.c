//Print all permutations of String(Non Duplicates)
//Test cases
//1. NULL string
//2. Non NULL string
//3. Non NULL string without duplicates
//4. Non NULL string with duplicates

//complecity O(n2.n!)

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
		int j = 0;
		int flag = 0;
		
		for(; i <= end	; i++)
		{
			flag = 0;
			//To avoid duplicates for ex - "aa"
			//it will work for aab, aba but not for abb, abcc
			
			j = i -1 ;	
			
			while( j>= start)
			{
				if(str[i] == str[j])	
				{
					flag = 1;
					break;
				}
				j--;	
			}		
			if(flag) continue;
				
			//if(i != start && str[start] == str[i])
			//	continue; //skip this loop to avoid duplicates

			//fix(start, i);
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
