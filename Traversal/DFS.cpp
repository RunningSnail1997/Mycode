/** �ڽӱ�������ȱ��� **/
#include<stdio.h>  
#include<stdlib.h>

#define MaxVex 255 
#define TRUE   1  
#define FALSE  0
 
typedef int VertexType;  //��������
typedef int Bool;
Bool visited[MaxVex];  //ȫ������,��¼ͼ�нڵ����״̬

typedef struct EdgeNode { //�߱�ڵ�  
    int adjvex;    //���ڽӵ��ڶ��������е��±�  
    struct EdgeNode *next;   //���� ָ����һ���ڽӵ�  
}EdgeNode;

typedef struct VertexNode { //ͷ�ڵ�
    VertexType data;  //������Ϣ
    EdgeNode *firstedge;  //�߱�ͷָ��(ָ���һ�������ڸö���Ļ���ָ��) 
}VertexNode,AdjList[MaxVex]; //��������(�ṹ������)   

typedef struct Graph{  
    AdjList adjList;  
    int numVertexes,numEdges;  //ͼ�е�ǰ�Ľ�����Լ�����  
}Graph,*GraphAdjList;



/**
 * ����ͼ���ڽӱ�ṹ(�˴�������ͼΪ��)
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
        printf("Edge %d��",k+1);
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
            DFS(G,p->adjvex); //�ݹ���ȱ���
        }
        p= p->next;
    }
}


/**
 * ������ȱ���
 */
void DFSTraverse(GraphAdjList &G){
    int i;  
    for (i=0; i<G->numVertexes; ++i){ 
        visited[i] = FALSE;  //��ʼ����������visited��Ԫ��ֵΪfalse
    }
    for (i=0; i<G->numVertexes; ++i){
        if(!visited[i]){ //�ڵ���δ����
            DFS(G,i);
        }
    }
}



/**
 * �������
 */
int main(){
    GraphAdjList G = NULL;  
    CreateALGraph(G); 
    printf("\ndepth-first traversal: ");
    DFSTraverse(G); 
    printf("\n");
    return 0;
}
