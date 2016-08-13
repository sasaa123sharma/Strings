//Count the occurrence of a character in a string
//Test cases
//1. NULL string
//2. One occurrence of character
//3. No occurrence
//4. Mix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio_ext.h>

int FreqOfChar(char *str, char ch)
{
	int i = 0, count = 0;	

	while(str[i])
	{
		if(str[i] == ch)
			count++;
		i++;
	}
	return count;
}

int main()
{
	char str[50];
	char ch;
	
	printf("enter string\n"); 
	gets(str);

	printf("enter character\n"); 
	scanf("%c", &ch);
	//__fpurge(stdin);

	printf("(%c) Freq - %d in '%s' \n", ch, FreqOfChar(str, ch), str);

	return 0;
}
