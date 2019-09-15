#ifndef _INCLUDED_SLIST_
#define _INCLUDED_SLIST_
#include <stdint.h>
typedef struct _node_ Node;
typedef struct _slist_ Slist;
struct _node_{
    int32_t data;
    Node *next;
};
struct _slist_{
    Node *head;
    Node *tail;
    uint32_t length;
};

Slist slist_new();
uint32_t slist_length(const Slist *list);
uint32_t slist_lookup(const Slist *list, int32_t key);
Slist* slist_add_head(Slist *list,int32_t element);
Slist* slist_add_tail(Slist *list,int32_t element);
Slist* slist_delete_head(Slist *list);
Slist* slist_delete_head(Slist *list);
int32_t max_ele(Slist *list);
int32_t min_ele(Slist *list);
Slist* add_element_after_specified(Slist *list,int32_t ele,int32_t spec);
SList* delete_specified_ele(Slist *list,int32_t ele);
#endif
