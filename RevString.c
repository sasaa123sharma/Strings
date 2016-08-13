//reverse a string using recursion and iteration
//Test cases
//1. NULL string
//2. One letter in string
//3. All same letters
//4. All letters are different
//5. Having one space in middle
//6. Having one space at start of the string
//7. Having one space in last of the string

#include <stdio.h>
#include <string.h>

void ReverseItr(char *str)//complexity O(n)
{
	int i = 0;	
	int len = strlen(str);
	char ch;

	for(i = 0 ; i < len/2 ; i++)
	{
		ch = str[i];
		str[i] = str[len -1 - i];
		str[len -1 - i] = ch;
	}

	return;
}

void ReverseItr1(char *str)//complexity O(n)
{
	int len = strlen(str);
	int i = 0;
	char ch ;

	while(i < len)
	{
		ch = str[i];
		str[i] = str[len-1];
		str[len -1] = ch;
		i++;
		len--;
	}	
	return ;
}

void ReverseItrXOR(char *str)//complexity O(n/2)
{
	int i = 0;	
	int len = strlen(str);

	for(i = 0 ; i < len/2 ; i++)
	{
		str[len - 1 -i]  = str[i] ^ str[len -1 - i];
		str[i] = str[i] ^ str[len -1 - i];
		str[len - i - 1] = str[i] ^ str[len -1 - i];
	}

	return;
}

void ReverseRec(char *str, char *ostr)
{
	static int i ;
	//base case
	if(!(*str)) return ;

	ReverseRec(&str[i+1], ostr);
	
	ostr[i] = *str;
	i++;

	return ;
}


void ReverseRec2(char *str, int start, int end )
{
	char temp;
	if(start >= end) return ;
	
	temp = str[end];
	str[end] = str[start];
	str[start] = temp;

	ReverseRec2(str, start +1, end -1);
	
	return ;
}

int main()
{
	char str[20];
	char ostr[20] = {0};

	fgets(str, 20, stdin);

	
	if(str[strlen(str)-1] == '\n')
		str[strlen(str)-1] = '\0';

	int end = strlen(str);

	ReverseItr(str);
	printf("reversed string '%s'\n", str);
	ReverseItrXOR(str);
	printf("reversed string '%s'\n", str);
	ReverseRec(str, ostr);
	printf("reversed string '%s'\n", ostr);
	ReverseItr1(str);
	printf("reversed string '%s'\n", str);
	ReverseRec2(str, 0, end -1);
	printf("reversed string '%s'\n", str);
	return 0;
}
