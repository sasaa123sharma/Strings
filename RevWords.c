//Reverse words in a given string
//Let the input string be “i like this program very much”. The function should change the string to “much very program this like i”
//
//Test cases - 
//1. NULL string
//2. String with only spaces
//3. String starting with spaces
//4. String ending with spaces

//complexity O(n)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Reverse individual word and then reverse whole string

void reverse(char *str, int start, int len)
{
	char temp;
	int i = 0;

	while(i < (len/2))
	{
		temp = str[start+i];

		str[start+i] = str[start + len - 1 - i]; 

		str[start + len - 1 - i] = temp; 
		i++;	
	}

	return ;
}


void RevWords(char *str)
{
	int i = 0, j = 0;

	while(str[i])
	{
		//string can start with spaces as well 
		//so skip those first spaces
		if(str[i] == ' ')
			i++;
		else
		{
			j = i; //start of the word
	
			//count the number of letters 
			while(str[i] && str[i] != ' ')
				i++;

			//This new i will be end of the word
			//i - j //length of this word
			
			reverse(str, j, (i-j));//reverse this particular word
		}
	}

	//now reverse the whole string
	reverse(str, 0, strlen(str));

	return ;
}

int main()
{
	char str[50] = {0};
	printf("Enter the string\n");
	
	fgets(str, 50, stdin);
	int len = strlen(str);
	
	if(str[len -1] == '\n')
		str[len -1] = '\0';

	RevWords(str);	
	printf("Reversed string - '%s'\n", str);	
	return 0;
}
