/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * temp = head;

        Node * copyNode;
        while(temp != NULL)
        {
            copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }

        temp = head;

        while(temp != NULL)
        {
            copyNode = temp->next;
            if(temp->random != NULL)
            {
                copyNode->random = temp->random->next;
            }
            else
            {
                copyNode->random = NULL;
            }
            temp = temp->next->next;
        }

        Node * dummyNode = new Node(-1);
        Node * res = dummyNode;
        temp = head;

        while(temp != NULL)
        {
            res->next = temp->next;
            temp->next = temp->next->next;

            res = res->next;
            temp = temp->next;
        }

        return dummyNode->next;
    }
};
