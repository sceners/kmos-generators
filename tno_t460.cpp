/* bY Kmos in 2000 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void main()
{
        unsigned char name[100]={0}, company[100]={0};
        int i=0, len_name=0, len_comp=0;
        unsigned long int ebp0110=0, ebp0110_=0, total=0;
        double ebp08=0, ebp0118=0, ebp18=0, ebp04=0, ebp0118_=0, ebp18_=0, ebp04_=0, x004020c0=-1, x004020b8=9, x004020b0=10, xnumber=1000000000, x004020a8=1005229475, xnumber1=100000000, xibu=0;

	clrscr();
	printf("ÚÄÄÄÄÄÄÄ ° ÄÄÄ Ü ÄÄÄÄÄÄÄ ° ÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
	printf("şßÛÛ²ßÛÛÛ²ßÛÛ²ßÛÛ²Ü   Ü²Û² ß²ÛÛ²ßÛÛÛ²ß ³\n");
	printf("³  ß° ÛÛÛ² Û°  ÛÛÛß²Ü ÛÛÛ²  ÛÛÛ² ÛÛÛ²  ³\n");
	printf("³    °ÛÛÛ²    °ÛÛÛ  ÛÛÛÛÛ² °ÛÛÛ² ÛÛÛ²  ³\n");
	printf("³   Ü²ÛÛÛ²Ü  Ü²ÛÛÛ²Ü ß²ÛÛ²Ü²ÛÛÛ²Ü²ÛÛ²Ü ³\n");
	printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ ßß² ÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
        printf("\nKeyGenerator for The Cassette Tape Producer v4.6.0");
        printf("\nWritten bY Kmos [tNO '2000].\n");
        printf("\nEnter your First Name: ");
	gets(name);
        len_name=strlen(name);
        strlwr(name);

        printf("Enter your Last Name: ");
        gets(company);
        len_comp=strlen(company);
        strlwr(company);

        if (len_name < 1)
	{
                printf("\nERROR: Enter your First Name again...\n");
                getch();
                return;
	}

        if (len_comp < 1)
	{
                printf("\nERROR: Enter your Last Name again...\n");
                getch();
                return;
	}

        for (i=0;i<len_name;i++)
        {
                ebp0110=name[i] & 0xFF;

                asm{
                        fild dword ptr [ebp0110]
                        fstp real8 ptr [ebp0118]
                        fld real8 ptr [ebp0118]
                        fsin
                        fstp real8 ptr [ebp0118]
                        fld real8 ptr [ebp0118]
                        fadd real8 ptr [ebp18]
                        fstp real8 ptr [ebp18]
                }
        }

        asm{
                fld real8 ptr [ebp18]
                fild dword ptr [len_name]
                fstp real8 ptr [ebp04]
                fdiv real8 ptr [ebp04]
                fstp real8 ptr [ebp18]
                fld real8 ptr [ebp18]
                fcomp real8 ptr [xibu]
                fstsw ax
                sahf
                jae j2

                fld real8 ptr [ebp18]
                fmul real8 ptr [x004020c0]
                fstp real8 ptr [ebp18]
        j2:
        }

        for (i=0;i<len_comp;i++)
        {
                ebp0110_=company[i] & 0xFF;

                asm{
                        fild dword ptr [ebp0110_]
                        fstp real8 ptr [ebp0118_]
                        fld real8 ptr [ebp0118_]
                        fcos
                        fstp real8 ptr [ebp0118_]
                        fld real8 ptr [ebp0118_]
                        fadd real8 ptr [ebp18_]
                        fstp real8 ptr [ebp18_]
                }
        }

        asm{
                fld real8 ptr [ebp18_]
                fild dword ptr [len_comp]
                fstp real8 ptr [ebp04_]
                fdiv real8 ptr [ebp04_]
                fstp real8 ptr [ebp18_]
                fld real8 ptr [ebp18_]
                fcomp real8 ptr [xibu]
                fstsw ax
                sahf
                jae j1

                fld real8 ptr [ebp18_]
                fmul real8 ptr [x004020c0]
                fstp real8 ptr [ebp18_]
        j1:
                fld real8 ptr [xnumber]
                fdivr real8 ptr [x004020a8]
                fadd real8 ptr [ebp18_]
                fadd real8 ptr [ebp18]
                fstp real8 ptr [ebp08]
                fld real8 ptr [xnumber1]
                fmul real8 ptr [ebp08]
                fistp dword ptr [esp]
                wait
                pop eax

                mov [total], eax
        }

        printf("\nRegistration: %lu\n",total);
        printf("\n* EnJoY aNotHeR KeyGen bY The Nameless Ones '2000 *\n");
        getch();
}
