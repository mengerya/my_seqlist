#include"seqlist.h"

void InitSeqList(pSeqList ps)
{
	ps->sz = 0;
	ps->data = (DataType*)malloc(sizeof(DataType) * DEFAULT_SZ);
	if(ps->data == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	ps->capacity = DEFAULT_SZ;

}

void CheckCapacity(pSeqList ps)
{
	if(ps->sz == ps->capacity)
	{
		DataType* tmp = (DataType*)realloc(ps->data,(ps->capacity + DEFAULT_INC)*sizeof(DataType));
		if(tmp != NULL)
		{
			ps->data = tmp;
		}
		ps->capacity += DEFAULT_INC;
		printf("增容成功\n");
	}
}

void DestroySeqList(pSeqList ps)
{
	free(ps->data);
	ps->data = NULL;
	ps->capacity = 0;
	ps->sz = 0;
}

void PushBack(pSeqList ps, DataType d)
{
	assert(ps);
	CheckCapacity(ps);
	ps->data[ps->sz] = d;
	ps->sz++;
}

void PrintSeqList(const pSeqList ps)
{
	int i = 0;
	assert(ps);
	for(i=0;i<ps->sz;i++)
	{
		printf("%d   ",ps->data[ps->sz]);
	}
	printf("\n");
}

void PopBack(pSeqList ps)
{
	assert(ps);
	ps->sz--;
}

void PushFront(pSeqList ps,DataType d)
{
	int i = 0;
	assert(ps);
	CheckCapacity(ps);
	for(i=ps->sz-1;i>=0;i--)
	{
		ps->data[i+1] = ps->data[i];
	}
	ps->data[0] = d;
	ps->sz++;
}

void PopFront(pSeqList ps)
{
	int i = 0;
	assert(ps);
	if(ps->sz == 0)
	{
		printf("通讯录为空:>");
		return;
	}
	for(i=0;i<ps->sz-1;i++)
	{
		ps->data[i] = ps->data[i+1];
	}
	ps->sz--;
}

void SortSeqList(pSeqList ps)
{
	int i = 0;
	int j = 0;
	assert(ps);
	for(i=0;i<ps->sz-1;i++)
	{
		for(j=i;j<ps->sz-i-1;j++)
		{
			if(ps->data[j]>ps->data[j+1])
			{
				int tmp = 0;
				tmp = ps->data[j];
				ps->data[j] = ps->data[j+1];
				ps->data[j+1] = tmp;
			}
		}
	}
}

int FindSeqList(pSeqList ps,DataType d)
{
	int i= 0;
	assert(ps);
	for(i=0;i<ps->sz;i++)
	{
		if(ps->data[i] == d)
		{
			return d;
		}
	}
	return -1;
}

void Insert(pSeqList ps,int pos,DataType d)
{
	int i = 0;
	assert(ps);
	CheckCapacity(ps);
	if(pos == -1)
	{
		return;
	}
	for(i=ps->sz-1;i>=pos;i--)
	{
		ps->data[i+1] = ps->data[i];
	}
	ps->data[pos] = d;
	ps->sz++;
}

int BinarySearch(pSeqList ps,DataType d)
{
	int right = 0;
	int left = 0;
	int mid = 0;
	SortSeqList(ps);
	right = ps->sz-1;
	assert(ps);
	while(left<=right)
	{
		mid = (left + right)/2;
		if(ps->data[mid] > d)
		{
			right = mid-1;
		}
		else if(ps->data[mid] < d)
		{
			left = mid + 1;
		}
		else
			return mid;
	}
	return -1;
}

void Remove(pSeqList ps,DataType d)
{
	int i = 0;
	assert(ps);
	for(i=0;i<ps->sz;i++)
	{
		if(ps->data[i] == d)
		{
			int j = 0;
			for(j=i;j<ps->sz;j++)
			{
				ps->data[j] = ps->data[j+1];
			}
		}
	}
	ps->sz--;
}
