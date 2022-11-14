# LeetCode
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    typedef struct ListNode* List;
    typedef struct ListNode* Position;
        Position p = l1;
        Position q = l2;
        Position current,prev;
        List l3 = NULL;
        int num = 0;
        while(q!= NULL||p!= NULL)
        {
            current = (Position)malloc(sizeof(struct ListNode));
            if(l3 == NULL)
                l3 = current;
            else
                prev->next = current;
            if(p != NULL&&q!= NULL)
            {
                current->val = (p->val+q->val+num)%10;
                num = (p->val+q->val+num)/10;
                p = p->next;
                q = q->next;
            }
            else if(p == NULL)
            {
                current->val = (q->val+num)%10;
                num = (q->val+num)/10;
                q = q->next;
            }
            else
            {
                current->val = (p->val+num)%10;
                num = (p->val+num)/10;
                p = p->next;
            }
            current->next = NULL;
            prev = current;
        }
        if(num!=0)
            {
                current = (Position)malloc(sizeof(struct ListNode));
                current->val = num;
                prev->next = current;
                current->next = NULL;
            }
        return l3;
    }
