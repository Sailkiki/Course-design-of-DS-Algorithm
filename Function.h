#pragma once
#define Usize 31 //4*7+3自定义表长 
#define Utotle 26 //自定义关键字个数 
#define Hsize 67//这个是c++哈希数组总长度 
#define Totle 59//c++关键字个数 
#define Letter 26//26个英文字母 
#define MaxSizeOfWord 10 //令单词最长不超过10 
/*自定义用户标识符结构体，经过查找资料，我自己的理解就是对于两个程序来说，不单单
其中有必要的c++关键字，还要有特殊的自定义关键字，

举一个例子

两个程序，其中一个是“小型英汉词典”，另一个是“迷宫游戏”，其中，两个程序经过计算
后，例如， c++关键字只用了 void int double 这三个(太少了，不是很恰当), 那么好了，现
你用不带自定义标识符的程序算算，相似度肯定是100%了， 很荒唐，两个核心算法都不一样的
程序， 相似度怎么可能是100呢， 所以这就需要我们把c++关键字的频度和自定义关键字的频度
相互比较处理来得出相似性了， 当然我写的只是针对于同种的程序，例如两个“迷宫游戏”
程序，我们可能会定义“Maze”, “DFS”, "Search", “Start”等等的关键字，所以我们就建立
这种的文件， 以及结构体对程序进行处理。

建立这个表的原理和c++关键字的是一样的，没有什么特殊之处。*/

class OtherFunc;

typedef struct  UserIdentifier
{
	int UValue;
	char * UKey;
	UserIdentifier(): UValue(0), UKey(NULL){}
}UserNode;

/*这个结构体其实是类似于起到一个(前缀树)字典树的作用，但是没有字典树树的功能完整
但是它本质上是一种哈希树的变种，查阅了很多博客，一般来说哈希表配合这种结构来使用 
对于统计和排序大量的字符串方面有很大用处，要要比单单使用哈希表来操作的话效率高出
很多，同时也更加节省空间。*/ 
typedef struct WordsLine
{ //用来储存单词的结构体
	int SUM;//计数器用来计算判断循环读入的字母是否可以完整的组成一个关键字单词 
	struct WordsLine * Bond[Letter];//子树结点，大小为26个英文字母的个数
	WordLine(){//初始化操作 
		SUM = 0;
		memset(Bond, 0, sizeof(WordsLine * ) * Letter);
	}
} Line, * NodeOfLine;

//c++关键字哈希表的结构体，本来想把用户自定义的和这个写在一起，结果好像不让。 
typedef struct NodeOfHashTable
{
	int WordsValue;//权值， 具体求法已经在文件中给出
	char * Key;//这是哈希表中的关键字
	NodeOfHashTable(): WordsValue(0), Key(NULL) {}//初始化操作 
} NodeOfHash;

//各类功能型函数的类 
class Function{
	
	protected:
		
		friend InitKeyWords_Second(int * a, int * b, NodeOfHash * hashTable[Hsize]);
		
		friend DealKeyWords_Second(Function &hashtable, int Num_1, int UNum_1, int Species, double trans1, double trans2, double trans3, double trans4, NodeOfHash * hashTable[Hsize]);
		
		friend InitKeyWords_First(Function &hashtable, char (*Word) [MaxSizeOfWord], char (*word2) [MaxSizeOfWord], NodeOfHash * hashTable[Hsize]);
		
		friend DealKeyWords_First(Function &hashtable, NodeOfHash * hashTable[Hsize]);
		/*可能想问UhashTable，和hashTable这两个数组为什么不同时写在类里或者同时直接当做参数在程序中进行
		传递·· 其实都可以，只不过要都当做参数的话那么前面的函数声明就老长了，看着太麻烦，所以就有一个
		数组定义在了类里面，总之都不是全局变量就是了*/
	public:
		UserNode * UhashTable[Usize];
		//当前表长 
		int UTableSize;
		int TableSize;
	public:
		
		
		Function();//无参构造函数，内容是对以上三个变量进行初始化 
		
		Function(char* Key);//有参构造函数(测试函数)
		
		Line * Create();//创建单词的根部，类似于树根的建立
		
		void InsWords(NodeOfLine LineRoot, char * str);//单词结点的插入
		
		void Caclulate(int * a, int * b, Function hashtable, OtherFunc Ot, NodeOfHash * hashTable[Hsize]);
		
		int FindWords(NodeOfLine LineRoot, char * str);//查找函数，在这个类似于字典树的树中查找单词 
		
		void HashTableInit(NodeOfHash * hashTable[Hsize]);//初始化哈希表的函数
		
		void UhashTableInit();//初始化另一个哈希表
		
		int HashTableStr(char * Key);//构造c++关键字的哈希函数
		
		int UHashTableStr(char * Key);//构造自定义标识符哈希表的函数 
		
		void HashTableInsert(char* Key, NodeOfHash * hashTable[Hsize]);//插入哈希表的操作
		
		void UHashTableInsert(char* Key);//另一个哈希表的插入 
		
		NodeOfHash * HashTableFind(char* Key, NodeOfHash * hashTable[Hsize]);//查找关键字位置 
		
		UserNode * UHashTableFind(char * Key);//自定义标识符在表中的查找 
		
		void UHashTablePrint();//打印自定义标识符的哈希表 
		
		void HashTablePrint(NodeOfHash * hashTable[Hsize]);//打印c++关键字哈希表
		
		void HashTableDelete();//删除哈希表(测试函数)
		
		int HashGet(int x, NodeOfHash * hashTable[Hsize]);//获取c++关键字权值
		
		int UHashGet(int x);//获取另一个用户自定义标识符哈希表的权值 
		
};




