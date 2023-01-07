/*
 *
 * bY Kmos in 2000
 *
*/

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "kmos.h"
#include "blackgui.h"

#define CTRLMSG HIWORD(wParam)
#define CTRLID  LOWORD(wParam)

/*
 *
 * Prototypes
 *
 */

void GenerateCode(HWND);
BOOL CALLBACK KeygenDialogProcedure(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK AboutDialogProcedure(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);

/*
 * Global declarations
 */

char myname[]="Kmos tNO 2000";
char myname_[]="Kmos [tNO '2000]";
char prog_name[200]="32bit Fax";
char date[11]="";
char about_box_caption[]="The Nameless Ones '2000";
char first_title[]="User Name or Company Name";
char second_title[]="Registration Code";
char tno_website[]="http:\\\\www.page.com\\";
char about_box_text[500]={0};
char good_marker_buffer[]={0xe1,0xd7,0xc9,0xc6,0xa3};
char version_buffer[30],date_buffer[11],marker_buffer[5];

HINSTANCE hInstance2;

/*
 *
 * The KeyGen routine
 *
 */

div_t x;

void GenerateCode(HWND hDlg){
   HWND hwndName, hwndCode;

   unsigned char name[100]={0}, strlcs[100]={0}, tno[10]="32bit Fax", bah[100]={0}, codez[100]={0}, xiba[100]={0}, serial[100]={0}, code_string[100]={0}, licenses[1000]={0};
   unsigned char table[97]="071519420606107804171080102919400715194206061078041710801029194007151942060610780417108010291940";
   int i=0, length=0, lenbah=0, lencdz=0, cl=0, al=0, flag=0;
   long int ebx=0, eax=0, edx=0, ecx=0, lcs=0, ebp4=0, zzz=0, esi=0, n1=0;

   // Get user name from input box
   hwndName=GetDlgItem(hDlg,IDC_NAMEEDIT);
   SendMessage(hwndName,EM_SETLIMITTEXT,sizeof(name),0);

   //
   // ^ max length of name that user can type into edit box - sizeof(name)
   //   means the number of char in the array name[] u have declared
   //
   GetWindowText(hwndName,name,sizeof(name));
   hwndCode=GetDlgItem(hDlg,IDC_CODEEDIT);

   flag=blacklist_check(name,hwndCode);
   if(flag!=0){
      return;
   }
   //...
   length=strlen(name);
   //...
   if(length<3){
      SetWindowText(hwndCode,"Enter your Name...");
      return;
   }

   GetWindowText(GetDlgItem(hDlg,IDC_WRITERSEDIT),licenses,sizeof(licenses)-1);
   lcs=atol(licenses);

   if ((lcs<2) || (lcs>1000))
   {
        SetWindowText(hwndCode,"Invalid number of Licenses...");
        return;
   }

	strlwr(name);

	lcs=lcs * 0x41;
	lcs=lcs + 0x11776;

	ltoa(lcs, strlcs, 10);
	strcpy(bah,name);
	strcat(bah,strlcs);
	strcat(bah,tno);

	lenbah=strlen(bah);

	eax=name[0];
	ebx=name[1];
	eax=eax + ebx;
	ecx=name[2];
	eax=eax + ecx;

	x=div(eax,3);
	cl=x.quot;

	if ((cl < 0x30) || (cl > 0x39))
	{
		if ((cl < 0x61) || (cl > 0x7A))
		{
			if (cl < 0x30)
			{
				goto x1;
			}
			if (cl <= 0x7A)
			{
				cl=cl - 0x39;
				goto x1;
			}
			else
			{
				cl=cl - 0x7A;
				goto x1;
			}
		}
		cl=cl - 0x61;
		goto x1;
	}
	else
	{
		cl=cl - 0x30;
	}

	x1:

	eax=cl;
	eax=eax - 1;
	edx=0;
	cl=eax + 1;
	eax=name[0];
	eax=eax * cl;
	x=div(eax,3);
	esi=x.quot;
	eax=cl * 2 + cl;
	x=div(eax,cl);
	eax=x.quot;
	esi=((esi * eax) + cl);

	n1=esi;

	asm{
		mov eax, n1
                mov dl, al
                mov bx, 0001
                lea edi, [name]
                add al, [edi+ebx]
                mov cx, ax
                mov edi, 1
                mov ah, [edi+table]
                or al, ah
                ror ax, cl
                and ax, 00FFh
                mov [ebp4], eax
	}

	for (i=0;i<lenbah;i++)
	{
		zzz=bah[i];
		ecx=zzz * 0x13;
		edx=ebp4;
		edx=edx + ecx;
		ebp4=edx;
		eax=ebp4;
		eax=eax + i;
		ebp4=eax;
		ecx=i;
		edx=0;

		if (bah[i] >= 0x60)
		{
			goto xiba;
		}

		eax=ebp4;
		eax=eax + 0x15;
		ebp4=eax;
		goto endz;
	xiba:
		ecx=ebp4;
		ecx=ecx - 0x15;
		ebp4=ecx;
	endz:
	}

	sprintf(codez,"%06lu",ebp4);

	lencdz=strlen(codez);

	for (i=0;i<lencdz;i++)
	{
		edx=codez[i];
		edx=edx + i;
		sprintf(xiba,"%02X",edx);
		strcat(serial, xiba);
	}

   sprintf(code_string,"%s",serial);
   SetWindowText(hwndCode,code_string);
}

BOOL CALLBACK KeygenDialogProcedure(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam){

   HMODULE kg_exe_handle;
   FILE *fp;
   char exe_filename[250];
   int i,flag;

   switch(uMsg){

      case WM_SHOWWINDOW:
         /* StartUp Procedure */

         MessageBox(hDlg,

            "The distribution of any serial created\r\n"
            "with this keygen, except the one shown by\r\n"
            "default on startup, is strictly prohibited.\r\n\r\n"

            "This includes the distribution by scene\r\n"
            "groups in their releases, public cracks\r\n"
            "distribution channels, cracks websites, and\r\n"
            "any other form of distribution medium.\r\n\r\n"
      
            "Any individual, group, or otherwise, found\r\n"
            "to be ignoring this disclaimer will be\r\n"
            "publicly exposed.\r\n\r\n"

            "As decreed by the TNO Council.",
            "TNO DISCLAIMER",MB_OK + MB_ICONEXCLAMATION);

         /* retrieve version nfo from end of file */
         kg_exe_handle=GetModuleHandle(NULL);
         GetModuleFileName(kg_exe_handle,exe_filename,200);
         if((fp=fopen(exe_filename,"rb"))==NULL){
            MessageBox(hDlg,"You should never be seeing this!","FUCK!",MB_OK);
         }

         fseek(fp,-46,SEEK_END);
         fread(marker_buffer,5,1,fp);

         for(i=0,flag=0;i<5;i++){
            if(marker_buffer[i]!=good_marker_buffer[i]){
               flag=-1;
               break;
            }
         }
         if(flag==-1){
            SetWindowText(GetDlgItem(hDlg,IDC_VERSION),"WARNING: No version info detected!");
            version_buffer[0]=0;
         }
         else{
            fseek(fp,-41,SEEK_END);
            fread(version_buffer,30,1,fp);
            for(i=0;i<30;i++){
               version_buffer[i]-=7;
               version_buffer[i]^=0x98;
            }
		    fseek(fp,-11,SEEK_END);
            fread(date_buffer,11,1,fp);
            for(i=0;i<11;i++){
               date_buffer[i]-=7;
               date_buffer[i]^=0x98;
            }
         }
		 fclose(fp);
         strcat(prog_name," ");
         strcat(prog_name,version_buffer);
         strcat(prog_name," *KeyGen*");

         strcat(date,date_buffer);
         strcat(date,"");

         SetWindowText(GetDlgItem(hDlg,IDC_GREYNAME),myname_);
         SetWindowText(GetDlgItem(hDlg,IDC_GREYDATE),date);
         SetWindowText(GetDlgItem(hDlg,IDC_GROUPBOX1),first_title);
         SetWindowText(GetDlgItem(hDlg,IDC_GROUPBOX2),second_title);
         SetWindowText(hDlg,prog_name);

         SetWindowText(GetDlgItem(hDlg,IDC_NAMEEDIT),myname);
         SendMessage(GetDlgItem(hDlg,IDC_NAMEEDIT),EM_SETSEL,0,-1);
         SetWindowText(GetDlgItem(hDlg,IDC_WRITERSEDIT),"1000");
         SetFocus(GetDlgItem(hDlg,IDC_NAMEEDIT));
         GenerateCode(hDlg);
         break;

      case WM_CLOSE:
         EndDialog(hDlg,1);
         return 1;

      case WM_COMMAND:
         switch(CTRLID){

            case IDC_NAMEEDIT:
            case IDC_WRITERSEDIT:
               if(CTRLMSG==EN_UPDATE) {
                  GenerateCode(hDlg);
                  break;
               }
               break;

            case IDC_EXIT:
               // Terminate dialog process
               EndDialog(hDlg, TRUE);
               break;

            case IDC_ABOUT:
               // User pressed About button
               EnableWindow(hDlg,FALSE);
               DialogBox(hInstance2,MAKEINTRESOURCE(IDD_ABOUTDIALOG),NULL,(DLGPROC)AboutDialogProcedure);
               EnableWindow(hDlg,TRUE);
               SetActiveWindow(hDlg);
               SendMessage(GetDlgItem(hDlg,IDC_NAMEEDIT),EM_SETSEL,0,-1);
               SetFocus(GetDlgItem(hDlg,IDC_NAMEEDIT));
               break;

            case IDC_BANNER:

               ShellExecute(hDlg,"open",tno_website,0,0,0);
               break;
         }
      break;

      default:
         return FALSE; // We handle it
   }
   return TRUE; // Let Windows handle it
}

BOOL CALLBACK AboutDialogProcedure(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam){
   switch(uMsg){

      case WM_SHOWWINDOW:
         /* StartUp Procedure */

         SetFocus(GetDlgItem(hDlg,IDC_BUTTON1));

         strcpy(about_box_text,"ANOTHeR FiNE *KeyGen* fRoM tNO...\r\n\r\n");
         strcat(about_box_text,prog_name);
         strcat(about_box_text,"\r\n");
         strcat(about_box_text,"Keygenned by ");
         strcat(about_box_text,myname_);
         strcat(about_box_text,"\r\n");
         strcat(about_box_text,date);
         strcat(about_box_text,"\r\n\r\n");
         strcat(about_box_text,"The Nameless Ones '2000\r\n");
         strcat(about_box_text,"http://www.page.com/\r\n");
         strcat(about_box_text,"#CensuredChannel, EFnet");
         SetWindowText(GetDlgItem(hDlg,IDC_ABOUTTEXT),about_box_text);
         SetWindowText(hDlg,about_box_caption);
         break;

      case WM_CLOSE:
         EndDialog(hDlg,1);
         return 1;

      case WM_COMMAND:
         switch(CTRLID){
            case IDC_ABOUTOK:
               EndDialog(hDlg,1);
               return 1;
            }
         break;

      default:
         return FALSE; // We handle it
   }
   return TRUE; // Let Windows handle it
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow){
   // Application starts here
   hInstance2=hInstance;
   DialogBox(hInstance,MAKEINTRESOURCE(IDD_KEYGENDIALOG),NULL,(DLGPROC)KeygenDialogProcedure);
   return FALSE;
}
