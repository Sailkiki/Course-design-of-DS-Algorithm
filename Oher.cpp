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

//һ��û�õĺ��� 
void Time()
{
	system("cls");
	cout << "�������ڷ�����" << endl;
	for (int i = 0; i < 4; i++) 
	{
		Sleep(500);//��ͣ0.5s
		cout << ".";
	}
}

void OtherFunc::Welcome() 
{
	cout << "*******************************************" << endl;
	cout << "                                           " << endl;
	cout << "                                           " << endl;
	cout << "           Դ����������Լ��              " << endl;
	cout << "                                           " << endl;
	cout << "                                           " << endl;
	cout << "*******************************************" << endl;
	cout << "                                           " << endl;
	cout << "                                           " << endl;


	cout << "��ʾ �� 1��ʹ��֮ǰ�� ��ȷ���������ڵ��ļ�������Keywords.txt���ı��ļ�" << endl;
	cout << "        2, ��ȷ������������Դ������ı��ļ����ļ�����                 " << endl << endl;

	cout << "�������� �밴���������ʼ��⡣" << endl;

}

void OtherFunc::ProConnect1() 
{
	system("cls");
	cout << "����(1)�Ѿ�������ϣ�������ָ��鿴���" << endl;
	cout << "*****************************************" << endl;
	cout << "����1�鿴����1�Ĺ�ϣ��" << endl;
	cout << "����2��������(2)          " << endl << endl;
	cout << "������ָ��" << endl;
}

void OtherFunc::ProConnect2() 
{
	system("cls");
	cout << "����(2)�Ѿ�������ϣ� ������ָ��鿴���" << endl;
	cout << "*****************************************" << endl;
	cout << "����1�鿴����2�Ĺ�ϣ��" << endl;
	cout << "����2�鿴����Sֵ          " << endl << endl;
}

//��ʼ���� 
void OtherFunc::Start_F()
{
	Time();
	OtherFunc Ot;//����һ������
	Function hashtable;//����һ������
	char Word[Totle][MaxSizeOfWord]; //����һ������ؼ��ֵ�����,Ĭ��Ϊÿ�����ʲ�����10����ĸ
	char Word2[Utotle][MaxSizeOfWord]; //�û��Զ����ʶ�������� 
	NodeOfHash * hashTable[Hsize];//����c++�ؼ��ֵĽṹ��ָ������ 
	Ot.InitKeyWords_First(hashtable, Word, Word2, hashTable);//��һ�γ�ʼ���ؼ��ֵĹ�ϣ����ļ�1������ 
	Ot.DealKeyWords_First(hashtable, hashTable);//�����������������Ҵ������2 
	return;
}


void OtherFunc::DealKeyWords_First(Function &hashtable, NodeOfHash * hashTable[Hsize])
{
	//�ֱ����������,������ϣ��
	//��u�ľ���User��Ҳ�����û��Զ���ϵ�е� 
	int Num1 = 0;
	int UNum1 = 0;
	int Temp1[Hsize];
	int UTemp1[Usize];
	memset(Temp1, 0, sizeof(Hsize));//��������г�ʼ��
	memset(UTemp1, 0, sizeof(Usize)); 
	
	//�������������������þ��Ƿֱ������������Ȼ������е�Ȩֵ���뵽
	//�����У���������֮��ļ�������� 
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
	
	//����whileѭ��û��ʲô��˵�ģ�����������ָ����в����Ĳ��� 
	while (cin >> n)
	{
		if (n == 1) 
		{
			system("cls");
			cout << "����һ����Ϊ���½����(������c++�ؼ��ֺ��û��Զ����ʶ��)" << endl << endl;
			fflush(stdin);
			//���c++�ؼ��ֱ��״̬ 
			hashtable.HashTablePrint(hashTable);
			cout << "*****************************************" << endl;
			//����Զ����ʶ�����״̬ 
			hashtable.UHashTablePrint();
			cout << "����Y����" << endl;
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
					cout << "����������" << endl;
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
			cout << "������������, ����������" << endl;
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
			cout << "�ڶ�������Ĺ�ϣ���״̬���£�" << endl;
			hashtable.HashTablePrint(hashTable);
			cout << "*****************************************" << endl;
			hashtable.UHashTablePrint();
			cout << endl;
			cout << "����Y����" << endl;
			char s;
			while (cin >> s) 
			{
				if (s == 'Y')
				{
					ProConnect2();
					break;
				}
				else
					cout << "����������" << endl;
			}
		}

		else if (n == 2) 
		{
			cout << "����c++�ؼ�����˵,S��ֵΪ��" << endl;
			cout << sqrt(Num_1) << endl;		
			cout << "�����û��Զ��ı�ʶ��,S��ֵΪ��" << endl;
			cout << sqrt(UNum_1) << endl;
			
			cout << "����S��ֵ�Ľ���޷�ֱ�۵��жϳ���������������ԣ���Ϊ\n" 					
			    "������ó�S1(�ؼ���Ƶ��)Ϊ0ʱ��Ҳ���Ƕ��ڹؼ�����\n" 					
				"˵�����ֵ�Ƶ��һģһ����ʱ�������ʱS2��ֵΪ�ܴ�ܴ�\n" 					
				"��ʱ���ǾͿ��Է���������ʹ����������c++�ؼ���һģһ��\n" 					
				"�����û��Զ���Ĺؼ���ȴ������ɣ���ô��Ҳ��Ϊ���ǵ�����\n" 					
				"��Ϊ0�����Լ�����������������Ե����ƶȸ��ʣ��������\n" 					
				"�Ƚ�ֱ��һЩ��" << endl << endl; 
			cout << "���������ɵõ�����������һ���� " << Species << " �ֹ�\n"
			    "������ͬ�����У��� " << Species << " �ֹؼ���ռ����1�ؼ���\n"
				"����������%" << 100*trans1 << ", ռ����2��%" << 100*trans2<<"\n"
				"����Ƶ��(���ִ���)��˵����Щ�ظ��Ĺؼ����ڳ���1��ռ����1�ܳ�\n"
				"���%" << 100*trans3 << ", ռ����2���ܹؼ��ָ�����%"<< 100*trans4 <<"\n"
				<<endl;   
			
			/*���������Լ����һ���ۺ��ĸ������жϳ������ƶȵİ취����֪��������׼ȷ*/
			cout << "����������ϵͳ�����Ľ����ǣ�" << endl;
			if (100*trans1 == 100*trans2 && 100*trans3 == 100*trans4)
			{
				cout << "��������һģһ����" << endl;
			}
			
			else if (abs(100*trans1 - 100*trans2) <= 10 && abs(100*trans3 - 100*trans4) <= 10 && abs(100*trans1 - 100*trans2) && abs(100*trans3 - 100*trans4))
			{
				cout << "��������ǳ�����" << endl<< endl;
			}
			
			else if (abs(100*trans1 - 100*trans2) <= 20 && abs(100*trans1 - 100*trans2) > 10 && abs(100*trans3 - 100*trans4) > 10 && abs(100*trans3 - 100*trans4) <= 20)
			{
				cout << "����������΢����" << endl<< endl;
			}

			else
			{
				cout << "������������" << endl<< endl;
			}
			cout << "����Y����" << endl;
			char s;
			while (cin >> s) 
			{
				if (s == 'Y')
				{
					ProConnect2();
					break;
				}
				else
					cout << "����������" << endl;
			}
		}

		else 
		{
			cout << "������������, ����������" << endl;
		}
	}
}

void OtherFunc::InitKeyWords_First(Function &hashtable, char (*Word) [MaxSizeOfWord], char (*word2) [MaxSizeOfWord], NodeOfHash * hashTable[Hsize])
{
	//���ȶ�������г�ʼ�� 
	for (int i = 0; i < Totle; i++)
	{
		for (int j = 0; j < MaxSizeOfWord; j++)
		{
			Word[i][j] = 0;
		}
	}
	//������������ȡ�ļ��Ĳ����� 
	FILE * fp;
	fp = fopen("keywords.txt", "r");//���ж��ļ�����
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
	
	//����һ�������������Ľ�� 
	NodeOfLine LineRoot = NULL;
	NodeOfLine ULineRoot = NULL;
	//�Խ����г�ʼ��
	LineRoot = hashtable.Create();
	ULineRoot = hashtable.Create();
	if (LineRoot == NULL || ULineRoot == NULL)
	{
		cout << "Fall!" << endl;
	}
	
	for (int i = 0; i < Totle; i++) 
	{
		//�����в��뵥�ʣ����������ǽ�������ĸ��һ���롣 
		hashtable.InsWords(LineRoot, Word[i]);
	}
	
	for (int i = 0; i < Utotle; i++)
	{
		//�����в��뵥��
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
		cout << "���ļ�ʧ��" <<endl;
		exit(0);
	}
	//�������� 
	char word1[MaxSizeOfWord];
	//�м�ֵ��������ʱ���� 
	int i = 0;
	int Tar = 0;
	while ( (ch1 = getc(fp1) ) != EOF )
	{
		//ע�⣬������Դ������ļ��У�������������һ���س�����ô�ſɰ���ƪ��ȫ��ȡ������ͣ�������һ�С� 
		//��¼���ʵ���ʱ���顣 
		if ( (ch1 >= 'a') && (ch1 <= 'z') ) 
		{
			word1[i++] = ch1;
			Tar++;
		}
		
		//������Զ�ȡ���Ļ����������ʵķ�֧ 
		else if ( (word1[0] >= 'a') && (word1[0] <= 'z') )
		{
			/*���ڵ��Ե�ʱ����ֺܶ൥�ʶ�ȡ���֮����ȡstrlenֵ�ܻ���һ������
			������ܷ�����˼����ʱ�ᣬ��ʱ�Ͳ��ᣬ����Ϊ�˽��������⣬��ֻ��������
			һ���м����Tar,�����ж��Ƿ��STRLEN���ֵ��ȣ��������ȣ���ô���жԶ���
			��Ԫ�ظ�ֵΪ'\0'��һ�������������ʾͻᱻ���ȥ���Ӷ�������һ���������Ȼ
			�Ļ���������ʳ��Ȳ�ƥ�䣬���޷�����ʶ��ģ������ܻ����*/
			if (Tar != strlen(word1))
			{
				word1[Tar] = '\0';
				word1[Tar+1] = '\0';
			}
			//������Զ�ȡ�����ʵĻ�
			if (hashtable.FindWords(LineRoot, word1))
			{
				//��ôʹ�ñ�ɢ�б�ķ�ʽ��ʼ�����ʡ�
				hashtable.HashTableFind(word1, hashTable);
			}
			
			if (hashtable.FindWords(ULineRoot, word1))
			{
				hashtable.UHashTableFind(word1);
			}
			
			i = 0;//ÿ�δ����굥����Ҫ������� 
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
		cout << "�ر�ʧ��" << endl;
		exit(1);
	}
}

void OtherFunc::InitKeyWords_Second(int * a, int * b, NodeOfHash * hashTable[Hsize])
{
	OtherFunc Ot;
	Function hashtable;//����һ������
	char Words[Totle][MaxSizeOfWord];                                 //����һ���洢�ؼ��ֵĶ�ά����
	char Words2[Utotle][MaxSizeOfWord];
	for (int i = 0; i < Totle; i++)
	{
		for (int j = 0; j < MaxSizeOfWord; j++)
		{
			Words[i][j] = 0;
		}
	}
	
	//c������ʽ���ļ�����Ҫ��c++������ܶ࣬��Ȼ��
	//�������ּ򵥵�ֻ��������ʱ�� 
	FILE * fp;                                               //�����ļ�ָ��
	fp = fopen("keywords.txt", "r");                         //�򿪴洢C++�ؼ��ֵ��ļ�	
	for (int i = 0; i < Totle; i++) 
	{                                                        
		if (fscanf(fp, "%s", Words[i]) != 1)               
		{
			break;
		}
	}
	fclose(fp);                                              //�ر��ļ�ָ��
	
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
	
	//�ֱ�Ե��ʽ��н����νṹ�Ĳ����� ������ͼ��ĵ� 
	NodeOfLine LineRoot = NULL;                                  //����һ�����ڵ�
	NodeOfLine ULineRoot = NULL;
	LineRoot = hashtable.Create();  							//��ʼ��
	ULineRoot = hashtable.Create();
	
	if (LineRoot == NULL || ULineRoot == NULL)
	{                                        //������ڵ�ָ��Ϊ��  ������ʧ��
		cout << "Fall!" << endl;
	}
	
	for (int i = 0; i < Totle; i++) 
	{
		//��ʼѭ������ 
		hashtable.InsWords(LineRoot, Words[i]);
	}
	
	for (int i = 0; i < Utotle; i++)
	{
		hashtable.InsWords(ULineRoot, Words2[i]);
	}
	
	//�ܱ�Ҫ�Ĳ��裬�������������ٽ��г�ʼ��һ�Σ����������ڷ�������2��ʱ�� 
	hashtable.HashTableInit(hashTable);                                       //��ʼ����ϣ��
	hashtable.UhashTableInit();
	
	//�ֱ���в��� 
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
	//ѭ����ȡ���� 
	while ( (ch1 = getc(fp1)) != EOF ) 
	{
		if ( (ch1 >= 'a') && (ch1 <= 'z') ) 
		{
			words1[i++] = ch1;
		}
		
		else if ( (words1[0] >= 'a') && (words1[0] <= 'z') ) 
		{
			//����������ҵ���������ʣ���ô HashTableFind �� UHashTableFind
			//��ʼ�Ե��ʽ��в��뵽���еĲ����� �����������Ǻܹ淶�� 
			if (hashtable.FindWords(LineRoot, words1))
			{
				hashtable.HashTableFind(words1, hashTable);
			}
			
			if (hashtable.FindWords(ULineRoot, words1))
			{
				hashtable.UHashTableFind(words1);
			}
			
			i = 0;
			
			//������������³�ʼ�� 
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
	
	hashtable.Caclulate(a, b, hashtable, Ot, hashTable);//���㺯��������1Ϊ���󣬲���2Ϊ����3Ϊ���� 
	
	//����ܴ�һ�������ظ�����Ĺ��������ע�ͼ����� 
//	int Num2 = 0;
//	int UNum2 = 0;
//	int Temp2[Hsize];
//	int UTemp2[Usize];
//	memset(Temp2, 0, sizeof(Hsize));
//	memset(UTemp2, 0, sizeof(Usize));
//	
//	for (int i = 0; i < Hsize; i++) 
//	{
//		/*��ʼ�ѳ�ͻ����(Ȩֵ)������������*/
//		Temp2[Num2++] = hashtable.HashGet(i, hashTable);
//	}
//	
//	for (int i = 0; i < Usize; i++)
//	{
//		/*��ʼ�ѳ�ͻ����(Ȩֵ)������������*/
//		UTemp2[UNum2++] = hashtable.UHashGet(i);
//	}
//	
//
//	int Num_1 = 0;
//	int UNum_1 = 0;
//	
//	for (int i = 0; i < Hsize; i++) 
//	{
//		/*����һ���жϣ����û��Զ���Ĺؼ��ֳ�ͻ������c++�ؼ��ֳ�ͻ������С��
//		���߽�ʱ����ô���������*/
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
//	//�Գ�����о�ȷ���� 
//	int Species = 0;//���������е��ظ����� 
//	int F_Total = 0;//����1���ֵĹؼ����ܸ��� 
//	int F_Species = 0;//����1���ֵĹؼ��������� 
//	int S_Total = 0;//����2���ֵĹؼ����ܸ��� 
//	int S_Species = 0;//����2���ֵĹؼ��������� 
//	//�����ظ��Ĺؼ��ֱַ��ڸ��Եĳ����г��ֵĴ��������ڼ���Ƶ�ʡ� 
//	int T1_Species = 0;
//	int T2_Species = 0;
//	
//	for (int i = 0; i < Hsize; i++)
//	{
//		F_Total += a[i];//����1�ؼ��ָ��� 
//		S_Total += Temp2[i];//����2�ؼ����ܸ��� 
//		
//		if (a[i]!=0&&Temp2[i]!=0)
//		{
//			Species++;//�ظ���������
//			T1_Species+=a[i];//����Ѵ���Ҳ���ȥ�ˣ������������࣬��ͬ�����ֵĴ�����T����TOTAL��
//			//Ҫ��������ѭ����Ҳ������Щ���еı�����������ͬc++�ؼ��ֺ��û��Զ����һ�����ϡ����ܷ����� 
//			T2_Species+=Temp2[i];
//		}
//		
//		if (a[i]!=0)
//		{
//			F_Species++;//����1�ؼ������� 
//		}
//		
//		if (Temp2[i] !=0)
//		{
//			S_Species++;//����2�ؼ������� 
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
//			T1_Species+=b[i];//����Ѵ���Ҳ���ȥ�ˣ������������࣬��ͬ�����ֵĴ�����T����TOTAL�� 
//			T2_Species+=UTemp2[i];
//		}
//		
//		if (b[i]!=0)
//		{
//			F_Species++;//����1�ؼ������� 
//		}
//		
//		if (UTemp2[i] !=0)
//		{
//			S_Species++;//����2�ؼ������� 
//		}
//	}
//	
//	//�ظ�����ռ1�������� 
//	double trans1 = (double)Species/F_Species;//�����ʣ�������ֵ�Ƶ�� 
//	double trans2 = (double)Species/S_Species;//�����ʣ�������ֵ�Ƶ�� 
//	
//	double trans3 = (double)T1_Species/F_Total;//Ƶ�ʣ������˳��ֵĴ��� 
//	double trans4 = (double)T2_Species/S_Total;//Ƶ�ʣ������˳��ֵĴ��� 
//	system("pause");
//	ProConnect2();
//	Ot.DealKeyWords_Second(hashtable, Num_1, UNum_1, Species, trans1, trans2, trans3, trans4, hashTable);
}

