#include <stdlib.h>
#include <stdio.h>

int total;
int M,N;

typedef struct Map{
	int data;
	int visit;
} mapnode;

mapnode Map[21][21];

typedef struct Qn{
	int x;
	int y;
	int movecost;
	struct Qn* Next;
	struct Qn* Prev;
} Qnode;

Qnode* Top;
Qnode* Rear;

void enque(Qnode* que){ 
	if(Top == NULL){
		Top = que;
		Rear = que;
	}else {
		Top->Prev = que;
		que->Next = Top;
		Top = que;
	}
}

Qnode* deque(){
	if(Rear == NULL){
		return NULL;
	}

	Qnode* que = Rear;

	if(Rear == Top){
		Rear = NULL;
		Top = NULL;
	}else {
		Rear = Rear->Prev;
		Rear->Next = NULL;
	}

	return que;
}




int BFS(int startx, int starty){
	int totalcost;
	
	Map[startx][starty].visit = 1;
	Qnode* node = (Qnode*)calloc(1,sizeof(Qnode));
	node->x = startx;
	node->y = starty;
	node->Prev = NULL;
	node->Next = NULL;
	node->movecost = 1;

	enque(node);

	while(Rear != NULL){
		Qnode* ret = deque();
		printf("deque [%d][%d] cost[%d]\n ", ret->x, ret->y,ret->movecost);
		totalcost = ret->movecost;
		if( (ret->x == N-1) && (ret->y == M-1)){
			printf("Goal!\n");
			break;
		}

		//check nearby (x+1)
		if(ret->x+1 < N ){
			if(Map[ret->x +1][ret->y].data == 0){ //road check
				if(Map[ret->x +1][ret->y].visit != 1){ //visit check
					Map[ret->x +1][ret->y].visit = 1; 
					Qnode* nextnodex = (Qnode*)calloc(1,sizeof(Qnode));
					nextnodex->x = ret->x+1;
					nextnodex->y = ret->y;
					nextnodex->movecost = ret->movecost+1;
					enque(nextnodex);
				}
			}
		}

		//check nearby (x-1)
		if(ret->x-1 >= 0 ){
			if(Map[ret->x -1][ret->y].data == 0){ //road check
				if(Map[ret->x -1][ret->y].visit != 1){ //visit check
					Map[ret->x -1][ret->y].visit = 1; 
					Qnode* nextnodex = (Qnode*)calloc(1,sizeof(Qnode));
					nextnodex->x = ret->x-1;
					nextnodex->y = ret->y;
					nextnodex->movecost = ret->movecost+1;
					enque(nextnodex);
				}
			}
		}

		//check nearby (y+1)
		if(ret->y+1 < M){
			if(Map[ret->x][ret->y+1].data == 0){ //road check
				if(Map[ret->x][ret->y+1].visit != 1){ //visit check
					Map[ret->x][ret->y+1].visit = 1; 
					Qnode* nextnodey = (Qnode*)calloc(1,sizeof(Qnode));
					nextnodey->x = ret->x;
					nextnodey->y = ret->y+1;
					nextnodey->movecost = ret->movecost+1;
					enque(nextnodey);
				}
			}
		}
		
		if(ret->y-1 >= 0){
			if(Map[ret->x][ret->y-1].data == 0){ //road check
				if(Map[ret->x][ret->y-1].visit != 1){ //visit check
					Map[ret->x][ret->y-1].visit = 1; 
					Qnode* nextnodey = (Qnode*)calloc(1,sizeof(Qnode));
					nextnodey->x = ret->x;
					nextnodey->y = ret->y-1;
					nextnodey->movecost = ret->movecost+1;
					enque(nextnodey);
				}
			}
		}
		//free(ret);	

		printf("\n");
	}


	return totalcost;
}

int main(){
	scanf("%d %d", &N, &M);

	for(int i = 0; i<N ; i++){
		for(int j = M-1; j >= 0; j--){
			scanf("%1d", &Map[i][j].data);
			Map[i][j].visit = 0;
		}
	}

	printf("\n");
	printf("===== map =====\n");
	for(int i = 0; i<N ; i++){
		for(int j = 0; j < M; j++){
			printf("%d", Map[i][j].data);
		}
		printf("\n");
	}
	printf("===== map =====\n");
	printf("\n");
	
	printf("total cost : %d\n",BFS(0,0 ) );
	





	return 0;
}
