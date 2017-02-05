// List ADT 정의
// 멤버함수는 list.cpp에서 정의


#ifndef NODETYPE
#define NODETYPE
typedef struct node {
	int Data ;
	struct node* Next ;
} Node ;							// 노드 구조체 정의
typedef Node* Nptr ;				// 노드 포인터타입 정의
#endif


#ifndef LIST_H
#define LIST_H
class List_Class {
public:
	List_Class() ;							// 생성자
	~List_Class() ;							// 소멸자
	void Insert_List(int Position, int Data) ;		// 원하는 위치에 데이터삽입
	void Delete_List(int Position) ;				// 원하는 위치 삭제
	void Output_List() ;				// 현제 데이터 모두 출력
	void Search_List(int Data) ;			// 원하는 데이터 검색
	bool IsEmpty_List() ;						// 비어있는지 확인
	int Length_List() ;							// 리스트 내의 개수
	void Set_Count(int Data) ;
	void Set_Head(Nptr ptr) ;
	int Get_Count() ;
	Nptr Get_Head() ;

private:
	int Count ;							// 카운터
	Nptr Head ;							// 해드포인터

} ; 		// 클래스 선언
#endif


