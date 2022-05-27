//
// Created by usrname on 26.05.22.
//

#ifndef CP8_LIST_ITEM_H
#define CP8_LIST_ITEM_H

#endif //CP8_LIST_ITEM_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _list_item {
    char* val;
    struct list_item* next;
} list_item;

list_item* create_list_item_empty();
list_item* create_list_item(char* string);
void delete_list_item(list_item* ptr);