/*******************************************************************
Copyright (C) 2017 - All Rights Reserved by
重庆邮电大学xxx

文 件 名: main.c
作    者: xxxxx
编写日期: xxxxx
说    明: 一个随机数集合含有最多100个随机数，打印输出随机数组，要求找出最小的那个随机数

历史纪录:
  <作者>	<日期>		  <版本>		<内容>
1、xxxx 	8/11/2017     1.0.0	        1. 编写xxxx；

*******************************************************************/

#include <stdio.h> // for printf
#include <stdlib.h> // for malloc,free,srand,rand,system
#include <time.h> // for time
#include "find_min.h"
#include "output_all.h"

int main()
{
    srand(time(NULL)); // 用时间作为随机数种子
    // 随机数为SZ个，0 <= SZ <= 100
    const unsigned MOD = 100,SZ = rand() % MOD;
    // 在堆上开辟一段空间，存储产生的随机数
    unsigned *arr = (unsigned *)malloc(SZ * sizeof(SZ));
    unsigned k = 0;
    printf("随机数为: %d  个！ \n",SZ);
    for(; k < SZ; ++k)
        arr[k] = rand();
    // 输出产生的所有随机数
    output_all(arr, SZ);
    // 找到最小的那个随机数，并返回它的下标
    unsigned min = find_min(arr, SZ);
    // 如果集合非空必然存在最小值，输出它

    if(0 != SZ)
        printf("The minimum in all : %d \n",arr[min]);
    // 释放分配的堆内存空间
    free(arr);
    // 让系统等待，以便我们查看结果是否正确
    system("PAUSE");
    printf("Hello world!\n");
    return 0;
}
