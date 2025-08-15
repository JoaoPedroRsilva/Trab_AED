/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* findMiddle( struct ListNode* List ){
    if( List == NULL || List->next == NULL ){
        return List;
    }
    struct ListNode* slow = List;
    struct ListNode* fast = List->next;

    while( fast->next != NULL && fast->next->next != NULL ){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct ListNode* mergedList( struct ListNode* l1, struct ListNode* l2 ){
    struct ListNode temp;
    struct ListNode* tempHead = &temp;
    struct ListNode* tail = &temp;

    while( l1 != NULL && l2 != NULL ){
        if( l1->val < l2->val ){
            tail->next = l1;
            l1 = l1->next;
        }else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if( l1 != NULL ){
        tail->next = l1;
    } 
    if( l2 != NULL ){
        tail->next = l2;
    }
    return tempHead->next;
}

struct ListNode* sortList(struct ListNode* head) {
    if( head == NULL || head->next == NULL ){
        return head;
    }

    struct ListNode* middle = findMiddle( head );
    struct ListNode* left = head;
    struct ListNode* right = middle->next;
    middle->next = NULL;

    left = sortList( left );
    right = sortList( right );

    head = mergedList( left, right );
    
    

    return head;
}