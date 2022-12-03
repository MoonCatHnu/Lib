//本文件实现对图书的查找、排序

#include<iostream>
#include "hnulib.h"
using namespace std;

books* books::look_up_id(int id,books *books_head){
	books *temp=books_head->next;
	while(temp!=NULL){
		if(temp->id==id){
			cout<<temp->isbn<<" "<<temp->name<<" "<<temp->author<<" "<<temp->publishing<<" "<<temp->published<<" "<<temp->price<<" "<<temp->price<<"\n";
			cout<<"借阅情况： ";
			if(temp->borrow)
				cout<<"本书已被借阅"<<'\n';
			else
				cout<<"本书可借阅"<<'\n';
			system("pause");
			return temp;
		}
		else{
			temp=temp->next;
		}
	}
	cout<<"未查找到相关书籍，请检查输入是否正确"<<'\n';
	system("pause");
	return NULL;
}

books* books::lookup_name(string name,books *book_head)   //书名精确查找
{
	books *temp=book_head->next;
	while(temp)
	{
		if(temp->name.compare(name)==0)
		{
			cout<<temp->isbn<<" "<<temp->name<<" "<<temp->author<<" "<<temp->publishing<<" "<<temp->published<<" "<<temp->price<<" "<<temp->price<<"\n"<<"详情："<<temp->description<<'\n';
			cout<<"借阅情况： ";
			if(temp->borrow)
				cout<<"本书已被借阅"<<'\n';
			else
				cout<<"本书可借阅"<<'\n';
			system("pause");
			return temp;
		}
		else
			temp=temp->next;
	}
	cout<<"未查找到相关书籍，请检查输入是否正确"<<'\n';
	system("pause");
	return NULL;
}

books* books::lookup_isbn(string isbn,books *book_head)   //ISBN精确查找
{
	books *temp=book_head;
	while(temp)
	{
		if(temp->isbn.compare(isbn)==0)
		{
			cout<<temp->isbn<<" "<<temp->name<<" "<<temp->author<<" "<<temp->publishing<<" "<<temp->published<<" "<<temp->price<<" "<<temp->price<<"\n"<<"详情："<<temp->description<<'\n';
			cout<<"借阅情况： ";
			if(temp->borrow)
				cout<<"本书已被借阅"<<'\n';
			else
				cout<<"本书可借阅"<<'\n';
			system("pause");
			return temp;
		}
		else
			temp=temp->next;
	}
	cout<<"未查找到相关书籍，请检查输入是否正确"<<'\n';
	system("pause");
	return NULL;
}
//接下来应该是两个模糊查找
void books::lookup_author(string author,books *book_head)
{
	books *temp=book_head;
	bool finding=false;
	while(temp)
	{
		if(temp->author.compare(author)==0)
		{
			finding=true;
			cout<<temp->isbn<<" "<<temp->name<<" "<<temp->author<<" "<<temp->publishing<<" "<<temp->published<<" "<<temp->price<<" "<<temp->price<<"\n";
			cout<<"借阅情况： ";
			if(temp->borrow)
				cout<<"本书已被借阅"<<'\n';
			else
				cout<<"本书可借阅"<<'\n';
			temp=temp->next;
		}
		else
			temp=temp->next;
	}
	if(!finding){
		cout<<"未查找到相关书籍，请检查输入是否正确或向管理员反应书籍缺失"<<'\n';
		
	}
	system("pause");
	return ;
}

void books::lookup_publishing(string publishing,books *book_head)
{
	books *temp=book_head;
	bool finding=false;
	while(temp)
	{
		if(temp->publishing.compare(publishing)==0)
		{
			finding=true;
			cout<<temp->isbn<<" "<<temp->name<<" "<<temp->author<<" "<<temp->publishing<<" "<<temp->published<<" "<<temp->price<<" "<<temp->price<<"\n";
			cout<<"借阅情况： ";
			if(temp->borrow)
				cout<<"本书已被借阅"<<'\n';
			else
				cout<<"本书可借阅"<<'\n';
			temp=temp->next;
		}
		else
			temp=temp->next;
	}
	if(!finding){
		cout<<"未查找到相关书籍，请检查输入是否正确或向管理员反应书籍缺失"<<'\n';
		
	}
	system("pause");
	return ;
}

books* books::dictionary_list(books* books_head){
	books *tmp_head=new books;  //深拷贝一份链表
	books *tmp_end=tmp_head;
	books *tmp=books_head->next;
	int count=0;
	while(tmp!=NULL){
		books *node=new books;
		node->id=tmp->id;
		node->isbn=tmp->isbn;
		node->name=tmp->name;
		node->author=tmp->author;
		node->publishing=tmp->publishing;
		node->published=tmp->published;
		node->price=tmp->price;
		node->pages=tmp->pages;
		node->description=tmp->description;
		node->b_num=tmp->b_num;
		node->borrow=tmp->borrow;
		tmp=tmp->next;
		tmp_end->next=node;
		tmp_end=tmp_end->next;
		count++;
	}
	tmp_end->next=NULL;
	int i,num;
	books *p,*q,*last;
	p=tmp_head->next;
	for(i=0;i<count-1;i++){
		p=tmp_head->next;
		q=p->next;
		last=tmp_head;
		for(num=0;num<count-i-1;num++){
			if(p->name.compare(q->name)==1){    //链表交换
				last->next=q;
				p->next=q->next;
				q->next=p;
			}
			last=last->next;
			p=last->next;
			q=p->next;
		}
	}
	return tmp_head;
	
}

void books::book_list(books *book_head) //图书借阅排行，我把返回值改成空了
{
	cout<<"加载中。。。"<<'\n';
	books* tmp=dictionary_list(book_head);  //先按字典序排
	int i,count=0,num;
	books *p,*q,*last;
	p=tmp->next;
	
	while (p->next!=NULL)
	{
		count++;
		p=p->next;
	}
	
	for(i=0;i<count-1;i++){
		p=tmp->next;
		q=p->next;
		last=tmp;
		for(num=0;num<count-i-1;num++)
		{
			if(p->b_num<p->next->b_num)
			{    //按借阅次数大小排序
				last->next=q;
				p->next=q->next;
				q->next=p;
			}
			last=last->next;
			p=last->next;
			q=p->next;
		}
	}
	cout<<"图书借阅次数排行榜（前20）："<<'\n';
	p=tmp->next;
	for(int i=0;i<20;i++)
	{
		cout<<i+1<<" "<<p->isbn<<" "<<p->name<<" "<<p->author<<" "<<p->publishing<<" "<<p->published<<" "<<p->price<<" "<<p->price<<"\n";
		p=p->next;
	}
	system("pause");
	return ;    //函数结束应该会自动释放内存的……吧？
}

void books::new_publish(books *book_head) //图书最新出版排行
{
	cout<<"加载中。。。"<<'\n';
	books* tmp=dictionary_list(book_head);  //先按字典序排
	system("cls");
	int i,count=0,num;
	books *p,*q,*last;
	p=tmp->next;
	
	while (p->next!=NULL)
	{
		count++;
		p=p->next;
	}
	
	for(i=0;i<count-1;i++){
		p=tmp->next;
		q=p->next;
		last=tmp;
		for(num=0;num<count-i-1;num++)
		{
			if(p->published.compare(q->published)==1)
			{    //按出版时间排序
				last->next=q;
				p->next=q->next;
				q->next=p;
			}
			last=last->next;
			p=last->next;
			q=p->next;
		}
	}
	cout<<"图书最新出版排行榜（前20）："<<'\n';
	p=tmp->next;
	for(int i=0;i<20;i++)
	{
		cout<<i+1<<" "<<p->isbn<<" "<<p->name<<" "<<p->author<<" "<<p->publishing<<" "<<p->published<<" "<<p->price<<" "<<p->price<<"\n";
		p=p->next;
	}
	system("pause");
	return ;
}

struct author{
	string name;
	int num;
	struct author* next;
};

void books::author_list(books *book_head)
{
	books* tmp=book_head;
	struct author *head,*q,*p;
	head=NULL;
	p=head;
	q=p;
	while (tmp)
	{
		bool flag=false;
		while (p)
		{
			if(p->name==tmp->author)
			{
				flag=true;
				p->num+=tmp->b_num;
				break;
			}
			p=p->next;
		}
		if(!flag)
		{
			p=new struct author;
			p->name=tmp->author;
			p->num=tmp->b_num;
			p->next=NULL;
			if(!head)
			{
				head=p;
				q=p;
			}
			else
			{
				q->next=p;
				q=p;
			}
		}
		
		tmp=tmp->next;
	}
	
	p=head->next;
	int i,count=0,num;
	struct author *last;
	while (p->next!=NULL)
	{
		count++;
		p=p->next;
	}
	
	for(i=0;i<count-1;i++){
		p=head->next;
		q=p->next;
		last=head;
		for(num=0;num<count-i-1;num++)
		{
			if(p->num<q->num)
			{
				last->next=q;
				p->next=q->next;
				q->next=p;
			}
			last=last->next;
			p=last->next;
			q=p->next;
		}
	}
	cout<<"作者被借阅次数排行榜（前20）："<<'\n';
	p=head->next;
	for(int i=0;i<20;i++)
	{
		cout<<i+1<<" "<<p->name<<" 被借阅次数："<<p->num<<'\n';
		p=p->next;
	}
	system("pause");
	return ;
}
