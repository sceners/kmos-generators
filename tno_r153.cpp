/*
 *
 * bY Kmos in 2000
 *
*/

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "new.h"

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

char myname[]="Kmos [tNO '2000]";
char prog_name[200]="Resistor Selector";
char date[11]="";
char about_box_caption[]="About...";
char first_title[]="Name";
char second_title[]="Registration Code";
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
 
   unsigned char table[6]={0x27, 0x59, 0x28, 0xb1, 0x31, 0x7a};
   unsigned char name[100]={0}, xiba[50]={0}, code[50]={0}, code_string[50]={0};
   int i=0, length=0;

   // Get user name from input box
   hwndName=GetDlgItem(hDlg,IDC_NAMEEDIT);
   SendMessage(hwndName,10,sizeof(name),0);

   //
   // ^ max length of name that user can type into edit box - sizeof(name)
   //   means the number of char in the array name[] u have declared
   //
   GetWindowText(hwndName,name,sizeof(name));
   hwndCode=GetDlgItem(hDlg,IDC_CODEEDIT);

   length=strlen(name);

   if (length < 1)
   {
        SetWindowText(hwndCode,"Enter your Name...");
	return;
   }

        asm{
                xor ecx, ecx
                lea esi, [name]
                mov edi, [length]
                mov [xiba-01], 12h
        j1:
                mov eax, ecx
                push ecx
                cdq
                mov ecx, 05h
                idiv ecx
                mov al, [esi]
                pop ecx
                xor al, 12h
                inc ecx
                add [xiba+edx], al
                inc esi
                cmp edi, ecx
                jg j1

                lea esi, [xiba]
                lea eax, [table]
                xor ecx, ecx
        j2:
                mov dl, [eax]
                xor [esi], dl
                inc ecx
                inc esi
                inc eax
                cmp ecx, 05h
                jl j2
        }

        sprintf(code,"%02X%02X%02X%02X%02X%02X",xiba[-1],xiba[0],xiba[1],xiba[2],xiba[3],xiba[4]);

        for (i=0;i<3;i++)
        {
                code_string[i]=code[i];
        }

        code_string[3]='-';

        for (i=3;i<7;i++)
        {
                code_string[i+1]=code[i];
        }

        code_string[7]='-';

        for (i=7;i<11;i++)
        {
                code_string[i+1]=code[i-1];
        }

        code_string[11]='-';

        for (i=11;i<15;i++)
        {
                code_string[i+1]=code[i-2];
        }

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
         strcat(about_box_text,myname);
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
