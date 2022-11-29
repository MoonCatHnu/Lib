//本文件用于实行管理员权力，对图书进行增删改查，对用户密码进行统一重置
#include "hnulib.h"
#include <iostream>
#include <fstream>
using namespace std;

void admin::add_book(books *books_head){    //暂时设计成放到队尾
    books *h=books_head;
    while(h->next!=NULL){
        h=h->next;
    }
    books *node=new books;
    start:
    system("cls");
    cout<<"请输入图书名：";
    cin>>h->name;
    cout<<endl<<"请输入图书isbn号：";
    cin>>h->isbn;
    cout<<endl<<"请输入图书作者名：";
    cin>>h->author;
    cout<<endl<<"请输入图书出版社：";
    cin>>h->published;
    cout<<endl<<"请输入图书发行时间：";
    cin>>h->publishing;
    cout<<endl<<"请输入图书价格：";
    cin>>h->price;
    cout<<endl<<"请输入图书页数：";
    cin>>h->pages;
    cout<<endl<<"请输入图书描述（回车停止输入）：";
    cin>>h->description;
    cout<<endl<<"请输入已被借阅次数：";
    cin>>h->b_num;
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
    h->borrow=false;
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
                            //接口暂时还没实现
            break;
        case 2:
            cout<<"请输入isbn：";
            cin>>T;
            temp=books_head->lookup_isbn(T,books_head);
        case 3:
            cout<<"请输入书名：";
            cin>>T;
            temp=books_head->lookup_name(T,books_head);
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
                        //暂时没有接口
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
    while (users_head)
    {
        user* tmp=users_head;
        if(tmp->account_num==str)
        {
            tmp->key=123456;
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

    cout<<"没有相应账号的学生0-重新查找 1-退出："<<'\n';
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
        if(tmp->account_num==amount){
            sign=1;
            break;
        }
        tmp=tmp->next;
    }
    if(sign){
        cout<<"账号或密码错误，请重试或返回上级菜单，键入并回车："<<endl<<"0-重新输入 1-返回上级菜单：";
        cin>>sign;
        if(sign){
            return NULL;
        }
        else{
            goto start;
        }
    }
    else{
        if(tmp->key==key){
            cout<<"登陆成功！"<<endl;
            system("pause");
            system("cls");
            return tmp;
        }
        else{
            cout<<"账号或密码错误，请重试或返回上级菜单，键入并回车："<<endl<<"0-重新输入 1-返回上级菜单：";
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
