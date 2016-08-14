//Return maximum occurring character in the input string
//If two characters have same max frequency, then first max occurring character will be returned
//For ex-> in abc --> a will be returned
//In asdasd --> a will be returned
//
//Test cases
//1. NULL string
//2. One character
//3. All characters have freq one
//4. Mix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int FreqOfChar(char *str, char *ch)
{
	int i = 0;
	int max = 0;
	*ch = '\0';

	int count[127] = {0};

	while(str[i])
	{
		count[(int)str[i]]++;

		if(count[(int)str[i]] > max)
		{
			max = count[(int)str[i]];
			*ch = str[i];			
		}
		i++;
	}

	return max;
}

int main()
{
	char str[50] = {0};
	char ch;
	
	printf("enter string\n"); 
	gets(str);

	int max = FreqOfChar(str, &ch);

	printf("%c has max Freq - %d in '%s' \n", ch, max , str);

	return 0;
}

