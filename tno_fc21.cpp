/* bY Kmos in 2000 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void main()
{
        unsigned char name[100]={0}, code[10]={0}, code_string[10]={0};
        int i=0, length=0;
        unsigned long xiba=0, total=0;
        double ebp18=0, ebp0c=0, number=2315;

        clrscr();
        printf("�������� � ��� � ������� � �����������Ŀ\n");
        printf("���۲���۲��۲��۲�   ܲ۲ ߲�۲���۲� �\n");
        printf("�  ߰ ��۲ ۰  ���߲� ��۲  ��۲ ��۲  �\n");
        printf("�    ���۲    ����  ����۲ ���۲ ��۲  �\n");
        printf("�   ܲ��۲�  ܲ��۲� ߲�۲ܲ��۲ܲ�۲� �\n");
        printf("���������������������� �߲ �������������\n");
        printf("\nKeyGenerator for FileCut v2.1");
        printf("\nWritten bY Kmos [tNO '2000].\n");
        printf("\nEnter your Registration name: ");
	gets(name);
	length=strlen(name);

        if (length < 4)
        {
                printf("\nERROR: Enter your Registration name... (min 4)\n");
                return;
        }

        asm{
                mov ebx, 1h
                mov esi, [length]
        j1:
                lea eax, [name]
                mov al, [ebx+eax-01]
                cmp al, 80h
                jae j2
                lea eax, [name]
                movzx eax, byte ptr [ebx+eax-01]
                imul eax
                mov [xiba], eax
                fild word ptr [xiba]
                fadd real8 ptr [ebp0c]
                fstp real8 ptr [ebp0c]
                wait
        j2:
                inc ebx
                dec esi
                jnz j1

                fld real8 ptr [ebp0c]
                fmul real8 ptr [number]
                fistp dword ptr [esp]
                wait
                pop eax
                sub esp, 4
                mov [total], eax
        }

        sprintf(code,"%lu",total);

        for (i=0;i<7;i++)
        {
                code_string[i]=code[i];
        }

        printf("Registration code: %s\n",code_string);
        getch();
}
