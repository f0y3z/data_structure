#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node* prev;
    int x;
    struct node* next;
};
struct node* head=NULL;
struct node* tail=NULL;
void push_back(int a){
    struct node* newnode=malloc(sizeof(struct node));
    newnode->x=a;
    newnode->next=NULL;
    newnode->prev=tail;
    if (tail==NULL) head=newnode;
    else tail->next=newnode;
    tail=newnode;
}
void push_front(int a){
    struct node* newnode=malloc(sizeof(struct node));
    newnode->x=a;
    newnode->prev=NULL;
    newnode->next=head;
    if (head==NULL) tail=newnode; 
    else head->prev=newnode;
    head=newnode;
}
void pop_front(){
    if (head==NULL) return;
    struct node* temp=head;
    head=head->next;
    free(temp);
    if (head==NULL) tail=NULL;
    else head->prev=NULL;
}
void pop_back(){
    if (tail==NULL) return;
    struct node* temp=tail;
    tail=tail->prev;
    free(temp);
    if (tail==NULL) head=NULL;
    else tail->next=NULL;
}
void pop_node(int g){
    if (head==NULL) return;
    struct node* temp=head;
    while (temp!=NULL){
        if (temp->x==g){
            if (temp==head){
                pop_front();
                break;
            } 
            else if (temp==tail) {
                pop_back();
                break;
            } 
            else{
                struct node* temp_prev=temp;
                struct node* temp_next=temp;
                temp_prev=temp_prev->prev;
                temp_next=temp_next->next;
                free(temp);
                temp_prev->next=temp_next;
                temp_next->prev=temp_prev;
                break;
            }  
        }
        temp=temp->next;
    }
}
int main(){
    push_front(5);
    push_front(3);
    push_front(23);
    push_back(30);
    push_back(23);
    pop_back();
    pop_front();
    pop_node(5);
    pop_node(30);
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ",temp->x);
        temp = temp->next;
    }
}