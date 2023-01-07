/*
 *
 * bY Kmos in 2000
 *
*/

#include <windows.h>
#include "xiba.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

unsigned char myname[]="Kmos [tNO '2000]";
unsigned char prog_name[200]="WinControl 2000";
unsigned char date[20];
unsigned char about_box_caption[]="The Nameless Ones '2000";
unsigned char second_title[]="Code";
unsigned char tno_website[]="http:\\\\www.page.com\\";
unsigned char about_box_text[500]={0};
unsigned char good_marker_buffer[]={0xe1,0xd7,0xc9,0xc6,0xa3};
unsigned char version_buffer[30],marker_buffer[5],date_buffer[11];


HINSTANCE hInstance2;

/*
 *
 * The KeyGen routine
 *
 */

void GenerateCode(HWND hDlg){
   HWND hwndCode;

   char code[19]={0};
   int code1=0, code2=0, code3=0, code4=0, code5=0, code6=0, code7=0, code8=0, code9=0, code10=0, code11=0, code12=0, code13=0,
   code14=0, code15=0, code16=0, code17=0, code18=0;
   time_t t;
   long rand_seed;

   SYSTEMTIME SystemTime;

   hwndCode=GetDlgItem(hDlg,IDC_CODEEDIT);

   GetSystemTime(&SystemTime);
   rand_seed=SystemTime.wMilliseconds;
   rand_seed=rand_seed << 0x10;
   GetSystemTime(&SystemTime);
   rand_seed=rand_seed | SystemTime.wMilliseconds;
   rand_seed=rand_seed * rand() % 0x3344;
   srand(rand_seed);

   code1=rand() % 10;code2=rand() % 10;code3=rand() % 10;code4=rand() % 10;
   code5=rand() % 10;code6=rand() % 10;code7=rand() % 10;code8=rand() % 10;
   code9=rand() % 10;code10=rand() % 10;code11=rand() % 10;code12=rand() % 10;
   code13=rand() % 10;code14=rand() % 10;code15=rand() % 10; code16=rand() % 10;
   code17=rand() % 10;code18=rand() % 10;
   sprintf(code,"%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", code1, code2, code3, code4, code5, code6, code7, code8, code9, code10, code11, code12, code13, code14, code15, code16, code17, code18);
   SetWindowText(hwndCode,code);
}

BOOL CALLBACK KeygenDialogProcedure(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam){

   HMODULE kg_exe_handle;
   FILE *fp;
   unsigned char exe_filename[250];
   int i,flag;

   switch(uMsg){

      case WM_SHOWWINDOW:
         /* StartUp Procedure */

         MessageBox(hDlg,

            "The distribution of any serial created\r\n"
            "with this keygen is strictly prohibited.\r\n\r\n"

            "This includes the distribution by scene\r\n"
            "groups in their releases, public cracks\r\n"
            "distribution channels, cracks websites, and\r\n"
            "any other form of distribution medium.\r\n\r\n"
      
            "Any individual, group, or otherwise, found\r\n"
            "to be ignoring this disclaimer will be\r\n"
            "publicly exposed.\r\n\r\n"

            "As decreed by the TNO Council.",
            "TNO DISCLAIMER",MB_OK + MB_ICONQUESTION);


         MessageBox(hDlg,
            "Hi! I've only made a keygen for generate serials,\r\n"
            "because the program don't need the name & company!!!\r\n\r\n"
            "                                                         bY Kmos '2000\r\n",
            "iMPORTANT",MB_OK);


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
         strcat(prog_name," ");
         strcat(prog_name,version_buffer);
         strcat(prog_name," *KeyGen*");

         strcat(date,date_buffer);

         SetWindowText(GetDlgItem(hDlg,IDC_GREYNAME),myname);
         SetWindowText(GetDlgItem(hDlg,IDC_GREYDATE),date);
         SetWindowText(GetDlgItem(hDlg,IDC_GROUPBOX2),second_title);
         SetWindowText(hDlg,prog_name);

         SetFocus(GetDlgItem(hDlg,IDC_GENERATE));
         GenerateCode(hDlg);
         break;

      case WM_CLOSE:
         EndDialog(hDlg,1);
         return 1;

      case WM_COMMAND:
         switch(CTRLID){

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
               SetFocus(GetDlgItem(hDlg,IDC_GENERATE));
               break;

            case IDC_BANNER:
               ShellExecute(hDlg,"open",tno_website,0,0,0);
               break;

            case IDC_GENERATE:
               GenerateCode(hDlg);
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

         strcpy(about_box_text,"ANOTHeR FiNE *KeyGen* FRoM tNO...\r\n\r\n");
         strcat(about_box_text,prog_name);
         strcat(about_box_text,"\r\n");
         strcat(about_box_text,"Keygenned by ");
         strcat(about_box_text,myname);
         strcat(about_box_text,"\r\n");
         strcat(about_box_text,date);
         strcat(about_box_text,"\r\n\r\n");
         strcat(about_box_text,about_box_caption);
         strcat(about_box_text,"\r\nhttp://www.page.com/\r\n");
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
