#include<stdio.h>
/*
 * abc.txt pqr.txt xyz.txt
 * */
void fillList(char* ch)
{
	int len = strlen(ch);
	char* newStr = (char*)calloc(sizeof(char)*len);

	for(int i=0; i<len; i++)
	{
		if(ch[i]=='.')
		{

		}
		else
		{
			newStr[i] = ch[i];
		}
	}
}
int main(void)
{
	return 0;
}
