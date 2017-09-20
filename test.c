#define  _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"
#include<stdio.h>
#include<Windows.h>
enum
{
	Exit,
	PusB,
	PopB,
	Prin,
	PusF,
	PopF,
	Inse,
	Sort,
	Bina,
	Find,
	Rem
};

void menu()
{
	printf("*********************************************\n");
	printf("********           seqlist         **********\n");
	printf("******** 1.PusB             2.PopB **********\n");
	printf("******** 3.Prin             4.PusF **********\n");
	printf("******** 5.PopF             6.Inse **********\n");
	printf("******** 7.Sort             8.Bina **********\n");
	printf("******** 9.Find             10.Rem **********\n");
	printf("********           0.Exit          **********\n");
	printf("*********************************************\n");
}
void test()
{
	int input = 0;
	SeqList seq;
	InitSeqList(&seq);
	while(1)
	{
		menu();
		printf("请选择:>");
		scanf("%d",&input);
		switch(input)
		{
		case PusB:
			 PushBack(&seq,1);//需要优化
			break;
		case PopB:
			PopBack(&seq);
			break;
		case Prin:
			PrintSeqList(&seq);
			break;
		case PusF:
			PushFront(&seq,2);//需要优化
			break;
		case PopF:
			PopFront(&seq);
			break;
		case Inse:
			Insert(&seq,2,6);//需要优化
			break;
		case Sort:
			SortSeqList(&seq);
			break;
		case Bina:
			BinarySearch(&seq,3);//需要优化
			break;
		case Find:
			/*DataType d = 0;
			scanf("%d",&d);*///有问题，如果换DataType怎么办
			FindSeqList(&seq,3);
			break;
		case Rem:
			Remove(&seq,1);
			break;
		case Exit:
			DestroySeqList(&seq);
			break;
		default:
			printf("输入错误，请重新输入:>");
			break;
		}

	}
}

int main()
{
	test();
	system("pause");
	return 0;
}
