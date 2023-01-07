/*
 *
 * bY Kmos in 2000
 *
*/

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "tplate1.h"
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

char myname[]="Kmos [tNO '2000]";
char prog_name[200]="File Tool";
char date[11]="";
char about_box_caption[]="The Nameless Ones '2000";
char first_title[]="Name";
char second_title[]="Serial No";
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

   unsigned char name[85]={0}, namez[85]={0}, *xiba="FILETOOL.EXE", code_string[50]={0};
   int i=0, length=0, length1=0, flag=0;
   long int code1=0, code2=0;

   // Get user name from input box
   hwndName=GetDlgItem(hDlg,IDC_NAMEEDIT);
   SendMessage(hwndName,EM_SETLIMITTEXT,sizeof(name),0);

   //
   // ^ max length of name that user can type into edit box - sizeof(name)
   //   means the number of char in the array name[] u have declared
   //
   GetWindowText(hwndName,name,sizeof(name));
   hwndCode=GetDlgItem(hDlg,IDC_CODEEDIT);
   //...
   flag=blacklist_check(name,hwndCode);
   if(flag!=0){
      return;
   }
   //...
   length1=strlen(name);
   //...
   if(length1<1){
      SetWindowText(hwndCode,"Enter your Name...");
      return;
   }
   else
   { 
   // Start of KeyGeneration...

	strupr(name);
        strcat(name, xiba);


	length=strlen(name);

        asm{
                lea edi, name
                xor ebx, ebx
        }

	for (i=0;i<length;i++)
	{
		asm{
                        mov dl, byte ptr [edi]
                        and edx, 0FFh
                        add ebx, edx
                        inc edi
		}
	}

        asm{
                cmp ebx, 64h
                jge j2
                add ebx, 64h
        j2:
                mov eax, ebx
                mov ecx, 0Ah
                cdq
                idiv ecx
                mov eax, edx

                cmp eax, 01h
                jnz j3
                add ebx, 07h
                jmp jlast
        j3:
                cmp eax, 02h
                jnz j4
                sub ebx, 0Bh
                jmp jlast
        j4:
                cmp eax, 03h
                jnz j5
                add ebx, 13h
                jmp jlast
        j5:
                cmp eax, 04h
                jnz j6
                sub ebx, 1Ch
                jmp jlast
        j6:
                cmp eax, 05h
                jnz j7
                add ebx, 18h
                jmp jlast
        j7:
                cmp eax, 06h
                jnz j8
                sub ebx, 03h
                jmp jlast
        j8:
                cmp eax, 07h
                jnz j9
                add ebx, 2Ch
                jmp jlast
        j9:
                cmp eax, 08h
                jnz j10
                sub ebx, 43h
                jmp jlast
        j10:
                cmp eax, 09h
                jnz j11
                add ebx, 15h
                jmp jlast
        j11:
                add ebx, 23h
        jlast:
                mov eax, length
                cmp eax, 02h
                jle jlast1
                lea eax, name
                movzx eax, byte ptr [eax]
                add ebx, eax
                lea eax, name
                movzx eax, byte ptr [eax+01]
                add ebx, eax
                mov eax, length
                lea edx, name
                movzx eax, byte ptr [eax+edx-01]
                add ebx, eax
                mov eax, length
                lea edx, name
                movzx eax, byte ptr [eax+edx-02]
                add ebx, eax
        jlast1:
                mov eax, length
                cmp eax, 04h
                jle jlast2
                lea eax, name
                movzx eax, byte ptr [eax+02]
                sub ebx, eax
                lea eax, name
                movzx eax, byte ptr [eax+03]
                sub ebx, eax
        jlast2:
                mov eax, ebx
                and eax, 80000007h
                jns jend
                dec eax
                or eax, 0FFFFFFF8h
                inc eax
        jend:
                cmp eax, 01h
                jnz jend1
                add ebx, 02h
                jmp jkms
        jend1:
                cmp eax, 02h
                jnz @j1
                add ebx, 05h
                jmp jkms
        @j1:
                cmp eax, 03h
                jnz @j2
                sub ebx, 0Fh
                jmp jkms
        @j2:
                cmp eax, 04h
                jnz @j3
                inc ebx
                jmp jkms
        @j3:
                cmp eax, 05h
                jnz @j4
                sub ebx, 0dh
                jmp jkms
        @j4:
                cmp eax, 06h
                jnz @j5
                add ebx, 0dh
                jmp jkms
        @j5:
                cmp eax, 07h
                jnz jjj
                add ebx, 07h
                jmp jkms
        jjj:
                sub ebx, 03h
        jkms:
                mov [code2], ebx
        }




//-------------------------------------------------------------------------//



        strcpy(namez, xiba);
        strncat(namez, name, length+12);


        asm{
                lea edi, namez
                xor ebx, ebx
        }

	for (i=0;i<length;i++)
	{
		asm{
                        mov dl, byte ptr [edi]
                        and edx, 0FFh
                        add ebx, edx
                        inc edi
		}
	}

        asm{
                cmp ebx, 64h
                jge _j2
                add ebx, 64h
        _j2:
                mov eax, ebx
                mov ecx, 0Ah
                cdq
                idiv ecx
                mov eax, edx

                cmp eax, 01h
                jnz _j3
                add ebx, 07h
                jmp _jlast
        _j3:
                cmp eax, 02h
                jnz _j4
                sub ebx, 0Bh
                jmp _jlast
        _j4:
                cmp eax, 03h
                jnz _j5
                add ebx, 13h
                jmp _jlast
        _j5:
                cmp eax, 04h
                jnz _j6
                sub ebx, 1Ch
                jmp _jlast
        _j6:
                cmp eax, 05h
                jnz _j7
                add ebx, 18h
                jmp _jlast
        _j7:
                cmp eax, 06h
                jnz _j8
                sub ebx, 03h
                jmp _jlast
        _j8:
                cmp eax, 07h
                jnz _j9
                add ebx, 2Ch
                jmp _jlast
        _j9:
                cmp eax, 08h
                jnz _j10
                sub ebx, 43h
                jmp _jlast
        _j10:
                cmp eax, 09h
                jnz _j11
                add ebx, 15h
                jmp _jlast
        _j11:
                add ebx, 23h
        _jlast:
                mov eax, length
                cmp eax, 02h
                jle _jlast1
                lea eax, namez
                movzx eax, byte ptr [eax]
                add ebx, eax
                lea eax, namez
                movzx eax, byte ptr [eax+01]
                add ebx, eax
                mov eax, length
                lea edx, namez
                movzx eax, byte ptr [eax+edx-01]
                add ebx, eax
                mov eax, length
                lea edx, namez
                movzx eax, byte ptr [eax+edx-02]
                add ebx, eax
        _jlast1:
                mov eax, length
                cmp eax, 04h
                jle _jlast2
                lea eax, namez
                movzx eax, byte ptr [eax+02]
                sub ebx, eax
                lea eax, namez
                movzx eax, byte ptr [eax+03]
                sub ebx, eax
        _jlast2:
                mov eax, ebx
                and eax, 80000007h
                jns _jend
                dec eax
                or eax, 0FFFFFFF8h
                inc eax
        _jend:
                cmp eax, 01h
                jnz _jend1
                add ebx, 02h
                jmp _jkms
        _jend1:
                cmp eax, 02h
                jnz _@j1
                add ebx, 05h
                jmp _jkms
        _@j1:
                cmp eax, 03h
                jnz _@j2
                sub ebx, 0Fh
                jmp _jkms
        _@j2:
                cmp eax, 04h
                jnz _@j3
                inc ebx
                jmp _jkms
        _@j3:
                cmp eax, 05h
                jnz _@j4
                sub ebx, 0dh
                jmp _jkms
        _@j4:
                cmp eax, 06h
                jnz _@j5
                add ebx, 0dh
                jmp _jkms
        _@j5:
                cmp eax, 07h
                jnz _jjj
                add ebx, 07h
                jmp _jkms
        _jjj:
                sub ebx, 03h
        _jkms:
                mov [code1], ebx
        }

   sprintf(code_string,"%lX-%lX",code1, code2);
   SetWindowText(hwndCode,code_string);
   }
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


         MessageBox(hDlg,
            "Hi! If my keygen don't work, i know why :)\r\n"
            "The name of executable program, must be\r\n"
            "FILETOOL.EXE, if it isn't equal, then my\r\n"
            "KeyGen don't work!\r\n"
            "                                               -Kmos",
            "iNFO",MB_OK);

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

         SetWindowText(GetDlgItem(hDlg,IDC_GREYNAME),myname);
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
         strcat(about_box_text,"Keygenned bY ");
         strcat(about_box_text,myname);
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
