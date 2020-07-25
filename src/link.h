//
// Created by ELIO on 2020/7/24.
//

#ifndef _LINK_H
#define _LINK_H
#include "macro.h"
struct list_head {
        struct list_head *prev, *next;
};

//Init a head of a double link list
#define LIST_HEAD_INIT(name){ &(name), &(name)}
#define LIST_HEAD(name){\
        struct list_head list=LIST_HEAD_INIT(name);\
}

static inline void INIT_LIST_HEAD(struct list_head *list)
{
        list->prev = list;
        list->next = list;
}
//add node
static inline void __list_add(struct list_head *new,struct list_head *prev, struct list_head *next)
{
        prev->next=new;
        new->prev=prev;
        next->prev=new;
        new->next=next;
}

static inline void list_add(struct list_head *new,struct list_head *head)
{
        __list_add(new,head,head->next);
}

static inline void list_add_tail(struct list_head *new,struct list_head *head)
{
        __list_add(new,head->prev,head);
}

//delete node between prev and next
static inline void __list_del(struct list_head *prev, struct list_head *next)
{
        prev->next=next;
        next->prev=prev;
}

static inline void list_del(struct list_head *entry)
{
        __list_del(entry->prev,entry->next);
}

static inline void __list_del_entry(struct list_head *entry)
{
        __list_del(entry->prev,entry->next);
}

static inline void list_del_init(struct list_head *entry)
{
        __list_del_entry(entry);
        INIT_LIST_HEAD(entry);
}

//replace node
static inline void list_replace(struct list_head *old, struct list_head *new)
{
        new->next=old->next;
        new->next->prev=new;
        new->prev=old->prev;
        new->prev->next=new;
}

//is empty?
static inline int list_empty(const struct list_head *head)
{
        return head->next==head;
}

//get node
#define list_entry(ptr,type,member)\
        __container_of__(ptr,type,member)

//go through list
#define list_for_each(pos,head)\
        for(pos=(head)->next;pos!=(head);pos=pos->next)

#define list_for_each_safe(pos,n,head)\
        for(pos=(head)->next,n=(pos)->next;pos!=(head);\
        pos=n,n=pos->next)

#endif //_LINK_H_
