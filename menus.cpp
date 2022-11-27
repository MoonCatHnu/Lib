#include<iostream>
#include "hnulib.h"
using namespace std;
//哦，这是个敷衍的菜单（爬）
int menu::show_menu_main() //等等，你对这个主菜单的用法的构想是不是和我理解的不一样
{
    int i;
    cout<<"*********************************************"<<'\n';
    cout<<"*              图书馆信息管理系统            *"<<'\n';
    cout<<"*                                           *"<<'\n';
    cout<<"*                 1.注册账号                 *"<<'\n';
    cout<<"*                 2.游客模式                 *"<<'\n';
    cout<<"*                 3.学生模式                 *"<<'\n';
    cout<<"*                 4.管理员模式               *"<<'\n';
    cout<<"*           0.退出图书馆信息管理系统          *"<<'\n';
    cout<<"*                                           *"<<'\n';
    cout<<"*********************************************"<<'\n';

    cin>>i;
    return i;
        
}

int show_menu_reg()
{
    int i;
    cout<<"*********************************************"<<'\n';
    cout<<"*              图书馆信息管理系统            *"<<'\n';
    cout<<"*                                           *"<<'\n';
    cout<<"*                 1.学生注册                 *"<<'\n';
    cout<<"*                 2.管理员注册               *"<<'\n';
    cout<<"*                 0.返回上级目录             *"<<'\n';
    cout<<"*                                           *"<<'\n';
    cout<<"*********************************************"<<'\n';

    cin>>i;
    return i;
}

int menu::show_menu_admin()
{
    int i;
    cout<<"*********************************************"<<'\n';
    cout<<"*              图书馆信息管理系统            *"<<'\n';
    cout<<"*                                           *"<<'\n';
    cout<<"*                 1.追加图书                 *"<<'\n';
    cout<<"*                 2.删除图书                 *"<<'\n';
    cout<<"*                 3.更改图书                 *"<<'\n';
    cout<<"*                 4.重置学生密码             *"<<'\n';
    cout<<"*                 0.返回上级目录             *"<<'\n';
    cout<<"*                                           *"<<'\n';
    cout<<"*********************************************"<<'\n';

    cin>>i;
    return i;
}

int menu::show_menu_user()
{
    int i;
    cout<<"*********************************************"<<'\n';
    cout<<"*              图书馆信息管理系统            *"<<'\n';
    cout<<"*                                           *"<<'\n';
    cout<<"*                 1.查找图书                 *"<<'\n';
    cout<<"*                 2.归还图书                 *"<<'\n';
    cout<<"*                 3.借阅图书                 *"<<'\n';
    cout<<"*                 4.查看借阅记录             *"<<'\n';
    cout<<"*                 5.查看图书借阅排行榜       *"<<'\n';
    cout<<"*                 6.查看作者借阅排行榜       *"<<'\n';
    cout<<"*                 7.查看最新出版书籍         *"<<'\n';
    cout<<"*                 0.返回上级目录             *"<<'\n';
    cout<<"*                                           *"<<'\n';
    cout<<"*********************************************"<<'\n';

    cin>>i;
    return i;
}

int menu::show_menu_tourist()
{
    int i;
    cout<<"*********************************************"<<'\n';
    cout<<"*              图书馆信息管理系统            *"<<'\n';
    cout<<"*                                           *"<<'\n';
    cout<<"*                 1.查找图书                 *"<<'\n';
    cout<<"*                 2.查看图书借阅排行榜       *"<<'\n';
    cout<<"*                 3.查看作者借阅排行榜       *"<<'\n';
    cout<<"*                 4.查看最新出版书籍         *"<<'\n';
    cout<<"*                 0.返回上级目录             *"<<'\n';
    cout<<"*                                           *"<<'\n';
    cout<<"*********************************************"<<'\n';

    cin>>i;
    return i;
}

