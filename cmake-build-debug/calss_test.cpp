//
// Created by mac on 2021/4/25.
//
//学习类
#include <iostream>
#include <cstring>
using namespace std;

/*
 * 构造函数（初始化 类似python---init），析构函数
1，拷贝构造函数

*/





//定义类
class Boxs{
//    定义权限
public:
//    定义参数
    double length;
    double breadth;
    double height;
//    定义成员方法
    double getv(){
        return length*breadth*height;
    }
    //    声明成员函数
    void set(double l,double b,double  h);

};

//类中的定义函数
void Boxs::set(double l, double b, double h) {
    length=l;
    breadth=b;
    height=h;

}


int main(){
    Boxs box1;
    box1={1,2,3};
    cout<<"宽度："<<box1.breadth<<endl;
    double v;
    //    v = box1.breadth*box1.height*box1.length;
    v = box1.getv();
    cout<<"体积："<<v<<endl;


    Boxs box2;
    box2.set(10,30,50);
    cout<<"体积2："<<box2.getv()<<endl;



    return 0;
}