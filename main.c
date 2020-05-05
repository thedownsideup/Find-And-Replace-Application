#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "func.h"

int main()
{
	int i = 0; /*i is a counter*/
	int request;
	char word[50], newWord[50], rep[50];
	/*word is the one we want to count*/
	/*rep is the word we want to replace*/
	/*newWord is the one we want to put instead of rep*/

	
	printf("Welcome To The Find & Replace Application!\n\n");
	printf("PLEASE NOTICE:\n When I run this code it asks for the name of the file couple of times for some reason and I couldn't fix it or find anyone who could!\n\n");
	printf("How may I serve you?\n");
	printf(" 1-I want to find a word.\n 2-I want to replace a word.\n 3-Exit\n");
	scanf("%d", &request);

	while ((request != 1 && request != 2 && request != 3)) /*checks if request is valid*/
	{
		printf("Sorry, your request is not valid\n Please try again\n");
		scanf("%d", &request);
	}
	
		

	switch (request)
	{
	case 1: //code for getting info for couonting a specific word


		printf("Enter the word you want to count\n");
		scanf("%s", word);
		count(word);
		
		printf("%d, %s(s), were found!\n", count(word), word);
		break;

	case 2: //code for getting info for finding, counting and replacing a specific word:
		printf("enter a word to replace\n");
		scanf("%s", rep);
		printf("enter a new word\n");
		scanf("%s", newWord);

		replace(rep, newWord);
	

		printf("%d %s (s) were found & replaced with %s!\n", count(newWord), rep, newWord);

		break;

	case 3: //code for exiting
		break;
	default: //nothing important don't bother...
		break;
	}
	return 0;
}