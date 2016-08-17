//C Program to Check if a Given String is Palindrome
//Test cases - 
//1. NULL string
//2. Non NULL String
//3. String with spaces


#define FALSE 0
#define TRUE 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindrome(char *str)
{
	int i = 0;
	int len = strlen(str);

	while(i < len/2)
	{
		if(str[i] != str[len -1 -i])
			return FALSE;
		i++;
	}
	return TRUE;
}

int main()
{
	char str[50];
	
	printf("enter string\n");

	fgets(str, 50 ,stdin);
	int len = strlen(str);
	
	if(str[len - 1] == '\n')
		str[len - 1] = '\0';

	if(palindrome(str))
		printf("Given string is palindrome\n");

	else
		printf("Given string is not palindrome\n");
		
	return 0;
}
