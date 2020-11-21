#pragma once
#define Usize 31 //4*7+3�Զ���� 
#define Utotle 26 //�Զ���ؼ��ָ��� 
#define Hsize 67//�����c++��ϣ�����ܳ��� 
#define Totle 59//c++�ؼ��ָ��� 
#define Letter 26//26��Ӣ����ĸ 
#define MaxSizeOfWord 10 //����������10 
/*�Զ����û���ʶ���ṹ�壬�����������ϣ����Լ��������Ƕ�������������˵��������
�����б�Ҫ��c++�ؼ��֣���Ҫ��������Զ���ؼ��֣�

��һ������

������������һ���ǡ�С��Ӣ���ʵ䡱����һ���ǡ��Թ���Ϸ�������У��������򾭹�����
�����磬 c++�ؼ���ֻ���� void int double ������(̫���ˣ����Ǻ�ǡ��), ��ô���ˣ���
���ò����Զ����ʶ���ĳ������㣬���ƶȿ϶���100%�ˣ� �ܻ��ƣ����������㷨����һ����
���� ���ƶ���ô������100�أ� ���������Ҫ���ǰ�c++�ؼ��ֵ�Ƶ�Ⱥ��Զ���ؼ��ֵ�Ƶ��
�໥�Ƚϴ������ó��������ˣ� ��Ȼ��д��ֻ�������ͬ�ֵĳ��������������Թ���Ϸ��
�������ǿ��ܻᶨ�塰Maze��, ��DFS��, "Search", ��Start���ȵȵĹؼ��֣��������Ǿͽ���
���ֵ��ļ��� �Լ��ṹ��Գ�����д���

����������ԭ���c++�ؼ��ֵ���һ���ģ�û��ʲô����֮����*/

class OtherFunc;

typedef struct  UserIdentifier
{
	int UValue;
	char * UKey;
	UserIdentifier(): UValue(0), UKey(NULL){}
}UserNode;

/*����ṹ����ʵ����������һ��(ǰ׺��)�ֵ��������ã�����û���ֵ������Ĺ�������
��������������һ�ֹ�ϣ���ı��֣������˺ܶ಩�ͣ�һ����˵��ϣ��������ֽṹ��ʹ�� 
����ͳ�ƺ�����������ַ��������кܴ��ô���ҪҪ�ȵ���ʹ�ù�ϣ���������Ļ�Ч�ʸ߳�
�ܶ࣬ͬʱҲ���ӽ�ʡ�ռ䡣*/ 
typedef struct WordsLine
{ //�������浥�ʵĽṹ��
	int SUM;//���������������ж�ѭ���������ĸ�Ƿ�������������һ���ؼ��ֵ��� 
	struct WordsLine * Bond[Letter];//������㣬��СΪ26��Ӣ����ĸ�ĸ���
	WordLine(){//��ʼ������ 
		SUM = 0;
		memset(Bond, 0, sizeof(WordsLine * ) * Letter);
	}
} Line, * NodeOfLine;

//c++�ؼ��ֹ�ϣ��Ľṹ�壬��������û��Զ���ĺ����д��һ�𣬽�������á� 
typedef struct NodeOfHashTable
{
	int WordsValue;//Ȩֵ�� �������Ѿ����ļ��и���
	char * Key;//���ǹ�ϣ���еĹؼ���
	NodeOfHashTable(): WordsValue(0), Key(NULL) {}//��ʼ������ 
} NodeOfHash;

//���๦���ͺ������� 
class Function{
	
	protected:
		
		friend InitKeyWords_Second(int * a, int * b, NodeOfHash * hashTable[Hsize]);
		
		friend DealKeyWords_Second(Function &hashtable, int Num_1, int UNum_1, int Species, double trans1, double trans2, double trans3, double trans4, NodeOfHash * hashTable[Hsize]);
		
		friend InitKeyWords_First(Function &hashtable, char (*Word) [MaxSizeOfWord], char (*word2) [MaxSizeOfWord], NodeOfHash * hashTable[Hsize]);
		
		friend DealKeyWords_First(Function &hashtable, NodeOfHash * hashTable[Hsize]);
		/*��������UhashTable����hashTable����������Ϊʲô��ͬʱд���������ͬʱֱ�ӵ��������ڳ����н���
		���ݡ��� ��ʵ�����ԣ�ֻ����Ҫ�����������Ļ���ôǰ��ĺ����������ϳ��ˣ�����̫�鷳�����Ծ���һ��
		���鶨�����������棬��֮������ȫ�ֱ���������*/
	public:
		UserNode * UhashTable[Usize];
		//��ǰ�� 
		int UTableSize;
		int TableSize;
	public:
		
		
		Function();//�޲ι��캯���������Ƕ����������������г�ʼ�� 
		
		Function(char* Key);//�вι��캯��(���Ժ���)
		
		Line * Create();//�������ʵĸ����������������Ľ���
		
		void InsWords(NodeOfLine LineRoot, char * str);//���ʽ��Ĳ���
		
		void Caclulate(int * a, int * b, Function hashtable, OtherFunc Ot, NodeOfHash * hashTable[Hsize]);
		
		int FindWords(NodeOfLine LineRoot, char * str);//���Һ�����������������ֵ��������в��ҵ��� 
		
		void HashTableInit(NodeOfHash * hashTable[Hsize]);//��ʼ����ϣ��ĺ���
		
		void UhashTableInit();//��ʼ����һ����ϣ��
		
		int HashTableStr(char * Key);//����c++�ؼ��ֵĹ�ϣ����
		
		int UHashTableStr(char * Key);//�����Զ����ʶ����ϣ��ĺ��� 
		
		void HashTableInsert(char* Key, NodeOfHash * hashTable[Hsize]);//�����ϣ��Ĳ���
		
		void UHashTableInsert(char* Key);//��һ����ϣ��Ĳ��� 
		
		NodeOfHash * HashTableFind(char* Key, NodeOfHash * hashTable[Hsize]);//���ҹؼ���λ�� 
		
		UserNode * UHashTableFind(char * Key);//�Զ����ʶ���ڱ��еĲ��� 
		
		void UHashTablePrint();//��ӡ�Զ����ʶ���Ĺ�ϣ�� 
		
		void HashTablePrint(NodeOfHash * hashTable[Hsize]);//��ӡc++�ؼ��ֹ�ϣ��
		
		void HashTableDelete();//ɾ����ϣ��(���Ժ���)
		
		int HashGet(int x, NodeOfHash * hashTable[Hsize]);//��ȡc++�ؼ���Ȩֵ
		
		int UHashGet(int x);//��ȡ��һ���û��Զ����ʶ����ϣ���Ȩֵ 
		
};




