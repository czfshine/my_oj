#include "goods.h"

int main(){

	Store * S;
	S=InitStore();

	AddGoods(*S,1,"1111",2);
	AddGoods(*S,2,"2111",3);

	ShowAllGoods();

	ChangeGoodsName(*S,1,"5555");

	ChangeGoodsCount(*S,2,555);

	ShowAllGoods();


	return 0;
}