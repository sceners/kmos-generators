/* bY Kmos in 2000 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void main()
{
        unsigned char name[255]={0}, totstr[50]={0}, code_string[50]={0}, nlic[50]={0};
        int i=0, length=0, len_tot=0;
        unsigned long int total=0, nlicenses=1;

	clrscr();
	printf("ÚÄÄÄÄÄÄÄ ° ÄÄÄ Ü ÄÄÄÄÄÄÄ ° ÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
	printf("şßÛÛ²ßÛÛÛ²ßÛÛ²ßÛÛ²Ü   Ü²Û² ß²ÛÛ²ßÛÛÛ²ß ³\n");
	printf("³  ß° ÛÛÛ² Û°  ÛÛÛß²Ü ÛÛÛ²  ÛÛÛ² ÛÛÛ²  ³\n");
	printf("³    °ÛÛÛ²    °ÛÛÛ  ÛÛÛÛÛ² °ÛÛÛ² ÛÛÛ²  ³\n");
	printf("³   Ü²ÛÛÛ²Ü  Ü²ÛÛÛ²Ü ß²ÛÛ²Ü²ÛÛÛ²Ü²ÛÛ²Ü ³\n");
	printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ ßß² ÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
        printf("\nKeyGenerator for ClockMan95 v1.0.78");
        printf("\nWritten bY Kmos [tNO '2000].\n");
	printf("\nEnter your Name: ");
	gets(name);
        length=strlen(name);
        strupr(name);
        printf("Enter # Users: ");
        gets(nlic);

        nlicenses = atol(nlic);

        if (length < 1)
	{
                printf("\nERROR: Enter your Name again (min 1)...\n");
                getch();
                exit(1);
	}

        if (length > 31)
	{
                printf("\nERROR: Enter your Name again (max 31)...\n");
                getch();
                exit(1);
	}

        if (nlicenses < 1 || nlicenses > 999999)
	{
                printf("\nERROR: The # Users must be 1 to 999999\n");
                getch();
                exit(1);
	}

        asm{
                mov al, [name]
                xor esi, esi
                lea ecx, [name]
                mov edx, 2Fh
                mov edi, 7F806450h
        j1:
                test al, al
                jz jend
                cmp al, 20h
                jz j2
                dec esi
                mov ebx, edx
                sub ebx, esi
                movsx ax, al
                inc ebx
                imul ebx, eax
                add edi, ebx
        j2:
                mov al, [ecx+01]
                inc ecx
                jmp j1
        jend:
                mov eax, [nlicenses]
                lea ecx, [edx-03]
                add edx, 06
                imul edx, [nlicenses]
                shr eax, 10h
                imul eax, ecx
                add edx, edi
                add eax, edx
                movzx eax, ax
                lea ecx, [eax-11]
                lea edx, [eax-03]
                imul ecx, edx
                imul ecx, eax
                add ecx, 47h

                mov [total], ecx
        }

        sprintf(totstr,"%10lu",total);
        len_tot=strlen(totstr);

        for (i=0;i<6;i++,len_tot--)
        {
                code_string[i]=totstr[len_tot-1];
        }

        strrev(code_string);

        printf("\nSerial Number: 8703658945");
        printf("\nLicense Number: %s\n",code_string);
        printf("\n* EnJoY aNotHeR KeyGen bY The Nameless Ones '2000 *\n");
        getch();
}
