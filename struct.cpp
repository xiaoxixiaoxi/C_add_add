//
// Created by mac on 2021/4/25.
//
//结构体学习
#include <iostream>
#include <cstring>
using namespace std;

//定义一个结构体
struct Books{
    char  title[50];
    char author[50];
    char  subject[100];
    int book_id;
};
void printBook(struct Books book){
    cout<<"值传入结构体----\n"<<book.title <<endl;
    cout<<book.author <<endl;
    cout<<book.subject <<endl;
    cout<<book.book_id <<endl;
}
void printBook2(struct Books *book){
    cout<<"指针传入结构体----\n"<<book->title <<endl;
    cout<<book->author <<endl;
    cout<<book->subject <<endl;
    cout<<book->book_id <<endl;
}

int main()
{
    //    定义自定义结构体Books的变量Book1
    Books Book1;
    Book1={"营销成功","小溪","一部书的自定义结构体测试",0001};

    cout << "第一本书标题 : " << Book1.title <<endl;
    cout << &Book1<<endl;

//    新建指针
    Books *p= &Book1;

    printBook(Book1);
    printBook2(p);

    return 0;
};

