//Replace a blank character by '%20'
//Test cases
//1. NULL string
//2. No space in string
//3. String starting with spaces
//4. String ending with spaces
//5. String have spaces in between
//6. All 4, 5, 6

#include <stdio.h>
#include <stdlib.h>

void ReplaceChar(char *str)
{
	int i = 0, count = 0, new_len = 0;

	while(str[i])
	{
		if(str[i] == ' ')
			count++;
		i++;
	}	

	//i will give here the length of the string
	//as one blank character needs to be replaced by 3 so 
	//new length = i + 2*count
	
	new_len = i + 2*count - 1;

	for(i = i-1  ; i >=0 ; i--)
	{
		if(str[i] == ' ')
		{
			str[new_len] = '0';
			str[new_len -1] = '2';
			str[new_len -2] = '%';
			new_len = new_len -3;
		}
		else
		{
			str[new_len] = str[i];
			new_len--;
		}
	}

	return;
}

int main()
{
	char str[50] = {0};	
	printf("enter string\n");
	gets(str);

	ReplaceChar(str);
	printf("output - '%s'\n", str);

	return 0;
}
