//print duplicate characters in a string

//Test cases
//1. NULL string
//2. No Duplicate
//3. Only one character is repeating
//4. String with duplicates 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintDups(char *str);

int main()
{
	char str[100] = {0};

	printf("enter string, max length 100\n");

	fgets(str, 100, stdin);
	
	
	if (str[strlen(str) -1] == '\n')
		str[strlen(str) -1]  = '\0';

	PrintDups(str);

	return 0;
}


void PrintDups(char *s)
{
	int i = 0;
	int l = strlen(s);
	
	int count[127] = {0};

	for(i = 0 ; i < l ; i++)
		count[(int)s[i]]++;

	
	for(i = 0 ; i < l ; i++)
	{
		if(count[(int)s[i]] > 1)
			printf("%c  ", s[i]);

		count[(int)s[i]] = 0; //make count zero so next time that should not get printed
	}
	
	return;
}
