#ifndef TUI_H
#define TUI_H 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define CleanScreen()  system("cls");SayHello();
#define InputClean() 	char ch;\
						while((ch=getchar())!='\n'){}


#define WANTTYPEERROR -1
#define WANTNULLERROR -2
#define WANTLONGERROR -3


#ifndef MENULOGGIN
#define MENULOGGIN 1
#endif
#ifndef MENUCHANGE
#define MENUCHANGE 2
#endif
#ifndef MENUREMOVE
#define MENUREMOVE 3
#endif
#ifndef MENULOG2S
#define MENULOG2S 4
#endif
#ifndef MENUQUERY
#define MENUQUERY 5
#endif
#ifndef MENUSTATIS
#define MENUSTATIS 6
#endif
#ifndef MENUHELP
#define MENUHELP 7
#endif
#ifndef MENUEXIT
#define MENUEXIT 0
#endif



#define T_NUM 0
#define T_STR 1


#define MainWantError(errortype,wanttype) 	CleanScreen();\
										   	errortype(wanttype);\
											ShowMainMenu();\
											return 0;
#define MENUITEM(ID,CALLBACK) case ID :CALLBACK;break;
#define MENU(op) switch(op){
#define DEFAULTITEM(CALLBACK) default : CALLBACK; }	


void SayHello();
void SayGoodbye();
void ShowMainMenu();
void ShowHelp();
void TypeError(INPUTTYPE T);
void TypeNullError(INPUTTYPE T);
void TypeLongError(INPUTTYPE T);


int WantNum();
#endif