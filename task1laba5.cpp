include <iostream>
#include <ctime>
using namespace std;

struct tree {
    int x;
    tree* left, *right;
};

void fill(tree*& head, int& n);
void cls(tree*& head);
void add_node(tree*& head, int x);
void print(tree*& head);
bool rcheck(tree*& head1, tree*& head2);
bool check(tree*& head1, tree*& head2);
int main() {
    srand(time(NULL));
    tree* head1 = nullptr;
    tree* head2 = nullptr;

    int n1, n2;
    cout << "Enter count of elements in the first tree: "; cin >> n1;
    cout << "Enter count of elements in the second tree: "; cin >> n2;

    fill(head1, n1);
    fill(head2, n2);

    print(head1);
    cout << endl;
    print(head2);

    cout << endl << rcheck(head1, head2);
    cout << endl << check(head1, head2);
    cls(head1);
    cls(head2);
    return 0;
}

void fill(tree*& head, int& n)
{
    while (n != 0) {
        add_node(head, rand() % 10);
        n--;
    }
}

void cls(tree*& head)
{
    if (head != nullptr) {
        cls(head->left);
        cls(head->right);
    }
}

void add_node(tree*& head, int x)
{
    if (head == NULL) {
        head = new tree; 
        head->x = x;   
        head->left = NULL;
        head->right = NULL; 
    }
    else if (x < 5)   
        add_node(head->left, x);
    else    
        add_node(head->right, x);
}

void print(tree*& head) {
    if (head != nullptr) {
        print(head->left);
        print(head->right);
        cout << head->x << " ";
    }
}

bool rcheck(tree*& head1, tree*& head2) {
    if (head1->x == head2->x) {
        if (head1->left == nullptr && head2->left != nullptr)
            return false;
        if (head1->left != nullptr && head2->left == nullptr)
            return false;
        if (head1->right == nullptr && head2->right != nullptr)
            return false;
        if (head1->right != nullptr && head2->right == nullptr)
            return false;
        if (head1->right != nullptr && head2->right != nullptr)
            rcheck(head1->right, head2->right);
        if (head1->left != nullptr && head2->left != nullptr)
            rcheck(head1->left, head2->left);
        return true;
    }
    else
        return false;
}

bool check(tree*& head1, tree*& head2) {
    tree* temp1 = head1;
    tree* temp2 = head2;
    bool lf = false;
    while (true) {
        if (temp1 == nullptr && temp2 == nullptr && lf)
            return true;
        if (temp1 == nullptr && temp2 == nullptr && !lf) {
            temp1 = head1;
            temp2 = head2;
            lf = true;
        }
        if ((temp1 == nullptr && temp2 != nullptr) || (temp1 != nullptr && temp2 == nullptr))
            return false;
        if (temp1->x == temp2->x) {
            if (temp1->right && temp2->right) {
                if (temp1->right->x == temp2->right->x) {

                }
                else
                    return false;
            }
            if (temp1->left && temp2->left) {
                if (temp1->left->x == temp2->left->x) {

                }
                else 
                    return false;
            }
            if (!lf) {
                temp1 = temp1->left;
                temp2 = temp2->left;
            }
            else {
                temp1 = temp1->right;
                temp2 = temp2->right;
            }
        }
        else {
            return false;
        }
        
    }
}
