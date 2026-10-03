
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        ListNode head;
        ListNode *last = &head;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                last->next = list1;
                list1 = list1->next;
            }
            else
            {
                last->next = list2;
                list2 = list2->next;
            }

            last = last->next;
        }

        last->next = (list1 == nullptr) ? list2 : list1;

        return head.next;
    }
};