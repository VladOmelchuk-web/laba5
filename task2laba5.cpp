#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


struct stack {
    string data;
    stack* next;
};


void add(stack*& head, string data);
void cls(stack*& head);
void print(stack*& head);
bool check(stack*& head);
void add_v(stack*& head, vector<string>& v);
int main() {
    stack* head = new stack;
    head->next = nullptr;
    ifstream file("task2.txt");
    while (!file.eof()) {
        string temp;
        file >> temp;
        add(head, temp);
    }
    file.close();


    print(head);
    cout << endl;
    cout << check(head);
    cls(head);

    return 0;
}

void add(stack*& head, string data)
{
    if (head->next == nullptr) {
        stack* temp;
        temp = new stack;
        temp->data = data;
        temp->next = nullptr;
        head->next = temp;
    }
    else
        add(head->next, data);
}

void cls(stack*& head)
{
    if (head == nullptr)
        return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    if (head->next != nullptr) {
        cls(head->next);
    }
}

void print(stack*& head)
{
    if (head->next == nullptr) {
        cout << head->data << " ";
        return;
    }
    print(head->next);
    cout << head->data << " ";
}

bool check(stack*& head)
{
    vector<string> v;
    add_v(head, v);

    bool f = 0, s = 0, op = 0;
    if (v[0] == "true") f = 1;
    if (v[1] == "true") s = 1;
    if (v[2] == "or") op = 1;

    if (op)
        return f || s;
    return f && s;

}

void add_v(stack*& head, vector<string>& v) {
    if (head == nullptr)
        return;
    v.push_back(head->data);
    add_v(head->next, v);
}
