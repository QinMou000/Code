#define _CRT_SECURE_NO_WARNINGS 1

#include<stdbool.h>
#include<stdio.h>
//
//bool is_alp(char c)
//{
//	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
//}
//
//bool isPalindrome(char* s)
//{
//	int len = strlen(s);
//	int left = 0;
//	int right = len - 1;
//
//	while (left < right)
//	{
//		while (left < right && !is_alp(s[left]))
//			left++;
//		while (left < right && !is_alp(s[right]))
//			right--;
//
//		if (tolower(s[left]) != tolower(s[right]))
//		{
//			return 0;
//		}
//		left++;
//		right--;
//	}
//	return 1;
//}
//
//
//int main()
//{
//
//
//	return 0;
//}


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct ListNode* ReverseList(struct ListNode* head) {
    // write code here
    struct ListNode* pcur = head;
    struct ListNode* prev = NULL;
    while (pcur)
    {
        struct ListNode* tmp = pcur->next;
        pcur->next = prev;
        prev = pcur;
        pcur = tmp;
    }
    return prev;
}

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* fast = head, * slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        struct ListNode* mid = middleNode(A);
        struct ListNode* rmid = ReverseList(mid);
        while (A && rmid)
        {
            if (A->val != rmid->val)
                return false;
            A = A->next;
            rmid = rmid->next;
        }
        return true;
    }
};