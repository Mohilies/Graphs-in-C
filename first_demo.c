#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 10
typedef struct data{
    int a;
    char name[10];
}data;
typedef struct Node{
    data data;
    struct edge *edges;
}Node;
typedef struct edge{
    Node *node;
    int weight;
   struct edge *next_edge;
}edge;
void allocate_node(Node **node,int value,char na[]){(*node)=malloc(sizeof(Node));
(*node)->data.a=value;
(*node)->edges=NULL;
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
int main(){
Node *nodes[n]={NULL};
int a=10;
char name[10];
int i=0;
while(a!=0){
printf("1-add a node\n");
printf("2-show all nodes \n");
printf("3-add an edge\n");
printf("4-check first relationship between first node and second one(just a test)");
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
printf("source:%s\n",nodes[0]->data.name);
printf("destination:%s\n",nodes[0]->edges->node->data.name);
break;
default:
}}
}
