
//Count Number of Vowels, Consonants, Digits and White space in a String
//Test cases
//1. NULL string
//2. All vowels
//3. All consonants
//4. All digits
//5. All spaces
//6. Mix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CheckVowels(char *str)
{
	int i = 0;
	int vowels_c = 0;
	int consts_c = 0;
	int digits_c = 0;
	int spaces_c = 0;
	
	while(str[i])
	{
		if(str[i] >= '0' && str[i] <= '9')
			digits_c++;
		else if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
			vowels_c++;
		else if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			consts_c++;
		else if(str[i] == ' ' || str[i] == '	')
			spaces_c++;
		i++;
	}
	
	printf("Vowels: %d\n", vowels_c);
	printf("Consonants: %d\n", consts_c);
	printf("Spaces: %d\n", spaces_c);
	printf("Digits: %d\n", digits_c);
	
	return;
}



int main()
{
	char str[50];
	fgets(str, 50, stdin);
	int len = strlen(str);
			
	if(str[len-1] == '\n')
		str[len-1] = '\0';
	
	CheckVowels(str);
	return 0;
}
