#include "hnulib.h"
#include <fstream>
#include <string>
using namespace std;

//此文件编写每次程序开始时进行对图书、管理员、用户的数据处理函数，返回值为链表头结点
books* loading_books(int &num){
    ifstream ifs;
    ifs.open("books.txt",ios::in);
    num=0;
    cout<<"程序加载中(0%)。。。。。。"<<endl;
    char ch;
    ifs>>ch;
    books *head=new books;
    head->next=NULL;
    if(ifs.eof()){
        ifs.close();
    }

    else{
        ifs.close();    //重新打开文件；
        ifs.open("books.txt",ios::in); //此处及以下文件路径需要改动
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
        books *end=head;
        while(ifs>>id&&ifs>>isbn&&ifs>>name&&ifs>>author&&ifs>>publishing&&ifs>>published&&ifs>>price&&ifs>>pages&&ifs>>description&&ifs>>b_num){
            books *node=new books;
            node->id=id;
            node->isbn=isbn;
            node->name=name;
            node->author=author;
            node->publishing=publishing;
            node->published=published;
            node->price=price;
            node->pages=pages;
            node->description=description;
            node->b_num=b_num;
            node->borrow=false;
            end->next=node;
            end=end->next;
            num++;
        }
        end->next=NULL;
        ifs.close();
    }
    system("cls");
    return head;
}

admin* loading_admin(int &num){
    ifstream ifs;
    ifs.open("admin.txt",ios::in);
    num=0;
    cout<<"程序加载中(25%)。。。。。。"<<endl;
    char ch;
    ifs>>ch;
    admin *head=new admin;
    head->next=NULL;
    if(ifs.eof()){
        ifs.close();
    }

    else{
        ifs.close();    //重新打开文件；
        ifs.open("admin.txt",ios::in); //此处及以下文件路径需要改动
        string account_num,key;
        admin *end=head;
        while(ifs>>account_num&&ifs>>key){
            admin *node=new admin;
            node->account_num=account_num;
            node->key=key;
            end->next=node;
            end=end->next;
            num++;
        }
        end->next=NULL;
        ifs.close();
    }
    system("cls");
    return head;
}

user* loading_users(int &num,books *head_books){ //用户需要录入借阅记录，更改图书的借阅信息，此处引入图书链表的头指针
    ifstream ifs;
    ifs.open("user.txt",ios::in);
    num=0;
    cout<<"程序加载中(75%)。。。。。。"<<endl;
    char ch;
    ifs>>ch;
    user *head=new user;
    head->next=NULL;
    if(ifs.eof()){
        ifs.close();
    }

    else{
        ifs.close();    //重新打开文件；
        ifs.open("user.txt",ios::in); //此处及以下文件路径需要改动
        string account_num,key;
        int log_num;
        user *end=head;
        while(ifs>>account_num&&ifs>>key&&ifs>>log_num){
            user *node=new user;
            node->account_num=account_num,node->key=key,node->log_num=log_num;
            if(log_num!=0){
                for(int i=0;i<log_num;i++){
                    ifs>>node->log[i];
                    for(books *h=head_books->next;h!=NULL;h=h->next){
                        if(node->log[i]==h->id){
                            h->borrow=true;
                            break;
                        }
                    }
                }
            }
            end->next=node;
            end=end->next;
            num++;
        }
        end->next=NULL;
        ifs.close();
    }
    system("cls");
    cout<<"程序加载完成！"<<' ';
    system("pause");
    system("cls");
    return head;
}


