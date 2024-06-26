#include "hnulib.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
	int books_num=0,users_num=0,admins_num=0;
	books *books_head=loading_books(books_num);
	admin *admins_head=loading_admin(admins_num);
	user *users_head=loading_users(users_num,books_head);
	menu main;
	int i,sign=1;
	string tmp;
	user *us_tmp=NULL;
	admin *ad_tmp=NULL;
	while(sign){
		system("cls");
		i=main.show_menu_main();
		switch(i){
			case 0:     //退出系统
			system("cls");
			sign=0;
			break;
			case 1:     //注册账号
			reg_menu:
				system("cls");
				i=main.show_menu_reg();
				switch(i){
					case 0:     //返回上级菜单
					system("cls");
					break;  //结束函数，开始新的while循环
					case 1:     //用户注册
					system("cls");
					reg_user(users_head);
					break;
					case 2:     //管理员注册
					system("cls");
					reg_admin(admins_head);
					break;
				default:
					cout<<"您的输入有误，请重试"<<endl;
					goto reg_menu;
				}
				break;
				case 2:     //游客模式
				menu_tourist:
					system("cls");
					i=main.show_menu_tourist();
					switch(i){
						case 0:     //返回上级菜单
						system("cls");
						break;
					case 1:
						book_menu:    //查找图书
						system("cls");
						i=main.show_menu_books();
						switch (i){
						case 0:
							system("cls");
							break;
						case 1:
							system("cls");
							cout<<"请输入ISBN号：";
							cin>>tmp;
							books_head->lookup_isbn(tmp,books_head);
							break;
						case 2:
							system("cls");
							cout<<"请输入书名：";
							cin>>tmp;
							books_head->lookup_name(tmp,books_head);
							break;
						case 3:
							system("cls");
							cout<<"请输入作者名：";
							cin>>tmp;
							books_head->lookup_author(tmp,books_head);
							break;
						case 4:
							system("cls");
							cout<<"请输入出版社名：";
							cin>>tmp;
							books_head->lookup_publishing(tmp,books_head);
							break;
						default:
							cout<<"您的输入有误，请重试"<<endl;
							goto book_menu;
						}
						goto menu_tourist;
						case 2:     //查看图书借阅排行榜
						system("cls");
						books_head->book_list(books_head);
						goto menu_tourist;
						case 3:     //查看作者借阅排行榜
						system("cls");
						books_head->author_list(books_head);
						goto menu_tourist;
						case 4:     //查看读者借阅排行榜
						system("cls");
						users_head->user_list(users_head);
						goto menu_tourist;
						case 5:     //查看最新出版书籍
						system("cls");
						books_head->new_publish(books_head);
						goto menu_tourist;
					default:
						cout<<"您的输入有误，请重试"<<endl;
						goto menu_tourist;
						
					}
					break;
					case 3:     //学生模式
					us_re_lo:
						system("cls");
						cout<<"亲爱的同学，欢迎使用图书馆信息管理系统，请先登录以使用后续功能！"<<endl;
						system("pause");
						us_tmp=users_head->login(users_head);
						if(us_tmp==NULL)
						{
							cout<<"0-重新登录 1-返回上级目录"<<endl;
							cin>>i;
							if(i)
								break;
							else
								goto us_re_lo;
						}
						menu_user:
							system("cls");
							i=main.show_menu_user();
							switch(i){
								case 0:     //返回上级菜单
								system("cls");
								break;
								case 1:     //查书
								book_menu2:    //查找图书
								system("cls");
								i=main.show_menu_books();
								switch (i){
								case 0:
									system("cls");
									break;
								case 1:
									system("cls");
									cout<<"请输入ISBN号：";
									cin>>tmp;
									books_head->lookup_isbn(tmp,books_head);
									break;
								case 2:
									system("cls");
									cout<<"请输入书名：";
									cin>>tmp;
									books_head->lookup_name(tmp,books_head);
									break;
								case 3:
									system("cls");
									cout<<"请输入作者名：";
									cin>>tmp;
									books_head->lookup_author(tmp,books_head);
									break;
								case 4:
									system("cls");
									cout<<"请输入出版社名：";
									cin>>tmp;
									books_head->lookup_publishing(tmp,books_head);
									break;
								default:
									cout<<"您的输入有误，请重试"<<endl;
									goto book_menu2;
								}
								goto menu_user;
								case 2:     //还书
								system("cls");
								if(us_tmp==NULL)
								{
									cout<<"请先登录"<<endl;
									goto us_re_lo;
								}
								users_head->b_r(2,users_head,books_head,us_tmp);
								goto menu_user;
								case 3:     //借书
								system("cls");
								if(us_tmp==NULL)
								{
									cout<<"请先登录"<<endl;
									goto us_re_lo;
								}
								users_head->b_r(1,users_head,books_head,us_tmp);
								goto menu_user;
							case 4:
								system("cls");
								if(us_tmp==NULL)
								{
									cout<<"请先登录"<<endl;
									goto us_re_lo;
								}
								users_head->change_key(users_head,us_tmp);
								goto menu_user;
								case 5:     //查看借阅记录
								system("cls");
								if(us_tmp==NULL)
								{
									cout<<"请先登录"<<endl;
									goto us_re_lo;
								}
								users_head->show_borrow(us_tmp,books_head);
								goto menu_user;
								case 6:     //查看图书借阅排行榜
								system("cls");
								books_head->book_list(books_head);
								goto menu_user;
								case 7:     //作者借阅排行榜
								system("cls");
								books_head->author_list(books_head);
								goto menu_user;
								case 8:     //查看读者借阅排行榜
								system("cls");
								users_head->user_list(users_head);
								goto menu_user;
								case 9:     //出版时间排行榜
								system("cls");
								books_head->new_publish(books_head);
								goto menu_user;
							case 10:
								system("cls");
								us_tmp=NULL;
								cout<<"您已退出登录"<<endl;
								break;
							default:
								cout<<"您的输入有误，请重试"<<endl;
								goto menu_user;
							}
							break;
							case 4:     //管理员模式
							
							cout<<"亲爱的管理员，欢迎使用图书馆信息管理系统，请先登录以使用后续功能！"<<endl;
							ad_tmp=admins_head->login(admins_head);
							if(ad_tmp==NULL)
								break;
							
							menu_admin:
								system("cls");
								i=main.show_menu_admin();
								switch(i){
									case 0:     //返回上级菜单
									system("cls");
									break;
									case 1:     //追加图书
									system("cls");
									admins_head->add_book(books_head);
									goto menu_admin;
									case 2:     //删除图书
									system("cls");
									admins_head->del_book(books_head);
									goto menu_admin;
									case 3:     //更改图书
									system("cls");
									admins_head->change_book(books_head);
									goto menu_admin;
									case 4:     //查找学生
									system("cls");
									admins_head->lookup_user(users_head);
									goto menu_admin;
									case 5:     //追加学生
									system("cls");
									admins_head->add_user(users_head,books_head);
									goto menu_admin;
									case 6:     //删除学生
									system("cls");
									admins_head->del_user(users_head);
									goto menu_admin;
									case 7:     //更改学生
									system("cls");
									admins_head->change_user(users_head,books_head);
									goto menu_admin;
									case 8:     //重置学生密码
									system("cls");
									admins_head->reset_key(users_head);
									goto menu_admin;
								case 9:
									system("cls");
									ad_tmp=NULL;
									cout<<"您已退出登录"<<endl;
									system("pause");
									break;
								default:
									cout<<"您的输入有误，请重试"<<endl;
									goto menu_admin;
								}
								break;
		default:
			cout<<"您的输入有误，请重试"<<endl;
			break;
		}
	}
	system("cls");
	cout<<"感谢您的使用"<<endl;
	system("pause");
	return 0;
}
