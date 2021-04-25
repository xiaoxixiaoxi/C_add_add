//
// Created by mac on 2021/4/25.
//

#include <iostream>
#include <ctime>

using namespace std;

int main ()
{
    //    获取当前时间
    time_t t =time(0);

    char* dt = ctime(&t);

    cout<< dt <<endl;

    return 0;
}