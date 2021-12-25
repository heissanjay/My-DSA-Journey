// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *temp = head;
        if (temp == nullptr)
            return head;
        while (temp->next != nullptr)
        {
            if (temp->val == temp->next->val)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }
};

// https://leetcode.com/problems/linked-list-cycle/

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                return true;
            }
        }
        return false;
    }
};

// https://leetcode.com/problems/linked-list-cycle-ii/

class Solution
{
public:
    int findLength(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                ListNode *temp = slow;
                int length = 0;
                do
                {
                    temp = temp->next;
                    length++;
                } while (temp != slow);
                return length;
            }
        }
        return 0;
    }
    ListNode *detectCycle(ListNode *head)
    {
        int length = 0;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                length = findLength(slow);
                break;
            }
        }
        if (length == 0)
        {
            return NULL;
        }
        ListNode *fst = head;
        ListNode *slw = head;

        while (length > 0)
        {
            slw = slw->next;
            length--;
        }

        while (fst != slw)
        {
            fst = fst->next;
            slw = slw->next;
        }

        return slw;
    }
};

// https://leetcode.com/problems/happy-number/

class Solution
{
public:
    int findSquare(int num)
    {
        int square = 0;
        while (num > 0)
        {
            int digit = num % 10;
            square += digit * digit;
            num /= 10;
        }
        return square;
    }
    bool isHappy(int n)
    {
        int fast = n;
        int slow = n;

        do
        {
            slow = findSquare(slow);
            fast = findSquare(findSquare(fast));
        } while (slow != fast);

        if (slow == 1)
            return true;

        return false;
    }
};

// https : // leetcode.com/problems/middle-of-the-linked-list/
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
// https : // leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            head = nullptr;
            return head;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = nullptr;

        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        return head;
    }
};

// https: // leetcode.com/problems/reverse-linked-list/
