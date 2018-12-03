/** 邻接表深度优先遍历 **/
#include<stdio.h>  
#include<stdlib.h>

#define MaxVex 255 
#define TRUE   1  
#define FALSE  0
 
typedef int VertexType;  //顶点类型
typedef int Bool;
Bool visited[MaxVex];  //全局数组,记录图中节点访问状态

typedef struct EdgeNode { //边表节点  
    int adjvex;    //该邻接点在顶点数组中的下标  
    struct EdgeNode *next;   //链域 指向下一个邻接点  
}EdgeNode;

typedef struct VertexNode { //头节点
    VertexType data;  //顶点信息
    EdgeNode *firstedge;  //边表头指针(指向第一条依附于该顶点的弧的指针) 
}VertexNode,AdjList[MaxVex]; //顶点数组(结构体数组)   

typedef struct Graph{  
    AdjList adjList;  
    int numVertexes,numEdges;  //图中当前的结点数以及边数  
}Graph,*GraphAdjList;



/**
 * 建立图的邻接表结构(此处以无向图为例)
 */
void CreateALGraph(GraphAdjList &G){
    int i, j, k;  
    if(G==NULL){
        G = (GraphAdjList)malloc(sizeof(Graph));
    }

    printf("Please input the number of node: ");  
    scanf("%d",&G->numVertexes);
    printf("Please input the number of edge: ");  
    scanf("%d",&G->numEdges);
    fflush(stdin);

   // printf("===========================\n");
    printf("Please input datas of each node:\n");  
    for (i=0; i<G->numVertexes; ++i){  
        printf("vertex%d: ",i+1);
        scanf("%d", &(G->adjList[i].data));  
        G->adjList[i].firstedge = NULL;  
        fflush(stdin);  
    }
    
    printf("\nPlease input endpoints of edge\n");
    for (k=0; k<G->numEdges; ++k){
        printf("Edge %d：",k+1);
        scanf("%d%d",&i,&j);

        EdgeNode *ptrEdgeNode = (EdgeNode*)malloc(sizeof(EdgeNode));
        ptrEdgeNode->adjvex = j;
        ptrEdgeNode->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = ptrEdgeNode;
 
        ptrEdgeNode = (EdgeNode*)malloc(sizeof(EdgeNode));
        ptrEdgeNode->adjvex = i;
        ptrEdgeNode->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = ptrEdgeNode;
    }
}

void DFS(GraphAdjList &G, int i){
    visited[i] = TRUE;  
    printf("%d ", G->adjList[i].data);  
    
    EdgeNode *p = G->adjList[i].firstedge;
    while(p){
        if(!visited[p->adjvex]){
            DFS(G,p->adjvex); //递归深度遍历
        }
        p= p->next;
    }
}


/**
 * 深度优先遍历
 */
void DFSTraverse(GraphAdjList &G){
    int i;  
    for (i=0; i<G->numVertexes; ++i){ 
        visited[i] = FALSE;  //初始化访问数组visited的元素值为false
    }
    for (i=0; i<G->numVertexes; ++i){
        if(!visited[i]){ //节点尚未访问
            DFS(G,i);
        }
    }
}



/**
 * 程序入口
 */
int main(){
    GraphAdjList G = NULL;  
    CreateALGraph(G); 
    printf("\ndepth-first traversal: ");
    DFSTraverse(G); 
    printf("\n");
    return 0;
}
