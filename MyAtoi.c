//Convert numeric String to an int 
//Write atoi function
//
//Test cases
//1. NULL string --> output should be zero
//2. String with characters -->output should be zero
//3. String with mix of characters and digits --> output should be zero if any character comes first 
// sasas13131,.a,dla ==> 0, else 1233dnsjds ==> 123
//4. String with spaces --> output should be zero
//5. String with decimals --> output should be only integer for ex - for 123.5 ==> 123 , 0.54 ==> 0
//6. String with only integers --> right output
//7. Negative numbers
//8. Numbers with positive sign

#include <stdio.h>
#include <stdlib.h>

int MyAtoi(char *str)
{
	if(!*str) return 0;

	int i = 0;
	int sum = 0, sign = 1;

	if(str[i] == '-')
	{
		sign = -1;
		i++;
	}
	
	if(str[i] == '+') i++;

	while(str[i])
	{
		if(str[i] >= '0' && str[i] <= '9')
			sum = sum*10 + (str[i] -'0');
		else
			return sign*sum;
		i++;
	}
	return sign*sum;
}

int main()
{
	char str[50] = {0};
	
	printf("enter string\n");
	gets(str);

	printf("%d\n", atoi(str));
	printf("%d\n", MyAtoi(str));

	return 0;
}
