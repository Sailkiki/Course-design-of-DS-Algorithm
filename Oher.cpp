#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include "Function.h"
#include "Oher.h"
#define MaxBoard 200

using namespace std;

//一个没用的函数 
void Time()
{
	system("cls");
	cout << "程序正在分析中" << endl;
	for (int i = 0; i < 4; i++) 
	{
		Sleep(500);//暂停0.5s
		cout << ".";
	}
}

void OtherFunc::Welcome() 
{
	cout << "*******************************************" << endl;
	cout << "                                           " << endl;
	cout << "                                           " << endl;
	cout << "           源程序的相似性检测              " << endl;
	cout << "                                           " << endl;
	cout << "                                           " << endl;
	cout << "*******************************************" << endl;
	cout << "                                           " << endl;
	cout << "                                           " << endl;


	cout << "提示 ： 1，使用之前， 请确保程序所在的文件夹里有Keywords.txt的文本文件" << endl;
	cout << "        2, 请确保有两个带有源代码的文本文件在文件夹内                 " << endl << endl;

	cout << "检查无误后， 请按下任意键开始检测。" << endl;

}

void OtherFunc::ProConnect1() 
{
	system("cls");
	cout << "程序(1)已经分析完毕，请输入指令查看结果" << endl;
	cout << "*****************************************" << endl;
	cout << "输入1查看程序1的哈希表" << endl;
	cout << "输入2分析程序(2)          " << endl << endl;
	cout << "请输入指令" << endl;
}

void OtherFunc::ProConnect2() 
{
	system("cls");
	cout << "程序(2)已经分析完毕， 请输入指令查看结果" << endl;
	cout << "*****************************************" << endl;
	cout << "输入1查看程序2的哈希表" << endl;
	cout << "输入2查看最终S值          " << endl << endl;
}

//开始程序 
void OtherFunc::Start_F()
{
	Time();
	OtherFunc Ot;//声明一个对象
	Function hashtable;//声明一个对象
	char Word[Totle][MaxSizeOfWord]; //声明一个储存关键字的数组,默认为每个单词不超过10个字母
	char Word2[Utotle][MaxSizeOfWord]; //用户自定义标识符的数组 
	NodeOfHash * hashTable[Hsize];//声明c++关键字的结构体指针数组 
	Ot.InitKeyWords_First(hashtable, Word, Word2, hashTable);//第一次初始化关键字的哈希表和文件1的内容 
	Ot.DealKeyWords_First(hashtable, hashTable);//处理上述函数，并且处理程序2 
	return;
}


void OtherFunc::DealKeyWords_First(Function &hashtable, NodeOfHash * hashTable[Hsize])
{
	//分别定义两组变量,建立哈希表
	//带u的就是User，也就是用户自定义系列的 
	int Num1 = 0;
	int UNum1 = 0;
	int Temp1[Hsize];
	int UTemp1[Usize];
	memset(Temp1, 0, sizeof(Hsize));//对数组进行初始化
	memset(UTemp1, 0, sizeof(Usize)); 
	
	//下面这两个函数的作用就是分别遍历这两个表，然后把所有的权值存入到
	//数组中，这样便于之后的计算操作。 
	for (int i = 0; i < Hsize; i++) 
	{
		Temp1[Num1++] = hashtable.HashGet(i, hashTable);
	}
	
	for (int i = 0; i < Usize; i++)
	{
		UTemp1[UNum1++] = hashtable.UHashGet(i);
	}
	
	ProConnect1();
	int n;
	
	//整个while循环没有什么好说的，仅仅是输入指令进行操作的步骤 
	while (cin >> n)
	{
		if (n == 1) 
		{
			system("cls");
			cout << "程序一分析为如下结果：(包含了c++关键字和用户自定义标识符)" << endl << endl;
			fflush(stdin);
			//输出c++关键字表的状态 
			hashtable.HashTablePrint(hashTable);
			cout << "*****************************************" << endl;
			//输出自定义标识符表的状态 
			hashtable.UHashTablePrint();
			cout << "输入Y返回" << endl;
			fflush(stdin);
			char s;
            
			while (cin >> s) 
			{
				fflush(stdin);
				if (s == 'Y') 
				{

					ProConnect1();
					break;
				}
				
				else
				{ 
					cout << "请重新输入" << endl;
				} 
			}
		}

		else if (n == 2) 
		{
			fflush(stdin);
			system("cls");
			InitKeyWords_Second(Temp1, UTemp1, hashTable);
		}

		else 
		{
			cout << "您的输入有误, 请重新输入" << endl;
		}
	}
}


void OtherFunc::DealKeyWords_Second(Function &hashtable, int Num_1, int UNum_1, int Species, double trans1, double trans2, double trans3, double trans4, NodeOfHash * hashTable[Hsize])
{
	int n;
	while (cin >> n) 
	{
		fflush(stdin);
		if (n == 1) 
		{
			system("cls");
			cout << "第二个程序的哈希表的状态如下：" << endl;
			hashtable.HashTablePrint(hashTable);
			cout << "*****************************************" << endl;
			hashtable.UHashTablePrint();
			cout << endl;
			cout << "输入Y返回" << endl;
			char s;
			while (cin >> s) 
			{
				if (s == 'Y')
				{
					ProConnect2();
					break;
				}
				else
					cout << "请重新输入" << endl;
			}
		}

		else if (n == 2) 
		{
			cout << "对于c++关键字来说,S的值为：" << endl;
			cout << sqrt(Num_1) << endl;		
			cout << "对于用户自定的标识符,S的值为：" << endl;
			cout << sqrt(UNum_1) << endl;
			
			cout << "两个S的值的结果无法直观地判断出两个程序的相似性，因为\n" 					
			    "如果最后得出S1(关键字频度)为0时候，也就是对于关键字来\n" 					
				"说，出现的频度一模一样的时候，如果此时S2的值为很大很打\n" 					
				"的时候，那就可以分析出，即使这两个程序c++关键字一模一样\n" 					
				"但是用户自定义的关键字却毫不相干，那么我也认为他们的相似\n" 					
				"度为0，所以计算出了两个程序的相对的相似度概率，这样结果\n" 					
				"比较直观一些。" << endl << endl; 
			cout << "经过分析可得到，两个程序一共有 " << Species << " 种关\n"
			    "键字相同，其中，这 " << Species << " 种关键字占程序1关键字\n"
				"总种类数的%" << 100*trans1 << ", 占程序2的%" << 100*trans2<<"\n"
				"算上频度(出现次数)来说，这些重复的关键字在程序1中占程序1总程\n"
				"序的%" << 100*trans3 << ", 占程序2的总关键字个数的%"<< 100*trans4 <<"\n"
				<<endl;   
			
			/*下面是我自己想的一种综合四个概率判断程序相似度的办法，不知道够不够准确*/
			cout << "综上所述，系统给出的结论是：" << endl;
			if (100*trans1 == 100*trans2 && 100*trans3 == 100*trans4)
			{
				cout << "两个程序一模一样！" << endl;
			}
			
			else if (abs(100*trans1 - 100*trans2) <= 10 && abs(100*trans3 - 100*trans4) <= 10 && abs(100*trans1 - 100*trans2) && abs(100*trans3 - 100*trans4))
			{
				cout << "两个程序非常相似" << endl<< endl;
			}
			
			else if (abs(100*trans1 - 100*trans2) <= 20 && abs(100*trans1 - 100*trans2) > 10 && abs(100*trans3 - 100*trans4) > 10 && abs(100*trans3 - 100*trans4) <= 20)
			{
				cout << "两个程序略微相似" << endl<< endl;
			}

			else
			{
				cout << "两个程序不相似" << endl<< endl;
			}
			cout << "输入Y返回" << endl;
			char s;
			while (cin >> s) 
			{
				if (s == 'Y')
				{
					ProConnect2();
					break;
				}
				else
					cout << "请重新输入" << endl;
			}
		}

		else 
		{
			cout << "您的输入有误, 请重新输入" << endl;
		}
	}
}

void OtherFunc::InitKeyWords_First(Function &hashtable, char (*Word) [MaxSizeOfWord], char (*word2) [MaxSizeOfWord], NodeOfHash * hashTable[Hsize])
{
	//首先对数组进行初始化 
	for (int i = 0; i < Totle; i++)
	{
		for (int j = 0; j < MaxSizeOfWord; j++)
		{
			Word[i][j] = 0;
		}
	}
	//下面是两个读取文件的操作。 
	FILE * fp;
	fp = fopen("keywords.txt", "r");//进行读文件操作
	for (int i = 0; i < Totle; i++) 
	{
		if (fscanf(fp, "%s", Word[i]) != 1) 
		{
			break;
		}
	}
	fclose(fp);
	
	
	FILE * Ufp;
	Ufp = fopen("yonghu.txt", "r");
	for (int i = 0; i < Utotle; i++)
	{
		if (fscanf(Ufp, "%s", word2[i]) !=1)
		{
			break;
		}
	}
	fclose(Ufp);
	
	//申请一个类似于树根的结点 
	NodeOfLine LineRoot = NULL;
	NodeOfLine ULineRoot = NULL;
	//对结点进行初始化
	LineRoot = hashtable.Create();
	ULineRoot = hashtable.Create();
	if (LineRoot == NULL || ULineRoot == NULL)
	{
		cout << "Fall!" << endl;
	}
	
	for (int i = 0; i < Totle; i++) 
	{
		//往树中插入单词，函数内容是将各个字母逐一插入。 
		hashtable.InsWords(LineRoot, Word[i]);
	}
	
	for (int i = 0; i < Utotle; i++)
	{
		//往树中插入单词
		hashtable.InsWords(ULineRoot, word2[i]);
	}
	
	hashtable.HashTableInit(hashTable);
	
	for (int i = 0; i < Totle; i++) 
	{
//		cout << i << " ";	
		hashtable.HashTableInsert(Word[i], hashTable);
	}
//	cout << endl;
	for (int i = 0; i < Utotle; i++)
	{
//		cout << i << " ";
		hashtable.UHashTableInsert(word2[i]);
	}
	
	system("pause");
	
	FILE * fp1;
	int ch1;
	
	if ((fp1 = fopen("test1.txt", "r")) == NULL)
	{
		cout << "打开文件失败" <<endl;
		exit(0);
	}
	//单词数组 
	char word1[MaxSizeOfWord];
	//中间值，属于临时变量 
	int i = 0;
	int Tar = 0;
	while ( (ch1 = getc(fp1) ) != EOF )
	{
		//注意，在两个源程序的文件中，必须在最后加上一个回车，那么才可把整篇完全读取，不能停留在最后一行。 
		//记录单词的临时数组。 
		if ( (ch1 >= 'a') && (ch1 <= 'z') ) 
		{
			word1[i++] = ch1;
			Tar++;
		}
		
		//如果可以读取到的话，建立单词的分支 
		else if ( (word1[0] >= 'a') && (word1[0] <= 'z') )
		{
			/*我在调试的时候出现很多单词读取完毕之后，再取strlen值总会多出一个来的
			情况，很匪夷所思，有时会，有时就不会，所以为了解决这个问题，我只好又设置
			一个中间变量Tar,用来判断是否和STRLEN后的值相等，如果不相等，那么进行对多余
			的元素赋值为'\0'的一个处理，这样单词就会被算进去，从而进到下一个函数里，不然
			的话，这个单词长度不匹配，是无法进行识别的，所以总会出错。*/
			if (Tar != strlen(word1))
			{
				word1[Tar] = '\0';
				word1[Tar+1] = '\0';
			}
			//如果可以读取到单词的话
			if (hashtable.FindWords(LineRoot, word1))
			{
				//那么使用闭散列表的方式开始处理单词。
				hashtable.HashTableFind(word1, hashTable);
			}
			
			if (hashtable.FindWords(ULineRoot, word1))
			{
				hashtable.UHashTableFind(word1);
			}
			
			i = 0;//每次处理完单词需要数组归零 
			Tar = 0;
			
			for (int j = 0; j < 10; j++) 
			{
				word1[j] = '\0';
			}
		}
		
		else 
		{
			for (int j = 0; j < 10; j++) 
			{
				word1[j] = '\0';
			}
			i = 0;
			Tar = 0;
		}
	}
	
	if (fclose(fp1) != 0) 
	{
		cout << "关闭失败" << endl;
		exit(1);
	}
}

void OtherFunc::InitKeyWords_Second(int * a, int * b, NodeOfHash * hashTable[Hsize])
{
	OtherFunc Ot;
	Function hashtable;//声明一个对象
	char Words[Totle][MaxSizeOfWord];                                 //声明一个存储关键字的二维数组
	char Words2[Utotle][MaxSizeOfWord];
	for (int i = 0; i < Totle; i++)
	{
		for (int j = 0; j < MaxSizeOfWord; j++)
		{
			Words[i][j] = 0;
		}
	}
	
	//c语言形式的文件操作要比c++的流快很多，当然是
	//进行这种简单的只读操作的时候 
	FILE * fp;                                               //声明文件指针
	fp = fopen("keywords.txt", "r");                         //打开存储C++关键字的文件	
	for (int i = 0; i < Totle; i++) 
	{                                                        
		if (fscanf(fp, "%s", Words[i]) != 1)               
		{
			break;
		}
	}
	fclose(fp);                                              //关闭文件指针
	
	FILE * Ufp;
	Ufp = fopen("yonghu.txt", "r");
	for (int i = 0; i < Utotle; i++)
	{
		if (fscanf(Ufp, "%s", Words2[i]) != 1)             
		{
			break;
		}
	}
	fclose(Ufp);
	
	//分别对单词进行建树形结构的操作。 具体解释见文档 
	NodeOfLine LineRoot = NULL;                                  //声明一个根节点
	NodeOfLine ULineRoot = NULL;
	LineRoot = hashtable.Create();  							//初始化
	ULineRoot = hashtable.Create();
	
	if (LineRoot == NULL || ULineRoot == NULL)
	{                                        //如果根节点指向为空  即创建失败
		cout << "Fall!" << endl;
	}
	
	for (int i = 0; i < Totle; i++) 
	{
		//开始循环建立 
		hashtable.InsWords(LineRoot, Words[i]);
	}
	
	for (int i = 0; i < Utotle; i++)
	{
		hashtable.InsWords(ULineRoot, Words2[i]);
	}
	
	//很必要的步骤，对这两个数组再进行初始化一次，否则会出错，在分析程序2的时候 
	hashtable.HashTableInit(hashTable);                                       //初始化哈希表
	hashtable.UhashTableInit();
	
	//分别进行插入 
	for (int i = 0; i < Totle; i++) 
	{                           
		hashtable.HashTableInsert(Words[i], hashTable);
	}
	
	for (int i = 0; i < Utotle; i++) 
	{                       
		hashtable.UHashTableInsert(Words2[i]);
	}
	
	FILE* fp1;
	int ch1;
	
	if ((fp1 = fopen("test2.txt", "r")) == NULL) 
	{
		printf("Fall!");
		exit(0);
	}

	char words1[MaxSizeOfWord];
	int i = 0;
	//循环读取单词 
	while ( (ch1 = getc(fp1)) != EOF ) 
	{
		if ( (ch1 >= 'a') && (ch1 <= 'z') ) 
		{
			words1[i++] = ch1;
		}
		
		else if ( (words1[0] >= 'a') && (words1[0] <= 'z') ) 
		{
			//如果在树中找到了这个单词，那么 HashTableFind 和 UHashTableFind
			//开始对单词进行插入到表中的操作， 可能命名不是很规范。 
			if (hashtable.FindWords(LineRoot, words1))
			{
				hashtable.HashTableFind(words1, hashTable);
			}
			
			if (hashtable.FindWords(ULineRoot, words1))
			{
				hashtable.UHashTableFind(words1);
			}
			
			i = 0;
			
			//对数组进行重新初始化 
			for (int j = 0; j < MaxSizeOfWord; j++) 
			{
				words1[j] = '\0';
			}
		}
		
		else 
		{
			for (int j = 0; j < MaxSizeOfWord; j++) 
			{
				words1[j] = '\0';
			}
			i = 0;
		}
	}
	
	if (fclose(fp1) != 0)
	{
		printf("Fall!");
		exit(1);
	}
	
	hashtable.Caclulate(a, b, hashtable, Ot, hashTable);//计算函数，参数1为对象，参数2为对象，3为数组 
	
	//下面很大一部分是重复上面的工作具体的注释见上文 
//	int Num2 = 0;
//	int UNum2 = 0;
//	int Temp2[Hsize];
//	int UTemp2[Usize];
//	memset(Temp2, 0, sizeof(Hsize));
//	memset(UTemp2, 0, sizeof(Usize));
//	
//	for (int i = 0; i < Hsize; i++) 
//	{
//		/*开始把冲突次数(权值)都存入数组中*/
//		Temp2[Num2++] = hashtable.HashGet(i, hashTable);
//	}
//	
//	for (int i = 0; i < Usize; i++)
//	{
//		/*开始把冲突次数(权值)都存入数组中*/
//		UTemp2[UNum2++] = hashtable.UHashGet(i);
//	}
//	
//
//	int Num_1 = 0;
//	int UNum_1 = 0;
//	
//	for (int i = 0; i < Hsize; i++) 
//	{
//		/*进行一步判断，当用户自定义的关键字冲突次数和c++关键字冲突次数都小于
//		最大边界时，那么把他们相加*/
//		if (a[i] < MaxBoard && Temp2[i] < MaxBoard) 
//		{
//			Num_1 += pow((a[i] - Temp2[i]), 2);
//		}
//	}
//	
//	for (int i = 0; i < Usize; i++)
//	{
//		if (b[i] < MaxBoard && UTemp2[i] < MaxBoard)
//		{
//			UNum_1 += pow((b[i] - UTemp2[i]), 2);
//		}
//	}
//	
//	//对程序进行精确分析 
//	int Species = 0;//两个程序共有的重复种类 
//	int F_Total = 0;//程序1出现的关键字总个数 
//	int F_Species = 0;//程序1出现的关键字总种类 
//	int S_Total = 0;//程序2出现的关键字总个数 
//	int S_Species = 0;//程序2出现的关键字总种类 
//	//两种重复的关键字分别在各自的程序中出现的次数，便于计算频率。 
//	int T1_Species = 0;
//	int T2_Species = 0;
//	
//	for (int i = 0; i < Hsize; i++)
//	{
//		F_Total += a[i];//程序1关键字个数 
//		S_Total += Temp2[i];//程序2关键字总个数 
//		
//		if (a[i]!=0&&Temp2[i]!=0)
//		{
//			Species++;//重复种类总数
//			T1_Species+=a[i];//这里把次数也算进去了，不单单有种类，连同他出现的次数。T代表TOTAL。
//			//要进行两个循环，也就是这些所有的变量，必须连同c++关键字和用户自定义的一起算上。不能分着算 
//			T2_Species+=Temp2[i];
//		}
//		
//		if (a[i]!=0)
//		{
//			F_Species++;//程序1关键字种类 
//		}
//		
//		if (Temp2[i] !=0)
//		{
//			S_Species++;//程序2关键字种类 
//		}
//	}
//	
//	for (int i = 0; i < Usize; i++)
//	{
//		F_Total += b[i];
//		S_Total += UTemp2[i];
//		
//		if (b[i]!=0&&UTemp2[i]!=0)
//		{
//			Species++;
//			T1_Species+=b[i];//这里把次数也算进去了，不单单有种类，连同他出现的次数。T代表TOTAL。 
//			T2_Species+=UTemp2[i];
//		}
//		
//		if (b[i]!=0)
//		{
//			F_Species++;//程序1关键字种类 
//		}
//		
//		if (UTemp2[i] !=0)
//		{
//			S_Species++;//程序2关键字种类 
//		}
//	}
//	
//	//重复种类占1的总种类 
//	double trans1 = (double)Species/F_Species;//覆盖率：种类出现的频度 
//	double trans2 = (double)Species/S_Species;//覆盖率：种类出现的频度 
//	
//	double trans3 = (double)T1_Species/F_Total;//频率，包括了出现的次数 
//	double trans4 = (double)T2_Species/S_Total;//频率，包括了出现的次数 
//	system("pause");
//	ProConnect2();
//	Ot.DealKeyWords_Second(hashtable, Num_1, UNum_1, Species, trans1, trans2, trans3, trans4, hashTable);
}

