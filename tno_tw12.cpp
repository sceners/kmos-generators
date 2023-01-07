/*
 *
 * bY Kmos in 2000
 *
*/

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "new2.h"

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
char mycomp[]="The Nameless Ones '2000";
char prog_name[200]="TextWiz";
char date[11]="";
char about_box_caption[]="About...";
char first_title[]="First Name";
char second_title[]="Last Name";
char third_title[]="Registration #";
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
   HWND hwndName, hwndCode, hwndComp;

   unsigned char name[100]={0}, company[100]={0}, code_string[150]={0};
   int i=0, len_name=0, len_comp=0;
   unsigned long int ebp0110=0, ebp0110_=0, total=0;
   double ebp08=0, ebp0118=0, ebp18=0, ebp04=0, ebp0118_=0, ebp18_=0, ebp04_=0, x004020c0=-1, x004020b8=9, x004020b0=10, xnumber=1000000000, x004020a8=1005229475, xibu=0, constant=1.50489372, foo=0;

   // Get user name from input box

   hwndName=GetDlgItem(hDlg,IDC_NAMEEDIT);
   GetWindowText(hwndName,name,sizeof(name));
   hwndComp=GetDlgItem(hDlg,IDC_COMPEDIT);
   GetWindowText(hwndComp,company,sizeof(company));

   hwndCode=GetDlgItem(hDlg,IDC_CODEEDIT);

   len_name=strlen(name);
   len_comp=strlen(company);

   if (len_name < 1)
   {
        SetWindowText(hwndCode,"Enter your First Name...");
        return;
   }

   if (len_comp < 1)
   {
        SetWindowText(hwndCode,"Enter your Last Name...");
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
                fld real8 ptr [ebp18_]
                fadd real8 ptr [constant]
                fadd real8 ptr [ebp18]
                fmul real8 ptr [xnumber]

                fstp real8 ptr [foo]
        }

        foo=ceil(foo);

   sprintf(code_string,"%.0lf",foo);
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

         MessageBox(hDlg,
            "Hi! If the registration #, don't work for your\r\n"
            "name, please read TNO.nfo included with the keygen!\r\n\r\n"
            "bY Kmos [tNO '2000]",
            "KeyGen Help...",MB_OK + MB_ICONINFORMATION);

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
         SetWindowText(GetDlgItem(hDlg,IDC_GROUPBOX3),third_title);
         SetWindowText(hDlg,prog_name);

         SetWindowText(GetDlgItem(hDlg,IDC_NAMEEDIT),myname);
         SetWindowText(GetDlgItem(hDlg,IDC_COMPEDIT),mycomp);
         SendMessage(GetDlgItem(hDlg,IDC_NAMEEDIT),EM_SETSEL,0,-1);
         SetFocus(GetDlgItem(hDlg,IDC_NAMEEDIT));
         GenerateCode(hDlg);
         break;

      case WM_CLOSE:
         EndDialog(hDlg,1);
         return 1;

      case WM_COMMAND:
         switch(CTRLID){

            case IDC_COMPEDIT:
            case IDC_NAMEEDIT:
               // User makes a change to the name edit box
               if (CTRLMSG==EN_UPDATE){
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
