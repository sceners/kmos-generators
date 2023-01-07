/* bY Kmos in 2000 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void main()
{
        unsigned char name[100]={0};
        int length=0;
        unsigned long al1=0, al2=0, total=0;
        double al1_double=0, constant=3;

	clrscr();
	printf("ÚÄÄÄÄÄÄÄ ° ÄÄÄ Ü ÄÄÄÄÄÄÄ ° ÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
	printf("şßÛÛ²ßÛÛÛ²ßÛÛ²ßÛÛ²Ü   Ü²Û² ß²ÛÛ²ßÛÛÛ²ß ³\n");
	printf("³  ß° ÛÛÛ² Û°  ÛÛÛß²Ü ÛÛÛ²  ÛÛÛ² ÛÛÛ²  ³\n");
	printf("³    °ÛÛÛ²    °ÛÛÛ  ÛÛÛÛÛ² °ÛÛÛ² ÛÛÛ²  ³\n");
	printf("³   Ü²ÛÛÛ²Ü  Ü²ÛÛÛ²Ü ß²ÛÛ²Ü²ÛÛÛ²Ü²ÛÛ²Ü ³\n");
	printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ ßß² ÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
        printf("\nKeyGenerator for NoKnocks v3.0");
        printf("\nWritten bY Kmos [tNO '2000].\n");
	printf("\nEnter your Name: ");
        gets(name);
	length=strlen(name);

        if (length < 2)
        {
                printf("\nERROR: Enter your Name (min 2)...\n");
                return;
        }

        al1=name[0] & 0xFF;
        al2=name[2] & 0xFF;

        asm{
                xor eax, eax

                fild dword ptr [al1]
                fstp real8 ptr [al1_double]
                fld real8 ptr [constant]
                fld real8 ptr [al1_double]
                fyl2x
                fld st(0)
                frndint
                fsubr st(1), st
                fxch st(1)
                fchs
                f2xm1
                fld1
                faddp st(1), st
                fscale
                fstp st(1)
                fistp dword ptr [esp]
                wait
                pop eax
                sub esp, 4
                sub eax, [al2]
                mov [total], eax
        }

        printf("Registration Code: %lu\n",total);
	printf("\nEnJoY aNoThEr qUaLiTy kEyGeN fRoM The Nameless Ones '2000.\n");
        getch();
}
