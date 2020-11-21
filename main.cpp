/*说明;
1, 对于如何建表以及各种处理方法，在报告中已经写明
2, 对于为什么二次平方探测法的表长应该取 4k + 3 (k为非负整数)的整数
报告中也给出了具体的解释。*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <conio.h>
#include "Function.h"
#include "Oher.h"
using namespace std;

int main() 
{
	//声明对象 
	OtherFunc O;
	O.Welcome();//界面 
	while (true)
	{ 
		//检测到键盘敲击的时候，开始运行程序 
		if (_kbhit()) 
		{
			O.Start_F();
			break;
		}
	}
	return 0;
}

