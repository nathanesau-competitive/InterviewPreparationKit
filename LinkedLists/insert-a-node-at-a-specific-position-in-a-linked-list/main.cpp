// https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem
using namespace std;

#include <vector>
#include <limits>
#include <cassert>

namespace insertanodeataspecificpositioninalinkedlist
{
class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    ~SinglyLinkedList() // implement destructor to avoid memory leak
    {
        auto curr = head;

        while(curr)
        {
            auto next = curr->next;
            delete curr;
            curr = next;
        }
    }

    void insert_node(int node_data)
    {
        SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);

        if (!this->head)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
        }

        this->tail = node;
    }

    vector<int> getData() const // return a vector with the linked list data
    {
        vector<int> data;

        auto curr = head;
        while(curr)
        {
            data.push_back(curr->data);
            curr = curr->next;
        }

        return data;
    }
};

SinglyLinkedListNode *insertNodeAtPosition(SinglyLinkedListNode *head, int data, int position)
{
    auto curr = head;

    int cnt = 0;
    while(cnt < position)
    {
        curr = curr->next;
        cnt++;
    }

    if(curr) // not nullptr
    {
        auto temp = curr->next;
        curr->next = new SinglyLinkedListNode(curr->data);
        curr->next->next = temp;
        curr->data = data;
        return curr;
    }
    else
    {
        curr = new SinglyLinkedListNode(data);
        return curr;
    }
}

void test()
{
    SinglyLinkedList linkedList;
    linkedList.insert_node(16);
    linkedList.insert_node(13);
    linkedList.insert_node(7);

    insertNodeAtPosition(linkedList.head, 1, 2);
    
    vector<int> actual_data = linkedList.getData();
    vector<int> expected_data = {16, 13, 1, 7};

    for(int i = 0; i < 4; i++)
    {
        assert(actual_data[i] == expected_data[i]);
    }
}
} // namespace insertanodeataspecificpositioninalinkedlist