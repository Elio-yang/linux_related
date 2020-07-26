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
        struct student *a_student;
        struct student student_head;
        struct list_head *pos, *next;
        int i;

        INIT_LIST_HEAD(&student_head.list);

        for (int j = 0; j < 5; j++) {
                a_student=(struct student *)malloc(sizeof(struct student));
                a_student->age= 10 * j + 1;
                sprintf(a_student->name, "%d", j + 1);
                list_add_tail(&(a_student->list), &(student_head.list));
        }
        printf("========== 1st iterator link =========\n");
        list_for_each(pos, &student_head.list) {
                a_student = list_entry(pos, struct student, list);
                printf("student age: %2d student name: %s\n", a_student->age, a_student->name);
        }
        list_for_each_safe(pos,next,&student_head.list){
                a_student=list_entry(pos, struct student, list);
                if (a_student->age == 21){
                        list_del_init(pos);
                        free(a_student);
                }
        }
        printf("========== 2nd iterator link =========\n");
        list_for_each(pos, &student_head.list) {
                a_student = list_entry(pos, struct student, list);
                printf("student age: %2d student name: %s\n", a_student->age, a_student->name);
        }
        list_for_each_safe(pos,next,&student_head.list){
                a_student=list_entry(pos, struct student, list);
                list_del_init(pos);
                free(a_student);
        }

        return 0;
}