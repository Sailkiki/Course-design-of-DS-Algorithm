#pragma once
#include "Function.h"
class OtherFunc {
	public:
		
		friend class Function;
		
		void InitKeyWords_Second(int * a, int * b, NodeOfHash * hashTable[Hsize]);//��ʼ���ڶ����ļ��ĺ��� 
		
		void DealKeyWords_Second(Function &hashtable, int Num_1, int UNum_1, int Species, double trans1, double trans2, double trans3, double trans4, NodeOfHash * hashTable[Hsize]);//�������������ĺ��� 
		
		void InitKeyWords_First(Function &hashtable, char (*Word) [MaxSizeOfWord], char (*word2) [MaxSizeOfWord], NodeOfHash * hashTable[Hsize]);//��ʼ����һ���ļ��ĺ��� 
		
		void DealKeyWords_First(Function &hashtable, NodeOfHash * hashTable[Hsize]);//��������֮��ĳ���һ�ĺ���
		
		void Welcome();//��ӭ���� 
		
		void Start_F();//��ʼ���� 
		
		void ProConnect1();//�νӽ���ĺ��� 
		
		void ProConnect2();//�νӽ���ĺ��� 
		
};
void Time();//��ͣ�ĺ��� 


