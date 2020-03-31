#include<stdio.h>

int isalpha(char c)
{
	if(c>=48 && c<=57) //ASCII values of 0 is 48 and 9 is 57, so if the read charachter is between these values then it is a number, else it is a charachter
	  return 0;
	else
	  return 1;
}

int isdigit(char c)
{
	if(c>=48 && c<=57) //ASCII values of 0 is 48 and 9 is 57, so if the read charachter is between these values then it is a number, else it is a charachter
	  return 1;
	else
	  return 0;
}

int main()
{
	char c;
	scanf("%c",&c);
	printf("\nis alpha = %d",isalpha(c));
	printf("\nis digit = %d",isdigit(c));
}
