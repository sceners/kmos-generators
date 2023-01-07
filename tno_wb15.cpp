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
char prog_name[200]="Platypus Web Builder";
char date[11]="";
char about_box_caption[]="About...";
char first_title[]="User Name";
char second_title[]="User ID";
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
 
   unsigned char name[100]={0}, code[10]={0};
   int length=0, len=0;
   unsigned long bleh=0, serial1=0, serial2=0, serial3=0, serial4=0, serial5=0, serial6=0, serial7=0, serial8=0;

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

   if (length < 4)
   {
        SetWindowText(hwndCode,"Enter your Name... (min 4)");
	return;
   }

        strcat(name,"WB16");
	length=strlen(name);
        len=length / 2;

        asm{
                lea esi, [name]
                mov edi, [length]
                xor ecx, ecx
                xor eax, eax
                xor ebx, ebx
        j1:
                movsx edx, byte ptr [esi+ecx]
                add eax, edx
                inc ecx
                cmp ecx, edi
                jl j1
                cdq
                idiv edi
                mov [bleh], eax
                mov ebx, eax
                mov [serial1], eax
                mov eax, edi
                cdq
                sub eax, edx
                sar eax, 1
                add eax, esi
                movsx eax, byte ptr [eax]
                add eax, ebx
                cdq
                sub eax, edx
                sar eax, 1
                mov [serial2], eax
                mov al, byte ptr [esi+edi-03]
                add edi, esi
                mov [serial3], eax
                movsx eax, byte ptr [esi+05]
                movsx ecx, byte ptr [esi+04]
                add eax, ecx
                push 03
                movsx ecx, byte ptr [esi+03]
                add eax, ecx
                pop ecx
                cdq
                idiv ecx
                mov ebx, eax
                add ebx, ecx
                mov al, bl
                add al, 20h
                mov [serial4], eax
                mov eax, [bleh]
                add eax, ebx
                cdq
                sub eax, edx
                sar eax, 1
                sub al, 1ch
                mov [serial5], eax
                mov al, byte ptr [edi-02]
                add al, 20h
                mov [serial6], eax
                mov ebx, [len]
                movsx eax, byte ptr [esi-ebx+02]
                add al, 03h
                mov [serial7], eax
                movsx eax, byte ptr [edi-01]
                movsx ecx, byte ptr [esi+02]
                add eax, ecx
                push 05
                movsx ecx, byte ptr [esi+01]
                add eax, ecx
                movsx ecx, byte ptr [edi-02]
                add eax, ecx
                movsx ecx, byte ptr [esi]
                add eax, ecx
                cdq
                pop ecx
                idiv ecx
                sub al, 03h
                mov [serial8], eax
        }

        sprintf(code,"%c%c%c%c%c%c%c%c",serial1,serial2,serial3,serial4,serial5,serial6,serial7,serial8);
        code[8]='\0';

        asm{
                xor ebx, ebx
        j2:
                lea eax, [code]
                mov al, byte ptr [eax+ebx]
                cmp al, 5bh
                jl x00416214
                cmp al, 60h
                jg x00416214
                sub al, 2ah
                jmp x00416222

        x00416214:
                cmp al, 41h
                jl x0041621C
                cmp al, 7ah
                jle x0041622C

        x0041621C:
                mov al, bl
                shl al, 1
                add al, 5dh

        x00416222:
                mov [code+ebx], al

        x0041622C:
                inc ebx
                cmp ebx, 8
                jl j2
        }

   SetWindowText(hwndCode,code);
}

BOOL CALLBACK KeygenDialogProcedure(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam){

   HMODULE kg_exe_handle;
   FILE *fp;
   char exe_filename[250];
   int i,flag;
   HKEY hKey;

   switch(uMsg){
      case WM_SHOWWINDOW:
         /* StartUp Procedure */

/*         if (RegOpenKeyEx(HKEY_LOCAL_MACHINE,"SOFTWARE\\NuMega\\SoftICE",0,KEY_ALL_ACCESS,&hKey)==ERROR_SUCCESS)
         {
                MessageBox(hDlg,
                "SoftICE detected in your system!",
                "WARNING...",MB_OK);
                RegCloseKey(hKey);
                exit(0);
         } */

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
