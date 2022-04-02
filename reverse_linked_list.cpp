#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseRecursevly(ListNode* &head, ListNode* node) {
    if(!node || !node->next) {
        head = node;
        return node;
    }
    
    ListNode* next = reverseRecursevly(head, node->next);
    node->next = nullptr;
    next->next = node;
    return node;
}

ListNode* reverseList(ListNode* head) {
    ListNode* reversedList = nullptr;
    reverseRecursevly(reversedList, head);
    return reversedList;
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
    int n;
    cin>>n;

    ListNode* head = nullptr;

    int val;
    for (int i = 0; i < n; i++) {
        cin>>val;
        ListNode* newNode = new ListNode(val);
        insert(head, newNode);
    }
    
    ListNode* reversedList = reverseList(head);
    printLinkedList(reversedList);

    return 0;
}