
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* rotateList(ListNode* head, int K) {
    //Complete the function
    //Agar ek bhi element nahi hai ya k==0 hai toh
    if(!head) return nullptr;
    if(!k) return head;

    int n =0;
    ListNode *cur = head;
    ListNode *last = head;

    // Coutning no of nodes
    while(cur) {
        n++;
        last = cur;
        cur = cur->next;
    }

    K = K%n;
    cur = head;
    for(int i=0;i < n-k-1; i++){
        cur = cur->next;
    }

    last->next = head;

    ListNode *temporary = cur->next;
    cur->next = NULL;

    return temporary;
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

    int K;
    cin >> K;

    ListNode* head = GetList(num);

    head = rotateList(head, K);

    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
    
    return 0;
}
