/* bY Kmos in 2000 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void main()
{
        unsigned char name[150]={0}, totstr[100]={0}, totstrz[100]={0}, totstr1[100]={0}, totstr2[100]={0}, totstr3[100]={0}, totstr4[100]={0}, xxx[50]={0}, totstry[50]={0}, tot_n2str[50]={0}, yyy[50]={0};
        int i=0, length=0;
        unsigned long int total=0, ebp0168=0, tot_n1=137, tot_n2=137, total1=0, total1z=0, total2=0, total2z=0, total3=0, total3z=0, total4=0, total4z=0;
        double ebp0170=0, x00401008=3.1415, x00401010=3200, x004010F0=3.1415, x004010F8=1000, x00401038=3.1415, x00401040=2100, x004010B0=3.1415, x004010B8=160;

	tno:
	clrscr();
	printf("ÚÄÄÄÄÄÄÄ ° ÄÄÄ Ü ÄÄÄÄÄÄÄ ° ÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
	printf("şßÛÛ²ßÛÛÛ²ßÛÛ²ßÛÛ²Ü   Ü²Û² ß²ÛÛ²ßÛÛÛ²ß ³\n");
	printf("³  ß° ÛÛÛ² Û°  ÛÛÛß²Ü ÛÛÛ²  ÛÛÛ² ÛÛÛ²  ³\n");
	printf("³    °ÛÛÛ²    °ÛÛÛ  ÛÛÛÛÛ² °ÛÛÛ² ÛÛÛ²  ³\n");
	printf("³   Ü²ÛÛÛ²Ü  Ü²ÛÛÛ²Ü ß²ÛÛ²Ü²ÛÛÛ²Ü²ÛÛ²Ü ³\n");
	printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ ßß² ÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
        printf("\nKeyGenerator for John's Multimedia Suite v4.0");
	printf("\nWritten bY Kmos [tNO '2000]\n");
	printf("\nEnter your Name: ");
	gets(name);
	length=strlen(name);

        if (length<2)
	{
                printf("\nERROR: Enter your Name again (min 2)...");
		getch();
		goto tno;
	}

	asm{
                mov eax, [length]
                mov [ebp0168], eax
		fild dword ptr [ebp0168]
		fstp real8 ptr [ebp0170]
                fld real8 ptr [ebp0170]
                fmul real8 ptr [x00401008]
                fmul real8 ptr [x00401010]
		fistp real8 ptr [esp]
		wait
		pop eax
		mov [total], eax
	}

	itoa(total, totstr, 10);

        for (i=0;i<4;i++)
        {
                totstrz[i]=totstr[i];
        }

	tot_n1=tot_n1 - name[0]+1-1;
        tot_n2=tot_n2 - ((name[length-1]-0x20)+1-1);

        if (tot_n2 > 99)
        {
                itoa(tot_n2, tot_n2str, 10);
                sprintf(yyy,"%c%c",tot_n2str[1],tot_n2str[2]);
                tot_n2=atol(yyy);
        }
        
        total1=tot_n1;
        total1z=tot_n2;

        strcat(totstr1,totstrz);
	strcat(totstr,"");
        strcat(totstrz,"");
        strcat(yyy,"");
        strcat(tot_n2str,"");
	tot_n1=0;
	tot_n2=0;
	ebp0168=0;
	ebp0170=0;
	total=0;

        // Jc-Pic

	asm{
		mov eax, [length]
		mov [ebp0168], eax
		fild dword ptr [ebp0168]
		fstp real8 ptr [ebp0170]
		fld real8 ptr [ebp0170]
		fmul real8 ptr [x004010F0]
		fmul real8 ptr [x004010F8]
		fistp real8 ptr [esp]
		wait
		pop eax
		mov [total], eax
	}

	itoa(total, totstr, 10);

        for (i=0;i<4;i++)
        {
                totstrz[i]=totstr[i];
        }

        tot_n1=name[0]-1+1;
        tot_n2=tot_n2 - ((name[length-1]-0x20)+1-1);

        if (tot_n2 > 99)
        {
                itoa(tot_n2, tot_n2str, 10);
                sprintf(yyy,"%c%c",tot_n2str[1],tot_n2str[2]);
                tot_n2=atol(yyy);
        }

	total2=tot_n1;
	total2z=tot_n2;

        strcat(totstr2,totstrz);
	strcat(totstr,"");
        strcat(totstrz,"");
        strcat(yyy,"");
        strcat(tot_n2str,"");
        tot_n1=0xc8;
        tot_n2=0xc8;
	ebp0168=0;
	ebp0170=0;
	total=0;

        asm{
                mov eax, [length]
                mov [ebp0168], eax
                fild dword ptr [ebp0168]
                fstp real8 ptr [ebp0170]
                fld real8 ptr [ebp0170]
                fmul real8 ptr [x004010B0]
                fmul real8 ptr [x004010B8]
                fistp real8 ptr [esp]
                wait
                pop eax
                mov [total], eax
        }

        itoa(total, totstr, 10);

        for (i=0;i<4;i++)
        {
                totstrz[i]=totstr[i];
        }

        tot_n1=tot_n1 - (name[0]+1-1);
        tot_n2=tot_n2 - ((name[length-1]-0x20)+1-1);

        total3=tot_n1;
        total3z=tot_n2;

        strcat(totstr3,totstrz);
        itoa(total3z, totstrz, 10);
        totstrz[0]='\0';

        sprintf(xxx,"%c%c",totstrz[1],totstrz[2]);
        strcat(totstry,xxx);

        strcat(totstr,"");
        strcat(totstrz,"");
        strcat(yyy,"");
        strcat(tot_n2str,"");
        tot_n1=0x75;
        tot_n2=0x75;
	ebp0168=0;
	ebp0170=0;
	total=0;

        asm{
                mov eax, [length]
                mov [ebp0168], eax
                fild dword ptr [ebp0168]
                fstp real8 ptr [ebp0170]
                fld real8 ptr [ebp0170]
                fmul real8 ptr [x00401038]
                fmul real8 ptr [x00401040]
                fistp real8 ptr [esp]
                wait
                pop eax
                mov [total], eax
        }

        itoa(total, totstr, 10);

        for (i=0;i<4;i++)
        {
                totstrz[i]=totstr[i];
        }

        tot_n1=tot_n1 - name[0]+1-1;
        tot_n2=tot_n2 - ((name[length-1]-0x20)+1-1);

        if (tot_n2 > 99)
        {
                itoa(tot_n2, tot_n2str, 10);
                sprintf(yyy,"%c%c",tot_n2str[1],tot_n2str[2]);
                tot_n2=atol(yyy);
        }

        total4=tot_n1;
        total4z=tot_n2;
        strcat(totstr4,totstrz);

        printf("\nRegistration Numbers for:\n",total1,totstr1,total1z);
        printf("John's CD Player   : %lu%s%lu\n",total1,totstr1,total1z);
        printf("John's Jc-Pic      : %lu%s%lu\n",total2,totstr2,total2z);
        printf("John's Amortize    : %lu%s%s\n",total3,totstr3,xxx);
        printf("John's Midi Player : %lu%s%lu\n",total4,totstr4,total4z);
        printf("\n* EnJoY aNotHeR KeyGen bY The Nameless Ones '2000 *\n");
        getch();
}
