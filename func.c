#define _CRT_SECURE_NO_WARNINGS
#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int count(char *word)
{
	
	int occurrence = 0; /*occurrence is a counter*/
	int i = 0; /*i is a counter for array(temp)*/
	char ch;
	char temp[50];
	char file_name[50];
	FILE *file = NULL;

	printf("Please enter the name of the file:\n");
	scanf("%s", file_name);
	file = fopen(file_name, "r");
	while (file == NULL)
	{
		printf("cannot find file\n");
		printf("Please enter the name of the file\n");
		scanf("%s", file_name);
		file = fopen(file_name, "r");
	}

	while (ch = fgetc(file)) /*reads text character by character*/
	{
		if ((ch > 'z' || ch < 'a') && (ch<'A' || ch>'Z')) /*checks if word has ended*/
		{
			temp[i] = '\0'; /*ends the array*/
			if (Strcmp(temp, word) == strlen(word)) /*checks if the word has been found or nah*/
			{
				occurrence++; /*if word was found counts as one*/
			}
			i = 0; /*it's for starting over*/
		}
		else {
			temp[i++] = ch;
		}
		if (ch == EOF)
			break;
	}
	
	return occurrence;

	fclose(file);
}
void replace(char *rep, char *newWord) // code to replace words in a file
{
	time_t x = time(NULL);

	char file_name[50];
	printf("Please enter the name of the file\n");
	scanf("%s", file_name);
	FILE *file = fopen(file_name, "r"); /*the original file*/
	while (!file)
	{
		printf("cannot find file\n");
		printf("Please enter the name of the file\n");
		scanf("%s", file_name);
	}

	int i = 0; /*i is a counter for array(temp)*/
	char ch, temp[50];

	FILE *file_rep = fopen("output.txt", "w"); /*the replacement file*/
	if (!file_rep)
	{
		printf("ERROR!\n");
	}

	while ((ch = fgetc(file))!=EOF) /*reads text character by character*/
	{

		if ((ch > 'z' || ch < 'a') && (ch<'A' || ch>'Z')) /*checks if word has ended*/
		{
			temp[i] = '\0';  /*ends the array*/
			if (Strcmp(temp, rep) == strlen(rep)) /*checks if the word has been found or nah*/
			{
				fprintf(file_rep, "%s", newWord); /*replaces the word with the new one in the replacement file*/
			}
			else
			{
				fprintf(file_rep, "%s", temp); /*writes the other words as the same*/
			}
			i = 0; /*is for restarting looking for the word*/
			fprintf(file_rep, " ");
		}
		else
			temp[i++] = ch;
	}
	fclose(file);
	fclose(file_rep);
	file = fopen("input.txt", "w"); /*the original file*/
	file_rep = fopen("output.txt", "r"); /*the replacement file*/
	while ((ch = fgetc(file_rep)) != EOF) /*reads text character by character*/
	{
		if ((ch > 'z' || ch < 'a') && (ch<'A' || ch>'Z'))
		{
			temp[i] = '\0';  /*establishes the end of the array*/
			fprintf(file, "%s", temp); /*writes the other words as the same*/
			i = 0; /*is for restarting looking for the word*/
			if (ch == ' ') {
				fprintf(file, " ");
			}
			if (ch == '\n') //if the text in the original file goes to the next line,
				            //it'll go to the next line in the replacement file as well
			{
				fprintf(file, "\n");
			}

		}
		else
			temp[i++] = ch;
	}
	fprintf(file,"***At %s %d, %s(s), were found and replaced!\n", ctime(&x), count(rep), rep);
	fclose(file);
	fclose(file_rep);
	remove("output.txt");
}
int Strcmp(char *temp,char *word) /*checks if it's the word user asks to count or replace letter by letter*/
{
	if (strlen(temp) != strlen(word))
		return -1;
	//-1 is just a number the length could never be, so the if used above in function count and replace won't be true
	int occ = 0; /*occ stands for occurrence and is a counter*/
	for (int i = 0; temp[i] != NULL; i++)
	{
		//code for checking both capital and small form of the letters
		if (temp[i] + 32 == word[i] || temp[i] - 32 == word[i] || temp[i] == word[i])
			occ++;
	}
	return occ;
}