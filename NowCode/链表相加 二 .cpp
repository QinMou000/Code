/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
    public:
      ListNode* reverse(ListNode* head) {
          assert(head != nullptr);
          ListNode* newNode = new ListNode(0);
          ListNode* cur = head;
  
          while (cur) {
              ListNode* next = cur->next;
              cur->next = newNode->next;
              newNode->next = cur;
              cur = next;
          }
          return newNode->next;
      }
      // void push_back(ListNode* head, ListNode* newnode) {
      //     assert(head != nullptr);
      //     ListNode* cur = head;
      //     while (cur->next)
      //         cur = cur->next;
      //     cur->next = newnode;
      // }
      ListNode* addInList(ListNode* head1, ListNode* head2) {
          // write code here
          head1 = reverse(head1);
          head2 = reverse(head2);
  
          ListNode* ans = new ListNode(0);
          int c = 0; // 进位
          ListNode* prev = ans;
  
          while (head1 || head2 || c) {
              if (head1) {
                  c += head1->val ;
                  head1 = head1->next;
              }
              if (head2) {
                  c += head2->val ;
                  head2 = head2->next;
              }
              ListNode* cur = new ListNode(c % 10);
              // push_back(ans, cur); // 会超时
              prev = prev->next = cur; // 放在链表最后
              c /= 10;
          }
          ListNode *tmp = ans->next;
          delete ans;
          
          return reverse(tmp);
      }
  };
// link : https://www.nowcoder.com/practice/c56f6c70fb3f4849bc56e33ff2a50b6b
