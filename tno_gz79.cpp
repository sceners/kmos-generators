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

char myname[]="";
char myname_[]="Kmos [tNO '2000]";
char prog_name[200]="GodeZip 2000";
char date[11]="";
char about_box_caption[]="The Nameless Ones '2000";
char first_title[]="License Number";
char second_title[]="Corresponding Code";
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

void GenerateCode(HWND hDlg){
   HWND hwndName, hwndCode;

   unsigned char code[15]={0}, license[15]={0}, codez[15]={0}, tno[15]={0}, code_string[15]={0}, code_stringz[15]={0};
   int i=0;
   unsigned long int xiba=0, rand_seed=0;
   time_t t;

   SYSTEMTIME SystemTime;

   hwndName=GetDlgItem(hDlg,IDC_NAMEEDIT);
   hwndCode=GetDlgItem(hDlg,IDC_CODEEDIT);

   GetSystemTime(&SystemTime);
   rand_seed=SystemTime.wMilliseconds;
   rand_seed=rand_seed << 0x10;
   GetSystemTime(&SystemTime);
   rand_seed=rand_seed | SystemTime.wMilliseconds;
   rand_seed=rand_seed * rand() % 0x3355;
   srand(rand_seed);

	for (i=0;i<14;i++)
	{
                xiba=rand()%10;
		sprintf(codez,"%lu",xiba);
		strcat(code,codez);
	}

	code[15]='\0';

	license[0]=code[5]+0x15;
	license[1]=code[2]+0x1F;
	license[2]=code[4]+0x13;
	license[3]=code[6]+0x1D;
	license[4]=code[1]+0x17;
	license[5]=code[0]+0x1E;
	license[6]=code[3]+0x11;
	license[7]=code[7]+0x1E;
	license[8]=code[12]+0x1C;
	license[9]=code[13]+0x18;
	license[10]=code[10]+0x15;
	license[11]=code[11]+0x16;
	license[12]=code[9]+0x1B;
	license[13]=code[8]+0x1D;

   sprintf(code_string,"G%s",code);
   SetWindowText(hwndName,code_string);

   sprintf(code_stringz,"D%s",license);
   SetWindowText(hwndCode,code_stringz);
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

         SetWindowText(GetDlgItem(hDlg,IDC_GREYNAME),myname_);
         SetWindowText(GetDlgItem(hDlg,IDC_GREYDATE),date);
         SetWindowText(GetDlgItem(hDlg,IDC_GROUPBOX1),first_title);
         SetWindowText(GetDlgItem(hDlg,IDC_GROUPBOX2),second_title);
         SetWindowText(hDlg,prog_name);

         GenerateCode(hDlg);
         break;

      case WM_CLOSE:
         EndDialog(hDlg,1);
         return 1;

      case WM_COMMAND:
         switch(CTRLID){

            case IDC_GENERATE:
               GenerateCode(hDlg);
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

         strcpy(about_box_text,"ANOTHeR FiNE *KeyGen* FRoM tNO...\r\n\r\n");
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
