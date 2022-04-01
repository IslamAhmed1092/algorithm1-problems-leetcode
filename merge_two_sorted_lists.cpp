#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == nullptr) return list2;
    if(list2 == nullptr) return list1;

    if(list1->val <= list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}


// utility functions

void insert(ListNode* &head, ListNode* newNode) {
    ListNode* iter = head;

    if(iter == nullptr) {
        head = newNode;
        return;
    }

    while (iter->next != nullptr) {
        iter = iter->next;
    }

    iter->next = newNode;

}

void printLinkedList(ListNode* head) {
    ListNode* iter = head;
    while (iter != nullptr) {
        cout<<iter->val<<" ";
        iter = iter->next;
    }

    cout<<endl;
}

int main() {

    int n1;
    cin>>n1;

    ListNode* list1 = nullptr;

    int val;
    for (int i = 0; i < n1; i++) {
        cin>>val;
        ListNode* newNode = new ListNode(val);
        insert(list1, newNode);
    }
    
    int n2;
    cin>>n2;

    ListNode* list2 = nullptr;

    for (int i = 0; i < n2; i++) {
        cin>>val;
        ListNode* newNode = new ListNode(val);
        insert(list2, newNode);
    }

    ListNode* mergedList = mergeTwoLists(list1, list2);

    printLinkedList(mergedList);
    return 0;
}