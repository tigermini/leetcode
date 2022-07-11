#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *lnhead = NULL;
    struct ListNode *lnloop = NULL;
    struct ListNode *lntmp = NULL;
    int flag = 0;

    while ((l1 != NULL) || (l2 != NULL)) {
        lntmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (lntmp == NULL) {
            return NULL;
        }
        memset(lntmp, 0, sizeof(struct ListNode));
        
        if (l1 != NULL) {
            lntmp->val += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            lntmp->val += l2->val;
            l2 = l2->next;
        }
        if (flag == 1) {
            lntmp->val += 1;
            flag = 0;
        }
        if (lntmp->val > 9) {
            flag = 1;
            lntmp->val -= 10;
        }
        if (lnhead == NULL) {
            lnhead = lntmp;
            lnloop = lnhead;
        } else {
            lnloop->next = lntmp;
            lnloop = lnloop->next;
        }
    }
    if (flag == 1) {
        lntmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (lntmp == NULL) {
            return NULL;
        }
        memset(lntmp, 0, sizeof(struct ListNode));
        lntmp->val = 1;
        lnloop->next = lntmp;
    }

    return lnhead;
}

static void test(struct ListNode *lntest1, struct ListNode *lntest2)
{
    struct ListNode *lntest;

    if (lntest1 == NULL || lntest2 == NULL) {
        printf("lntest1 or lntest2 is invaild\n");
    }

    lntest = addTwoNumbers(lntest1, lntest2);

    while(lntest != NULL) {
        printf("%d\n", lntest->val);
        lntest = lntest->next;
    }
}

int main(int argc, char *argv[])
{
    struct ListNode lt11;
    struct ListNode lt12;
    struct ListNode lt13;
    struct ListNode lt21;
    struct ListNode lt22;
    struct ListNode lt23;

    lt11.val = 2;
    lt12.val = 4;
    lt13.val = 3;
    lt11.next = &lt12;
    lt12.next = &lt13;

    lt21.val = 5;
    lt22.val = 6;
    lt23.val = 4;
    lt21.next = &lt22;
    lt22.next = &lt23;

    test(&lt11, &lt21);

    return 0;
}
