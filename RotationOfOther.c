//Check if strings are rotations of each other or not
//Test cases
//1. NULL strings
//2. One NULL and other non NULL
//3. Both same strings 
//4. Both strings(anagram are of different length
//5. Both non similar strings 


//Create a temp string which is concatenation of str1   and str1
//If str2 is sub-string of temp string
//Then str1 and str2 will be rotation of each other

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int RotationOfOther(char *str1, char *str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	//if size of both strings are not same then they can't be rotation of each other
	if(len1 != len2) return 0;

	char str[2*len1];
	
	strcpy(str, str1);
	strcat(&str[len1], str1);
	str[2*len1] = '\0';
	
	char *ptr = strstr(str, str2);
	
	if(ptr) return 1;
	return 0;
}

int main()
{
	char str1[50+1];
	char str2[50+1];
	
	printf("enter two strings\n");
	
	fgets(str1, 50 , stdin); 
	fgets(str2, 50 , stdin);
	
	int len1 = strlen(str1);
	
	if(str1[len1-1] == '\n')
		str1[len1-1] = '\0';
	
	int len2 = strlen(str2);
	
	if(str2[len2-1] == '\n')
		str2[len2-1] = '\0';

	if(RotationOfOther(str1, str2))
		printf("strings are rotation of each other\n");
	else
		printf("strings are not rotation of each other\n");
	
	return 0;
}
