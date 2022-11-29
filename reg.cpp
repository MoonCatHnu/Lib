//本文件编写用户与管理员注册账号的功能，同时分别保存在user.txt与admin.txt中
#include <iostream>
#include "hnulib.h"
using namespace std;

void reg_admin(admin *admin_head){   //需要更改管理员链表数据，目前仅支持一个密钥
    ifstream ifs;
    system("cls");
    string key,key_temp;
    int sign;
    while(1){
        ifs.open("管理员注册密钥.txt",ios::in); //这里路径要改一改
        cout<<"请输入管理员注册密钥"<<endl<<"key:";
        cin>>key_temp;
        while(ifs>>key){
            if(!key.compare(key_temp)){
                cout<<"key正确！"<<endl;
                ifs.close();
            system("pause");
            system("cls");
            goto next;
            }
        }
            cout<<"key错误！请重新输入或返回上级菜单"<<endl;
            cout<<"1-返回上级菜单  2-重新输入"<<endl;
            cin>>sign;
            if(sign==1){
                system("cls");
                ifs.close();
                return;
            }
            else{
                system("cls");
                ifs.close();
                continue;
            }
    }
    next:
    admin *h=admin_head;
    while(h->next!=NULL){   //找到链表尾部
        h=h->next;
    }
    admin *node=new admin;
    cout<<"欢迎注册！"<<endl<<"账号：";
    cin>>node->account_num;
    cout<<endl<<"密码：";
    cin>>node->key;
    cout<<"请等待..."<<endl;
    h->next=node;
    node->next=NULL;
    save_admins(admin_head);
    cout<<"注册成功！"<<endl;
    system("cls");
}

void reg_user(user *user_head)  //突然意识到还有账号重复问题要解决
{
    system("cls");
    int sign;
    user *h=user_head;
    while(h->next!=NULL){
        h=h->next;
    }
    user *node=new user,*tmp;
    string ac_;
    re_ac:
    system("cls");
    tmp=user_head;
    cout<<"欢迎注册！"<<endl<<"账号：";
    cin>>ac_;
    while (tmp!=NULL)
    {
        if(tmp->account_num.compare(ac_)!=0)
        {
            tmp=tmp->next;
        }
        else
        {
            cout<<"账号已被注册，请重新输入或退出，键入0-退出 其他数字-重新输入：";
            cin>>sign;
            if(sign){
                goto re_ac;
            }
            else{
                delete node;
                return;
            }
        }
    }
    node->account_num=ac_;
    cout<<endl<<"密码：";
    cin>>node->key;
    node->log_num=0;
    h->next=node;
    node->next=NULL;
    cout<<endl<<"是否要保存注册？键入 0-保存 其他数字-取消并返回上级目录：";
    cin>>sign;
    if(!sign){
        save_users(user_head);
        cout<<"注册成功！"<<endl;
        system("pause");
        system("cls");
        return;
    }
    else{
        delete node;
        return;
    }
}
