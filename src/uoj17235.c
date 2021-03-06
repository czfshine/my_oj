/*

**************************************
17235 Minecraft是个好游戏
**************************************
Description

Minecraft是一个颠覆性的高自由度游戏，其中文译名叫“我的世界”。之所以会有如此译名，原因在于这个游戏就像一个沙盒世界，玩家就像是个创世神一般。其颠覆性在于它不同于以往那些游戏“要你做

去什么”，相反的，是由玩家去思考“我要做什么”。

说了这么一段，你们是不是很想上网搜一搜怎么玩呢？不过玩之前麻烦先帮Lrc解决一个问题。

这个游戏里面是可以制作逻辑电路的，通过简单的搭建，玩家可以制作出一个简单的TNT大炮。

假设现在Lrc想使用大炮轰地面上炸距离自己s米处的目标，大炮的发射仰角为A（单位角度），炮弹的初速度为v米/秒，TNT在发出后t秒爆炸，爆炸半径为r米（当目标到爆炸点的距离<=r时即视为击中），

炸药落地后不反弹。重力加速度取10m/s^2。问：Lrc能否击中目标？PS：目标与Lrc于同一平面。
**************************************
Input

输入包括5个实数，分别为s(s>0)，A(0<A<90)，v(v>0)，t(t>0)，r(r>0)，之间用空格分割。
**************************************
Output

输出一行，若能击中目标，输出“nice!”（不包含引号），否则输出“T^T”（不包含引号）。
**************************************
Sample Input

9 30 10 1 0.5
**************************************
Sample Output

nice!
**************************************
Source
**************************************
Author0*/
#include <stdio.h>
#include "math.h"
#define PI 3.141592653
int main(int argc, char const *argv[])
{
	double s,A,v,t,r,x,y,T,t0;
	scanf("%lf%lf%lf%lf%lf",&s,&A,&v,&t,&r);
	A=A/180.0*PI;
	t0=v*sin(A)/10.0*2.0;
	if(t>t0){
			x=v*cos(A)*t0;
			y=0.0;
		}else{
			x=v*cos(A)*t;
			y=v*sin(A)*t-10.0*t*t/2.0;
	}
	if(((x-s)*(x-s)+y*y)<=r*r){
		printf("nice!");
	}else{
		printf("T^T");
	}

	return 0;
}