#include <iostream>



struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* ans = new ListNode(0), * cur = ans;
    int non_empty_lists_counter = lists.size();
    // ПАРЫ (ЗНАЧЕНИЕ, ИНДЕКС В ВЕКТОРЕ)
    auto cmp = [](pair<int, int> left, pair<int, int> right) { return (left.first) > (right.first); };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> cur_elems(cmp);
    int i = 0;
    for (auto& l : lists) {
        if (l) {
            cur_elems.push(make_pair(l->val, i));
            l = l->next;
        }
        else non_empty_lists_counter--;
        i++;
    }
    while (non_empty_lists_counter) {
        pair<int, int> top_of_the_queue = cur_elems.top();
        const int index = top_of_the_queue.second;
        cur_elems.pop();
        cur->next = new ListNode(top_of_the_queue.first);
        cur = cur->next;
        if (lists[index]) {
            cur_elems.push(make_pair(lists[index]->val, index));
            lists[index] = lists[index]->next;
        }
        else non_empty_lists_counter--;
    }

    return ans->next;
}


int main()
{
    //
    return 0;
}
