
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



ListNode* removeNthFromEnd(ListNode* head, int N) {
    if(!head) return head;
        
    ListNode *prev = NULL, *cur = head;
    
    for(int i = 0; i < N; i++) 
        cur = cur->next;
    
    if(!cur) return head->next;
    
    while(cur) {
        cur = cur->next;
        if(prev) prev = prev->next;
        else prev = head;
    }
    
    prev->next = prev->next->next;
    
    return head;
}


ListNode* GetList(vector<int> &num) {
    ListNode* head = nullptr;

    if(num.empty()) {
        return head;
    }

    ListNode* cur = head;
    
    for(int i  = 0; i < (int)num.size(); i++) {
        ListNode* temp = new ListNode(num[i]);
        if(!cur) {
            cur = temp;
            head = cur;
        }
        else {
            cur->next = temp;
            cur = temp;
        }
    }
    
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> num;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }

    int N;
    cin >> N;

    ListNode* head = GetList(num);

    head = removeNthFromEnd(head, N);

    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
    
    return 0;
}
