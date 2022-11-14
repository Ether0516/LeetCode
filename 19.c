# LeetCode
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    typedef struct ListNode* Position;
    Position p,q;
    int cut = 0;
    q = head;
    while(q != NULL)
    {
        q = q->next;
        cut++;
    } 
    q =head;
    for(int i=1;i<=cut-n;i++)
        q = q->next;
    if(q == head)
    {
        head = head->next;
        free(q);
    }
    else
    {
        p = head;
        while(p->next!=q)
            p = p->next;
        p->next = q->next;
        free(q);
    }
    return head;

}
