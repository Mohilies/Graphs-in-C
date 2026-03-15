#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 100
typedef struct data{
    int a;
    char name[10];
}data;
typedef struct Queue{
    struct Node *front;
    struct Node *Rear;
}Queue;
typedef struct Node{
    data data;
    struct edge *edges;
    struct Node *next;
}Node;
typedef struct edge{
    Node *node;
    int weight;
   struct edge *next_edge;
}edge;
void allocate_node_queue(Queue **Q){
    (*Q)=malloc(sizeof(Queue));
}
Node *Dequeue(Queue **Q){
if((*Q)==NULL){printf("error");}else{
    Node *a = (*Q)->front;
    (*Q)->front=(*Q)->front->next;
    return a;
}
}
Node Enqueue(Queue **Q,Node *S){
S->next=(*Q)->Rear;
(*Q)->Rear=S;
}
void allocate_node(Node **node,int value,char na[]){(*node)=malloc(sizeof(Node));
(*node)->data.a=value;
(*node)->edges=NULL;
(*node)->next=NULL;
strcpy((*node)->data.name,na);
}
void allocate_edge(Node *start,edge **node,Node *end){(*node)=malloc(sizeof(edge));
    (*node)->next_edge=NULL;
if(start->edges==NULL){
    start->edges=(*node);
}else{
edge *a=start->edges;
while(a->next_edge!=NULL){
    a=a->next_edge;
}
a->next_edge=(*node);
}
(*node)->node=end;
}
void Node_show(Node *node){
printf("Node%s:\n",node->data.name);
printf("relationships\n");
edge *current =node->edges;
while(current!=NULL){
    printf("%s -> %s\n",node->data.name,current->node->data.name);
    printf("weight %d\n",node->data.a-current->node->data.a);
    current=current->next_edge;
}
}
int shortest_path(Node **sou,Node **des){
    Node *sour=(*sou);
    Node *dest=(*des);
int count=1;
Queue *A;
allocate_node_queue(&A);
A->front=sour;
A->Rear=sour;
while(A!=NULL){
    edge *current=Dequeue(&A)->edges;
while(current !=NULL){
if(current->node->data.name==dest->data.name){
    printf("it was found \n");
    return count;
}else{
    Enqueue(&A,current->node);
    current=current->next_edge;
}
}
count++;
}
return 0;
}
int main(){
Node *nodes[n]={NULL};
int a=10;
char name[10];
int i=0;
while(a!=0){
printf("1-add a node\n");
printf("2-show all nodes \n");
printf("3-add an edge\n");
printf("4-shows all the relationships for the chosen node\n");
printf("5-find the shorted path between 2 nodes \n");//doesn't work for any path longer than 1 :) would be fixed when i have time 
scanf("%d",&a);
switch(a){
case 1: 
printf("enter node name\n");
scanf("%9s",name); 
printf("enter the node value\n"); 
int s; 
scanf("%d",&s);
Node *a; 
allocate_node(&a,s,name); 
nodes[i]=a; 
i++;
break;
case 2:
int j=0;
printf("nodes:\n");
while(nodes[j]!=NULL){
    printf("%s/",nodes[j]->data.name);
    printf("%d \n",nodes[j]->data.a);
    j++;
}
break;
case 3:
edge *b;
int c;
printf("edge starting point?(enter i coordinates for the node )");
scanf("%d",&c);
printf("edge ending point");
scanf("%d",&s);
allocate_edge(nodes[c],&b,nodes[s]);
break;
case 4:
printf("which node relationships you want to display ?");
scanf("%d",&c);
Node_show(nodes[c]);
break;
case 5:
printf("Source index");
scanf("%d",&c);
printf("Destination index");
scanf("%d",&s);
printf("%d\n",shortest_path(&nodes[c],&nodes[s]));
default:
}}
}
