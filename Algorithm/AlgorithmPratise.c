//
//  AlgorithmPratise.c
//  Algorithm
//
//  Created by CBCT_MBP on 2020/2/27.
//  Copyright © 2020 Sunshine. All rights reserved.
//

#include "AlgorithmPratise.h"

#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

#pragma mark ****************  practise1   ****************
/*
 有1、2、3、4 4个数字，能组成多少个互不相同且无重复数字的三位数，都是多少？
 */
void(practise1)(void) {
    printf("practise1");
    int count = 0;
    for(int i = 1;i <= 4;i++) {
        for(int j = 1;j <= 4; j++) {
            for(int k = 1; k <= 4;k++) {
                if(i != j && j != k && k != i) {
                    count++;
                    printf("%d%d%d,",i,j,k);
                }
            }
        }
    }
    printf("\n1234 4个数字能组成 %d 个无重复不相同的数字",count);
}


#pragma mark ****************   Practise2  ****************
/*
 题目：企业发放的奖金根据利润提成。

 利润(I)低于或等于10万元时，奖金可提10%；
 利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；
 20万到40万之间时，高于20万元的部分，可提成5%；
 40万到60万之间时高于40万元的部分，可提成3%；
 60万到100万之间时，高于60万元的部分，可提成1.5%；
 高于100万元时，超过100万元的部分按1%提成。
 从键盘输入当月利润I，求应发放奖金总数？
 */
void(Practise2)(void) {
    printf("Practise Two\n");
    
    double bonus = 0;
    double currentMonthProfit = 900000;

//    scanf("请输入当月利润 %lf ",&currentMonthProfit);  Xcode 的 scanf 函数有问题
    printf("计算发放奖金总数中,请稍等...\n");
    
    if(currentMonthProfit <= 10000) {
        
        bonus = currentMonthProfit * 0.1;
        
    }else if (currentMonthProfit < 200000) {
        
        bonus = 100000 * 0.1 + (currentMonthProfit - 100000) * 0.075;
        
    }else if (currentMonthProfit < 400000) {
        
        bonus = 100000 * 0.1 + 100000 * 0.075 + (currentMonthProfit - 200000) * 0.05;
        
    }else if (currentMonthProfit < 600000) {
        
        bonus = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 + (currentMonthProfit - 400000) * 0.03;
        
    }else if (currentMonthProfit < 1000000) {
        
        bonus = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 + 200000 * 0.03 + (currentMonthProfit - 600000) * 0.015;
        
    }else {
        
        bonus = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 + 200000 * 0.03 + 400000 * 0.015 + (currentMonthProfit - 1000000) * 0.01;
        
    }
    printf("应发放的奖金总数为 %lf",bonus);
}

#pragma mark ****************  Practise3   ****************
/*
 题目：一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
 假设该数为 x,
 1、 x + 100 = n²; x + 168 = m²;
 2、 m²-n² = (m+n)(m-n) = 168;
 3、 设 i = m + n; j = m - n; i*j = 168, i和j至少有一个是偶数
 4、 m = (i+j)/2; n = (i-j)/2; i 和 j 要么都是偶数，要么都是基数
 5、 由3和4推导克制，i和j均是 >= 2 的偶数
 6、 由于 i * j = 168; j >= 2；代入 => 1 < i < 168/2 + 1;
 7、 接下来将i的所有数字循环计算即可
 */
void(Practise3)(void) {
    
    int x,m,n,i,j;
    
    for(i = 2; i < 85 ; i++) {
        
        if(168 % i == 0) {
            
            j = 168 / i;
            m = (j+i)/2;
            n = (i-j)/2;
            
            // 依据 第二条 m²-n² = 168 ==>
            if(m * m - n * n == 168) {
                x = n * n - 100;
                printf("%d + 100 = %d * %d; i = %d, j = %d \n",x,n,n,i,j);
                printf("%d + 168 = %d * %d; i = %d, j = %d \n",x,m,m,i,j);
                printf("x的值为 %d\n\n",x);
            }
        }
    }
    
}

#pragma mark ****************   Practise4  ****************
/*
 排序
 题目：输入n个整数x,y,z...，请把这n个数由小到大输出 / 由大到小输出
 */
void Practise4 (void) {
    int array[] = {20,6,5,23,3,8,7,1};
    int count = sizeof(array)/sizeof(array[0]);
    printf("选择排序  由小到大排序\n");
    /*
     选择排序
     外层循环每次拿出一个数a，内从循环每次将剩余的数和a比大小，遇到比a小的，就和a换位置；每次内层循环结束m，都会找出一个最小的值放到最前面，以此类推，这样外层循环结束后就得到由小到大的排序
     */
    for (int i = 0; i<count-1; i++) {
        for (int j = i+1; j<count; j++) {
            
            if (array[i] > array[j]) {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
        for (int i = 0; i<count; i++) {
            printf("%d ",array[i]);
        }
        printf("\n");
    }
    for (int i = 0; i<count; i++) {
        printf("%d ",array[i]);
    }
    
    int arrayb[] = {20,6,5,23,3,8,7,1};
    printf("\n\n冒泡排序  由大到小排序\n");
    /*
     冒泡排序 由大到小
     外层控制循环次数，内层循环每次比较相邻的数，将大的放到前面，每轮内存循环下来，凡是相邻左<右的都换一次位置。等外层循环结束，得到由大到小的排序
     */
    for (int i = 0; i<count; i++) {
        for (int j = 0; j < count-i; j++) {
            
            if (arrayb[j] < arrayb[j+1]) {
                
                int tmp = arrayb[j];
                arrayb[j] = arrayb[j+1];
                arrayb[j+1] = tmp;
                
            }
        }
        for (int k = 0; k<count; k++) {
            printf("%d ",arrayb[k]);
        }
        printf("\n");
        
    }
    
    for (int i = 0; i<count; i++) {
        printf("%d ",arrayb[i]);
    }
    
}

#pragma mark ****************  practise5   ****************
/*
 输出9*9口诀
 看图总结规律
 1*1 = 1;
 1*2 = 2; 2*2 =4;
 1*3 = 3; 2*3 =6; 3*3 =9;
 ...
 ...
 1*9 = 9; 2*9 = 18;..., 9*9 = 81;
 共9行，每行输出和行数有关
 */
void practise5 (void) {
    printf("9*9乘法表\n");
    // i 为 列， j 为 行
    for (int i = 1; i<=9; i++) {
        for (int j = 1; j <= i; j++) {
            printf("| %d * %d = %d ",j,i,(i*j));
            // 相等的时候换行
            if (i == j) {
                printf("\n");
            }
        }
    }
}

/*
 题目：菲波那切数列
 规律为数列 1,1,2,3,5,8,13,21....，即下个数是上两个数之和。输出前40个数
          0,1,2,3,4,5,6, 7...
 */
void practise6 (void) {
    int a1 = 1;
    int a2 = 1;
    // 每次输出俩数，循环20次即可
    for (int i = 1; i<=20; i++) {
        printf("%12d%12d",a1,a2);
        if (i%2==0) {
            printf("\n");
        }
        a1 = a1+a2;
        a2 = a1+a2;
    }
    
    printf("\n\n");
    int a[40];
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i<=40; i++) {
        a[i] = a[i-1] + a[i-2];
    }
    for (int i = 0; i<40; i++) {
        printf("%12d",a[i]);
        if ((i+1) % 4 == 0) {
            printf("\n");
        }
    }
}

/*
 判断101到200之间的素数
 素数：只有1和它自己 才能被整除的数 ，
 */
void practise7 (void) {
    
    int count = 0;
    // 方法1  若该数能被整除的数有且只有两个，则为素数
    for (int i = 101; i <= 200; i++) {
        count = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                count++;
            }
        }
        if (count == 2) {
            printf("%d   ",i);
        }
    }
    
    printf("\n\n");
     
    // 方法2 若该数能被2到该数-1之间的数整除，跳出循环继续执行
    int i,j;
    for (i = 101; i<200; i++) {
        // 内存for循环中，若i为素数，则不会break出去内层for循环,最后一次内存循环，执行j++后会和i相等
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                break;
            }
        }
        if (j==i) {
            printf("%d   ",i);
        }
    }
    
}

/*
 打印出所有的"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该数 本身。例如：153是一个"水仙花数"，因为153=1的三次方＋5的三次方＋3的三次方
 */
void practise8 (void) {
    
}

#pragma mark ****************  算法入门   ****************
void(AlgorithmEntrance)(void) {
    printf("\n************************************\n\n");
//    practise7();
//    practise6();
//    practise5();
//    Practise4();
//    Practise3();
//    Practise2();
//    practise1();
    printf("\n************************************\n\n");
}
