//Find if two strings are anagram of each other

//Test cases
//1. Both are NULL string
//2. One NULL string
//3. Length of both strings same
//4. All characters are same in both strings
//5. Different lengths
//6. Anagrams


#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CheckAnagram(char *str1, char *str2)
{
	int len1 = strlen(str1);					
	int len2 = strlen(str2);				
	//int sum1 = 0, sum2 = 0;	
	int i = 0;


	//if we are not considering lower and upper case, convert both strings to lower or upper format

	//if both are NULL strings return FALSE
	if((len1 != len2) || !len1 || !len2)
		return FALSE;	

/*
	//take ascii sum of characters
	for(i = 0; i < len1; i++)
		sum1 =  sum1 + str1[i];
	
	for(i = 0; i < len2; i++)
		sum2 =  sum2 + str2[i];
	
	if(sum1 != sum2)
		return FALSE;

	*/

	//If we are taking count array here then sum of ascii is not needed actually
	int count[127]= {0};
		
	for(i = 0; i < len1; i++)
	{
		count[(int)str1[i]]++;
		count[(int)str2[i]]--;
	}

	//If both strings are anagrams then corresponding counts will be zero, no need to check count for all 127 

	for(i = 0; i < len1; i++)
		if(count[(int)str1[i]])
			return FALSE;

	return TRUE;
}

int main()
{
	printf("enter two strings\n");

	char str1[20+1] = {0};
	char str2[20+1] = {0};
	
	fgets(str1, 21, stdin);
	if(str1[strlen(str1) -1] == '\n')
		str1[strlen(str1) -1] = '\0';

	fgets(str2, 21, stdin);
	if(str2[strlen(str2) -1] == '\n')
		str2[strlen(str2) -1] = '\0';
		
	if(CheckAnagram(str1, str2))
		printf("Anagram\n");
	else
		printf("Not Anagram\n");
	
	return 0;
}
