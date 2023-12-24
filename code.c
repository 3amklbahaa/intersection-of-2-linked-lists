#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
int size(node* head){
    node* current = head;
    int count = 0;
    while(current!=NULL){
        count++;
        current = current->next;
    }
    return count;
}
node* intersection(node* h1, node* h2){
    int size1, size2, diff;
    node* current1 = h1, *current2 = h2;
    size1 = size(h1);
    size2 = size(h2);
    if(size1>size2){
        diff=size1-size2;
        int i = 0;
        while(i<diff&&current1!=NULL){
            current1 = current1->next;
            i++;
        }
    }
    else{
        diff = size2-size1;
        int i = 0;
        while(i<diff&&current2!=NULL){
            current2 = current2->next;
            i++;
        }
    }
    while(current1!=NULL&&current2!=NULL){
        if(current1 == current2){
            return current1;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return NULL;
}
