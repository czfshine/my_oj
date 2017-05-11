/*
THE ERP SYSTEM FOR C (ERP4C)
Author czfshine (https://github.com/czfshine)
Date :2017-05-10 11:10
Langage :ANSI C
Listen :MIT
Description:
商品进销存管理程序
1、题目描述
   设计一个商品进销存管理程序，该程序具有以下功能：
   （1）录入商品信息；
   （2）给定商品编号，修改该商品信息；
   （3）给定商品编号，删除该商品信息；
   （4）录入商品的进货与销售信息；
   （5）给定商品编号或商品名，查看该商品及库存信息；
   （6）统计功能：提供一些统计各类信息的功能。
2、题目要求
   （1）按照分析、设计、编码、调试和测试过程完成应用程序；
   （2）学习并使用流程图等工具，并在撰写报告中使用；
   （3）程序的各项功能在程序运行时，以菜单方式选择并执行；
   （4）要求用户输入数据时，要给出清晰、明确的提示，包括：输入数据的内容、格式及结束方式等
   （5）所有的信息存储在一个文件或多个中，并实现文件读写操作。
   （6）程序中用链表存放商品及进销存信息并实现增删减功能。（必须）
3、提示
   （1）提醒事件信息可以设计一个结构体类型
   （2）自己构思并增加的除规定功能之外的新功能，酌情加分。

*/

#include "tui.h"
#include "goods.h"

#define LOOP(fn) while(!fn()){}

Store GobalStore;

void Init(){
	Store * S;
	S=InitStore();
	GobalStore=*S;
}
void callback(){
	printf("test callback");
}		


void LogginGoods(){
	while(1){
		ShowLogginGoods();
		char * name;
		int id,count;

		name=WantName();
		id=WantId();
		count=WantCount();
		printf("input end");
		printf("%d %d %s",id,count,name);
		/*TODO ERROR*/
		if(id == 0){
			ShowMainMenu();
			return 0;
		}
		goods *g;
		g=FindGoodsById(GobalStore,id);

		printf("%d %d %s",id,count,name);
		if(g!=NULL){
			ShowGoodsExist(id);
			WantEnter();
			continue;
		}


		AddGoods( GobalStore,id,name,count);
		printf("%d %d %s",id,count,name);
		ShowLogginSuccess();
	}
	return 0;
}
int ListenMainKey(){
	int op;

	op=WantNum();

	switch(op){
		case WANTTYPEERROR:
			MainWantError (TypeError,T_NUM);
		case WANTNULLERROR:
			MainWantError (TypeNullError,T_NUM);
		case WANTLONGERROR:
			MainWantError (TypeLongError,T_NUM);
	}

	MENU(op)
		MENUITEM(MENULOGGIN,LogginGoods());
		MENUITEM(MENUCHANGE,callback());
		MENUITEM(MENUREMOVE,callback());
		MENUITEM(MENULOG2S,callback());
		MENUITEM(MENUQUERY,callback());
		MENUITEM(MENUSTATIS,callback());
		MENUITEM(MENUHELP,ShowHelp());
		MENUITEM(MENUEXIT,return 1);
	DEFAULTITEM(callback());
	
	return 0;
}

int main()
{
	Init();

    CleanScreen();
    ShowMainMenu();
    LOOP(ListenMainKey);
    SayGoodbye();

    return 0;
}
