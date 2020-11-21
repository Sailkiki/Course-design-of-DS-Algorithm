#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <conio.h>
#include <windows.h>
#include <utility>
#include "Function.h"
#include "Oher.h"
#define Hsize 67//哈希数组总长度
#define MaxBoard 200
#define Prime 61
#define Uprime 29
using namespace std;



//对当前表长进行初始化 
Function::Function()
{
	memset(UhashTable, 0, sizeof(UserNode*) * Usize);
	TableSize = 0;
	UTableSize = 0;
}

//计算函数 
void Function::Caclulate(int * a, int * b, Function hashtable, OtherFunc Ot, NodeOfHash * hashTable[Hsize])
{
	int Num2 = 0;//数组的计数器 
	int UNum2 = 0;//数组的计数器 
	int Temp2[Hsize];
	int UTemp2[Usize];
	memset(Temp2, 0, sizeof(Hsize));
	memset(UTemp2, 0, sizeof(Usize));
	
	for (int i = 0; i < Hsize; i++) 
	{
		/*开始把冲突次数(权值)都存入数组中*/
		Temp2[Num2++] = hashtable.HashGet(i, hashTable);
	}
	
	for (int i = 0; i < Usize; i++)
	{
		/*开始把冲突次数(权值)都存入数组中*/
		UTemp2[UNum2++] = hashtable.UHashGet(i);
	}
	

	//这两个变量是题目中的要求，求s的值， 分别是c++关键字和用户自定义标识符的 
	int Num_1 = 0;
	int UNum_1 = 0;
	
	for (int i = 0; i < Hsize; i++) 
	{
		/*进行一步判断，当用户自定义的关键字冲突次数和c++关键字冲突次数都小于
		最大边界时，那么把他们相加*/
		if (a[i] < MaxBoard && Temp2[i] < MaxBoard) 
		{
			Num_1 += pow((a[i] - Temp2[i]), 2);
		}
	}
	
	for (int i = 0; i < Usize; i++)
	{
		if (b[i] < MaxBoard && UTemp2[i] < MaxBoard)
		{
			UNum_1 += pow((b[i] - UTemp2[i]), 2);
		}
	}
	
	//对程序进行精确分析 
	int Species = 0;//两个程序共有的重复种类 
	int F_Total = 0;//程序1出现的关键字总个数 
	int F_Species = 0;//程序1出现的关键字总种类 
	int S_Total = 0;//程序2出现的关键字总个数 
	int S_Species = 0;//程序2出现的关键字总种类 
	//两种重复的关键字分别在各自的程序中出现的次数，便于计算频率。 
	int T1_Species = 0;
	int T2_Species = 0;
	
	for (int i = 0; i < Hsize; i++)
	{
		F_Total += a[i];//程序1关键字个数 
		S_Total += Temp2[i];//程序2关键字总个数 
		
		if (a[i]!=0&&Temp2[i]!=0)
		{
			Species++;//重复种类总数
			T1_Species+=a[i];//这里把次数也算进去了，不单单有种类，连同他出现的次数。T代表TOTAL。
			//要进行两个循环，也就是这些所有的变量，必须连同c++关键字和用户自定义的一起算上。不能分着算 
			T2_Species+=Temp2[i];
		}
		
		if (a[i]!=0)
		{
			F_Species++;//程序1关键字种类 
		}
		
		if (Temp2[i] !=0)
		{
			S_Species++;//程序2关键字种类 
		}
	}
	
	for (int i = 0; i < Usize; i++)
	{
		F_Total += b[i];
		S_Total += UTemp2[i];
		
		if (b[i]!=0&&UTemp2[i]!=0)
		{
			Species++;
			T1_Species+=b[i];//这里把次数也算进去了，不单单有种类，连同他出现的次数。T代表TOTAL。 
			T2_Species+=UTemp2[i];
		}
		
		if (b[i]!=0)
		{
			F_Species++;//程序1关键字种类 
		}
		
		if (UTemp2[i] !=0)
		{
			S_Species++;//程序2关键字种类 
		}
	}
	
	//重复种类占1的总种类 
	double trans1 = (double)Species/F_Species;//覆盖率：种类出现的频度 
	double trans2 = (double)Species/S_Species;//覆盖率：种类出现的频度 
	
	double trans3 = (double)T1_Species/F_Total;//频率，包括了出现的次数 
	double trans4 = (double)T2_Species/S_Total;//频率，包括了出现的次数 
	system("pause");
	Ot.ProConnect2();
	Ot.DealKeyWords_Second(hashtable, Num_1, UNum_1, Species, trans1, trans2, trans3, trans4, hashTable);
}



int Function::HashTableStr(char * Key)
{
	char * p = Key;//工作指针指向的字符串
	int h;
	int num = strlen(Key);
	/*关键的一步，对一个单词的首字母代表的数字和尾字母代表的数字
	相加后对一个小于表长的并且离表长最近的素数作为模值，并进行取模。
	 */
	 //除留取余法 
	h = ((p[0] - 'a') + p[num - 1] - 'a') % Prime;
	return h;
}

int Function::UHashTableStr(char * Key)
{
	char * p = Key;
	int h;
	int num = strlen(Key);
	h = ((p[0] - 'a') + p[num - 1] - 'a') % Uprime;
	return h;
}

//对用户自定义标识符的关键字进行插入操作 
void  Function::UHashTableInsert(char * Key)
{
	//计算这个关键字出现的位置，在表中 
	int Pos = UHashTableStr(Key);
	UserNode * pHead = UhashTable[Pos];
	int SquareNum = 1;
	int Flag = 0;
	int k = Pos;
	//如果这个结点不是空的话 
	while (pHead)
	{
		//进行一步判断，如果这个位置没有元素
		/*需要注意的是，如果这两个参数中一个为NULL的话，那么程序就会出现段错误
		而崩溃，但是如果你把这两个结构体指针数组都声明为全局变量就不会了，但是
		不能有全局变量，那么解决方法一个就是在适当的时候进行初始化，(作为参数传递)
		的一个数组，另一个就是在类声明对象的时候，需要提前在无参构造函数中进行
		一步初始化的操作(声明在类里面的数组)*/ 
		if (strcmp(pHead->UKey, Key) == 0)
		{
			return;
		}
		
		//Flag是标记值，作为向右/左插入表中的一个判断值，偶数向右插
		//奇数向左插入，这就是二次探测法。 
		if (Flag % 2 == 0)
		{
			k = Pos + pow(SquareNum, 2);
			//必须不能忘记的一步，如果k比表长大，那么必须进行取余或者相减 
			if (k > Hsize)
			{
				k = k % Usize;
			}
			//把新的结点赋值Phead 
			pHead = UhashTable[k];
			Flag++;
		}
		//奇数的话，那么向左插 
		else
		{
			k = Pos - pow(SquareNum, 2);
			//曾经这里一度出现错误，，没有找到，数组下标不能为复数。 
			if (k < 0)
			{
				k = k + Usize;
			}
			
			pHead = UhashTable[k];
			Flag++;
			SquareNum++;
		}
	}
	UserNode * pNewNode = new UserNode;//声明一个新节点，给他分配空间
	//必须做的就是给关键字分配空间，不然在之后的操作中，就会
	//出现溢出而导致程序崩溃 
	pNewNode->UKey = (char*)malloc(sizeof(char));
	//赋值，把后者赋值给前者 
	strcpy(pNewNode->UKey, Key);
	//把新的结点赋值给即将进行处理的结点 
	UhashTable[k] = pNewNode;
}


void Function::HashTableInsert(char * Key, NodeOfHash * hashTable[Hsize])
{
	int Pos = HashTableStr(Key);//使用哈希函数计算出数组的序号
	NodeOfHash * pHead = hashTable[Pos];//声明指针指向待插入的节点
	int SquareNum = 1; 
	int Flag = 0;
	int k = Pos;//为什么要这样设置Squarenum(后用sq表示)和flag?
	/*由于二次探测法说白了就是向两边同时插入数据，所以我定义两个工作值sq，flag
	一开始的值分别为奇数和偶数，其中sq作为加减的工作值，flag作为判断条件
	的工作值 对sq的平方进行加减操作，来确定k值最后的位置，从而进行插入。
	这就是用二次探测法来解决冲突的思想*/
	while (pHead)//当pHead存在的时候
	{
		if (strcmp(pHead->Key, Key) == 0)//如果有冲突
		{
			return;
		}
		
		else if (Flag % 2 == 0)//首先对j进行判断，当j为偶数的时候，往前面插。
		{
			k = Pos + pow(SquareNum, 2);
			if (k > Hsize)
			{
				k = k % Hsize;//如果超出表的长度，那么在前面开始找。
			}
			pHead = hashTable[k];
			Flag++;
		}
		//此时j为奇数, 那么我选择往后插。
		else
		{
			/*这里一定要注意，在我调试程序的时候，选取了多组的代码进行比较，但是总是发现一个问题，位于
			从第47号位置开始的时候陷入了死循环，经过仔细分析后才知道犯了一个非常低级的错误，那就是没有
			考虑到k为负数的情况，数组下标怎么可能为负数呢？？ 所以进行了一步 判断处理，完美地解决了问题
			。*/ 
			k = Pos - pow(SquareNum, 2);
			if (k < 0)
			{
				k = k + Hsize;
			}
			pHead = hashTable[k];
			Flag++;
			SquareNum++;
		}
	}

	NodeOfHash* pNewNode = new NodeOfHash;//声明一个新节点，给他分配空间
	/*给这个结点的关键字分配一块空间， 大小为char类型乘以他的长度+1*/
	//必须给它分配空间 
	pNewNode->Key = (char *) malloc(sizeof(char));
	
	strcpy(pNewNode->Key, Key);//进行插入
	
	hashTable[k] = pNewNode;//将哈希表数组中的对应结点指向新的结点
	
}

UserNode * Function::UHashTableFind(char * Key)
{
	if (UhashTable[UHashTableStr(Key)])//如果他存在的话。
	{
		UserNode * pHead = UhashTable[UHashTableStr(Key)];//声明一个工作指针指向这个结点
		int SquareNum = 1, Flag = 0, k = UHashTableStr(Key);

		while (pHead)//如果存在的话
		{
			if (pHead->UKey != NULL)//如果要查找的和原来的相等
			{
				pHead->UValue++;//频数加1，也就是出现的次数 
				return pHead;
			}
		
			else if (Flag % 2 == 0)//这里跟之前上一个函数的一样
			{
				k = UHashTableStr(Key) + pow(SquareNum, 2);
				
				//当k大于表长的时候，必须要对表长取余，相减也可以，道理一样 
				if (k > Hsize)
				{
					k = k % Hsize;
				}

				pHead = UhashTable[k];
				Flag++;
			}

			else
			{
				k = UHashTableStr(Key) - pow(SquareNum, 2);
				//必须判断k的值是否为负数，否则程序将会发生错误。 
				if (k < 0)
				{
					k = k + Hsize;
				}
				pHead = UhashTable[k];
				Flag++;
				SquareNum++;
			}
		}
	}
	return NULL;
}

//在表中进行查找的函数，同时进行频数计算的操作的函数 
NodeOfHash * Function::HashTableFind(char* Key, NodeOfHash * hashTable[Hsize])
{
	int Pos = HashTableStr(Key);//寻找关键字位置
	if (hashTable[Pos])//如果他存在的话。
	{
		NodeOfHash * pHead = hashTable[Pos];//声明一个工作指针指向这个结点
		int SquareNum = 1, Flag = 0, k = Pos;
		
		while (pHead)//如果存在的话
		{
			//如果存在的话 
			if (strcmp(Key, pHead->Key) == 0)//如果要查找的和原来的相等
			{
				pHead->WordsValue++;//频数加1，也就是出现的次数 
				return pHead;
			}
			
			else if (Flag % 2 == 0)//这里跟之前上一个函数的一样
			{
				k = Pos + pow(SquareNum, 2);
				
				//当k大于表长的时候，必须要对表长取余，相减也可以，道理一样 
				if (k > Hsize)
				{
					k = k % Hsize;
				}

				pHead = hashTable[k];
				Flag++;
			}

			else
			{
				k = Pos - pow(SquareNum, 2);
				//必须判断k的值是否为负数，否则程序将会发生错误。 
				if (k < 0)
				{
					k = k + Hsize;
				}
				pHead = hashTable[k];
				Flag++;
				SquareNum++;
			}
		}
	}
	return NULL;
}


//打印函数 
void Function::UHashTablePrint()
{
	cout << "序号     关键字  在程序中出现的次数 " << endl;
	
	for (int i = 0; i < Usize; i++)//从头到尾遍历hash表
	{
		if (i == 17)
		{
			continue;
		}
		
		if (UhashTable[i])
		{
			printf("%4d :", i);//打印节点序号
			printf("%9s:  %4d ", UhashTable[i]->UKey, UhashTable[i]->UValue);
			cout << endl;
		}
	}
}

void  Function::HashTablePrint(NodeOfHash * hashTable[Hsize])
{
	cout << "序号     关键字  在程序中出现的次数 " << endl;
	for (int i = 0; i < Hsize; i++)//从头到尾遍历hash表
	{
		if (i == 48)
		{
			continue;
		}

		if (hashTable[i])
		{
			printf("%4d :", i);//打印节点序号
			printf("%9s:  %4d ", hashTable[i]->Key, hashTable[i]->WordsValue);
			cout << endl;
		}
	}
}

//用户自定义标识符权值查找函数 
int Function::UHashGet(int x)
{
	for (int i = 0; i < Usize; i++)
	{
		if (i == x)
		{
			if ( !UhashTable[i] )
			{
				return 0;
			}
			return UhashTable[i]->UValue;
		}
	}
}

//c++关键字权值查找函数 
int Function::HashGet(int x, NodeOfHash * hashTable[Hsize])
{
	//为了将每一个hashtable这个指针数组里元素的权值都赋值给一个数组，以后方便运算。 
	for (int i = 0; i < Hsize; i++)
	{
		if (i == x)
		{
			if ( !hashTable[i] )
			{
				return 0;
			}
			else
			{
				return hashTable[i] -> WordsValue;
			} 
		}
	}
}

//初始化，建立根节点 ，类似于树根 
Line * Function::Create()
{
    Line * node = (Line*)malloc(sizeof(Line));
    memset(node, 0, sizeof(Line));
    return node;
}

//类似于前缀树的操作，具体解释会在文档中 
void Function::InsWords(NodeOfLine LineRoot, char * str)
{
    if (LineRoot == NULL || *str == '\0')//如果没有字符串或者根结点是空
    {
        return;
    }

    Line * t = LineRoot;//声明两个工作指针
    char * p = str;
	
    while (*p != '\0') //当这个单词没有结束的时候 
    {
        if (t->Bond[*p - 97] == NULL)
        {//如果当前的结点是空的话，那么就申请一个结点 
            Line * tmp = Create();
            t->Bond[*p - 97] = tmp;
        }

        t = t->Bond[*p - 97];//赋值给下一个指针 
        p++;//数组指针往后移一位
 
    }
    t->SUM++;
}

int Function::FindWords(NodeOfLine root, char * str)//查找字符串是否在这个单词结构中 
{
    if (root == NULL || *str == '\0')//树为空或者字符串是空的
    {
        cout << "查找失败" << endl;
        return 0;
    }

    char * p = str;//声明工作指针指向字符串首位
    Line * t = root;//声明一个工作指针

    while (*p != '\0')
    {
        if (t->Bond[*p - 97] != NULL)//如果这个字符在树中不为空
        {
            t = t->Bond[*p - 97];//那么指针指向子结点
            p++;//向后移动字符串指针
        }

        else
        {
            break;
        }
    }
    
    if (*p == '\0')//如果字符串指针移动到了字符串结尾
    {
        if (t->SUM == 0)//如果这个结点的子叶数目为0
        {
            return 0;
        }

        else//如果存在子叶结点
        {
            return 1;
        }
    }

    else
    {
        return 0;
    }
}

//两个初始化函数 
void Function::HashTableInit(NodeOfHash * hashTable[Hsize])
{
	memset(hashTable, 0, sizeof(NodeOfHash*) * Hsize);
}

void Function::UhashTableInit()
{
	memset(UhashTable, 0, sizeof(UserNode*) * Usize);
}

