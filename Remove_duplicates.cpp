
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* deleteDuplicates(ListNode* head) {
    //Complete the function
    if(!head){
        return head;
    }
    set<int> st;
    ListNode *curr = head;
    ListNode *curr_prev = nullptr;
    while(curr != nullptr){
        int a = curr->val;
        if(!st.empty() && st.find(a) != st.end()){
            curr_prev->next = curr->next;
            curr = curr->next;
        }
        else{
            st.insert(a);
            curr_prev = curr;
            curr = curr->next;
        }
    }
    


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

    ListNode* head = GetList(num);

    head = deleteDuplicates(head);

    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
    
    return 0;
}
