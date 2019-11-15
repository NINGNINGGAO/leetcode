/*
 * @Author: AGOGIN
 * @Date: 2019-11-15 17:36:50
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-15 17:39:56
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


int main() {

	return 0;
}
char * intToRoman(int num){
    char *roman[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
	int num1[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
	int i;
	char* con;
	con = (char*)malloc(sizeof(char) * 20);
	memset(con, 0, 20);
	for (i = 0; i < 13; i++)
	{
		while (num >= num1[i])
		{
			num -= num1[i];
			strcat(con, roman[i]);
		}
	}
	return con;
}

