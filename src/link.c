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
        struct student *student_head;
        struct list_head *position, *next;
        int i;

        INIT_LIST_HEAD(&astudent->list);

        for (int j = 0; j < 5; j++) {
                astudent=(struct student *)malloc(sizeof(struct student));
                astudent->age= 10 * j + 1;
                sprintf(astudent->name, "%d", j + 1);
                list_add_tail(&(astudent->list),&(student_head->list));
        }
        printf("========== 1st iterator link =========");
        list_for_each(position, &student_head->list)
        {
                astudent=list_entry(position, struct student, list);


        }

        return 0;
}