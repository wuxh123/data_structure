#include"SeqStack.h"

void InitStack(SeqStack *s)
{
	s->base = (ElemType *)malloc(sizeof(ElemType)*STACK_INIT_SIZE);
	assert(s->base != NULL);
	s->capacity = STACK_INIT_SIZE;
	s->top = 0;
}

bool Inc(SeqStack *s)
{
	ElemType *newbase = (ElemType *)realloc(s->base,sizeof(ElemType)*(s->capacity+STACK_INC_SIZE));
	if(newbase == NULL)
	{
		printf("�ڴ治��,�޷�����ռ�.\n");
		return false;
	}
	s->base = newbase;
	s->capacity += STACK_INC_SIZE;
	return true;
}

bool IsFull(SeqStack *s)
{
	return s->top >= s->capacity;
}
bool IsEmpty(SeqStack *s)
{
	return s->top == 0;
}

void Push(SeqStack *s, ElemType x)
{
	if(IsFull(s) && !Inc(s))
	{
		printf("ջ�ռ�����,%d ������ջ.\n",x);
		return;
	}

	s->base[s->top++] = x;
	//s->top++;
}

void Pop(SeqStack *s)
{
	if(IsEmpty(s))
	{
		printf("ջ�ռ��ѿ�,���ܳ�ջ.\n");
		return;
	}

	s->top--;
}

bool GetTop(SeqStack *s, ElemType *v)
{
	if(IsEmpty(s))
	{	
		printf("ջ�ռ��ѿ�,����ȡջ��Ԫ��.\n");
		return false;
	}

	*v = s->base[s->top-1];
	return true;
}

void Show(SeqStack *s)
{
	for(int i=s->top-1; i>=0; --i)
	{
		printf("%d\n",s->base[i]);
	}
	printf("\n");
}

int Length(SeqStack *s)
{
	return s->top;
}

void Clear(SeqStack *s)
{
	s->top = 0;
}
void Destroy(SeqStack *s)
{
	free(s->base);
	s->base = NULL;
	s->capacity = s->top = 0;
}