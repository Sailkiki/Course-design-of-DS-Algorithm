/*˵��;
1, ������ν����Լ����ִ��������ڱ������Ѿ�д��
2, ����Ϊʲô����ƽ��̽�ⷨ�ı�Ӧ��ȡ 4k + 3 (kΪ�Ǹ�����)������
������Ҳ�����˾���Ľ��͡�*/
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
	//�������� 
	OtherFunc O;
	O.Welcome();//���� 
	while (true)
	{ 
		//��⵽�����û���ʱ�򣬿�ʼ���г��� 
		if (_kbhit()) 
		{
			O.Start_F();
			break;
		}
	}
	return 0;
}

