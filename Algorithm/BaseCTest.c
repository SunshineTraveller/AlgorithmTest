//
//  BaseTest.c
//  Algorithm
//
//  Created by CBCT_MBP on 2020/2/20.
//  Copyright © 2020 Sunshine. All rights reserved.
//


#include "BaseCTest.h"
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

/* 获取变量大小 */
void(getVariableSize)(void) {
    printf("int--%lu float--%lu long--%lu double--%lu char--%lu \n",sizeof(int),sizeof(float),sizeof(long),sizeof(double),sizeof(char));
}
/* 获取字符常量 */
void(getConstSpecialChar)(void) {
    printf("\\ \n \' \" \r \t \v  \a \?  \b \f \r \n");
}
/* static 关键字测试 */
void(staticSpecifyTest)(void) {
    static int staticVariable = 0;  // static修饰的局部变量
    staticVariable++;
    printf("%d - ",staticVariable);
}
/* 普通测试 */
void(nonStaticTest)(void) {
    int nonStaticVariable     = 0;  // 普通局部变量
    nonStaticVariable++;
    printf("%d = ",nonStaticVariable);
}

/*
 存储类
 %d 有符号十进制整数
 %u 无符号十进制
 %o 八进制整数
 %c 字符
 %p 指针
 %s 字符串
 %x 十六进制
 */
void(storeCategory)(void) {
    auto int a = 10; // auto是所有局部变量的默认存储类，auto只能用于函数内
    printf("%d",a);
    /*
     static 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。因此，使用 static 修饰局部变量可以在函数调用之间保持局部变量的值。局部变量用static修饰时，变量只会 初始化一次 ！下次再次进入该方法时变量不会重新初始化为某个值
     static 修饰符也可以应用于全局变量，当 static 修饰全局变量时，会使变量的作用域限制在声明它的文件内。
     全局声明的一个 static 变量或方法可以被任何函数或方法调用，只要这些方法出现在跟 static 变量或方法同一文件中。
     */
    // 调用 staticSpecifyTest 10次
    printf("static test  ");
    for(int i = 0;i<10;i++) {
        staticSpecifyTest();
    }
    printf("\n");
    printf("nonstatic test  ");
    for(int i = 0;i<10;i++) {
        nonStaticTest();
    }
}
/* 打印二进制 */
void(printBinary)(int var) {
    unsigned char *p = (unsigned char *)&var + 3;
    for(int i = 0;i <= 3;i++) {
        int var2 = *(p-i);
        for(int i = 7;i >= 0;i--) {
            if(var2 & (1 << i)) {
                printf("1");
            }else {
                printf("0");
            }
        }
    }
}
/* 运算测试 */
void(operatorTest)(void) {
    /*
     2进制    obxxxxxx
     8进制    0
     16进制   0x 0X
     10进制   不带0的
     后缀可带  L(long)  U(unsigned)
     
     & 返回变量的地址  %p 打印变量的内存地址，  &a 给出变量的实际地址
     * 指向一个变量   *a, 将指向一个变量
     */
    
    unsigned int a = 0b000000;  // 0
    unsigned int b = 0b000001;  // 1
    int bb = 1;
    printf("\n %p  %p  %s",&bb,&bb+3,(unsigned char *)(&bb + 3));
    printf("\n");
    printBinary(a);
    printf("\n");
    printBinary(b);
    printf("\n");
    printBinary(a & b);
    printf("\n");
    printBinary(a ^ b);
    printf("\n");
    printBinary(a<<1);
    printf("\n");
    printBinary(a>>1);
    printf("\n");
    printBinary(b<<1);
    printf("\n");
    printBinary(b>>1);
    printf("\n\n\n");
    
    int c = 4;
    int *pointer;  // 声明一个int类型的指针
    
    pointer = &c;
    printf("%d %p ",*pointer,&pointer);
    
}

enum dayEnumTest{
    Monday = 1,
    Tuesday,
    WednesDay,
    ThursDay,
    Friday,
    Saturday,
    Sunday,
};

/*
 数组里的值的内存地址 在 内存分布里 的表现是是 一组连续的地址  0x123456, 0x123457, 0x123458
 */
void(arrayTest)(void) {
    int array1[3] = {1,2,3};
    int array2[4] = {5,6,6,7};
    for(int i = 0;i < 3; i++) {
        printf("array1[%d]=%d  array2[%d]=%d ",i,array1[i],i,array2[i]);
    }
    printf("%d %d %d %d %d %d %d ",Monday,Tuesday,WednesDay,ThursDay,Friday,Saturday,Sunday);
}

/*
 指针
 & 连字符 可以用来访问变量内存的地址, &someVariable ：取 someVariable 变量的内存地址
 指针：1.指针也是一个变量，其值是其他变量的内存地址
      2.指针的标记是符号 *
      3.其定义为： type *pointerName  --- 指针类型 指针标记 指针变量的名称
      4.所有的实际数据类型，不管是整型、浮点型、字符型，还是其他的数据类型，对应的指针的值的类型都是一样的，都是一个代表内存地址的长的十六进制数。不同数据类型的指针之间唯一的不同是，指针所指向的变量或常量的数据类型不同
      5.如何取出指针里的值，即某变量的内存地址所存放的该变量的值：通过 *pointer 来取，
        举例：int a = 20;
             int *aPointer = &a;
             int b = *aPointer;
             此时，变量b里存放的值就是变量a里存放的值
      6.空指针为 NULL，当声明一个指针，暂时不知道确切值的时候，可以给指针赋值为 NULL ，即空指针
        举例：int *nullPointer = NULL;
      7.指针算术运算 ++,--,==, <=, >= ,
 */
void(pointerTest)(void) {
    int var1 = 10;
    char var2[2] = {'g','s'};
    printf("var1的地址--- %p   var2变量的地址---- %p",&var1,&var2);
    int *var1Pointer = &var1;
    char *var2Pointer = var2;
    int var3 = *var1Pointer;
    int *nullPointer = NULL;
    printf("\nvar1的指针所指向的地址 --- %p  var2的指针所指向的地址 --- %p",var1Pointer,var2Pointer);
    printf("\nvar1的值 -- %d  var2[0]的值 -- %d  var3的值 -- %d  空指针-%p ",*var1Pointer,*var2Pointer,var3,nullPointer);
    printf("\nvar2[1]的值 -- %c",*var2Pointer);
    var2Pointer++;
    printf("  var2[2]的值 -- %c",*var2Pointer);
}

/*
 数组指针
 数组名是一个指向数组中第一个元素的常量指针
    eg. 定义一个数组 double balance[50], 这里的 balance 是一个指向 &balance[0] 的指针，也就是数组 balance 第一个元素的地址
        double *arrayPointer = balance;
    可通过*(arrPointer + 1/2/3/4/5) 来取各个值
 */
void(arrayPointerTest)(void){
    // 定义一个数组并打印里面的值
    char array1[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n'};
    char *array1Pointer = array1;
    char *array1Pointer1 = array1;
    for(int i = 0;i<14;i++) {
        printf("%c ",*array1Pointer++);
    }
    // 访问某个位置的元素
    printf("\n%c",*(array1Pointer1 + 1));
    printf("\n %d %c %c %d",'a','a',97,97);
}

/* 定义个简单的函数用来测试 */
void(fpt)(void) {
    printf("一个简单函数调用");
}

/* 定义一个加法函数 */
int(addFunction)(int a,int b) {
    return a + b;
}

/* 一个函数，为了测试函数指针用的 */
int * funcPtrTest(void) {
    int a[2] = {2,3};
    int *ptr = a;
    printf("%d  %d",*ptr,*a);
//    return a;  注意，这里不能返回 a, 因为编译时系统会认定 a 是指向栈区的，但是系统并不能知道ptr指向的是堆区还是栈区;
    return ptr;
}

/*
 函数指针
 顾名思义：指向函数的指针
 定义：functionReturnype (*pointerName)(param1,param2,...)  --->  待指函数的返回值类型 (*指针名)(待值函数的参数)
 函数的函数名也是一个函数指针，类似数组的数组名就是数组首元素的指针
 */
void(functionPointerTest)(void) {
    void (*fptPointer)(void) = fpt;
    int (*addFunctionPointer)(int a,int b) = addFunction;
    
    fptPointer();
    int result = addFunctionPointer(3,67);
    printf("\n %d \n",result);
    // char    *strcpy(char *__dst, const char *__src);
    char des[] = "wwwwww";
    const char src[] = "qqqqqq";
    char *res = strcpy(des, src); // strcpy-- 拷贝字符串，将src字符串拷贝到des
//    printf("\n------%c  %s",*res,des);
    
    for(int i = 0;i<6;i++) {
        printf("%c ",res[i]);
//        res++;
    }

}


int (getNextnumber)(void) {
    return 3;
}
/* 函数指针的传递，可以将函数传过去，类似OC里的 @selector(selector) */
void fillAnArray (int *a,int (*getTheNextNumber)(void)) {
    for (int i = 0;i<3; i++) {
        a[i] = getNextnumber();
    }
}

/*
 字符串
 字符串是多个字符的集合，是字符数组
 字符串有两种写法
 char name[] = {'a','b',...};
 char name[] = "ab...";
 在C里调用字符串的复制拼接等方法时，要注意保证字符串的长度够长

 */
void(strTest)(void) {
    
//    char str1[10] = {'1','2','3'};  等同于 char str1[10] = "123";
//    char str2[10] = {'4','5','6'};  等同于 char str2[10] = "456";
    
    
    char str1[10] = "123";
    char str2[10] = "456";
    // 复制
//    char *strRes1 = strcpy(str1, str2);
//    for(int i = 0;i<strlen(str1);i++) {
//        printf("%c ",strRes1[i]);
//    }
//    printf("\n");
    // 连接
    char *strRes2 = strcat(str1, str2);
    for(int i = 0;i < 6;i++) {
        printf("%c ",strRes2[i]);
    }
    
}

/*
 结构体
 声明
 struct aStruct {               struct -- 结构体关键字 {} 里就是结构体里的成员变量
 type a;
 type b;
 ...
 }
 
 
 */

struct BOOK {
    char title[50];
    char author[20];
    char subject[100];
    int  bookID;
};

void printStructFuction (struct BOOK book){
    
}

void(structTest)(void) {
    struct BOOK book1;

    strcpy(book1.title, "《时间简史》");
    strcpy(book1.author, "霍金");
    strcpy(book1.subject, "人类自盘古开天辟地以来。。。");
    book1.bookID = 23456;
//    printf("书的名字:%s  \n书的作者: %s  \n书的内容: %s  \n书的编号: %d",book1.title,book1.author,book1.subject,book1.bookID);
}


/* C基本测试 */
void(BaseTestFunction)(void) {
    printf("\n************************************\n\n");
    
//    structTest();
    
//    strTest();
    
//    int anArray[3] = {};
//    fillAnArray(anArray, getNextnumber);
//    for(int i = 0;i<3;i++) {
//        printf("%d",anArray[i]);
//    }
    
//    printf("\ntestOne \n");
//    getVariableSize();
//    getConstSpecialChar();
//    storeCategory();
//    operatorTest();
//    arrayTest();
//    pointerTest();
//    arrayPointerTest();
//    functionPointerTest();
    funcPtrTest();
    printf("\n\n************************************\n");
}





