#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
#include<assert.h>

#define DEFAULT_SZ 3
#define DEFAULT_INC 2

typedef int DataType;
typedef struct SeqList
{
	DataType* data;  //数据区
	int sz;     //有效个数
	int capacity;   //容量
}SeqList,*pSeqList;


void InitSeqList(pSeqList ps);
void DestroySeqList(pSeqList ps);
void CheckCapacity(pSeqList ps);
void PushBack(pSeqList ps, DataType d);
void PrintSeqList(const pSeqList ps);
void PopBack(pSeqList ps);
void PushFront(pSeqList ps,DataType d);
void PopFront(pSeqList ps);
void Insert(pSeqList ps,int pos,DataType d);//插入
void SortSeqList(pSeqList ps);
int BinarySearch(pSeqList ps,DataType d);
int FindSeqList(pSeqList ps,DataType d);
void Remove(pSeqList ps,DataType d);
// RemoveAll(); 
#endif //__SEQLIST_H__
