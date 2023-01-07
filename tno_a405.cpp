/*
 *
 * bY Kmos in 2000
 *
*/

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "new.h"
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

char myname[]="Kmos@tNO.com";
char myname_[]="Kmos [tNO '2000]";
char prog_name[200]="Auction Tamer";
char date[11]="";
char about_box_caption[]="About...";
char first_title[]="Your E-mail Address";
char second_title[]="Registration Key";
char about_box_text[500]={0};
char good_marker_buffer[]={0xe1,0xd7,0xc9,0xc6,0xa3};
char version_buffer[30],date_buffer[11],marker_buffer[5];

HINSTANCE hInstance2;
/*
 *
 * The KeyGen routine
 *
 */

void GenerateCode(HWND hDlg){
   HWND hwndName, hwndCode;
 
   unsigned char name[250]={0}, code[50]={0}, code_string[250]={0};
   int i=0, length=0, flag=0;
   unsigned long int ecx=0, eax=0, edx=0, totaledi=0, totalecx=0, totaledi2=0, edi=0;

   // Get user name from input box
   hwndName=GetDlgItem(hDlg,IDC_NAMEEDIT);
   SendMessage(hwndName,10,sizeof(name),0);

   //
   // ^ max length of name that user can type into edit box - sizeof(name)
   //   means the number of char in the array name[] u have declared
   //
   GetWindowText(hwndName,name,sizeof(name));
   hwndCode=GetDlgItem(hDlg,IDC_CODEEDIT);

   flag=blacklist_check(name,hwndCode);

   if (flag!=0)
   {
      return;
   }

   length=strlen(name);

   if (length < 5)
   {
        SetWindowText(hwndCode,"Enter your E-mail Address (min 5)...");
        return;
   }

   if(memchr(name,'.',strlen(name))==NULL || memchr(name,'@',strlen(name))==NULL)
   {
        SetWindowText(hwndCode,"E-mail Address must contain a '.' and an '@' ...");
        return;
   }

	strlwr(name);
	strcat(name,"AUCTIONSELLER");
	length=strlen(name);

        asm{
                mov ebx, length
                dec ebx
                mov edi, 64h
        xj:
                movzx ecx, byte ptr [ebx+name]
                sar cl, 1
                add edi, ecx
                cmp edi, 3e7h
                jb xj1
                mov ecx, edi
                mov eax, 55555556h
                imul ecx
                shr ecx, 1fh
                add edx, ecx
                mov edi, edx
        xj1:
                sub ebx, 02
                cmp ebx, -01h
                jz xjend
                cmp ebx, -02h
                jnz xj
        xjend:
                mov [totaledi], edi
        }

	edi=0;

        for (ecx=0xC8,i=0;i<=length-1;i++)
	{
		edi=name[i] & 0xFF;
		edi=edi * 2;
		ecx=ecx + edi;
		if (ecx < 0x3E7)
		{
			goto endz;
		}
		else
		{
			ecx=ecx / 2;
		}
	endz:
	}

        asm{
                mov edi, 64h
                mov ebx, [length]
                dec ebx
                xor esi, esi
        j1:
                movzx ecx, byte ptr [esi+name]
                mov eax, 55555556h
                imul ecx
                add edi, edx
                cmp edi, 3e7h
                jb j2
                mov eax, edi
                cwd
                and edx, 03h
                add eax, edx
                sar eax, 02h
                mov edi, eax
        j2:
                add esi, 02h
                cmp esi, ebx
                jbe j1

                mov [totaledi2], edi
	}

        sprintf(code,"%lu-%lu-%lu\n",totaledi,ecx,totaledi2);

        for (i=0;i<3;i++)
        {
                if (code[i]==0x30)
                {
                        code[i]=0x38;
                }
        }

        for (i=4;i<7;i++)
        {
                if (code[i]==0x30)
                {
                        code[i]=0x32;
                }
        }

        for (i=8;i<11;i++)
        {
                if (code[i]==0x30)
                {
                        code[i]=0x35;
                }
        }

   code[11]='\0';

   sprintf(code_string,"%s",code);
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
            "The distribution of any serial created with\r\n"
            "this keygen must has the cracker default name.\r\n\r\n"

            "This includes the distribution by scene\r\n"
            "groups in their releases, public cracks\r\n"
            "distribution channels, cracks websites, and\r\n"
            "any other form of distribution medium.\r\n\r\n"

            "Don't try to use my keygen for your releases\r\n"
            "because I know if the serial has created with\r\n"
            "my keygen. So don't be a lamer... \r\n\r\n"

            "Any individual, group, or otherwise, found\r\n"
            "to be ignoring this disclaimer will be\r\n"
            "publicly exposed.\r\n\r\n"

            "As decreed by the TNO Council.",
            "TNO DISCLAIMER",MB_OK + MB_ICONINFORMATION);

         /* retrieve version nfo from end of file */
         kg_exe_handle=GetModuleHandle(NULL);
         GetModuleFileName(kg_exe_handle,exe_filename,200);
         if((fp=fopen(exe_filename,"rb"))==NULL){
            MessageBox(hDlg,"You should never be seeing this!","FUCK OFF!",MB_OK);
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

         SetWindowText(GetDlgItem(hDlg,IDC_GREYDATE),date);
         SetWindowText(GetDlgItem(hDlg,IDC_GROUPBOX1),first_title);
         SetWindowText(GetDlgItem(hDlg,IDC_GROUPBOX2),second_title);
         SetWindowText(hDlg,prog_name);

         SetWindowText(GetDlgItem(hDlg,IDC_NAMEEDIT),myname);
         SendMessage(GetDlgItem(hDlg,IDC_NAMEEDIT),EM_SETSEL,0,-1);
         SetFocus(GetDlgItem(hDlg,IDC_NAMEEDIT));
         GenerateCode(hDlg);
         break;

      case WM_CLOSE:
         EndDialog(hDlg,1);
         return 1;

      case WM_COMMAND:
         switch(CTRLID){

            case IDC_NAMEEDIT:
               // User makes a change to the name edit box
               if(CTRLMSG==EN_UPDATE){
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

         strcpy(about_box_text,"AnOtHeR qUALiTy ReLeAsE fRoM The Nameless Ones...\r\n\r\n");
         strcat(about_box_text,prog_name);
         strcat(about_box_text,"\r\n");
         strcat(about_box_text,"Keygenned bY ");
         strcat(about_box_text,myname_);
         strcat(about_box_text,"\r\n");
         strcat(about_box_text,date);
         strcat(about_box_text,"\r\n\r\n");
         strcat(about_box_text,"Visit us at: #CensuredChannel (EFnet)\r\n");
         strcat(about_box_text,"TNO homepage will be available soon...");
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
