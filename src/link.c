//
// Created by ELIO on 2020/7/24.
//

#include "link.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student{
        int age;
        char name[20];
        struct list_head list;
};

int main()
{
        struct student *astudent;
        struct student student_head;
        struct list_head *pos, *next;
        int i;

        INIT_LIST_HEAD(&student_head.list);

        for (int j = 0; j < 5; j++) {
                astudent=(struct student *)malloc(sizeof(struct student));
                astudent->age= 10 * j + 1;
                sprintf(astudent->name, "%d", j + 1);
                list_add_tail(&(astudent->list),&(student_head.list));
        }
        printf("========== 1st iterator link =========\n");
        list_for_each(pos, &student_head.list) {
                astudent = list_entry(pos, struct student, list);
                printf("student age: %2d student name: %s\n", astudent->age, astudent->name);
        }
        list_for_each_safe(pos,next,&student_head.list){
                astudent=list_entry(pos,struct student,list);
                if (astudent->age==21){
                        list_del_init(pos);
                        free(astudent);
                }
        }
        printf("========== 2nd iterator link =========\n");
        list_for_each(pos, &student_head.list) {
                astudent = list_entry(pos, struct student, list);
                printf("student age: %2d student name: %s\n", astudent->age, astudent->name);
        }
        list_for_each_safe(pos,next,&student_head.list){
                astudent=list_entry(pos,struct student,list);
                list_del_init(pos);
                free(astudent);
        }

        return 0;
}