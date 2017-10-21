#include<stdio.h>
#include <assert.h>  

typedef int STATUS;
typedef struct _LINK_NODE
{
	int data;
	struct _LINK_NODE* next;
}LINK_NODE;
LINK_NODE* alloca_node(int value)
{
	LINK_NODE* pLinkNode = NULL;
	pLinkNode = (LINK_NODE*)malloc(sizeof(LINK_NODE));

	pLinkNode->data = value;
	pLinkNode->next = NULL;
	return pLinkNode;
}
void delete_node(LINK_NODE** pNode)
{
	LINK_NODE** pNext;
	if (NULL == pNode || NULL == *pNode)
		return;

	pNext = &(*pNode)->next;
	free(*pNode);
	delete_node(pNext);
}
STATUS _add_data(LINK_NODE** pNode, LINK_NODE* pDataNode)
{
	if (NULL == *pNode){
		*pNode = pDataNode;
		return 1;
	}

	return _add_data(&(*pNode)->next, pDataNode);
}

STATUS add_data(const LINK_NODE** pNode, int value)
{
	LINK_NODE* pDataNode;
	if (NULL == *pNode)
		return 0;

	pDataNode = alloca_node(value);
	assert(NULL != pDataNode);
	return _add_data((LINK_NODE**)pNode, pDataNode);
}
STATUS _delete_data(LINK_NODE** pNode, int value)
{
	LINK_NODE* pLinkNode;
	if (NULL == (*pNode)->next)
		return 0;

	pLinkNode = (*pNode)->next;
	if (value == pLinkNode->data){
		(*pNode)->next = pLinkNode->next;
		free(pLinkNode);
		return 1;
	}
	else{
		return _delete_data(&(*pNode)->next, value);
	}
}

STATUS delete_data(LINK_NODE** pNode, int value)
{
	LINK_NODE* pLinkNode;
	if (NULL == pNode || NULL == *pNode)
		return 0;

	if (value == (*pNode)->data){
		pLinkNode = *pNode;
		*pNode = pLinkNode->next;
		free(pLinkNode);
		return 1;
	}

	return _delete_data(pNode, value);
}
LINK_NODE* find_data(const LINK_NODE* pLinkNode, int value)
{
	if (NULL == pLinkNode)
		return NULL;

	if (value == pLinkNode->data)
		return (LINK_NODE*)pLinkNode;

	return find_data(pLinkNode->next, value);
}
void print_node(const LINK_NODE* pLinkNode)
{
	if (pLinkNode){
		printf("%d ", pLinkNode->data);
		print_node(pLinkNode->next);
	}
}
int count_node(const LINK_NODE* pLinkNode)
{
	if (NULL == pLinkNode)
		return 0;

	return 1 + count_node(pLinkNode->next);
}
int main() {
	LINK_NODE* a;
	LINK_NODE** head = NULL;
	//creat 创建
	a = alloca_node(1);
	head = &a;
	//insert 插入
	add_data(head, 2);
	add_data(head, 3);
	add_data(head, 4);
	printf("data (insert) is: ");
	print_node(*head);
	printf("\n");
	//delete 删除
	delete_data(head, 3);
	printf("data (delete) is: ");
	print_node(*head);
	printf("\n");
	//find 查询
	LINK_NODE* find_node;
	find_node = find_data(*head, 2);
	printf("find data is: %d \n", find_node->data);
	//count 数节点
	int num = count_node(*head);
	printf("node number is: %d \n", num);
	system("pause");
}
