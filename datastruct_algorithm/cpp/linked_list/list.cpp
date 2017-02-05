// list.h���� ����� ����Լ� �� �����͸�
// �ʱ�ȭ �� �ۼ�

#include <iostream>
#include "list.h"

using std::cout ;
using std::endl ;

//			List_Class ����Լ� ����
List_Class::List_Class() {
	Count = 0 ;
	Head = NULL ;
} // ������
List_Class::~List_Class() {
} // �Ҹ���
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
} // ���ϴ� ��ġ�� �����ͻ���
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
}// ���ϴ� ��ġ ����
void List_Class::Output_List(){
	if (Head == NULL)
		cout << "����� �����Ͱ� ���� �� ����Ʈ�Դϴ�." ;
	else {
		Nptr ptr = Head ;
		while (ptr != NULL) {
			cout << ptr->Data << "     " ;
			ptr = ptr->Next ;
		}
	}
} // ���� ������ ��� ���
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
		cout << " �������� ����" << endl ;

} // ���ϴ� ������ �˻�
bool List_Class::IsEmpty_List() {
	if (Count ==0)
		return 0 ;
	else
		return 1 ;
}// ����ִ��� Ȯ��
int List_Class::Length_List(){
	return (Count) ;
}// ����Ʈ ���� ����

void List_Class::Set_Count(int Data) {
	Count = Data ;
}// �����Լ����� ���� Count������ ����
void List_Class::Set_Head(Nptr ptr) {
	Head = ptr ;
}// �����Լ����� ���� Head ������ ����
int List_Class::Get_Count() {
	return Count ;
}// �����Լ��� Count�� return 
Nptr List_Class::Get_Head() {
	return Head ;
}// �����Լ��� Head�� return 
