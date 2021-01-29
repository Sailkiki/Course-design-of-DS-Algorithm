#ifndef WIDGET_H
#define WIDGET_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <QWidget>
#include "dialog.h"
#include "dialog2.h"
#include "dialogofwarn.h"
#include "dialogofcppsym.h"
#include "customsym.h"
#include "showcuston.h"
#include "afterdeal.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
#define Usize 31 //4*7+3自定义表长
#define Utotle 26 //自定义关键字个数
#define Hsize 67//这个是c++哈希数组总长度
#define Totle 59//c++关键字个数
#define Letter 26//26个英文字母
#define MaxSizeOfWord 10 //令单词最长不超过10
#define MaxBoard 200


typedef struct  UserIdentifier
{
    int UValue;
    char * UKey;
    UserIdentifier(): UValue(0), UKey(NULL){}
}UserNode;


typedef struct WordsLine
{
    int SUM;
    struct WordsLine * Bond[Letter];
    WordsLine(){
        SUM = 0;
        memset(Bond, 0, sizeof(WordsLine * ) * Letter);
    }
} Line, * NodeOfLine;

typedef struct NodeOfHashTable
{
    int WordsValue;
    char * Key;
    NodeOfHashTable(): WordsValue(0), Key(NULL) {}//初始化操作
} NodeOfHash;
//extern UserNode * UhashTable[Usize];
//extern NodeOfHash * hashTable[Hsize];//声明c++/*关键字的结构体指针数组*/

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_2_clicked(bool checked);

    void on_pushButton_3_clicked(bool checked);

    void on_pushButton_5_clicked(bool checked);

    void on_view1_clicked(bool checked);

    void on_view2_clicked(bool checked);

    void on_pushButton_6_clicked(bool checked);

    void on_pushButton_7_clicked(bool checked);

    void on_viewcustom_clicked(bool checked);

    void on_Start_clicked(bool checked);

public:
    Ui::Widget *ui;
    QPalette pal;
    QDialog *dialog;
    Dialog dia;
    Dialog2 dia2;
    DialogOfWarn dia3;
    DialogOfcppsym dia4;
    CustomSym cus;
    ShowCuston Show;
    AfterDeal aft;
};

class Function : public Widget {
    public:
//        UserNode * UhashTable[Usize];
        //当前表长
        int UTableSize;
        int TableSize;
    public:
        Function();//无参构造函数，内容是对以上三个变量进行初始化

        Line * Create();//创建单词的根部，类似于树根的建立

        void InsWords(NodeOfLine LineRoot, char * str);//单词结点的插入

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

        int HashGet(int x, NodeOfHash * hashTable[Hsize]);//获取c++关键字权值

        int UHashGet(int x);//获取另一个用户自定义标识符哈希表的权值

};




class MakeHash : public Widget {
    public:

        void InitKeyWords_Second(int * a, int * b, NodeOfHash * hashTable[Hsize]);//初始化第二个文件的函数

        void DealKeyWords_Second(Function &hashtable, int Num_1, int UNum_1, int Species, double trans1, double trans2, double trans3, double trans4, NodeOfHash * hashTable[Hsize]);//操作处理程序二的函数

        void InitKeyWords_First(Function &hashtable, char (*Word) [MaxSizeOfWord], char (*word2) [MaxSizeOfWord], NodeOfHash * hashTable[Hsize]);//初始化第一个文件的函数

        void DealKeyWords_First(Function &hashtable, NodeOfHash * hashTable[Hsize]);//操作处理之后的程序一的函数

        void Start_F();//开始程序

    public:
        Widget ww;
        AfterDeal aft;
};



#endif // WIDGET_H
