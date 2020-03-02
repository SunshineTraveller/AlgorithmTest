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
#include <math.h>

#pragma mark ****************  practise1   ****************
/*
 有1、2、3、4 4个数字，能组成多少个互不相同且无重复数字的三位数，都是多少？
 */
void(practise1)(void) {
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
    printf("\n======================  practise1  ======================\n\n");
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
    printf("\n======================  practise2  ======================\n\n");
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
    printf("\n======================  practise3  ======================\n\n");
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
    printf("最终排序结果 \n");
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
    printf("最终排序结果 \n");
    for (int i = 0; i<count; i++) {
        printf("%d ",arrayb[i]);
    }
    printf("\n======================  practise4  ======================\n\n");
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
    printf("\n======================  practise5  ======================\n\n");
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
    printf("\n======================  practise6  ======================\n\n");
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
    printf("\n======================  practise7  ======================\n\n");
}

/*
 打印出所有的"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该数 本身。例如：153是一个"水仙花数"，因为153=1的三次方＋5的三次方＋3的三次方
 循环遍历 100 - 1000 内的数，判断是否满足条件  a³ = x³ + y³ + z³ 即可
 */
void practise8 (void) {
    
    for (int i = 100; i < 1000; i++) {
        
        int a = i % 100 % 10;   // 个位
        int b = i % 100 / 10;   // 十位
        int c = i / 100;        // 百位
        
        if (i == (a*a*a + b*b*b + c*c*c)) {
            printf("%d = %d³ + %d³ + %d³\n",i,c,b,a);
        }
    }
    
    printf("\n======================  practise8  ======================\n\n");
}

/*
 题目：将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5。
 分析：将该数除以 1-该数，能整除则继续
 下面给出两种算法，很明显第一种要优于第二种，第二种有两层循环嵌套，复杂度要比第一个高
 */
void practise9 (int number) {

    // 将该整数a从2开始，一直到a本身，遍历整除，若能整除，将a赋值成整除后的数，并将i置1重新开始新一轮的循环
    int a = number;
    printf("%d = ",number);
    for (int i = 2; i <= a; i++) {

        if (a % i == 0) {
            // 最后一位不加 *
            if (a == i) {
                printf("%d",i);
            }else {
                printf("%d * ",i);
            }
            a = a / i;
            i = 1;
        }
    }


    // 将该数从2开始整除，若能整除，将该数置为整除后的数，继续执行while循环，直至对i不能整除；然后i+1,进行下轮循环
    int n=number,i;
    printf("\n%d = ",n);
    for (i = 2; i <= n; i++) {

        while (n % i == 0) {
            printf("%d",i);
            n /= i;
            if (n!=1) {
                printf(" * ");
            }
        }
    }
    printf("\n======================  practise9  ======================\n\n");
}

/*
 题目：利用条件运算符的嵌套来完成此题：学习成绩>=90分的同学用A表示，60-89分之间的用B表示，60分以下的用C表示。
 */
void practise10 (int score) {
    char st = (score >= 90) ? 'A' : ((score >= 60) ? 'B' : 'C');
    printf(" score = %d , level = %c",score,st);
    printf("\n======================  practise10  ======================\n\n");
}

/*
 题目：输入两个正整数m和n，求其最大公约数和最小公倍数
 最大公约数 ： 两个数都能除尽的最大的数
 最小公倍数 ： 两个数都能被除尽的最小的数
 算法如下两种
 */
void practise11 (int m,int n) {
    
    // i 从 m n 中较小的数开始，分别用 m 和 n 去除这个数，第一次得到的这个数就是最大公约数
    for (int i = (m > n ? n : m); i >= 1; i--) {
        if (m % i == 0 && n % i == 0) {
            printf("%d %d 的最大公约数为 %d",m,n,i);
            break;
        }
    }

    // i 从 m n 中较大的数开始，分别用 i 去除 m 和 n，第一次m、n都被i整除的数就是最小公倍数
    for (int i = (m > n ? m : n); 1; i++) {
        if (i % m == 0 && i % n == 0) {
            printf(",%d %d 的最小公倍数为 %d",m,n,i);
            break;
        }
    }
    
    // 辗转相除法
    int a=m,b=n,t,r,q;
    if (a < b) {
        t = b;
        b = a;
        a = t;
    }
    r = a % b;
    q = a * b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    printf("这两个数的最大公约数是%d，最小公倍数是%d\n",b,q/b);
    printf("\n======================  practise11  ======================\n\n");
}

/*
 题目：输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
  一、通过 ASCII 码表查询范围
/ 二、通过字符大小比较
 */
void practise12 (void) {
    
    /*
     ASCII 码表的值如下
     数字 0~9       ASCII 48~57
     字母 a-zA-Z    ASCII 65~90, 97~122
     空格 ‘ ’       ASCII 32
     其他
     注意：判断条件为字符串的长度为实际长度
     */
    int numberCount     = 0;
    int alphmCount      = 0;
    int spaceCount      = 0;
    int specialCount    = 0;
    char a[100] = "12j 3  ok :, .";
    for (int i = 0; i<14; i++) {
        char tmpChar = a[i];
        // 方法一
//        // 数字
//        if (tmpChar >= 48 && tmpChar <= 57) {
//            numberCount++;
//        // 字母
//        }else if ((tmpChar >= 65 && tmpChar <= 90) || (tmpChar >= 97 && tmpChar <= 122)) {
//            alphmCount++;
//        // 空格
//        }else if(tmpChar == 32){
//            spaceCount++;
//        // 特殊字符等
//        }else {
//            specialCount++;
//        }
        
        // 方法二
        if ((tmpChar >= 'a' && tmpChar <= 'z') || (tmpChar >= 'A' && tmpChar <= 'Z')) {
            numberCount++;
        }else if (tmpChar >= '0' && tmpChar <= '9') {
            alphmCount++;
        }else if (tmpChar == ' ') {
            spaceCount++;
        }else {
            specialCount++;
        }
        
    }
    printf("数字有 %d 个， 字母 %d 个，  空格 %d 个， 特殊字符 %d 个",numberCount,alphmCount,spaceCount,specialCount);
    
    // 延伸: 字符是可以直接比较大小的，比较的依据是字符在ASCII表中的十进制大小 ，也就是方法1里的值，比如字符 'a' 在ASCII表中的十进制值就是 65.
    // *ptr+1 表达式 ，自右向左开始，先计算 ptr+1 ，即指针的值ptr+1（假设为x），然后取出x里对应的值 ，要注意运算符号的优先级，不然容易搞不清楚一个表达式的意思
    // int * sfd()    ----  一个函数，函数名 sfd  ,返回值类型为 int* 指针，参数为空void
    // int (*sfd)()   ----  一个函数指针，指针名为 sfd, 指针所指向的函数的返回值为int,参数为空void
    // 如下：
//    char aChar = 'A';
//    char *ptr = &aChar;
//    char c = *&aChar+3;
//    printf("\n %c  %c  %c  %c",*ptr,*ptr+1, *&aChar+2,c);
    printf("\n======================  practise12  ======================\n\n");
}


/*
 题目：求 s = func(x) = x + xx + xxx + xxxx +...+ x...x 的值，其中x是一个数字。
 分析如下：
 举例观察
 a=2,s=1;
 a=2,s=2+22;
 a=3,s=3+33+333;
 a=4,s=4+44+444+4444;
 a=5,s=5+55+555+5555+55555;
 ...
 a=n,s= n + nn + nnn +...+ (n...n);
        1   2     3          n个n
 
 总结每一项的算法公式：
 i == 0,  x * 10^0
 i == 1,  x * 10^i + x
 i == 2,  x * 10^i + x * 10^(i-1) + x
 i == 3,  x * 10^i + x * 10^(i-2) + x * 10^(i-1) + x
 ...   ,    ......
 i == n,  x * 10^n + x*10^(n-1)+ ... + x * 10^(n-(n-1)) + x
 
 1.先根据规律找出出每一项的公式    ---> 内存循环，用来计算每一项的值
 2.然后从第一项开始一直加到最后一项 ---> 外层循环，用来控制相加次数，并将每次新增项累加
 
 */
void practise13(double x) {printf("\n======================  practise8  ======================\n\n");
    
    int result = 0;  // 累加用
    printf("f(%d) = ",(int)x);
    for (double i = 0; i < x; i++) {
        
        // 记录 每次循环比上次循环多加出来的那个数,累加后就是当前项的总值
        int tmp0 = 0;
        
        // 计算 每次循环比上次循环多加出来的那个数
        for (double j = i; j >= 0; j--) {
            tmp0 += x * pow(10.0, j);
        }
        
        // 打印每次多出来的那个数
        if (i == x - 1) {
            printf("%d ",tmp0);
        }else {
            printf("%d + ",tmp0);
        }
        
        result += tmp0;
    }
    
    printf(" = %d",result);
    printf("\n======================  practise13  ======================\n\n");
}


/*
 题目：一个数如果恰好等于它的因子之和，这个数就称为"完数"。例如6=1＋2＋3.编程找出1000以内的所有完数。
 */
void practise14() {
    
    // 1. 求解每个数的因子
    // 2. 判断这个数是否 = 因子和
    // 3. 保存这个数
    
    int a[100]; // 保存完数的数组
    
    // 从1000开始找
    for (int i = 1; i <= 1000; i++) {
        
        int tmpValue = i;
        int tmpCount = 0; // 因子之和
        
        for (int j = 1; j< tmpValue; j++) {
            // 找该数的因子 并累加
            if (tmpValue % j == 0) {
                tmpCount += j;
            }
        }
        
        if (tmpCount == tmpValue) {
            printf("%d\n",tmpValue);
        }
        
    }
    
    printf("\n======================  practise14  ======================\n\n");
}


/*
 题目：一球从100米高度自由落下，每次落地后反跳回原高度的一半,再落下;求它在第10次落地时，共经过多少米？第10次反弹多高？
 第一次落地 100
 第二次落地 100+50+50
 第三次落地 100+50+50+25+25
 ...
 */
void practise15 (void) {
    
    float height = 100;
    float fantanHeight = 0;
    float resultHeight = height;
    
    for (int i = 0; i<10; i++) {
        resultHeight += 2*fantanHeight;
        fantanHeight = height/2;
        height =fantanHeight;
//        if (i==9) {
            printf("第%d次反弹高度为: %f\n",i+1,fantanHeight);
            printf("第%d次落地时，共经过%f米\n",i+1,resultHeight);
//        }
    }

    printf("\n======================  practise15  ======================\n\n");
}

/*
 题目：猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，还不瘾，又多吃了一个 第二天早上又将剩下的桃子吃掉一半，又多吃了一个。以后每天早上都吃了前一天剩下 的一半零一个。到第10天早上想再吃时，见只剩下一个桃子了。求第一天共摘了多少。
 */
void practise16() {
    
    int tenthCount = 1;     // 第10天的1个桃子，循环9次就得到第一天的了
    for (int i = 1; i<10; i++) {
        tenthCount = (tenthCount+1)*2;
    }
    printf("第一天共摘了%d个桃子",tenthCount);
    
    printf("\n======================  practise16  ======================\n\n");
}

/*
 打印如下图形
 ---*---
 --***--
 -*****-
 *******
 -*****-
 --***--
 ---*---
 
 1.每行x个元素，由 * 和 - 组成
 2.换行
 
 */
void practise17(int x) {
    
    // 方法一：外层负责换行，(我自己想的，因为太菜，废了半天时间...，但是适用性强，任何数都支持，下面的方法二只支持了行数为7的时候)
    for (int i = 1; i<=x; i++) {
        
        /* 内存负责打印
           将图案分为上下和左右4部分 左上，右上，左下，右下
         */
        for (int j = 1; j <= x; j++) {
            
            // 上半部分
            if (i <= x/2 + 1) {
                // 左半部分 + 右半部分
                if (j <= (x/2+1 - i) || j >= (x/2+1 + i) ) {
                    printf(".");
                }else {
                    printf("*");
                }
                
            // 下半部分
            }else {
                
                // 左半部分 + 右半部分
                if (j <= (i - (x/2+1)) || j > (x/2+1 + x-i) ) {
                    printf(".");
                }else {
                    printf("*");
                }
                
            }
        }
        // 换行
        printf("\n");
    }
    
    printf("\n\n\n");
    
    /*
     方法二 , '菜鸟教程' 里的方法,它将图案分为上下两部分打印
     每部分打印的都是左侧的空格和*,并没有打印右侧的空格，所以不适用于右侧也有花纹的图案比如下面的示例图
     
     ---*---
     --***--
     -*****-
     *******     示例图
     -*****-
     --***--
     ---*---
     
     
        *      ---> 上半部分：
       ***
      *****
     *******
     
      *****    ---> 下半部分：
       ***
        *
     */
    
    
    int i,j,k;
    for (int i = 0; i<=3; i++) {
        for (j=0; j<=2-i; j++) {
            printf(" ");
        }
        for (k=0; k<=2*i; k++) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 0; i<=2; i++) {
        for (j=0; j<=i; j++) {
            printf(" ");
        }
        for (k=0; k<=4-2*i; k++) {
            printf("*");
        }
        printf("\n");
    }
    
}

#pragma mark ****************  算法入门   ****************
void(AlgorithmEntrance)(void) {
    printf("\n************************************\n\n");
    practise17(65);
//    practise16();
//    practise15();
//    practise14();
//    practise13(6);
//    practise12();
//    practise11(12, 26);
//    practise10(89);
//    practise9(100);
//    practise8();
//    practise7();
//    practise6();
//    practise5();
//    Practise4();
//    Practise3();
//    Practise2();
//    practise1();
    printf("\n************************************\n\n");
}
