//Remove trailing spaces in string
//Test cases
//1. NULL string
//2. Only spaces
//3. With trailing spaces
//4. Without trailing spaces


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RmTrailSpaces(char *str)
{
	int len = strlen(str) - 1;
	printf("len = %d\n", len);
	while(len >= 0)
	{
		printf("'%c'\n", str[len]);
		
		if(str[len] != ' ')
		{	
			str[len+1] = '\0';
			break;
		}
		len--;
	}
	
	if(len == -1)//in case string only with spaces 
		str[len+1] = '\0';

	return ;
}

int main()
{	
	char str[50];
	printf("enter string\n");
	gets(str);	
	RmTrailSpaces(str);
	printf("output - '%s'\n", str); 
	return 0;
}

