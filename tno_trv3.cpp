/* bY Kmos in 2000 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

ldiv_t lx;

void main()
{
	unsigned char name[100]={0}, name1[100]={0}, caractere[]="@", code[50]={0}, code1[50]={0}, code_string[100]={0};
	int i=0, k=0, length=0, len_total=0;
	unsigned long int edx=0, ecx=0, ebp6c=0, ebp20=0;

	tno:
	clrscr();
	printf("ÚÄÄÄÄÄÄÄ ° ÄÄÄ Ü ÄÄÄÄÄÄÄ ° ÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
	printf("şßÛÛ²ßÛÛÛ²ßÛÛ²ßÛÛ²Ü   Ü²Û² ß²ÛÛ²ßÛÛÛ²ß ³\n");
	printf("³  ß° ÛÛÛ² Û°  ÛÛÛß²Ü ÛÛÛ²  ÛÛÛ² ÛÛÛ²  ³\n");
	printf("³    °ÛÛÛ²    °ÛÛÛ  ÛÛÛÛÛ² °ÛÛÛ² ÛÛÛ²  ³\n");
	printf("³   Ü²ÛÛÛ²Ü  Ü²ÛÛÛ²Ü ß²ÛÛ²Ü²ÛÛÛ²Ü²ÛÛ²Ü ³\n");
	printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ ßß² ÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
	printf("\nKeyGenerator for TrackerV3 v3.10.0000");
	printf("\nWritten bY Kmos [tNO '2000]\n");
	printf("\nEnter your Name: ");
	gets(name);
	length=strlen(name);

	if (length<1)
	{
		printf("\nERROR: Enter your Name again...");
		getch();
		goto tno;
	}

	strupr(name);
	strrev(name);
	len_total=40 - length;

	for (i=0;i<len_total;i++)
	{
		strcat(name1,caractere);
	}
	strcat(name1,name);
	strupr(name1);

	//-------------------------------------------------------------------

	for (k=1,i=0;i<40;i++,k++)
	{
		ecx=name1[i];
		ecx=ecx * k;
		ebp6c=ecx;
		ebp6c=ebp6c + ebp20;
		ebp20=ebp6c;
	}

	ebp20=ebp20 * 12.34;
	lx=ldiv(ebp20, 0x1A);
	edx=lx.rem;
	edx=edx + 0x41;

	sprintf(code,"%c",edx);
	strcat(code_string,code);
	strcat(code_string,"-");
	sprintf(code1,"%lu",ebp20);
	strcat(code_string,code1);

	printf("Code: %s\n",code_string);
	printf("\n* The Nameless Ones '2000 iS a QUALiTY GROUP! *\n");
}