// list.h에서 선언된 멤버함수 및 데이터를
// 초기화 및 작성

#include <iostream>
#include "list.h"

using std::cout ;
using std::endl ;

//			List_Class 멤버함수 선언
List_Class::List_Class() {
	Count = 0 ;
	Head = NULL ;
} // 생성자
List_Class::~List_Class() {
} // 소멸자
void List_Class::Insert_List(int Position, int Data) {
	Nptr temp = new Node ;
	temp->Data = Data ;
	temp->Next = NULL ;
	if ( Position <= 0 || Position-1 > Count)
		cout << "Position Error" << endl ;
	else if (Position == 1) {
		if (Head == NULL)
			Head = temp ;
		else{
			temp->Next = Head ;
			Head = temp ;
		}
	}
	else {
		Nptr ptr = Head ;
		for (int i=0 ; i<Position-2; i++)
			ptr = ptr->Next ;
		temp->Next = ptr->Next ;
		ptr->Next = temp ;
	}
	Count++ ;
} // 원하는 위치에 데이터삽입
void List_Class::Delete_List(int Position){
	Nptr temp = Head, ptr ;
	if ( Position <=0 || Position-1 > Count )
		cout << "Position Error" << endl ;
	else if (Position == 1 ) {
		ptr = Head ;
		Head = Head->Next ;
		delete(ptr) ;
	}
	else {
		for (int i=0; i<Position-2 ; i++)
			temp = temp->Next ;
		ptr = temp->Next ;
		temp->Next = ptr->Next ;
		delete (ptr) ;
	}
	--Count ;
}// 원하는 위치 삭제
void List_Class::Output_List(){
	if (Head == NULL)
		cout << "저장된 데이터가 없는 빈 리스트입니다." ;
	else {
		Nptr ptr = Head ;
		while (ptr != NULL) {
			cout << ptr->Data << "     " ;
			ptr = ptr->Next ;
		}
	}
} // 현제 데이터 모두 출력
void List_Class::Search_List(int Data) {

	Nptr p = Head ;
	int counter = 0 ;

	for (int i=0 ; i<Count ; i++) {
		if ( p->Data == Data )
			cout << "Find Data : " << Data << " Index : " << counter+1  ;
		p = p->Next ; counter ++ ;
	}
	if (p == NULL)
		cout << " Finish Search" << endl ;
	else
		cout << " 비정상적 종료" << endl ;

} // 원하는 데이터 검색
bool List_Class::IsEmpty_List() {
	if (Count ==0)
		return 0 ;
	else
		return 1 ;
}// 비어있는지 확인
int List_Class::Length_List(){
	return (Count) ;
}// 리스트 내의 개수

void List_Class::Set_Count(int Data) {
	Count = Data ;
}// 메인함수에서 받은 Count값으로 변경
void List_Class::Set_Head(Nptr ptr) {
	Head = ptr ;
}// 메인함수에서 받은 Head 값으로 변경
int List_Class::Get_Count() {
	return Count ;
}// 메인함수로 Count값 return 
Nptr List_Class::Get_Head() {
	return Head ;
}// 메인함수로 Head값 return 
