/* bY Kmos in 2000 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <mem.h>

void main()
{
	static unsigned char table[]={0x17, 0x59, 0x2D, 0x21, 0x4B, 0x0D, 0x5B, 0x03, 0x37, 0x43};
	unsigned char key[150]={0}, core[255]={0}, code[255]={0}, serial[255]={0}, tno[255]={0}, strecx[255]={0}, *xbs, final_code[255]={0}, codez[255]={0};
	int i=0, length=0, xiba=0, len_serial=0, len_final=0;
	unsigned long int ecx=0;

	tno:
	clrscr();
	printf("ÚÄÄÄÄÄÄÄ ° ÄÄÄ Ü ÄÄÄÄÄÄÄ ° ÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
	printf("şßÛÛ²ßÛÛÛ²ßÛÛ²ßÛÛ²Ü   Ü²Û² ß²ÛÛ²ßÛÛÛ²ß ³\n");
	printf("³  ß° ÛÛÛ² Û°  ÛÛÛß²Ü ÛÛÛ²  ÛÛÛ² ÛÛÛ²  ³\n");
	printf("³    °ÛÛÛ²    °ÛÛÛ  ÛÛÛÛÛ² °ÛÛÛ² ÛÛÛ²  ³\n");
	printf("³   Ü²ÛÛÛ²Ü  Ü²ÛÛÛ²Ü ß²ÛÛ²Ü²ÛÛÛ²Ü²ÛÛ²Ü ³\n");
	printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ ßß² ÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
	printf("\nKeyGenerator for AlarmMe v3.0");
	printf("\nWritten bY Kmos [tNO '2000]\n");
	printf("\nEnter your Key: ");
	gets(key);
	length=strlen(key);
	xiba=length;

	if (length<2)
	{
		printf("\nERROR: Enter your Key, try again...");
		getch();
                goto tno;
        }

	for (i=0;i<length;i++,xiba--)
	{
		ecx=key[xiba-1];
		sprintf(core,"%c",ecx);
		ecx=atol(core);
		ecx=table[ecx];
		ecx=ecx * xiba;
		sprintf(code,"%lu",ecx);
		strcat(serial,code);
	}

	len_serial=strlen(serial);

	for (i=0;i<len_serial;)
	{
		ecx=serial[i];
		sprintf(core,"%c",ecx);
		strcat(tno,core);
		ecx=serial[i+1];
		sprintf(core,"%c",ecx);
		strcat(tno,core);
		ecx=atol(tno);

		if (ecx < 10)
		{
			sprintf(codez,"%s","0");
			strcat(final_code,codez);
			goto xiba;
		}

		if (ecx < 0x41)
		{
			ultoa(ecx, strecx, 10);
			xbs[0]=strecx[0];
			xbs[1]='\0';
			sprintf(codez,"%s",xbs);
			strcat(final_code,codez);
		}
		else
		{
			if (ecx > 0x5A)
			{
				ultoa(ecx, strecx, 10);
				xbs[0]=strecx[0];
				xbs[1]='\0';
				sprintf(codez,"%s",xbs);
				strcat(final_code,codez);
			}
			else
			{
				sprintf(codez,"%c",ecx);
				strcat(final_code,codez);
			}
		}

	xiba:
		i+=2;
		memcpy(tno,"",1);
	}

	len_final=strlen(final_code);
	xiba=final_code[len_final-1];

	if (xiba==48)
	{
		final_code[len_final-1]='\0';
	}

	printf("Registration Code: %s\n",final_code);
	printf("\n* The Nameless Ones '2000 iS a QUALiTY GROUP! *\n");
}