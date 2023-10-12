#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode* p = l1;
	struct ListNode* q = l2;
	struct ListNode* ans = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* r = ans;
	int t = 0, carry = 0, x, y, sum;
	while (p != NULL || q != NULL)
	{
		x = (p != NULL) ? p->val : 0;
		y = (q != NULL) ? q->val : 0;
		sum = x + y + carry;
		carry = sum / 10;
		sum %= 10;
		if (!t)
		{
			r->val = sum;
			r->next = NULL;
			t = 1;
		}
		else
		{
			r->next = (struct ListNode*)malloc(sizeof(struct ListNode));
			r = r->next;
			r->val = sum;
			r->next = NULL;
		}
		if (q != NULL)
			q = q->next;
		if (p != NULL)
			p = p->next;
	}
	if (carry)
	{
		r->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		r = r->next;
		r->val = carry;
		r->next = NULL;
	}
		return ans;
}
//测试main
//int main()
//{
//	printf("请输入数1：\n");
//	struct ListNode* L1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* p = L1;
//	int num;
//	scanf("%d", &num);
//	p->val = num;
//	p->next = NULL;
//	while (scanf("%d", &num) != EOF) 
//	{
//		p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//		p = p->next;
//		p->val = num;
//		p->next = NULL;
//	}
//
//	printf("请输入数2：\n");
//	struct ListNode* L2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	L2->next = NULL;
//	p = L2;
//	scanf("%d", &num);
//	p->val = num;
//	p->next = NULL;
//	while (scanf("%d", &num) != EOF)
//	{
//		p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//		p = p->next;
//		p->val = num;
//		p->next = NULL;
//	}
//
//	struct ListNode* L3 = addTwoNumbers(L1, L2);
//	p = L3;
//	while (p != NULL)
//	{
//		printf("%d ", p->val);
//		p = p->next;
//	}
//
//	return 0;
//}