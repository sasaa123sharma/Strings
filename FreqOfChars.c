//Return frequency of characters in the input string
//
//Test cases
//1. NULL string
//2. One character
//3. All characters have freq one
//4. Mix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FreqOfChars(char *str)
{
	int i = 0;
	int count[127] = {0};
	int  temp = 0;

	if(!*str) return ;

	while(str[i])
	{
		count[(int)str[i]]++;
		i++;
	}

	i = 0;

	while(i < 127)
	{
		temp = count[i];

		if(temp > 0)
			printf("%c - %d\n", i, temp);

		i++;
	}

	return ;
}

int main()
{
	char str[50] = {0};

	printf("enter string\n"); 

	//Note -> gets should not be used in practical cases as it does not check the buffer overflow 
	//fgets() should be used always
	gets(str);

	FreqOfChars(str);

	return 0;
}

