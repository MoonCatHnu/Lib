# ifndef _HNULIB_H
# define _HUNLIB_H

#include <iostream>
#include <fstream>
using namespace std;

class books;
class admin;
class user;
class menu;
class operate;
class tourist;

class books{    //图书信息
friend void save_books(books *books_head);
friend struct books* loading_books(int &num);
friend struct user* loading_users(int &num,books *head_books);
friend user;
friend admin;
friend menu;
public:
    bool borrow;    //该图书是否被借阅
    books* look_up_id(int id,books *books_head);    //id查找图书
    books* lookup_name(string name,books *book_head);  //书名查找图书
    books* lookup_isbn(string isbn,books *book_head);  //isbn查找图书
    void lookup_author(string author,books *book_head);  //作者查找图书
    void lookup_publishing(string publishing,books *book_head);  //出版社查找图书
    void book_list(books *book_head);   //图书借阅次数排行榜
    void author_list(books *book_head); //作者借阅次数排行榜
    void new_publish(books *book_head); //最新出版排行榜
    books* dictionary_list(books *book_head); //字典序排序

protected:
    int id; //图书id
    string isbn;    //图书isdn，较长
    string name;   //图书名，有中文
    string author; //作者名
    string publishing; //出版社名字
    string published;   //出版日期
    double price;   //图书价格，含小数
    int pages;  //图书页数
    string description;    //图书描述
    long int b_num;   //图书被借阅次数
    struct books *next;

};

class user{ //读者（用户）
friend void save_users(user *user_head);
friend struct user* loading_users(int &num,books *head_books);
friend void reg_user(user *user_head);
friend admin;
friend menu;
public:
    user* login(user *user_head);   //登陆
    void change_key(user *user_head,user *user_temp);  //更改密码
    void show_borrow(user *user_head,books *); //查看借阅记录
    void b_r(int,user *user_head,books *,user *user_temp); //借阅或归还图书
    void user_list(user *user_head);
protected:
    string account_num;   //账号
    string key;   //密码
    int log_num;    //借阅书的数目
    int log[20];    //借阅记录，最多借阅20本书
    user *next;

};

class admin{    //管理员
friend void save_admins(admin *admin_head);
friend struct admin* loading_admin(int &num);
friend void reg_admin(admin *admin_head);
public:
    admin* login(admin *admin_head);   //登陆
    void add_book(books *books_head);    //增加图书
    void del_book(books *books_head);    //删除图书
    void change_book(books *books_head);    //更改图书信息
    void lookup_user(user *user_head);  //查找用户
    void add_user(user *user_head,books *books_head); //增加用户
    void del_user(user *user_head); //删除用户
    void change_user(user *user_head,books *books_head);  //更改账号信息（账号、密码、借阅记录）
    void reset_key(user *users_head);   //重置学生密码
protected:
    string account_num;
    string key;
    admin *next;

};

class menu{
    public:
    int show_menu_main();  //主目录
    int show_menu_reg(); //注册目录
    int show_menu_admin(); //管理员目录
    int show_menu_user();  //使用者目录
    int show_menu_tourist();  //游客目录
    int show_menu_books();  //查找图书
};
class tourist{  //游客（待开发）


};

struct books* loading_books(int &num);
struct admin* loading_admin(int &num);
struct user* loading_users(int &num,books *head_books);
void reg_admin(admin *admin_head);
void reg_user(user *user_head);
void save_books(books *books_head);  //保存更新（增、删、改等）信息到文件中
void save_users(user *user_head);  //保存更新信息到文件中
void save_admins(admin *admin_head); //保存更新信息到文件中
# endif
