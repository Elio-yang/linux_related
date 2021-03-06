//
// Created by ELIO on 2020/7/23.
//

#ifndef _MACRO_H_
#define _MACRO_H_
/**
 * 获取结构体变量成员的偏移量
 * @param type 类型（struct）
 * @param member 成员
 */
/* (type *)0                         转化为0型指针，即地址为0
 * ((type *)0)->member               获取成员
 * &(((type *)0)->member)            获取成员地址
 * (size_t)&(((type *)0)->member)    将地址转化为size_t 即为偏移量
 */
#define __offsetof__(type, member) ( ( size_t ) & ( ( type * ) 0 )->member )

/**
 * 获取指向整个结构体的指针
 * @param ptr 指向成员(member)变量的指针
 * @param type 类型(struct)
 * @param member 成员变量
 */
/* typeof()                                                   为GNU C Extension 获得变量类型
 * typeof (((type *)0 )->member)                              先是转化为0型指针，起始地址为0 再获取member 最后返回member类型
 * const typeof (((type *)0 )->member) *__mptr=(ptr)          定义__mptr 指针，指向ptr指向的地址，并成为常量指针
 * (char *)__mptr                                             __mptr转化为字符型指针(运算以1个字节为单位)
 * - __offsetof__(type,member))                               减去该成员的偏移量
 * (type*)( ( char * )__mptr - __offsetof__(type,member))     最后转化为指向该类型的指针(指向该类型的首地址)
 */
#define __container_of__(ptr, type, member) ({\
                const typeof ( ( ( type * ) 0 ) -> member ) *__mptr=(ptr);\
                ( type * )( ( char * )__mptr - __offsetof__( type, member ) );\
                })

typedef struct Student {
    char gender;
    int id;
    int age;
    char name[20];
    double score;
} Stu;
#endif