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
    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
