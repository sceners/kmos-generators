/* bY Kmos in 2000 */

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

void main()
{
        unsigned char name[100]={0}, codez[100]={0}, magicword[14]="GRAFX(9151910)", mb[13]={0}, mb2[6]={0}, pcode[100]={0};
	unsigned int magicnumber=0, temp=0;
        int i=0, len=0, len2=0, len_name=0, len_codez=0;

        clrscr();
        printf("ÚÄÄÄÄÄÄÄ ° ÄÄÄ Ü ÄÄÄÄÄÄÄ ° ÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
        printf("şßÛÛ²ßÛÛÛ²ßÛÛ²ßÛÛ²Ü   Ü²Û² ß²ÛÛ²ßÛÛÛ²ß ³\n");
        printf("³  ß° ÛÛÛ² Û°  ÛÛÛß²Ü ÛÛÛ²  ÛÛÛ² ÛÛÛ²  ³\n");
        printf("³    °ÛÛÛ²    °ÛÛÛ  ÛÛÛÛÛ² °ÛÛÛ² ÛÛÛ²  ³\n");
        printf("³   Ü²ÛÛÛ²Ü  Ü²ÛÛÛ²Ü ß²ÛÛ²Ü²ÛÛÛ²Ü²ÛÛ²Ü ³\n");
        printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ ßß² ÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
        printf("\nKeyGenerator for CDH GraFX Saver v2.1");
        printf("\nWritten bY Kmos [tNO '2000].\n");
        printf("\nEnter your Name: ");
        gets(name);
        printf("Enter your Personal Code: ");
        gets(codez);

        len_name=strlen(name);
        len_codez=strlen(codez);

        if (len_name < 1)
        {
                printf("\nERROR: Enter your Name...\n");
                return;
        }

        if (len_codez < 1)
        {
                printf("\nERROR: Enter your Personal Code...\n");
                return;
        }

        strcat(pcode,name);
        strcat(pcode,codez);

	len=strlen(pcode);
	len2=strlen(magicword);
	strupr(pcode);

	for (i=0;i<len2;i++) {
		magicnumber+=magicword[i];
	}

	mb[0]=(pcode[0] ^ (magicnumber >> 8));
	temp=(((magicnumber+mb[0])*0xad9c)+0x56ce);

	for(i=1;i<6;i++){
		mb[i]=(pcode[i] ^ (temp >> 8));
		temp=(((temp+mb[i])*0xad9c)+0x56ce);
	}

	asm{
                xor ebx, ebx
                xor edx, edx
        j1:
                mov al, [ebx+mb]
                shr al, 04h
                add al, 31h
                cmp al, 39h
                jbe j2
                add al, 07h
        j2:
                mov [edx+mb2], al
                inc edx
                mov al, [ebx+mb]
                and al, 0fh
                add al, 31h
                cmp al, 39h
                jbe j3
                add al, 07h
        j3:
                mov [edx+mb2], al
                inc edx
                inc ebx
                cmp ebx, 6
                jnz j1
	}

        printf("\nRegistration Code: %cA%c%cAC%c%c%c%c%c%c%c%c%c\n",mb2[0],mb2[1],mb2[2],mb2[3],mb2[4],mb2[5],mb2[6],mb2[7],mb2[8],mb2[9],mb2[10],mb2[11]);
        getch();
}
