//check if a String contains only digits? 
//Test cases
//1. NULL string
//2. One letter/digit
//3. All letters
//4. All digits 
//5. Mix of digits and letters

#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//Using standard C API - isdigit()
int CheckDigits(char *str)
{
	int i = 0;

	do
	{
		if(!isdigit(str[i]))
			return FALSE;
		i++;
	}while(str[i]);

	return TRUE;	
}

//by checking the ascii value
int CheckDigits1(char *str)
{
	int i = 0;
	
	do
	{
		if(str[i] < '0' || str[i] > '9')
			return FALSE;
		i++;
	}while(str[i]);

	return TRUE;
}

int main()
{
	char str[20];

	fgets(str, 20, stdin);
	
	int len = strlen(str);

	if(str[len-1] == '\n')
		str[len-1] = '\0';

	if(CheckDigits(str))
		printf("string contains all digits\n");
	else
		printf("string does not contain all digits\n");
		
	if(CheckDigits1(str))
		printf("string contains all digits\n");
	else
		printf("string does not contain all digits\n");

	return 0;
}
