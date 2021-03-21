#include"rect.h"
#include"uniform.h"
using namespace std; 
const float WIN_SIZE = 12.0;
const int   MAX_SIZE = 3;
SimpleWindow W("KaleidoWindow", WIN_SIZE, WIN_SIZE);  //创建一个窗口


//产生随机的颜色
//color是ezWin图形库中定义的表示颜色的枚举类型
color RandomColor()
{
	return (color)Uniform(0, MaxColors-1);
}


//随机产生正方形与中心的距离
float RandomOffSet(int Range, float TrinketSize)
{
	float OffSet = Uniform(0, Range * 10) / 10.0f;

	//正方形与中心的距离必须大于其边长的一半
	if (OffSet < TrinketSize / 2.0f)
	{
		OffSet = TrinketSize / 2.0f;
	}
	return OffSet;
}


//随机设置正方形的边长
float RandomTrinketetSize(int MaxSize)
{
	return Uniform(10, MaxSize * 10) / 10.0f;
}
int Kaleidoscopeh()
{
	const float Center = WIN_SIZE / 2;                   //窗口中心
	const float Size =  MAX_SIZE;  //设置正方形边长
	const color Color1 = RandomColor();	                 //产生随机颜色
	const color Color2 = RandomColor();
	float OffSet = RandomOffSet(MAX_SIZE, Size);         //设置正方形与中心的距离



	RectangleShape Trinket1(W, Center + OffSet, Center, Color1, Size, Size);
	RectangleShape Trinket2(W, Center - OffSet, Center, Color2, Size, Size);
	RectangleShape Trinket3(W, Center, Center - OffSet, Color2, Size, Size);
	RectangleShape Trinket4(W, Center, Center + OffSet, Color1, Size, Size);
	

	Trinket1.Draw();
	Trinket2.Draw();
	Trinket3.Draw();
	Trinket4.Draw();
	

	return 0;
}

int Kaleidoscopez()
{
	const float Center = WIN_SIZE / 2;                   //窗口中心
	const float Size = MAX_SIZE;  //设置正方形边长
	const color Color1 = RandomColor();	                 //产生随机颜色
	const color Color2 = RandomColor();
	float OffSet = RandomOffSet(MAX_SIZE, Size);         //设置正方形与中心的距离



	RectangleShape Trinket5(W, Center + OffSet, Center + OffSet, Color1, Size, Size);
	RectangleShape Trinket6(W, Center - OffSet, Center + OffSet, Color2, Size, Size);
	RectangleShape Trinket7(W, Center - OffSet, Center - OffSet, Color1, Size, Size);
	RectangleShape Trinket8(W, Center + OffSet, Center - OffSet, Color2, Size, Size);



	
	Trinket5.Draw();
	Trinket6.Draw();
	Trinket7.Draw();
	Trinket8.Draw();

	return 0;
}

int Kaleidoscope()
{
	if (Uniform(1, 2))
		Kaleidoscopez();
	else
		Kaleidoscopeh();
	return 0;
}

int ApiMain()
{
	W.Open();
	W.SetTimerCallback(Kaleidoscope);
	W.StartTimer(1000);
	return 0;
}