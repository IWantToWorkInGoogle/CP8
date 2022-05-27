//
// Created by usrname on 26.05.22.
//

#include "list.h"
#include <unistd.h>

list* create_list() {
    list* ptr = (list*)malloc(sizeof(list));
    ptr->size = 0;
    ptr->begin = create_list_item_empty();
    ptr->end = create_list_item_empty();
    ptr->begin->next = (struct list_item *)ptr->end;
    return ptr;
}

bool equal(iterator i1,iterator i2) {
    if(i1.ptr == i2.ptr) {
        return true;
    } else {
        return false;
    }
}

iterator next(list* l,iterator i1) {
    if(i1.ptr == NULL) {
        iterator p = {NULL};
        return p;
    } else {
        iterator p = {(list_item *)i1.ptr->next};
        return p;
    }
}

iterator prev(list* l,iterator i1) {
    iterator p = {NULL};
    if(equal(i1, head(l)) || equal(i1,end(l))) {
        return p;
    }
    for(iterator i = head(l);!equal(i,end(l));i = next(l,i)) {
        if(equal(i1,next(l,i))) {
            p.ptr = i.ptr;
            break;
        }
    }
    return p;
}

iterator head(list* l) {
    iterator p = {l->begin};
    return p;
}

iterator end(list* l) {
    iterator p = {l->end};
    return p;
}

iterator last(list* l) {
    iterator p = head(l);
    for(int i = 0;i < l->size;i++) {
        p = next(l,p);
    }
    return p;
}

void delete_list(list* ptr) {
    iterator p = next(ptr,head(ptr));
    for(int i = 0;i < ptr->size;i++) {
        iterator new_p = next(ptr,p);
        delete_list_item(p.ptr);
        p = new_p;
    }
    ptr->size = 0;
    delete_list_item(ptr->begin);
    delete_list_item(ptr->end);
    free(ptr);
}

void push_back(list* l,char* val) {
    iterator i1 = last(l);
    list_item* new_item = create_list_item(val);
    l->size++;
    i1.ptr->next = (struct list_item *)new_item;
    new_item->next = (struct list_item *)l->end;
}

int size(list* l) {
    return l->size;
}

void print_list(list* l) {
    printf("[");
    iterator i1 = head(l);
    for(int i = 0;i < l->size;i++) {
        i1 = next(l,i1);
        printf("'%s'",i1.ptr->val);
        if(!equal(i1,last(l))) {
            printf(",");
        }
    }
    printf("]\n");
}

void erase(list* l,int k) {
    if(k < 0 || k >= l->size) {
        printf("The index is out of range!\n");
        return;
    } else {
        iterator i1 = head(l);
        for(int i = 0;i <= k;i++) {
            i1 = next(l,i1);
        }
        l->size--;
        prev(l,i1).ptr->next = i1.ptr->next;
        delete_list_item(i1.ptr);
        printf("The element was deleted!\n");
    }
}

void insert(list* l,int k,char* val) {
    if(k >= 0 && k <= l->size) {
        if(k == l->size) {
            push_back(l,val);
        } else {
            iterator i1 = head(l);
            for (int i = 0; i <= k; i++) {
                i1 = next(l, i1);
            }
            l->size++;
            list_item *new_item = create_list_item(val);
            prev(l, i1).ptr->next = (struct list_item *) new_item;
            new_item->next = (struct list_item *) i1.ptr;
        }
        printf("The element was added to the list\n");
    } else {
        printf("The index is out of range!\n");
    }
}

void function(list* l,char* val) {
    bool st = false;
    for(iterator i = next(l,head(l));!equal(i,end(l));i = next(l,i)) {
        if(!strcmp(i.ptr->val,val)) {
            st = true;
            break;
        }
    }
    if(st) {
        printf("The value was found.\nThe list was deleted\n");
        delete_list(l);
        l = create_list();
    } else {
        printf("The value wasn't found\n");
    }
}