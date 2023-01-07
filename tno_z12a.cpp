/* bY Kmos in 2000 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

div_t x;

void main()
{
	unsigned char name[100]={0}, xiba[100]={0};
	int i=0, k=0, j=0, yep=0, length=0, remain=0, counter=0, tno=0;
	long int ecx=0, total=0;

	clrscr();
	printf("ÚÄÄÄÄÄÄÄ ° ÄÄÄ Ü ÄÄÄÄÄÄÄ ° ÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
	printf("şßÛÛ²ßÛÛÛ²ßÛÛ²ßÛÛ²Ü   Ü²Û² ß²ÛÛ²ßÛÛÛ²ß ³\n");
	printf("³  ß° ÛÛÛ² Û°  ÛÛÛß²Ü ÛÛÛ²  ÛÛÛ² ÛÛÛ²  ³\n");
	printf("³    °ÛÛÛ²    °ÛÛÛ  ÛÛÛÛÛ² °ÛÛÛ² ÛÛÛ²  ³\n");
	printf("³   Ü²ÛÛÛ²Ü  Ü²ÛÛÛ²Ü ß²ÛÛ²Ü²ÛÛÛ²Ü²ÛÛ²Ü ³\n");
	printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ ßß² ÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
	printf("\nKeyGenerator for Zip Projects v1.02a");
	printf("\nWritten by Kmos [tNO '2000].\n");

	printf("\nEnter your User Name: ");
	gets(name);
	length=strlen(name);

	printf("Registration Code: ZPR-");

	for (j=0;j<length;j++)
	{
		remain=name[j];
		remain-=2;
		ecx=name[j];
		counter=2;
		k=2;

		for (i=0;i<remain;i++,counter++)
		{
			x=div(ecx,counter);
			tno=x.quot;

			if (x.rem==0)
			{
				k++;
			}

			if (k <= 2)
			{
				goto xiba;
			}
			else
			{
				i=remain;
			}
		xiba:
		}

		if (tno==1)
		{
			ecx=name[j];
			sprintf(xiba,"%c",ecx);
			strupr(xiba);
			printf("%s",xiba);
		}

		if (yep==0)
		{
			ecx=name[0];
			ecx=ecx << 3;
			total=total + ecx;
		}

		if (j==1)
		{
			ecx=name[0];
			ecx=ecx << 3;
			total=total + ecx;
		}
		else
		{
			ecx=name[j-1];
			ecx=ecx << 3;
			total=total + ecx;
		}
		yep++;
	}
	printf("%lu\n",total);
	printf("\nEnJoY aNoThEr qUaLiTy kEyGeN fRoM The Nameless Ones '2000.\n");
}
