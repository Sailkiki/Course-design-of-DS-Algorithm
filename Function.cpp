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
#define Hsize 67//��ϣ�����ܳ���
#define MaxBoard 200
#define Prime 61
#define Uprime 29
using namespace std;



//�Ե�ǰ�����г�ʼ�� 
Function::Function()
{
	memset(UhashTable, 0, sizeof(UserNode*) * Usize);
	TableSize = 0;
	UTableSize = 0;
}

//���㺯�� 
void Function::Caclulate(int * a, int * b, Function hashtable, OtherFunc Ot, NodeOfHash * hashTable[Hsize])
{
	int Num2 = 0;//����ļ����� 
	int UNum2 = 0;//����ļ����� 
	int Temp2[Hsize];
	int UTemp2[Usize];
	memset(Temp2, 0, sizeof(Hsize));
	memset(UTemp2, 0, sizeof(Usize));
	
	for (int i = 0; i < Hsize; i++) 
	{
		/*��ʼ�ѳ�ͻ����(Ȩֵ)������������*/
		Temp2[Num2++] = hashtable.HashGet(i, hashTable);
	}
	
	for (int i = 0; i < Usize; i++)
	{
		/*��ʼ�ѳ�ͻ����(Ȩֵ)������������*/
		UTemp2[UNum2++] = hashtable.UHashGet(i);
	}
	

	//��������������Ŀ�е�Ҫ����s��ֵ�� �ֱ���c++�ؼ��ֺ��û��Զ����ʶ���� 
	int Num_1 = 0;
	int UNum_1 = 0;
	
	for (int i = 0; i < Hsize; i++) 
	{
		/*����һ���жϣ����û��Զ���Ĺؼ��ֳ�ͻ������c++�ؼ��ֳ�ͻ������С��
		���߽�ʱ����ô���������*/
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
	
	//�Գ�����о�ȷ���� 
	int Species = 0;//���������е��ظ����� 
	int F_Total = 0;//����1���ֵĹؼ����ܸ��� 
	int F_Species = 0;//����1���ֵĹؼ��������� 
	int S_Total = 0;//����2���ֵĹؼ����ܸ��� 
	int S_Species = 0;//����2���ֵĹؼ��������� 
	//�����ظ��Ĺؼ��ֱַ��ڸ��Եĳ����г��ֵĴ��������ڼ���Ƶ�ʡ� 
	int T1_Species = 0;
	int T2_Species = 0;
	
	for (int i = 0; i < Hsize; i++)
	{
		F_Total += a[i];//����1�ؼ��ָ��� 
		S_Total += Temp2[i];//����2�ؼ����ܸ��� 
		
		if (a[i]!=0&&Temp2[i]!=0)
		{
			Species++;//�ظ���������
			T1_Species+=a[i];//����Ѵ���Ҳ���ȥ�ˣ������������࣬��ͬ�����ֵĴ�����T����TOTAL��
			//Ҫ��������ѭ����Ҳ������Щ���еı�����������ͬc++�ؼ��ֺ��û��Զ����һ�����ϡ����ܷ����� 
			T2_Species+=Temp2[i];
		}
		
		if (a[i]!=0)
		{
			F_Species++;//����1�ؼ������� 
		}
		
		if (Temp2[i] !=0)
		{
			S_Species++;//����2�ؼ������� 
		}
	}
	
	for (int i = 0; i < Usize; i++)
	{
		F_Total += b[i];
		S_Total += UTemp2[i];
		
		if (b[i]!=0&&UTemp2[i]!=0)
		{
			Species++;
			T1_Species+=b[i];//����Ѵ���Ҳ���ȥ�ˣ������������࣬��ͬ�����ֵĴ�����T����TOTAL�� 
			T2_Species+=UTemp2[i];
		}
		
		if (b[i]!=0)
		{
			F_Species++;//����1�ؼ������� 
		}
		
		if (UTemp2[i] !=0)
		{
			S_Species++;//����2�ؼ������� 
		}
	}
	
	//�ظ�����ռ1�������� 
	double trans1 = (double)Species/F_Species;//�����ʣ�������ֵ�Ƶ�� 
	double trans2 = (double)Species/S_Species;//�����ʣ�������ֵ�Ƶ�� 
	
	double trans3 = (double)T1_Species/F_Total;//Ƶ�ʣ������˳��ֵĴ��� 
	double trans4 = (double)T2_Species/S_Total;//Ƶ�ʣ������˳��ֵĴ��� 
	system("pause");
	Ot.ProConnect2();
	Ot.DealKeyWords_Second(hashtable, Num_1, UNum_1, Species, trans1, trans2, trans3, trans4, hashTable);
}



int Function::HashTableStr(char * Key)
{
	char * p = Key;//����ָ��ָ����ַ���
	int h;
	int num = strlen(Key);
	/*�ؼ���һ������һ�����ʵ�����ĸ��������ֺ�β��ĸ���������
	��Ӻ��һ��С�ڱ��Ĳ�����������������Ϊģֵ��������ȡģ��
	 */
	 //����ȡ�෨ 
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

//���û��Զ����ʶ���Ĺؼ��ֽ��в������ 
void  Function::UHashTableInsert(char * Key)
{
	//��������ؼ��ֳ��ֵ�λ�ã��ڱ��� 
	int Pos = UHashTableStr(Key);
	UserNode * pHead = UhashTable[Pos];
	int SquareNum = 1;
	int Flag = 0;
	int k = Pos;
	//��������㲻�ǿյĻ� 
	while (pHead)
	{
		//����һ���жϣ�������λ��û��Ԫ��
		/*��Ҫע����ǣ����������������һ��ΪNULL�Ļ�����ô����ͻ���ֶδ���
		�������������������������ṹ��ָ�����鶼����Ϊȫ�ֱ����Ͳ����ˣ�����
		������ȫ�ֱ�������ô�������һ���������ʵ���ʱ����г�ʼ����(��Ϊ��������)
		��һ�����飬��һ�������������������ʱ����Ҫ��ǰ���޲ι��캯���н���
		һ����ʼ���Ĳ���(�����������������)*/ 
		if (strcmp(pHead->UKey, Key) == 0)
		{
			return;
		}
		
		//Flag�Ǳ��ֵ����Ϊ����/�������е�һ���ж�ֵ��ż�����Ҳ�
		//����������룬����Ƕ���̽�ⷨ�� 
		if (Flag % 2 == 0)
		{
			k = Pos + pow(SquareNum, 2);
			//���벻�����ǵ�һ�������k�ȱ�����ô�������ȡ�������� 
			if (k > Hsize)
			{
				k = k % Usize;
			}
			//���µĽ�㸳ֵPhead 
			pHead = UhashTable[k];
			Flag++;
		}
		//�����Ļ�����ô����� 
		else
		{
			k = Pos - pow(SquareNum, 2);
			//��������һ�ȳ��ִ��󣬣�û���ҵ��������±겻��Ϊ������ 
			if (k < 0)
			{
				k = k + Usize;
			}
			
			pHead = UhashTable[k];
			Flag++;
			SquareNum++;
		}
	}
	UserNode * pNewNode = new UserNode;//����һ���½ڵ㣬��������ռ�
	//�������ľ��Ǹ��ؼ��ַ���ռ䣬��Ȼ��֮��Ĳ����У��ͻ�
	//������������³������ 
	pNewNode->UKey = (char*)malloc(sizeof(char));
	//��ֵ���Ѻ��߸�ֵ��ǰ�� 
	strcpy(pNewNode->UKey, Key);
	//���µĽ�㸳ֵ���������д���Ľ�� 
	UhashTable[k] = pNewNode;
}


void Function::HashTableInsert(char * Key, NodeOfHash * hashTable[Hsize])
{
	int Pos = HashTableStr(Key);//ʹ�ù�ϣ�����������������
	NodeOfHash * pHead = hashTable[Pos];//����ָ��ָ�������Ľڵ�
	int SquareNum = 1; 
	int Flag = 0;
	int k = Pos;//ΪʲôҪ��������Squarenum(����sq��ʾ)��flag?
	/*���ڶ���̽�ⷨ˵���˾���������ͬʱ�������ݣ������Ҷ�����������ֵsq��flag
	һ��ʼ��ֵ�ֱ�Ϊ������ż��������sq��Ϊ�Ӽ��Ĺ���ֵ��flag��Ϊ�ж�����
	�Ĺ���ֵ ��sq��ƽ�����мӼ���������ȷ��kֵ����λ�ã��Ӷ����в��롣
	������ö���̽�ⷨ�������ͻ��˼��*/
	while (pHead)//��pHead���ڵ�ʱ��
	{
		if (strcmp(pHead->Key, Key) == 0)//����г�ͻ
		{
			return;
		}
		
		else if (Flag % 2 == 0)//���ȶ�j�����жϣ���jΪż����ʱ����ǰ��塣
		{
			k = Pos + pow(SquareNum, 2);
			if (k > Hsize)
			{
				k = k % Hsize;//���������ĳ��ȣ���ô��ǰ�濪ʼ�ҡ�
			}
			pHead = hashTable[k];
			Flag++;
		}
		//��ʱjΪ����, ��ô��ѡ������塣
		else
		{
			/*����һ��Ҫע�⣬���ҵ��Գ����ʱ��ѡȡ�˶���Ĵ�����бȽϣ��������Ƿ���һ�����⣬λ��
			�ӵ�47��λ�ÿ�ʼ��ʱ����������ѭ����������ϸ�������֪������һ���ǳ��ͼ��Ĵ����Ǿ���û��
			���ǵ�kΪ����������������±���ô����Ϊ�����أ��� ���Խ�����һ�� �жϴ��������ؽ��������
			��*/ 
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

	NodeOfHash* pNewNode = new NodeOfHash;//����һ���½ڵ㣬��������ռ�
	/*��������Ĺؼ��ַ���һ��ռ䣬 ��СΪchar���ͳ������ĳ���+1*/
	//�����������ռ� 
	pNewNode->Key = (char *) malloc(sizeof(char));
	
	strcpy(pNewNode->Key, Key);//���в���
	
	hashTable[k] = pNewNode;//����ϣ�������еĶ�Ӧ���ָ���µĽ��
	
}

UserNode * Function::UHashTableFind(char * Key)
{
	if (UhashTable[UHashTableStr(Key)])//��������ڵĻ���
	{
		UserNode * pHead = UhashTable[UHashTableStr(Key)];//����һ������ָ��ָ��������
		int SquareNum = 1, Flag = 0, k = UHashTableStr(Key);

		while (pHead)//������ڵĻ�
		{
			if (pHead->UKey != NULL)//���Ҫ���ҵĺ�ԭ�������
			{
				pHead->UValue++;//Ƶ����1��Ҳ���ǳ��ֵĴ��� 
				return pHead;
			}
		
			else if (Flag % 2 == 0)//�����֮ǰ��һ��������һ��
			{
				k = UHashTableStr(Key) + pow(SquareNum, 2);
				
				//��k���ڱ���ʱ�򣬱���Ҫ�Ա�ȡ�࣬���Ҳ���ԣ�����һ�� 
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
				//�����ж�k��ֵ�Ƿ�Ϊ������������򽫻ᷢ������ 
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

//�ڱ��н��в��ҵĺ�����ͬʱ����Ƶ������Ĳ����ĺ��� 
NodeOfHash * Function::HashTableFind(char* Key, NodeOfHash * hashTable[Hsize])
{
	int Pos = HashTableStr(Key);//Ѱ�ҹؼ���λ��
	if (hashTable[Pos])//��������ڵĻ���
	{
		NodeOfHash * pHead = hashTable[Pos];//����һ������ָ��ָ��������
		int SquareNum = 1, Flag = 0, k = Pos;
		
		while (pHead)//������ڵĻ�
		{
			//������ڵĻ� 
			if (strcmp(Key, pHead->Key) == 0)//���Ҫ���ҵĺ�ԭ�������
			{
				pHead->WordsValue++;//Ƶ����1��Ҳ���ǳ��ֵĴ��� 
				return pHead;
			}
			
			else if (Flag % 2 == 0)//�����֮ǰ��һ��������һ��
			{
				k = Pos + pow(SquareNum, 2);
				
				//��k���ڱ���ʱ�򣬱���Ҫ�Ա�ȡ�࣬���Ҳ���ԣ�����һ�� 
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
				//�����ж�k��ֵ�Ƿ�Ϊ������������򽫻ᷢ������ 
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


//��ӡ���� 
void Function::UHashTablePrint()
{
	cout << "���     �ؼ���  �ڳ����г��ֵĴ��� " << endl;
	
	for (int i = 0; i < Usize; i++)//��ͷ��β����hash��
	{
		if (i == 17)
		{
			continue;
		}
		
		if (UhashTable[i])
		{
			printf("%4d :", i);//��ӡ�ڵ����
			printf("%9s:  %4d ", UhashTable[i]->UKey, UhashTable[i]->UValue);
			cout << endl;
		}
	}
}

void  Function::HashTablePrint(NodeOfHash * hashTable[Hsize])
{
	cout << "���     �ؼ���  �ڳ����г��ֵĴ��� " << endl;
	for (int i = 0; i < Hsize; i++)//��ͷ��β����hash��
	{
		if (i == 48)
		{
			continue;
		}

		if (hashTable[i])
		{
			printf("%4d :", i);//��ӡ�ڵ����
			printf("%9s:  %4d ", hashTable[i]->Key, hashTable[i]->WordsValue);
			cout << endl;
		}
	}
}

//�û��Զ����ʶ��Ȩֵ���Һ��� 
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

//c++�ؼ���Ȩֵ���Һ��� 
int Function::HashGet(int x, NodeOfHash * hashTable[Hsize])
{
	//Ϊ�˽�ÿһ��hashtable���ָ��������Ԫ�ص�Ȩֵ����ֵ��һ�����飬�Ժ󷽱����㡣 
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

//��ʼ�����������ڵ� ������������ 
Line * Function::Create()
{
    Line * node = (Line*)malloc(sizeof(Line));
    memset(node, 0, sizeof(Line));
    return node;
}

//������ǰ׺���Ĳ�����������ͻ����ĵ��� 
void Function::InsWords(NodeOfLine LineRoot, char * str)
{
    if (LineRoot == NULL || *str == '\0')//���û���ַ������߸�����ǿ�
    {
        return;
    }

    Line * t = LineRoot;//������������ָ��
    char * p = str;
	
    while (*p != '\0') //���������û�н�����ʱ�� 
    {
        if (t->Bond[*p - 97] == NULL)
        {//�����ǰ�Ľ���ǿյĻ�����ô������һ����� 
            Line * tmp = Create();
            t->Bond[*p - 97] = tmp;
        }

        t = t->Bond[*p - 97];//��ֵ����һ��ָ�� 
        p++;//����ָ��������һλ
 
    }
    t->SUM++;
}

int Function::FindWords(NodeOfLine root, char * str)//�����ַ����Ƿ���������ʽṹ�� 
{
    if (root == NULL || *str == '\0')//��Ϊ�ջ����ַ����ǿյ�
    {
        cout << "����ʧ��" << endl;
        return 0;
    }

    char * p = str;//��������ָ��ָ���ַ�����λ
    Line * t = root;//����һ������ָ��

    while (*p != '\0')
    {
        if (t->Bond[*p - 97] != NULL)//�������ַ������в�Ϊ��
        {
            t = t->Bond[*p - 97];//��ôָ��ָ���ӽ��
            p++;//����ƶ��ַ���ָ��
        }

        else
        {
            break;
        }
    }
    
    if (*p == '\0')//����ַ���ָ���ƶ������ַ�����β
    {
        if (t->SUM == 0)//������������Ҷ��ĿΪ0
        {
            return 0;
        }

        else//���������Ҷ���
        {
            return 1;
        }
    }

    else
    {
        return 0;
    }
}

//������ʼ������ 
void Function::HashTableInit(NodeOfHash * hashTable[Hsize])
{
	memset(hashTable, 0, sizeof(NodeOfHash*) * Hsize);
}

void Function::UhashTableInit()
{
	memset(UhashTable, 0, sizeof(UserNode*) * Usize);
}

