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
char prog_name[200]="DialUp Trafficator";
char date[11]="";
char about_box_caption[]="About...";
char first_title[]="User Name";
char second_title[]="Company";
char third_title[]="Serial Number";
char about_box_text[500]={0};
char good_marker_buffer[]={0xe1,0xd7,0xc9,0xc6,0xa3};
char version_buffer[30],date_buffer[11],marker_buffer[5];

HINSTANCE hInstance2;
/*
 *
 * The KeyGen routine
 *
 */

void GenerateCode(HWND hDlg)
{
   HWND hwndName, hwndCode, hwndComp;
 
   static unsigned char table[86]="A33255FE87B98CAEKJH98798JHGJKHG346523645KJHKJKJHBN9823A098E09723F78632B9080C90809A098", addon[18]="DialUp Controller";
   unsigned char name[150]={0}, company[150]={0}, code[100]={0}, code_table[500]={0}, total1[100]={0}, code_string[500]={0};
   int i=0, length=0, tot_one=0, tot_two=0, tot_three=0, len_table=0, loop_len=0, len_name=0, len_comp=0;
   unsigned long int ecx=0, csum=0, len=0, total;
   double x0045aff8=1.86496648542432e-307L, foo=0;

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
        SetWindowText(hwndCode,"Enter your User Name...");
        return;
   }

   if (len_comp > 0)
   {
        strcat(name,company);
   }

   strcat(name,addon);
   length=strlen(name);

	for (i=0;i<length;i++)
	{
		ecx=name[i] & 0xFF;
		csum+=ecx;
	}

	asm{
		fild dword ptr [csum]
		fmul real4 ptr [x0045aff8]
                fstp real8 ptr [foo]
	}

        len=floor(foo);

        asm{
                mov esi, [csum]
                xor ecx, ecx
                mov ecx, [len]
                neg ecx
                shl ecx, 02h
                sub ecx, eax
                lea eax, [esi+ecx]
                lea eax, [ecx*4+eax]
                mov [len_table], eax

                // second letter
                xor ebx, ebx
                cmp eax, 0fh
                setle bl
                dec ebx
                and ebx, -14h
                add ebx, 0ah
                mov [tot_three], ebx
        }

        // first letter
        tot_two=len_table + 0x41;
        sprintf(code,"%c",tot_two);
        strcat(code_table,code);

        loop_len=tot_three + len_table;

        tot_three=(tot_three + len_table) + 0x41;
        sprintf(code,"%c",tot_three);
        strcat(code_table,code);

        for (i=0;i<loop_len;i++,len_table++)
        {
                ecx=table[len_table];
                sprintf(code,"%c",ecx);
                strcat(code_table,code);
        }

        for (i=0;i<length;i++)
        {
                ecx=name[i];
                sprintf(code,"%02X",ecx);
                strcat(code_table,code);
        }

        for (i=0;i<loop_len;i++,len_table++)
        {
                ecx=table[len_table] & 0xFF;
                sprintf(code,"%c",ecx);
                strcat(code_table,code);
        }

        length=strlen(code_table);

        asm{
                xor ecx, ecx
                xor ebx, ebx
                mov edx, [length]
        j1:
                movsx eax, byte ptr [code_table+ecx]
                imul eax, ecx
                inc ecx
                lea eax, [eax*4+eax]
                lea edi, [ebx+eax]
                lea ebx, [eax*4+edi]
                cmp ecx, edx
                jl j1

                mov [total], ebx

                mov esi, 1h
        j2:
                mov eax, ebx
                cdq
                idiv esi
                mov ecx, eax
                mov eax, 66666667h
                imul ecx
                sar edx, 02h
                mov eax, edx
                shr eax, 1fh
                add edx, eax
                mov eax, edx
                mov dl, 0ah
                imul dl
                sub cl, al
                add cl, 30h
                mov [total1+esi], cl
                inc esi
                cmp esi, 09h
                jl j2
        }

   sprintf(code_string,"DCU20-%lu-%c%c%c%c%c%c%c%c",total,total1[1],total1[2],total1[3],total1[4],total1[5],total1[6],total1[7],total1[8],total1[9]);
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
