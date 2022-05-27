//
// Created by usrname on 26.05.22.
//

#include "list_item.h"

list_item* create_list_item_empty() {
    list_item* ptr = (list_item*)malloc(sizeof(list_item));
    ptr->val = (char*)malloc(sizeof(char));
    ptr->next = NULL;
    return ptr;
}

list_item* create_list_item(char* string) {
    list_item* ptr = (list_item*)malloc(sizeof(list_item));
    ptr->val = (char*)malloc(sizeof(char) * strlen(string));
    for(int i = 0;i < strlen(string);i++) {
        ptr->val[i] = string[i];
    }
    ptr->next = NULL;
    return ptr;
}

void delete_list_item(list_item* ptr) {
    for(int i = 0;i < strlen(ptr->val);i++) {
        ptr->val[i] = 0;
    }
    free(ptr->val);
    ptr->next = NULL;
    free(ptr);
}