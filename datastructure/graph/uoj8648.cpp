#include"string.h"
#include"malloc.h" /* malloc()�� */
#include"stdio.h" /* EOF(=^Z��F6),NULL */
#include"stdlib.h" /* exit() */
typedef int InfoType; /* ����Ȩֵ���� */
#define MAX_NAME 3 /* �����ַ�������󳤶�+1 */
typedef char VertexType[MAX_NAME]; /* �ַ������� */
/*ͼ���ڽӱ��洢��ʾ */
#define MAX_VERTEX_NUM 20
typedef enum {DG,DN,AG,AN} GraphKind; /* {����ͼ,������,����ͼ,������} */
typedef struct ArcNode
{
    int adjvex; /* �û���ָ��Ķ����λ�� */
    struct ArcNode *nextarc; /* ָ����һ������ָ�� */
    InfoType *info; /* ����Ȩֵָ�룩 */
} ArcNode; /* ����� */

typedef struct
{
    VertexType data; /* ������Ϣ */
    ArcNode *firstarc; /* ��һ�������ĵ�ַ,ָ���һ�������ö���Ļ���ָ�� */
} VNode,AdjList[MAX_VERTEX_NUM]; /* ͷ��� */

typedef struct
{
    AdjList vertices;
    int vexnum,arcnum; /* ͼ�ĵ�ǰ�������ͻ��� */
    int kind; /* ͼ�������־ */
} ALGraph;

int LocateVex(ALGraph G,VertexType u)
{
    /* ��ʼ����: ͼG����,u��G�ж�������ͬ���� */
    /* �������: ��G�д��ڶ���u,�򷵻ظö�����ͼ��λ��;���򷵻�-1 */
    int i;
    for(i=0; i<G.vexnum; ++i)
        if(strcmp(u,G.vertices[i].data)==0)
            return i;
    return -1;
}

void CreateGraph(ALGraph *G)
{
    /* �����ڽӱ��洢�ṹ,����û�������Ϣ��ͼG(��һ����������4��ͼ) */
    int i,j,k;
    int w; /* Ȩֵ */
    VertexType va,vb;
    ArcNode *p;
    //printf("Enter the type of map:(0~3): ");
    scanf("%d",&(*G).kind);
    //printf("Enter Vertex number,Arc number: ");
    scanf("%d%d",&(*G).vexnum,&(*G).arcnum);
    //printf("Enter %d Vertex :\n",(*G).vexnum);
    for(i=0; i<(*G).vexnum; ++i) /* ���춥������ */
    {
        scanf("%s",(*G).vertices[i].data);
        (*G).vertices[i].firstarc=NULL;
    }
    //if((*G).kind==1||(*G).kind==3) /* �� */
    //	printf("Enter order every arc weight,head and tail (Takes the gap by the blank space ):\n");
    //else /* ͼ */
    //	printf("Enter order every arc head and tail (Takes the gap by the blank space ):\n");
    for(k=0; k<(*G).arcnum; ++k) /* ������������ */
    {
        if((*G).kind==1||(*G).kind==3) /* �� */
            scanf("%d%s%s",&w,va,vb);
        else /* ͼ */
            scanf("%s%s",va,vb);
        i=LocateVex(*G,va); /* ��β */
        j=LocateVex(*G,vb); /* ��ͷ */
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=j;
        if((*G).kind==1||(*G).kind==3) /* �� */
        {
            p->info=(int *)malloc(sizeof(int));
            *(p->info)=w;
        }
        else
            p->info=NULL; /* ͼ */
        p->nextarc=(*G).vertices[i].firstarc; /* ���ڱ�ͷ */
        (*G).vertices[i].firstarc=p;
        if((*G).kind>=2) /* ����ͼ����,�����ڶ�������� */
        {
            p=(ArcNode*)malloc(sizeof(ArcNode));
            p->adjvex=i;
            if((*G).kind==3) /* ������ */
            {
                p->info=(int*)malloc(sizeof(int));
                *(p->info)=w;
            }
            else
                p->info=NULL; /* ����ͼ */
            p->nextarc=(*G).vertices[j].firstarc; /* ���ڱ�ͷ */
            (*G).vertices[j].firstarc=p;
        }
    }
}

VertexType* GetVex(ALGraph G,int v)
{
    /* ��ʼ����: ͼG����,v��G��ĳ���������š��������: ����v��ֵ */
    if(v>=G.vexnum||v<0)
        exit(0);
    return &G.vertices[v].data;
}

int FirstAdjVex(ALGraph G,VertexType v)
{
    /* ��ʼ����: ͼG����,v��G��ĳ������ */
    /* �������: ����v�ĵ�һ���ڽӶ������š���������G��û���ڽӶ���,�򷵻�-1 */
    ArcNode *p;
    int v1;
    v1=LocateVex(G,v); /* v1Ϊ����v��ͼG�е���� */
    p=G.vertices[v1].firstarc;
    if(p)
        return p->adjvex;
    else
        return -1;
}

int NextAdjVex(ALGraph G,VertexType v,VertexType w)
{
    /* ��ʼ����: ͼG����,v��G��ĳ������,w��v���ڽӶ��� */
    /* �������: ����v��(�����w��)��һ���ڽӶ������š� */
    /* ��w��v�����һ���ڽӵ�,�򷵻�-1 */
    ArcNode *p;
    int v1,w1;
    v1=LocateVex(G,v); /* v1Ϊ����v��ͼG�е���� */
    w1=LocateVex(G,w); /* w1Ϊ����w��ͼG�е���� */
    p=G.vertices[v1].firstarc;
    while(p&&p->adjvex!=w1) /* ָ��p��������ָ����㲻��w */
        p=p->nextarc;
    if(!p||!p->nextarc) /* û�ҵ�w��w�����һ���ڽӵ� */
        return -1;
    else /* p->adjvex==w */
        return p->nextarc->adjvex; /* ����v��(�����w��)��һ���ڽӶ������� */
}

/*��ȱ���*/
int visited[MAX_VERTEX_NUM]; /* ���ʱ�־����(ȫ����),δ���ʱ��0�����ʱ��1 */
void(*VisitFunc)(char* v); /* ��������(ȫ����) */
void DFS(ALGraph G,int v)
{
    /* �ӵ�v����������ݹ��������ȱ���ͼG���㷨7.5 */
    /* ���÷��ʱ�־ΪTRUE(�ѷ���) */
    int w;
    visited[v]=1;
    /* ���ʵ�v������ */
    VisitFunc(G.vertices[v].data);
    /* ��v����δ���ʵ��ڽӵ�w�ݹ����DFS */
    for(w=FirstAdjVex(G,G.vertices[v].data); w>=0; w=NextAdjVex(G,G.vertices[v].data,G.vertices[w].data))
        if(!visited[w]) DFS(G,w);

}
void DFSTraverse(ALGraph G,void(*Visit)(char*))
{
    /* ��ͼG��������ȱ������㷨7.4 */
    /* ʹ��ȫ�ֱ���VisitFunc,ʹDFS�����躯��ָ����� */
    VisitFunc=Visit;
    /* ���ʱ�־�����ʼ�� */
    memset(visited,0,sizeof(visited));
    int v;
    /* ����δ���ʵĶ������DFS */
    for(v=0; v<G.vexnum; ++v)
    {

        if(!visited[v])
            DFS (G,v);
    }
    printf("\n");
}

void print(char *i)
{
    printf("%s ",i);
}

int main()
{
    ALGraph g;
    CreateGraph(&g);
    DFSTraverse(g,print);
    //if(g.vexnum>100) printf("1");
    return 1;
}