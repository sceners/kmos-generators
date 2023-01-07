/*
 *
 * bY Kmos in 2000
 *
*/

#include <windows.h>
#include "tplate2.h"
#include <stdio.h>
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

unsigned char myname[]="Kmos tNO '2K";
unsigned char myname_[]="Kmos [tNO '2000]";
unsigned char prog_name[200]="CyberInfo E-mail Notify";
unsigned char date[20]="";
unsigned char about_box_caption[]="The Nameless Ones '2000";
unsigned char first_title[]="User Name";
unsigned char second_title[]="Key Code";
unsigned char third_title[]="Password";
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
   HWND hwndName, hwndComp, hwndCode;

   unsigned char name[100]={0}, table[10]="cIeChEcK4", table1[7]="abdfef", table2[7]="fhfhfh", strtotal[100]={0}, strtotal1[100]={0}, xiba[100]={0}, code_string[100]={0}, code_string1[100]={0};
   int i=0, length=0, length1=0, length2=0, flag=0, len_name=0;
   unsigned long int ecx=0, eax=1, esi=0, total=0, total1=0, total2=0;

   // Get user name from input box
   hwndName=GetDlgItem(hDlg,IDC_NAMEEDIT);
   SendMessage(hwndName,EM_SETLIMITTEXT,sizeof(name),0);
   // ^ max length of name that user can type into edit box - sizeof(name)
   //   means the number of char in the array name[] u have declared
   GetWindowText(hwndName,name,sizeof(name));
   hwndCode=GetDlgItem(hDlg,IDC_CODEEDIT);
   hwndComp=GetDlgItem(hDlg,IDC_COMPEDIT);

   flag=blacklist_check(name,hwndCode);

   if (flag!=0)
   {
      return;
   }
   len_name=strlen(name);

   if (len_name<1)
   {
      SetWindowText(hwndComp,"Enter your Name...");
      SetWindowText(hwndCode,"Enter your Name...");
      return;
   }

   if (len_name>12)
   {
      SetWindowText(hwndComp,"Your Name is too long (the program was a limit of 12 chars)...");
      SetWindowText(hwndCode,"Your Name is too long (the program was a limit of 12 chars)...");
      return;
   }

	strcat(name,table);
	length=strlen(name);

        for (eax=1,i=0;i<length;i++,eax++)
	{
		ecx=name[i];
		ecx=ecx * eax;
		ecx=ecx * 2 + ecx;
		total=total + ecx;
	}

	total+=0xE86;

	ultoa(total,strtotal,10);

	strcat(strtotal,table1);
	length1=strlen(strtotal);

        for (eax=1,i=0;i<length1;i++,eax++)
	{
		ecx=strtotal[i];
		ecx=ecx * eax;
		esi=ecx;
		ecx=ecx << 5;
		ecx=ecx + esi;
		total1=total1 + ecx;
	}

	total1+=0x130D707;

	ultoa(total,strtotal1,10);

	strcpy(xiba, table2);
	strncat(xiba, strtotal1, 7);

	length2=strlen(xiba);

        for (eax=1,i=0;i<length2;i++,eax++)
	{
		ecx=xiba[i];
		ecx=ecx * eax;
		ecx=ecx * 0x17;
		total2=total2 + ecx;
	}

	total2+=0x5E30FC5;

   sprintf(code_string,"%lu%lu",total1,total2);
   SetWindowText(hwndCode,code_string);

   sprintf(code_string1,"%lu",total);
   SetWindowText(hwndComp,code_string1);
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
            "TNO DISCLAIMER",MB_OK + MB_ICONQUESTION);

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
         strcat(prog_name," ");
         strcat(prog_name,version_buffer);
         strcat(prog_name," *KeyGen*");

         strcat(date,date_buffer);

         SetWindowText(GetDlgItem(hDlg,IDC_GREYNAME),myname_);
         SetWindowText(GetDlgItem(hDlg,IDC_GREYDATE),date);
         SetWindowText(GetDlgItem(hDlg,IDC_GROUPBOX1),first_title);
         SetWindowText(GetDlgItem(hDlg,IDC_GROUPBOX2),second_title);
         SetWindowText(GetDlgItem(hDlg,IDC_GROUPBOX3),third_title);         
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
