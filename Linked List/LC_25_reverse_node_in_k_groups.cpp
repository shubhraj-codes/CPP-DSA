/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* temp) {
        ListNode * prev = NULL;
        while(temp != NULL)
        {
            ListNode * front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode * findKth(ListNode * temp, int k)
    {
        int cnt = 0;
        while(cnt < k-1)
        {
            if(temp == NULL) return temp;
            temp = temp->next;
            cnt++;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * temp = head;
        ListNode * nextNode;
        ListNode * prevNode = NULL;

        while(temp != NULL)
        {
            ListNode * kthNode = findKth(temp, k);
            if(kthNode == NULL) 
            {
                if(prevNode) prevNode->next = temp;
                break;
            }

            nextNode = kthNode->next;
            kthNode->next = NULL;

            reverseList(temp);

            if(temp == head)
            {
                head = kthNode;
            }
            else 
            {
                prevNode->next = kthNode;
            }

            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};
