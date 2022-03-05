// CODE BY :- AJAY PAL IIT (BHU) VARANASI
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

bool isLoop(Node *head)
{
    if (!head)
        return false;

    Node *fast = head->next;
    Node *slow = head;

    while (fast != slow)
    {
        if (!fast || !fast->next)
            return false;
        fast = fast->next->next;
        slow = slow->next;
    }

    return true;
}

class Solution
{
public:
    void removeLoop(Node *head)
    {

        if (!isLoop(head))
        {
            return;
        }

        Node *slow = head;
        Node *fast = head;

        do
        {
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        if (fast == head)
        {
            while (slow->next != head)
            {
                slow = slow->next;
            }
            slow->next = NULL;
            return;
        }

        fast = head;

        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = NULL;
    }
};
