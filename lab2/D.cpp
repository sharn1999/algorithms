#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// Define the structure for a node in the linked list
struct ListNode {
    int value;
    ListNode* next;
    ListNode(int val) : value(val), next(nullptr) {}
};

// Function to create a new node and add it to the end of the linked list
void appendNode(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (!head) {
        head = newNode;
    } else {
        ListNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to find the mode(s) in descending order
vector<int> findMode(ListNode* head) {
    unordered_map<int, int> countMap;
    int maxCount = 0;

    // Traverse the linked list and count occurrences
    ListNode* current = head;
    while (current) {
        countMap[current->value]++;
        maxCount = max(maxCount, countMap[current->value]);
        current = current->next;
    }

    // Find elements with maximum count
    vector<int> modes;
    for (const auto& entry : countMap) {
        if (entry.second == maxCount) {
            modes.push_back(entry.first);
        }
    }

    return modes;
}

bool compareDescending(int a, int b) {
    return a > b; // Swap the order of comparison to sort in descending order
}

int main() {
    ListNode* head = nullptr;

    // Add numbers to the linked list
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        appendNode(head, num);
    }

    // Find the mode(s)
    vector<int> modes = findMode(head);

    sort(modes.begin(), modes.end(), compareDescending);
    
    for (int num : modes) {
        cout << num << " ";
    }
    cout << endl;

    // Free memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}