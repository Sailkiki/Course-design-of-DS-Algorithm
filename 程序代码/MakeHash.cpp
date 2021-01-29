//#include <iostream>
//#include <cstdlib>
//#include <cstdio>
//#include <cmath>
//#include <string>
//#include <ctime>
//#include <cstring>
//#include <conio.h>
//#include <fstream>
//#include <windows.h>
//#include "MakeHash.h"
//#define MaxBoard 200
//using namespace std;
//#include "widget.h"
//#include "ui_widget.h"
//#include "ui_dialog.h"
//#include "ui_dialog2.h"
//#include "dialog.h"
//#include "dialog2.h"
//#include "dialogofwarn.h"
//#include "ui_dialogofwarn.h"
//#include "dialogofcppsym.h"
//#include "ui_dialogofcppsym.h"
//#include "customsym.h"
//#include "ui_customsym.h"
//#include "showcuston.h"
//#include "ui_showcuston.h"
//#include "afterdeal.h"
//#include "ui_afterdeal.h"
//#include <QFileDialog>
//#include <QDebug>
//#include <QProcess>
//#include <QTextCodec>
//#include <QWidget>
//void MakeHash::Start_F()
//{
//    qDebug() << "1" ;
//    MakeHash Ot;//声明一个对象
//    qDebug() << "2" ;
//    Function hashtable;//声明一个对象
//    qDebug() << "3" ;
//    char Word[Totle][MaxSizeOfWord]; //声明一个储存关键字的数组,默认为每个单词不超过10个字母
//    qDebug() << "4" ;
//    char Word2[Utotle][MaxSizeOfWord]; //用户自定义标识符的数组
//    qDebug() << "5" ;
//    NodeOfHash * hashTable[Hsize];//声明c++关键字的结构体指针数组
//    qDebug() << "6" ;
//    Ot.InitKeyWords_First(hashtable, Word, Word2, hashTable);//第一次初始化关键字的哈希表和文件1的内容
//    qDebug() << "7" ;
//    Ot.DealKeyWords_First(hashtable, hashTable);//处理上述函数，并且处理程序2
//    qDebug() << "8" ;
//    return;
//}


//void MakeHash::DealKeyWords_First(Function &hashtable, NodeOfHash * hashTable[Hsize])
//{
//    //分别定义两组变量,建立哈希表
//    //带u的就是User，也就是用户自定义系列的
//    int Num1 = 0;
//    int UNum1 = 0;
//    int Temp1[Hsize];
//    int UTemp1[Usize];
//    fflush(stdin);
//    memset(Temp1, 0, sizeof(Hsize));//对数组进行初始化
//    memset(UTemp1, 0, sizeof(Usize));

//    //下面这两个函数的作用就是分别遍历这两个表，然后把所有的权值存入到
//    //数组中，这样便于之后的计算操作。
//    for (int i = 0; i < Hsize; i++)
//    {
//        Temp1[Num1++] = hashtable.HashGet(i, hashTable);
//    }

//    for (int i = 0; i < Usize; i++)
//    {
//        UTemp1[UNum1++] = hashtable.UHashGet(i);
//    }
//}


//void MakeHash::InitKeyWords_First(Function &hashtable, char (*Word) [MaxSizeOfWord], char (*word2) [MaxSizeOfWord], NodeOfHash * hashTable[Hsize])
//{
//    //首先对数组进行初始化
//    for (int i = 0; i < Totle; i++)
//    {
//        for (int j = 0; j < MaxSizeOfWord; j++)
//        {
//            Word[i][j] = 0;
//        }
//    }
//    //下面是两个读取文件的操作。
//    FILE * fp;
//    fp = fopen("keywords.txt", "r");//进行读文件操作
//    for (int i = 0; i < Totle; i++)
//    {
//        if (fscanf(fp, "%s", Word[i]) != 1)
//        {
//            break;
//        }
//    }

//    fclose(fp);
//    //QT Qstring 转 char
//    QString qstr = ww.ui->lineEdit_3->text();
//    string ss = qstr.toStdString();
//    char * ptr;
//    QByteArray ba;
//    ba = qstr.toLatin1();
//    ptr = ba.data();

//    FILE * Ufp;
//    Ufp = fopen(ptr, "r");
//    for (int i = 0; i < Utotle; i++)
//    {
//        if (fscanf(Ufp, "%s", word2[i]) !=1)
//        {
//            qDebug() << word2[i] ;
//            qDebug() << "12333" ;
//            break;
//        }
//    }
//    fclose(Ufp);


//    //申请一个类似于树根的结点
//    NodeOfLine LineRoot = NULL;
//    NodeOfLine ULineRoot = NULL;
//    //对结点进行初始化
//    LineRoot = hashtable.Create();
//    ULineRoot = hashtable.Create();
//    if (LineRoot == NULL || ULineRoot == NULL)
//    {
//        cout << "Fall!" << endl;
//    }

//    for (int i = 0; i < Totle; i++)
//    {
//        hashtable.InsWords(LineRoot, Word[i]);
//    }

//    for (int i = 0; i < Utotle; i++)
//    {
//        hashtable.InsWords(ULineRoot, word2[i]);
//    }

//    hashtable.HashTableInit(hashTable);

//    for (int i = 0; i < Totle; i++)
//    {
//        hashtable.HashTableInsert(Word[i], hashTable);
//    }

//    for (int i = 0; i < Utotle; i++)
//    {
//        hashtable.UHashTableInsert(word2[i]);
//    }



//    FILE * fp1;
//    int ch1;

//    QString qstr2 = ww.ui->lineEdit->text();
//    char * ptr2;
//    QByteArray ba2;
//    ba2 = qstr2.toLatin1();
//    ptr2 = ba2.data();

//    if ((fp1 = fopen(ptr2, "r")) == NULL)
//    {
//        cout << "打开文件失败" <<endl;
//        exit(0);
//    }

//    char word1[MaxSizeOfWord];

//    int i = 0;
//    int Tar = 0;
//    while ( (ch1 = getc(fp1) ) != EOF )
//    {

//        if ( (ch1 >= 'a') && (ch1 <= 'z') )
//        {
//            word1[i++] = ch1;
//            Tar++;
//        }


//        else if ( (word1[0] >= 'a') && (word1[0] <= 'z') )
//        {

//            if (Tar != strlen(word1))
//            {
//                word1[Tar] = '\0';
//                word1[Tar+1] = '\0';
//            }

//            if (hashtable.FindWords(LineRoot, word1))
//            {

//                hashtable.HashTableFind(word1, hashTable);
//            }

//            if (hashtable.FindWords(ULineRoot, word1))
//            {
//                hashtable.UHashTableFind(word1);
//            }

//            i = 0;
//            Tar = 0;

//            for (int j = 0; j < 10; j++)
//            {
//                word1[j] = '\0';
//            }
//        }

//        else
//        {
//            for (int j = 0; j < 10; j++)
//            {
//                word1[j] = '\0';
//            }
//            i = 0;
//            Tar = 0;
//        }
//    }

//    if (fclose(fp1) != 0)
//    {
//        cout << "关闭失败" << endl;
//        exit(1);
//    }
//}


//void MakeHash::InitKeyWords_Second(int * a, int * b, NodeOfHash * hashTable[Hsize])
//{
//    MakeHash Ot;
//    Function hashtable;//声明一个对象
//    char Words[Totle][MaxSizeOfWord];                                 //声明一个存储关键字的二维数组
//    char Words2[Utotle][MaxSizeOfWord];
//    for (int i = 0; i < Totle; i++)
//    {
//        for (int j = 0; j < MaxSizeOfWord; j++)
//        {
//            Words[i][j] = 0;
//        }
//    }

//    //c语言形式的文件操作要比c++的流快很多，当然是
//    //进行这种简单的只读操作的时候
//    FILE * fp;                                               //声明文件指针
//    fp = fopen("keywords.txt", "r");                         //打开存储C++关键字的文件
//    for (int i = 0; i < Totle; i++)
//    {
//        if (fscanf(fp, "%s", Words[i]) != 1)
//        {
//            break;
//        }
//    }
//    fclose(fp);                                              //关闭文件指针

//    QString qstr1 = ww.ui->lineEdit_3->text();
//    char * ptr1;
//    QByteArray ba1;
//    ba1 = qstr1.toLatin1();
//    ptr1 = ba1.data();

//    FILE * Ufp;
//    Ufp = fopen(ptr1, "r");
//    for (int i = 0; i < Utotle; i++)
//    {
//        if (fscanf(Ufp, "%s", Words2[i]) != 1)
//        {
//            break;
//        }
//    }
//    fclose(Ufp);

//    //分别对单词进行建树形结构的操作。 具体解释见文档
//    NodeOfLine LineRoot = NULL;                                  //声明一个根节点
//    NodeOfLine ULineRoot = NULL;
//    LineRoot = hashtable.Create();  							//初始化
//    ULineRoot = hashtable.Create();

//    if (LineRoot == NULL || ULineRoot == NULL)
//    {                                        //如果根节点指向为空  即创建失败
//        cout << "Fall!" << endl;
//    }

//    for (int i = 0; i < Totle; i++)
//    {
//        //开始循环建立
//        hashtable.InsWords(LineRoot, Words[i]);
//    }

//    for (int i = 0; i < Utotle; i++)
//    {
//        hashtable.InsWords(ULineRoot, Words2[i]);
//    }

//    //很必要的步骤，对这两个数组再进行初始化一次，否则会出错，在分析程序2的时候
//    hashtable.HashTableInit(hashTable);                                       //初始化哈希表
//    hashtable.UhashTableInit();

//    //分别进行插入
//    for (int i = 0; i < Totle; i++)
//    {
//        hashtable.HashTableInsert(Words[i], hashTable);
//    }

//    for (int i = 0; i < Utotle; i++)
//    {
//        hashtable.UHashTableInsert(Words2[i]);
//    }

//    FILE* fp1;
//    int ch1;
//    /********************/
//    QString qstr = ww.ui->lineEdit_2->text();
//    char * ptr;
//    QByteArray ba;
//    ba = qstr.toLatin1();
//    ptr = ba.data();
//    /********************/

//    if ((fp1 = fopen(ptr, "r")) == NULL)
//    {
//        printf("Fall!");
//        exit(0);
//    }

//    char words1[MaxSizeOfWord];
//    int i = 0;
//    //循环读取单词
//    while ( (ch1 = getc(fp1)) != EOF )
//    {
//        if ( (ch1 >= 'a') && (ch1 <= 'z') )
//        {
//            words1[i++] = ch1;
//        }

//        else if ( (words1[0] >= 'a') && (words1[0] <= 'z') )
//        {
//            //如果在树中找到了这个单词，那么 HashTableFind 和 UHashTableFind
//            //开始对单词进行插入到表中的操作， 可能命名不是很规范。
//            if (hashtable.FindWords(LineRoot, words1))
//            {
//                hashtable.HashTableFind(words1, hashTable);
//            }

//            if (hashtable.FindWords(ULineRoot, words1))
//            {
//                hashtable.UHashTableFind(words1);
//            }

//            i = 0;

//            //对数组进行重新初始化
//            for (int j = 0; j < MaxSizeOfWord; j++)
//            {
//                words1[j] = '\0';
//            }
//        }

//        else
//        {
//            for (int j = 0; j < MaxSizeOfWord; j++)
//            {
//                words1[j] = '\0';
//            }
//            i = 0;
//        }
//    }

//    if (fclose(fp1) != 0)
//    {
//        printf("Fall!");
//        exit(1);
//    }

//    //下面很大一部分是重复上面的工作具体的注释见上文
//    int Num2 = 0;
//    int UNum2 = 0;
//    int Temp2[Hsize];
//    int UTemp2[Usize];
//    fflush(stdin);
//    memset(Temp2, 0, sizeof(Hsize));
//    memset(UTemp2, 0, sizeof(Usize));
//    fflush(stdin);

//    for (int i = 0; i < Hsize; i++)
//    {
//        Temp2[Num2++] = hashtable.HashGet(i, hashTable);
//    }

//    for (int i = 0; i < Usize; i++)
//    {
//        UTemp2[UNum2++] = hashtable.UHashGet(i);
//    }


//    int Num_1 = 0;
//    int UNum_1 = 0;

//    for (int i = 0; i < Hsize; i++)
//    {
//        if (a[i] < MaxBoard && Temp2[i] < MaxBoard)
//        {
//            Num_1 += pow((a[i] - Temp2[i]), 2);
//        }
//    }

//    for (int i = 0; i < Usize; i++)
//    {
//        if (b[i] < MaxBoard && UTemp2[i] < MaxBoard)
//        {
//            UNum_1 += pow((b[i] - UTemp2[i]), 2);
//        }
//    }

//    //对程序进行精确分析
//    int Species = 0;//两个程序共有的重复种类
//    int F_Total = 0;//程序1出现的关键字总个数
//    int F_Species = 0;//程序1出现的关键字总种类
//    int S_Total = 0;//程序2出现的关键字总个数
//    int S_Species = 0;//程序2出现的关键字总种类
//    //两种重复的关键字分别在各自的程序中出现的次数，便于计算频率。
//    int T1_Species = 0;
//    int T2_Species = 0;

//    for (int i = 0; i < Hsize; i++)
//    {
//        F_Total += a[i];//程序1关键字个数
//        S_Total += Temp2[i];//程序2关键字总个数

//        if (a[i]!=0&&Temp2[i]!=0)
//        {
//            Species++;//重复种类总数
//            T1_Species+=a[i];
//            T2_Species+=Temp2[i];
//        }

//        if (a[i]!=0)
//        {
//            F_Species++;//程序1关键字种类
//        }

//        if (Temp2[i] !=0)
//        {
//            S_Species++;//程序2关键字种类
//        }
//    }

//    for (int i = 0; i < Usize; i++)
//    {
//        F_Total += b[i];
//        S_Total += UTemp2[i];

//        if (b[i]!=0&&UTemp2[i]!=0)
//        {
//            Species++;
//            T1_Species+=b[i];
//            T2_Species+=UTemp2[i];
//        }

//        if (b[i]!=0)
//        {
//            F_Species++;//程序1关键字种类
//        }

//        if (UTemp2[i] !=0)
//        {
//            S_Species++;//程序2关键字种类
//        }
//    }

//    //重复种类占1的总种类
//    double trans1 = (double)Species/F_Species;//覆盖率：种类出现的频度
//    double trans2 = (double)Species/S_Species;

//    double trans3 = (double)T1_Species/F_Total;//频率，包括了出现的次数
//    double trans4 = (double)T2_Species/S_Total;
//    Ot.DealKeyWords_Second(hashtable, Num_1, UNum_1, Species, trans1, trans2, trans3, trans4, hashTable);
//}

//void MakeHash::DealKeyWords_Second(Function &hashtable, int Num_1, int UNum_1, int Species, double trans1, double trans2, double trans3, double trans4, NodeOfHash * hashTable[Hsize])
//{
//    qDebug() << Num_1 << " " << UNum_1 << " " << Species << " ";
//}

//Function::Function()
//{
//    memset(UhashTable, 0, sizeof(UserNode*) * Usize);
//    TableSize = 0;
//    UTableSize = 0;
//}

//int Function::HashTableStr(char * Key)
//{
//    char * p = Key;//工作指针指向的字符串
//    int h;
//    int num = strlen(Key);
//    h = ((p[0] - 97) * 100 + p[num - 1] - 97) % 61;
//    return h;
//}

//int Function::UHashTableStr(char * Key)
//{
//    char * p = Key;
//    int h;
//    int num = strlen(Key);
//    h = ((p[0] - 97) * 100 + p[num - 1] - 97) % 29;
//    return h;
//}


//void  Function::UHashTableInsert(char * Key)
//{

//    int Pos = UHashTableStr(Key);
//    UserNode * pHead = UhashTable[Pos];
//    int SquareNum = 1;
//    int Flag = 0;
//    int k = Pos;

//    while (pHead)
//    {

//        if (strcmp(pHead->UKey, Key) == 0)
//        {
//            return;
//        }


//        if (Flag % 2 == 0)
//        {
//            k = Pos + pow(SquareNum, 2);

//            if (k > Hsize)
//            {
//                k = k % Usize;
//            }

//            pHead = UhashTable[k];
//            Flag++;
//        }

//        else
//        {
//            k = Pos - pow(SquareNum, 2);

//            if (k < 0)
//            {
//                k = k + Usize;
//            }

//            pHead = UhashTable[k];
//            Flag++;
//            SquareNum++;
//        }
//    }
//    UserNode * pNewNode = new UserNode;


//    pNewNode->UKey = (char*)malloc(sizeof(char) * (strlen(Key) + 1));

//    strcpy(pNewNode->UKey, Key);

//    UhashTable[k] = pNewNode;
//}


//void  Function::HashTableInsert(char * Key, NodeOfHash * hashTable[Hsize])
//{
//    int Pos = HashTableStr(Key);
//    NodeOfHash * pHead = hashTable[Pos];
//    int SquareNum = 1, Flag = 0, k = Pos;

//    while (pHead)
//    {
//        if (strcmp(pHead->Key, Key) == 0)
//        {
//            return;
//        }

//        else if (Flag % 2 == 0)
//        {
//            k = Pos + pow(SquareNum, 2);
//            if (k > Hsize)
//            {
//                k = k % Hsize;
//            }
//            pHead = hashTable[k];
//            Flag++;
//        }

//        else
//        {

//            k = Pos - pow(SquareNum, 2);
//            if (k < 0)
//            {
//                k = k + Hsize;
//            }
//            pHead = hashTable[k];
//            Flag++;
//            SquareNum++;
//        }
//    }

//    NodeOfHash* pNewNode = new NodeOfHash;

//    pNewNode->Key = (char*)malloc(sizeof(char) * (strlen(Key) + 1));

//    strcpy(pNewNode->Key, Key);

//    hashTable[k] = pNewNode;//将哈希表数组中的对应结点指向新的结点

//}

//UserNode * Function::UHashTableFind(char * Key)
//{
//    int Pos = UHashTableStr(Key);//寻找关键字位置
//    if (UhashTable[Pos])//如果他存在的话。
//    {
//        UserNode * pHead = UhashTable[Pos];//声明一个工作指针指向这个结点
//        int SquareNum = 1, Flag = 0, k = Pos;

//        while (pHead)//如果存在的话
//        {
//            if (pHead->UKey!=NULL)//如果要查找的和原来的相等
//            {
//                pHead->UValue++;//频数加1，也就是出现的次数
//                return pHead;
//            }

//            else if (Flag % 2 == 0)//这里跟之前上一个函数的一样
//            {
//                k = Pos + pow(SquareNum, 2);

//                //当k大于表长的时候，必须要对表长取余，相减也可以，道理一样
//                if (k > Hsize)
//                {
//                    k = k % Hsize;
//                }

//                pHead = UhashTable[k];
//                Flag++;
//            }

//            else
//            {
//                k = Pos - pow(SquareNum, 2);

//                if (k < 0)
//                {
//                    k = k + Hsize;
//                }
//                pHead = UhashTable[k];
//                Flag++;
//                SquareNum++;
//            }
//        }
//    }
//    return NULL;
//}


//NodeOfHash * Function::HashTableFind(char* Key, NodeOfHash * hashTable[Hsize])
//{
//    int Pos = HashTableStr(Key);//寻找关键字位置
//    if (hashTable[Pos])//如果他存在的话。
//    {
//        NodeOfHash * pHead = hashTable[Pos];//声明一个工作指针指向这个结点
//        int SquareNum = 1, Flag = 0, k = Pos;

//        while (pHead)//如果存在的话
//        {
//            //如果存在的话
//            if (strcmp(Key, pHead->Key) == 0)//如果要查找的和原来的相等
//            {
//                pHead->WordsValue++;//频数加1，也就是出现的次数
//                return pHead;
//            }

//            else if (Flag % 2 == 0)//这里跟之前上一个函数的一样
//            {
//                k = Pos + pow(SquareNum, 2);


//                if (k > Hsize)
//                {
//                    k = k % Hsize;
//                }

//                pHead = hashTable[k];
//                Flag++;
//            }

//            else
//            {
//                k = Pos - pow(SquareNum, 2);

//                if (k < 0)
//                {
//                    k = k + Hsize;
//                }
//                pHead = hashTable[k];
//                Flag++;
//                SquareNum++;
//            }
//        }
//    }
//    return NULL;
//}

////打印函数
//void Function::UHashTablePrint()
//{
//    cout << "序号     关键字  在程序中出现的次数 " << endl;

//    for (int i = 0; i < Usize; i++)//从头到尾遍历hash表
//    {
//        if (i == 17)
//        {
//            continue;
//        }

//        UserNode * pHead = UhashTable[i]; //定义工作指针指向每个结点

//        if (pHead)
//        {
//            printf("%4d :", i);//打印节点序号
//            printf("%9s:  %4d ", pHead->UKey, pHead->UValue);
//            cout << endl;
//        }
//    }
//}

//void  Function::HashTablePrint(NodeOfHash * hashTable[Hsize])
//{
//    cout << "序号     关键字  在程序中出现的次数 " << endl;
//    for (int i = 0; i < Hsize; i++)//从头到尾遍历hash表
//    {
//        if (i == 48)
//        {
//            continue;
//        }

//        NodeOfHash * pHead = hashTable[i]; //定义工作指针指向每个结点

//        if (pHead)
//        {
//            printf("%4d :", i);//打印节点序号
//            printf("%9s:  %4d ", pHead->Key, pHead->WordsValue);
//            cout << endl;
//        }
//    }
//}


//int Function::UHashGet(int x)
//{
//    for (int i = 0; i < Usize; i++)
//    {
//        if (i == x)
//        {
//            UserNode * pHead = UhashTable[i];
//            if (pHead == NULL)
//            {
//                return 0;
//            }
//            return pHead->UValue;
//        }
//    }
//    return 0;
//}

////c++关键字权值查找函数
//int Function::HashGet(int x, NodeOfHash * hashTable[Hsize])
//{
//    for (int i = 0; i < Hsize; i++)
//    {
//        if (i == x)
//        {
//            NodeOfHash * pHead = hashTable[i];
//            if (pHead == NULL)
//            {
//                return 0;
//            }
//            return pHead->WordsValue;
//        }
//    }
//    return 0;
//}

//Line * Function::Create()
//{
//    Line * node = (Line*)malloc(sizeof(Line));
//    memset(node, 0, sizeof(Line));
//    return node;
//}


//void Function::InsWords(NodeOfLine LineRoot, char * str)
//{
//    if (LineRoot == NULL || *str == '\0')
//    {
//        return;
//    }

//    Line * t = LineRoot;
//    char * p = str;

//    while (*p != '\0')
//    {
//        if (t->Bond[*p - 97] == NULL)
//        {
//            Line * tmp = Create();
//            t->Bond[*p - 97] = tmp;
//        }

//        t = t->Bond[*p - 97];
//        p++;
//    }
//    t->SUM++;
//}

//int Function::FindWords(NodeOfLine root, char * str)//查找字符串是否在这个单词结构中
//{
//    if (root == NULL || *str == '\0')//树为空或者字符串是空的
//    {
//        cout << "查找失败" << endl;
//        return 0;
//    }

//    char * p = str;//声明工作指针指向字符串首位
//    Line * t = root;//声明一个工作指针

//    while (*p != '\0')
//    {
//        if (t->Bond[*p - 97] != NULL)//如果这个字符在树中不为空
//        {
//            t = t->Bond[*p - 97];//那么指针指向子结点
//            p++;//向后移动字符串指针
//        }

//        else
//        {
//            break;
//        }
//    }

//    if (*p == '\0')//如果字符串指针移动到了字符串结尾
//    {
//        if (t->SUM == 0)//如果这个结点的子叶数目为0
//        {
//            return 0;
//        }

//        else//如果存在子叶结点
//        {
//            return 1;
//        }
//    }

//    else//其实这里没有必要写else，但是为了程序工整，还是写上
//    {
//        return 0;
//    }
//}

////两个初始化函数
//void Function::HashTableInit(NodeOfHash * hashTable[Hsize])
//{
//    memset(hashTable, 0, sizeof(NodeOfHash*) * Hsize);
//}

//void Function::UhashTableInit()
//{
//    memset(UhashTable, 0, sizeof(UserNode*) * Usize);
//}

