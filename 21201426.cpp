#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct ABOOK
{
    char name[20];
    char auther[20];
    char press[20];
    double price;
}Abook,*abook;

typedef struct BOOK
{
    Abook book;
    abook next;
}Book,*book;

typedef struct
{
	book head;
	int length;
	int maxlength;
}Sqllist,*sqllist;

void input(sqllist sql);
void output(sqllist sql);
int compare1(Abook a, Abook b);
int visit1(Abook a);
void copy(abook b, abook a); 

int Initlist(sqllist sql);
int Destoylist(sqllist sql);
int Clearlist(sqllist sql);
int Listempty(sqllist sql);
int Listlength(sqllist sql);
int Getelem(sqllist sql, int i, abook b);
int Locateelem(sqllist sql, Abook e, int (*compare)(Abook a, Abook b));
int Priorelem(sqllist sql, Abook cur, sqllist pre);
int Nextelem(sqllist sql, Abook cur, sqllist next);
int Listinsert(sqllist sql, int i, Abook e);
int Listdelete(sqllist sql, int i, abook e);
int Listtraverse(sqllist sql, int (*visit)(Abook a));

int Merger(sqllist La, sqllist Lb, sqllist Lc); 
int Dele(sqllist Lc, double minprice, double maxprice);

int main()
{
	Sqllist la,lb,lc;
	Initlist(&la,5);
	Initlist(&lb,5);
	Initlist(&lc,10);
	input(&la);input(&lb);
	Merger(&la,&lb,&lc);
	printf("\n");
	output(&lc);
	printf("\n");
	Dele(&lc,20,40);
	output(&lc);
//	Abook b;
//	strcpy(b.name,"fe");strcpy(b.auther,"gt");strcpy(b.press,"qdr");b.price=4;
//	Listdelete(sql, 1, &b);
//	printf("%d\n",sql->length);
//	output(sql);
	Destoylist(&la);
	Destoylist(&lb);
	Destoylist(&lc);
	return 0;
}

void input(sqllist sql)
{
	book p = sql->head->next;
	while(p != NULL){
		scanf("%s%s%s%lf",p->book.name,p->book.auther,
			p->book.press,&p->book.price);
		p = p->next;
	}
}

void output(sqllist sql)
{
	book p = sql->head->next;
	while(p != NULL){
		printf("%s %s %s %lf\n",p->book.name,p->book.auther,
			p->book.press,p->book.price);
		p = p->next;
	}
}

//�ж�Abook��ֵ�Ƿ���� 
int compare1(Abook a, Abook b)
{
	if(!strcmp(a.auther,b.auther) && !strcmp(a.name,b.name) && !strcmp(a.press,b.press) && a.price==b.price)
		return 1;
	return 0;
}

int visit1(Abook a)
{
//  ������� 
	return 1;
}

//����ͼ�� 
void copy(abook b, abook a)
{
	strcpy(b->auther, a->auther);
	strcpy(b->name, a->name);
	strcpy(b->press, a->press);
	b->price = a->price;
} 

//�����յ����Ա� 
int Initlist(sqllist sql)
{
	sql->maxlength = MAX;
	sql->length = 0; 
	if(sql->head = (book)malloc(sizeof(Book))) 
		return 1;
	return 0;
}

//�������Ա� 
int Destoylist(sqllist sql)
{
	free(sql->head);
	free(sql);
	if(!sql)
		return 1;
	return 0;
}

//�������Ա� 
int Clearlist(sqllist sql)
{
	free(sql->head);
	sql->length = 0;
	sql->head = NULL;
	if(sql->head = (book)malloc(sizeof(Book)))
		return 1;
	return 0;
}

//�ж����Ա��Ƿ�Ϊ�ձ� 
int Listempty(sqllist sql)
{
	if(sql->length == -1 && sql->head == NULL)
		return 1;
	return 0;
}

//��ȡ���Ա��Ԫ�ظ��� 
int Listlength(sqllist sql)
{
	return sql->length;
}

//��ȡ��i��Ԫ�ص�ֵ,������*b 
int Getelem(sqllist sql, int i, abook b)
{
	copy(b, &sql->head[i-1].book);
}

//���ر��е�һ����e����compare()��ϵ��λ��,�����ڷ���0 
int Locateelem(sqllist sql, Abook e, int (*compare)(Abook a, Abook b))
{
	for(int n=0; n<sql->length; n++)
		if((*compare)(sql->head[n].book,e))
			return n+1;
	return 0;
}

//����ǰ�� 
int Priorelem(sqllist sql, Abook cur, sqllist pre)
{
	int i = Locateelem(sql, cur, compare1)-1;
	pre->length = i;
	pre->head = (book)malloc(i*sizeof(Book));
	pre->maxlength = MAX;
	for(int n=0; n<i; n++)
	{
		copy(&pre->head[n].book, &sql->head[n].book);
	}
	if(pre->head)
		return 1;
	return 0;
}

//���غ�� 
int Nextelem(sqllist sql, Abook cur, sqllist next)
{
	int i = Locateelem(sql, cur, compare1);
	next->length = sql->length-i;
	next->head = (book)malloc((sql->length-i)*sizeof(Book));
	next->maxlength = MAX;
	int t=0;
	for(int n=i; n<sql->length; n++)
	{
		copy(&next->head[t].book, &sql->head[n].book);
		t++;
	}
	if(next->head)
		return 1;
	return 0;
}

//�ڵ�i��λ��ǰ����Ԫ�� 
int Listinsert(sqllist sql, int i, Abook e)
{
	if(i<1 || i>sql->length)
		return 0;
	if(sql->length+1 <= sql->maxlength)
	{
		sql->length++;
		sql->head = (book)realloc(sql->head, (sql->length)*sizeof(Book));
		for(int n=sql->length-1; n>i-1; n--)
		{
			copy(&sql->head[n].book, &sql->head[n-1].book);
		}
		copy(&sql->head[i-1].book, &e);
		return 1;
	}
	return 0;
}

//ɾ����i��λԪ�� 
int Listdelete(sqllist sql, int i, abook e)
{
	if(i<1 || i>sql->length)
		return 0;
	for(int n=i-1; n<sql->length; n++)
	{
		copy(&sql->head[n].book, &sql->head[n+1].book);
	}
	sql->length--;
	sql->head = (book)realloc(sql->head, (sql->length)*sizeof(Book));
	return 1;
}

//��ÿ��Ԫ�ص���visit()���� 
int Listtraverse(sqllist sql, int (*visit)(Abook a))
{
	for(int n=0; n<sql->length; n++)
		(*visit)(sql->head[n].book);
	return 1;
}

//�ǵݼ������La��Lb�鲢���ǵ��������Lc 
int Merger(sqllist La, sqllist Lb, sqllist Lc)
{
	int i = La->length;
	int j = Lb->length;
	int k = 0;
	while(i>0 && j>0)
	{
		if(La->head[i-1].book.price > Lb->head[j-1].book.price)
		{
			copy(&Lc->head[k].book, &La->head[i-1].book);
			k++;
			i--;
		}
		else
		{
			copy(&Lc->head[k].book, &Lb->head[j-1].book);
			k++;
			j--;
		}
	}
	printf("%d %d %d\n",i,j,k);
	if(i > 0)
		while(i>0)
		{
			copy(&Lc->head[k].book, &La->head[i-1].book);
			k++;
			i--;
		}
	else if(j > 0)
		while(j>0)
		{
			copy(&Lc->head[k].book, &Lb->head[j-1].book);
			k++;
			j--;
		}
	return 1;
}

//ɾ���ض�ͼ�� 
int Dele(sqllist Lc, double minprice, double maxprice)
{
	int i=0, j=0;
	for( ; j<Lc->length; j++)
	{
		copy(&Lc->head[i].book, &Lc->head[j].book);
		if(Lc->head[i].book.price < minprice || Lc->head[i].book.price > maxprice)
		{
			i++;
		}
	}
	Lc->length = i;
	Lc->head = (book)realloc(Lc->head, i*sizeof(Book));
	return i;
}
