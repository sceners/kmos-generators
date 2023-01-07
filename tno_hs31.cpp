/* bY Kmos in 2000 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void main()
{
        unsigned char name[200]={0}, xiba[200]={0};
        int i=0, length=0;
        unsigned long ecx=0, ebpE0=0, total=0, total_esi=0, eaxz=0, esiz=0, kredu=0, totalz=0, numberz=0;
        double ebpE8=0, ebpF0=0, ebpF8=0, xibu=0, k=1, ebp100=0, constant1=5;
        static unsigned long constant=56789;

	clrscr();
	printf("ÚÄÄÄÄÄÄÄ ° ÄÄÄ Ü ÄÄÄÄÄÄÄ ° ÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
	printf("þßÛÛ²ßÛÛÛ²ßÛÛ²ßÛÛ²Ü   Ü²Û² ß²ÛÛ²ßÛÛÛ²ß ³\n");
	printf("³  ß° ÛÛÛ² Û°  ÛÛÛß²Ü ÛÛÛ²  ÛÛÛ² ÛÛÛ²  ³\n");
	printf("³    °ÛÛÛ²    °ÛÛÛ  ÛÛÛÛÛ² °ÛÛÛ² ÛÛÛ²  ³\n");
	printf("³   Ü²ÛÛÛ²Ü  Ü²ÛÛÛ²Ü ß²ÛÛ²Ü²ÛÛÛ²Ü²ÛÛ²Ü ³\n");
	printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ ßß² ÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
        printf("\nKeyGenerator for HtmlSS v3.1");
        printf("\nWritten bY Kmos [tNO '2000].\n");
        printf("\nEnter your Registration Key (6 random numbers): ");
	gets(name);
	length=strlen(name);

        if (length > 6)
        {
                printf("\nERROR: Enter exactly 6 random numbers...\n");
                return;
        }

        for (k=1,i=0;i<length;i++,k++)
        {
                strcat(xiba,"");
                ecx=name[i] & 0xFF;
                ebpE0=ecx;

                sprintf(xiba,"%c",ecx);
                xibu=atol(xiba);

                asm{
                        fild dword ptr [ebpE0]
                        fstp real8 ptr [ebpE8]
                        fild dword ptr [constant]
                        fstp real8 ptr [ebpF0]
                        fld real8 ptr [ebpF0]
                        fmul real8 ptr [xibu]
                        fadd real8 ptr [ebpE8]
                        fld real8 ptr [k]
                        fstp real8 ptr [ebpF8]
                        fmul real8 ptr [k]
                        fistp dword ptr [esp]
                        wait
                        pop eax
                        sub esp, 4
                        mov [total_esi], eax
                }

                total_esi+=kredu;
                total=total_esi;
                kredu=total;
        }

        asm{
                fild dword ptr [total]
                fstp real8 ptr [ebp100]
                fld real8 ptr [ebp100]
                fdiv real8 ptr [constant1]
                fistp dword ptr [esp]
                wait
                pop eax
                sub esp, 4
                mov [totalz], eax
        }

        numberz=ceil(totalz);

        asm{
                mov eax, [numberz]
                cdq
                mov ecx, 0Ah
                idiv ecx
                mov eax, [total]
                imul edx, edx, 3E8h
                add edx, eax
                mov [total], edx
        }

        printf("Registration Number: %lu\n",total);
        printf("\nNOTE: Enter the word ' -doh! ' in front of Registration Key in the HtmlSS Registration Box to enable a button for after enter the Registration Number.\n");
	printf("\nEnJoY aNoThEr qUaLiTy kEyGeN fRoM The Nameless Ones '2000.\n");
        getch();
}
