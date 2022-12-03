//本文件用于实行管理员权力，对图书进行增删改查，对用户密码进行统一重置
#include "hnulib.h"
#include <iostream>
#include <fstream>
using namespace std;

void admin::add_book(books *books_head){    //暂时设计成放到队尾
	books *tmp=books_head->next;
	int max=-1;
	while(tmp!=NULL){   //获取最大id号
		if(tmp->id>max){
			max=tmp->id;
		}
		tmp=tmp->next;
	}
	max+=1;
	books *h=books_head;
	while(h->next!=NULL){
		h=h->next;
	}
	books *node=new books;
	start:
		system("cls");
		cout<<"请输入图书名：";
		cin>>node->name;
		cout<<endl<<"请输入图书isbn号：";
		cin>>node->isbn;
		cout<<endl<<"请输入图书作者名：";
		cin>>node->author;
		cout<<endl<<"请输入图书出版社：";
		cin>>node->published;
		cout<<endl<<"请输入图书发行时间：";
		cin>>node->publishing;
		cout<<endl<<"请输入图书价格：";
		cin>>node->price;
		cout<<endl<<"请输入图书页数：";
		cin>>node->pages;
		cout<<endl<<"请输入图书描述（回车停止输入）：";
		cin>>node->description;
		cout<<endl<<"请输入已被借阅次数：";
		cin>>node->b_num;
		last_step:
			system("cls");
			cout<<"确定保存？输入0以确认，输入1以重新输入，输入2以取消增加图书操作：";
			int i;
			cin>>i;
			switch(i){
			case 0:
				break;
			case 1:
				goto start;
			case 2:
				delete node;
				return;
			default:
				cout<<"输入有误！请重新输入"<<endl;
				goto last_step;
			}
			h->next=node;
			node->next=NULL;
			cout<<"正在保存。。。"<<endl;
			node->borrow=false;
			node->id=max;
			save_books(books_head);
			cout<<"保存成功！"<<endl;
			system("pause");
			return;
}

void admin::change_book(books *books_head){
	int i,t;
	string T;
	start:
		system("cls");
		cout<<"请先查找书籍，输入1以id形式查找，输入2以isbn形式查找，输入3以书名形式查找"<<endl;
		cin>>i;
		books *temp;
		switch(i){
		case 1:
			cout<<"请输入id：";
			cin>>t;
			cout<<endl;
			temp=books_head->look_up_id(t,books_head);
			if(temp==NULL){
				goto start;
			}
			else{
				break;
			}
		case 2:
			cout<<"请输入isbn：";
			cin>>T;
			temp=books_head->lookup_isbn(T,books_head);
			if(temp==NULL){
				goto start;
			}
			else{
				break;
			}
		case 3:
			cout<<"请输入书名：";
			cin>>T;
			temp=books_head->lookup_name(T,books_head);
			if(temp==NULL){
				goto start;
			}
			else{
				break;
			}
		default:
			cout<<"输入有误！请检查并重新输入"<<endl;
			system("pause");
			goto start;
		}
		while(1){
			int i,t;
			string T;
			last_step:
				system("cls");
				cout<<temp->id<<" "<<temp->isbn<<" "<<temp->name<<" "<<temp->author<<" "<<temp->publishing<<" "<<temp->published<<" "<<temp->price<<" "<<temp->pages<<" "<<temp->b_num<<endl<<"\n"<<temp->description<<'\n';
				cout<<"请选择要修改的图书信息，输入1以更改isbn，输入2以更改书名，输入3以更改作者，输入4以更改出版社名称"<<endl
				<<"输入5以更改出版时间，输入6以更改价格，输入7以更改页数，输入8以更改描述，输入9以更改被借阅次数，输入'0'以退出：";
				cin>>i;
				switch(i){
				case 0:
					return;
				case 1:
					cout<<"请输入isbn：";
					cin>>T;
					cout<<"确定以“"<<T<<"”为本书的isbn码吗？ 输入0以确认，输入其他数字以取消：";
					cin>>t;
					if(t){
						goto last_step;
					}
					else{
						temp->isbn=T;
					}
					break;
				case 2:
					cout<<"请输入书名：";
					cin>>T;
					cout<<"确定以“"<<T<<"”为本书的书名吗？ 输入0以确认，输入其他数字以取消：";
					cin>>t;
					if(t){
						goto last_step;
					}
					else{
						temp->name=T;
					}
					break;
				case 3:
					cout<<"请输入作者名：";
					cin>>T;
					cout<<"确定以“"<<T<<"”为本书的作者名吗？ 输入0以确认，输入其他数字以取消：";
					cin>>t;
					if(t){
						goto last_step;
					}
					else{
						temp->author=T;
					}
					break;
				case 4:
					cout<<"请输入出版社名：";
					cin>>T;
					cout<<"确定以“"<<T<<"”为本书的出版社吗？ 输入0以确认，输入其他数字以取消：";
					cin>>t;
					if(t){
						goto last_step;
					}
					else{
						temp->published=T;
					}
					break;
				case 5:
					cout<<"请输入出版日期：";
					cin>>T;
					cout<<"确定以“"<<T<<"”为本书的出版日期吗？ 输入0以确认，输入其他数字以取消：";
					cin>>t;
					if(t){
						goto last_step;
					}
					else{
						temp->publishing=T;
					}
					break;
				case 6:
					cout<<"请输入价格：";
					double tt;
					cin>>tt;
					cout<<"确定以“"<<tt<<"”为本书的价格吗？ 输入0以确认，输入其他数字以取消：";
					cin>>t;
					if(t){
						goto last_step;
					}
					else{
						temp->price=tt;
					}
					break;
				case 7:
					cout<<"请输入页数：";
					int ttt;
					cin>>ttt;
					cout<<"确定以“"<<ttt<<"”为本书的页数吗？ 输入0以确认，输入其他数字以取消：";
					cin>>t;
					if(t){
						goto last_step;
					}
					else{
						temp->pages=tt;
					}
					break;
				case 8:
					cout<<"请输入描述：";
					cin>>T;
					cout<<"确定以“"<<T<<"”为本书的描述吗？ 输入0以确认，输入其他数字以取消：";
					cin>>t;
					if(t){
						goto last_step;
					}
					else{
						temp->description=T;
					}
					break;
				case 9:
					cout<<"请输入被借阅次数：";
					int tttt;
					cin>>tttt;
					cout<<"确定以“"<<tttt<<"”为本书的被借阅次数吗？ 输入0以确认，输入其他数字以取消：";
					cin>>t;
					if(t){
						goto last_step;
					}
					else{
						temp->b_num=tt;
					}
					break;
				default:
					cout<<"输入有误！请重新输入；"<<endl;
					system("pause");
					break;
				}
		}
		cout<<"保存修改中。。。"<<endl;
		save_books(books_head);
		cout<<"保存成功！"<<endl;
		system("pause");
		return;
}

void admin::del_book(books *books_head){
	int i;
	string T;
	books *temp;
	last_step:
		system("cls");
		cout<<"请先查找书籍，输入1以id形式查找，输入2以isbn形式查找，输入3以书名形式查找：";
		cin>>i;
		switch(i){
		case 1:
			cout<<endl<<"请输入id：";
			int t;
			cin>>t;
			temp=books_head->look_up_id(t,books_head);
			break;
		case 2:
			cout<<endl<<"请输入isbn码：";
			cin>>T;
			temp=books_head->lookup_isbn(T,books_head);
			break;
		case 3:
			cout<<endl<<"请输入书名：";
			cin>>T;
			temp=books_head->lookup_name(T,books_head);
			break;
		default:
			cout<<"您的输入有误！请重新输入"<<endl;
			system("pause");
			goto last_step;
			break;
		}
		cout<<"确认删除此书？1-是 0-否：";
		cin>>i;
		if(i){
			books *front=books_head;
			while(front->next!=temp){
				front=front->next;
			}
			front->next=temp->next;
			temp->next=NULL;
			delete temp;
			cout<<"删除成功！"<<endl;
			system("pause");
		}
		else{
			cout<<"您是想？ 0-重新查找 1-退出：";
			cin>>i;
			if(i){
				return;
			}
			else{
				goto last_step;
			}
		}
		cout<<"正在保存。。。"<<endl;
		save_books(books_head);;
		cout<<"保存成功！"<<endl;
		system("pause");
		return;
}

void admin::reset_key(user *users_head){
	
	string str;
	in_ag:
		cout<<"请输入要重置的账号：";
		cin>>str;
		user* tmp=users_head;
		while (tmp)
		{
			if(tmp->account_num==str)
			{
				tmp->key="123456";
				cout<<"重置成功！"<<'\n';
				cout<<"正在保存。。。"<<endl;
				save_users(users_head);
				cout<<"保存成功！"<<endl;
				system("pause");
				return ;
			}
			else
				tmp=tmp->next;
		}
		
		cout<<"没有相应账号的学生 0-重新查找 1-退出："<<'\n';
		int i;
		cin>>i;
		if(i)
			return;
		else
			goto in_ag;
}

admin* admin::login(admin *admins_head){
	string amount,key;
	int sign;
	start:
		system("cls");
		sign=0;
		cout<<"请输入账号：";
		cin>>amount;
		cout<<endl<<"请输入密码：";
		cin>>key;
		admin *tmp=admins_head->next;
		while(tmp!=NULL){
			if(tmp->account_num.compare(amount)==0){
				sign=1;
				break;
			}
			tmp=tmp->next;
		}
		if(!sign){
			cout<<"账号或密码错误，请重试或返回上级菜单，键入并回车："<<endl<<"0-重新输入 其他数字-返回上级菜单：";
			cin>>sign;
			if(sign){
				return NULL;
			}
			else{
				goto start;
			}
		}
		else{
			if(tmp->key.compare(key)==0){
				cout<<"登陆成功！"<<endl;
				system("pause");
				system("cls");
				return tmp;
			}
			else{
				cout<<"账号或密码错误，请重试或返回上级菜单，键入并回车："<<endl<<"0-重新输入 其他数字-返回上级菜单：";
				cin>>sign;
				if(sign){
					return NULL;
				}
				else{
					goto start;
				}
			}
		}
}

void admin::add_user(user *user_head,books *books_head){
	start:
		system("cls");
		string amount,key;
		int log;
		int i,j;
		cout<<"请输入学生账号：";
		cin>>amount;
		cout<<endl<<"请输入密码：";
		cin>>key;
		cout<<endl<<"请输入该用户的借阅数目：";
		cin>>log;
		int log_id[log];
		if(log<0||log>20){
			cout<<"请输入大等于0小等于20的数目！"<<endl;
		}
		else if(log>0&&log<=20){
			cout<<"请依次输入数目id" <<endl;
			for(j=0;j<log;j++){
				step:
					system("cls");
					cout<<"请输入第"<<j+1<<"个书的<有效>id:";
					cin>>log_id[j];
					books *books_temp=books_head->next;
					int sign=0;
					while(books_temp!=NULL){
						if(books_temp->id==log_id[j]){
							sign=1;
							break;
						}
					}
					if(!sign){
						cout<<"不存在此id！请重新输入或退出 0-重新输入 其他数字-退出"<<endl;
						cin>>sign;
						if(sign){
							return;
						}
						else{
							goto step;
						}
					}
					cout<<endl;
			}
		}
		last_step:
			system("cls");
			cout<<endl<<"确认保存？ 键入并回车：0-保存 1-重新输入 2-退出   ";
			cin>>i;
			switch(i){
			case 0:
				break;
			case 1:
				goto start;
			case 2:
				return;
			default:
				cout<<"键入错误！请重试"<<endl;
				goto last_step;
			}
			cout<<endl<<"正在处理..."<<endl;
			user *user_temp=user_head->next;
			while(user_temp->next!=NULL){
				user_temp=user_temp->next;
			}
			user *node=new user;
			node->account_num=amount;
			node->key=key;
			node->log_num=log;
			for(j=0;j<log;j++){
				node->log[j]=log_id[j];
			}
			user_temp->next=node;
			node->next=NULL;
			save_users(user_head);
			cout<<"保存成功！"<<endl;
			system("pause");
			system("cls");
			return;
}

void admin::del_user(user *users_head){
	start:
		system("cls");
		string amount;
		int sign=0;
		cout<<"请输入要删除的学生账号：";
		cin>>amount;
		user *user_temp=users_head->next;
		while(user_temp!=NULL){
			if(user_temp->account_num.compare(amount)==0){
				sign=1;
				break;
			}
		}
		if(!sign){
			cout<<"没有该学生！键入并回车 0-重新输入 其他数字-退出：";
			cin>>sign;
			if(sign){
				return;
			}
			else{
				goto start;
			}
		}
		cout<<endl<<"确认删除？ 键入并回车 0-确认 其他数字-取消并退出 ：";
		cin>>sign;
		if(sign){
			return;
		}
		else{
			user *temp=users_head;
			while(temp->next!=user_temp){
				temp=temp->next;
			}
			temp->next=user_temp->next;
			user_temp->next=NULL;
			delete user_temp;
			save_users(users_head);
		}
		cout<<endl<<"保存成功！"<<endl;
		system("pause");
		system("cls");
		return;
}

void admin::change_user(user *user_head,books *books_head){
	start:
		system("cls");
		string amount;
		int sign=0;
		cout<<"请输入要更改的学生账号：";
		cin>>amount;
		user *user_temp=user_head->next;
		while(user_temp!=NULL){
			if(user_temp->account_num.compare(amount)==0){
				sign=1;
				break;
			}
		}
		if(!sign){
			cout<<"没有该学生！键入并回车 0-重新输入 其他数字-退出：";
			cin>>sign;
			if(sign){
				return;
			}
			else{
				goto start;
			}
		}
		cout<<"键入并回车选择需要更改的信息编号"
		<<endl<<"1-账号："<<user_temp->account_num
		<<endl<<"2-密码："<<user_temp->key
		<<endl<<"3-借阅书数目"<<user_temp->log_num;
		if(user_temp->log_num!=0){
			sign=1;
			cout<<endl<<"4-借阅书编号：";
			for(int i=0;i<user_temp->log_num;i++){
				cout<<user_temp->log[i]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;
		int sign1;
		cin>>sign1;
		if(sign1==1){
			cout<<"请输入新账号：";
			string amount1;
			cin>>amount1;
			cout<<endl<<"是否保存修改？ 键入并回车 0-保存 其他数字-取消并退出：";
			cin>>sign;
			if(sign){
				return;
			}
			else{
				user_temp->account_num=amount1;
			}
		}
		else if(sign1==2){
			cout<<"请输入新密码：";
			string key;
			cin>>key;
			cout<<endl<<"是否保存修改？ 键入并回车 0-保存 其他数字-取消并退出：";
			cin>>sign;
			if(sign){
				return;
			}
			else{
				user_temp->key=key;
			}
		}
		else if(sign1==3){
			system("cls");
			step1:
				cout<<"请输入新借阅书数目：";
				int log_num;
				cin>>log_num;
				if(log_num>user_temp->log_num&&log_num<=20){
					for(int i=user_temp->log_num;i<log_num;i++){
						step:
							cout<<"请输入第"<<i-log_num+1<<"个新增书的id：";
							int id;
							cin>>id;
							books *books_temp=books_head->next;
							int sign=0;
							while(books_temp!=NULL){
								if(books_temp->id==id){
									sign=1;
									break;
								}
							}
							if(!sign){
								cout<<"不存在此id！请重新输入或退出 0-重新输入 其他数字-退出"<<endl;
								cin>>sign;
								if(sign){
									return;
								}
								else{
									goto step;
								}
							}
							user_temp->log[i]=id;
							cout<<endl;
					}
				}
				else if(log_num>20||log_num<0){
					cout<<"请输入大等于0小等于20的数目！"<<endl;
					goto step1;
				}
				cout<<endl<<"是否保存修改？ 键入并回车 0-保存 其他数字-取消并退出：";
				cin>>sign;
				if(sign){
					return;
				}
				else{
					user_temp->log_num=log_num;
				}
		}
		else if(sign1==4&&sign==1){
			int log_id[user_temp->log_num];
			for(int j=0;j<user_temp->log_num;j++){
				step2:
					system("cls");
					cout<<"请输入第"<<j+1<<"个书的<有效>id:";
					cin>>log_id[j];
					books *books_temp=books_head->next;
					int sign=0;
					while(books_temp!=NULL){
						if(books_temp->id==log_id[j]){
							sign=1;
							break;
						}
					}
					if(!sign){
						cout<<"不存在此id！请重新输入或退出 0-重新输入 其他数字-退出"<<endl;
						cin>>sign;
						if(sign){
							return;
						}
						else{
							goto step2;
						}
					}
					cout<<endl;
			}
			cout<<endl<<"是否保存修改？ 键入并回车 0-保存 其他数字-取消并退出：";
			cin>>sign;
			if(sign){
				return;
			}
			else{
				for(int i=0;i<user_temp->log_num;i++){
					user_temp->log[i]=log_id[i];
				}
			}
		}
		else{
			cout<<endl<<"输入错误！键入并回车 0-重新输入 其他数字-退出：";
			cin>>sign;
			if(sign){
				return;
			}
			else{
				goto start;
			}
		}
		cout<<"正在保存....."<<endl;
		save_users(user_head);
		cout<<"保存成功！"<<endl;
		system("pause");
		system("cls");
		return;
}

void admin::lookup_user(user *users_head)   //查找学生
{
	string str;
	in_again:
		cout<<"请输入查找的账号：";
		cin>>str;
		user* tmp=users_head;
		while (tmp)
		{
			if(tmp->account_num==str)
			{
				cout<<tmp->account_num<<" "<<tmp->key<<" "<<tmp->log_num<<'\n';
				cout<<"借阅书目的id：";
				for(int i=0;i<tmp->log_num;i++)
				{
					cout<<tmp->log[i]<<" ";
				}
				cout<<'\n';
				system("pause");
				return ;
			}
			else
				tmp=tmp->next;
		}
		
		cout<<"没有相应账号的学生 0-重新查找 1-退出："<<'\n';
		int i;
		cin>>i;
		if(i)
			return;
		else
			goto in_again;
}