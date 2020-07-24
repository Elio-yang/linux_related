//
// Created by ELIO on 2020/7/24.
//

#include <stdio.h>
#include <string.h>
#include "macro.h"
int main() {
        int gender_offset,id_offset,age_offset,name_offset,score_offset;
        gender_offset = __offsetof__(struct Student, gender);
        id_offset     = __offsetof__(struct Student, id);
        age_offset    = __offsetof__(struct Student, age);
        name_offset   = __offsetof__(struct Student, name);
        score_offset  = __offsetof__(struct Student, score);
        printf("%d\t%d\t%d\t%d\t%d\n", gender_offset, id_offset, age_offset, name_offset, score_offset);

        Stu stu;
        Stu *pstu;
        stu.gender = '1';
        stu.id = 9527;
        stu.age = 18;
        stu.score = 98.2;
        strcpy(stu.name, "elioyang");

        pstu = __container_of__(&stu.id, Stu, id);

        printf("gender=%c\n", pstu->gender);
        printf("age=%d\n", pstu->age);
        printf("name=%s\n", pstu->name);
        printf("score=%lf", pstu->score);

        return 0;
}

