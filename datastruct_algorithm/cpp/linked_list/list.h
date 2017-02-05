// List ADT ����
// ����Լ��� list.cpp���� ����


#ifndef NODETYPE
#define NODETYPE
typedef struct node {
	int Data ;
	struct node* Next ;
} Node ;							// ��� ����ü ����
typedef Node* Nptr ;				// ��� ������Ÿ�� ����
#endif


#ifndef LIST_H
#define LIST_H
class List_Class {
public:
	List_Class() ;							// ������
	~List_Class() ;							// �Ҹ���
	void Insert_List(int Position, int Data) ;		// ���ϴ� ��ġ�� �����ͻ���
	void Delete_List(int Position) ;				// ���ϴ� ��ġ ����
	void Output_List() ;				// ���� ������ ��� ���
	void Search_List(int Data) ;			// ���ϴ� ������ �˻�
	bool IsEmpty_List() ;						// ����ִ��� Ȯ��
	int Length_List() ;							// ����Ʈ ���� ����
	void Set_Count(int Data) ;
	void Set_Head(Nptr ptr) ;
	int Get_Count() ;
	Nptr Get_Head() ;

private:
	int Count ;							// ī����
	Nptr Head ;							// �ص�������

} ; 		// Ŭ���� ����
#endif


