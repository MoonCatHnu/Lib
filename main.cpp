#include "hnulib.h"
#include <iostream>
using namespace std;

int main(){
    int books_num=0,users_num=0,admins_num=0;
    books *books_head=loading_books(books_num);
    admin *admins_head=loading_admin(admins_num);
    user *users_head=loading_users(users_num,books_head);
    menu main;
    int i,sign=1;
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
            case 2:     //游客模式
                menu_tourist:
                system("cls");
                i=main.show_menu_tourist();
                switch(i){
                    case 0:     //返回上级菜单
                    system("cls");
                    break;
                    case 1:     //查找图书
                            //需要图书查找目录
                    case 2:     //查看图书借阅排行榜
                        system("cls");
                        books_head->book_list(books_head);
                        break;
                    case 3:     //查看作者借阅排行榜
                        system("cls");
                        books_head->author_list(books_head);
                        break;
                    case 4:     //查看最新出版书籍
                        system("cls");
                        books_head->new_publish(books_head);
                        break;
                    default:
                        cout<<"您的输入有误，请重试"<<endl;
                        goto menu_tourist;

                }
            case 3:     //学生模式

                        //需要登录目录

                menu_user:
                system("cls");
                i=main.show_menu_user();
                switch(i){
                    case 0:     //返回上级菜单
                        system("cls");
                        break;
                    case 1:     //查书
                            //需要查书目录
                    case 2:     //还书
                        system("cls");
                        users_head->b_r(2,users_head,books_head);
                        break;
                    case 3:     //借书
                        system("cls");
                        users_head->b_r(1,users_head,books_head);
                        break;
                    case 4:     //查看借阅记录
                        system("cls");
                        users_head->show_borrow(users_head,books_head);
                        break;
                    case 5:     //查看图书借阅排行榜
                        system("cls");
                        books_head->book_list(books_head);
                        break;
                    case 6:     //作者借阅排行榜
                        system("cls");
                        books_head->author_list(books_head);
                        break;
                    case 7:     //出版时间排行榜
                        system("cls");
                        books_head->new_publish(books_head);
                        break;
                    default:
                        cout<<"您的输入有误，请重试"<<endl;
                        goto menu_user;
                }
            case 4:     //管理员模式

                            //需要登录目录

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
                        break;
                    case 2:     //删除图书
                        system("cls");
                        admins_head->del_book(books_head);
                        break;
                    case 3:     //更改图书
                        system("cls");
                        admins_head->change_book(books_head);
                        break;
                    case 4:     //重置学生密码
                        system("cls");
                        admins_head->reset_key(users_head);
                        break;
                    default:
                        cout<<"您的输入有误，请重试"<<endl;
                        goto menu_admin;
                }
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