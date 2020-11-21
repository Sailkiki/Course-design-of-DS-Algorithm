#pragma once
#include "Function.h"
class OtherFunc {
	public:
		
		friend class Function;
		
		void InitKeyWords_Second(int * a, int * b, NodeOfHash * hashTable[Hsize]);//初始化第二个文件的函数 
		
		void DealKeyWords_Second(Function &hashtable, int Num_1, int UNum_1, int Species, double trans1, double trans2, double trans3, double trans4, NodeOfHash * hashTable[Hsize]);//操作处理程序二的函数 
		
		void InitKeyWords_First(Function &hashtable, char (*Word) [MaxSizeOfWord], char (*word2) [MaxSizeOfWord], NodeOfHash * hashTable[Hsize]);//初始化第一个文件的函数 
		
		void DealKeyWords_First(Function &hashtable, NodeOfHash * hashTable[Hsize]);//操作处理之后的程序一的函数
		
		void Welcome();//欢迎界面 
		
		void Start_F();//开始程序 
		
		void ProConnect1();//衔接界面的函数 
		
		void ProConnect2();//衔接界面的函数 
		
};
void Time();//暂停的函数 


