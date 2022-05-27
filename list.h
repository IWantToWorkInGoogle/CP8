//
// Created by usrname on 26.05.22.
//

#ifndef CP8_LIST_H
#define CP8_LIST_H

#endif //CP8_LIST_H

#include "iterator.h"
#include <stdbool.h>

typedef struct {
    list_item* begin;
    list_item* end;
    int size;
} list;

list* create_list();
bool equal(iterator i1,iterator i2);
void delete_list(list* ptr);
iterator next(list* l,iterator i1);
iterator prev(list* l,iterator i1);
iterator head(list* l);
iterator end(list* l);
iterator last(list* l);
void push_back(list*l,char* val);
void erase(list* l,int k);
void insert(list* l,int k,char* val);
void function(list*l,char* val);
void print_list(list* l);
int size(list* l);