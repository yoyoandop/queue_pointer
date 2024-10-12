#include <iostream>
using namespace std;

// 節點結構
struct Node {
    int data;       // 儲存資料
    Node* next;     // 指向下一個節點

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Queue 類別實作
class Queue {
private:
    Node* front;    // 指向 queue 的前端
    Node* rear;     // 指向 queue 的後端

public:
    // 建構子：初始化空的 queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // 檢查 queue 是否為空
    bool isEmpty() {
        return front == nullptr;
    }

    // 將元素加入到 queue 的後端
    void enqueue(int value) {
        Node* newNode = new Node(value); // 建立新節點
        if (isEmpty()) {
            // 若 queue 為空，front 與 rear 都指向新節點
            front = rear = newNode;
        } else {
            // 將新節點加入到 rear 的後面
            rear->next = newNode;
            rear = newNode; // 更新 rear
        }
    }

    // 從 queue 的前端移除元素
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // 返回-1表示失敗
        }

        int value = front->data;  // 取得 front 節點的資料
        Node* temp = front;       // 暫存 front 節點
        front = front->next;      // 將 front 指向下一個節點

        // 若移除後 queue 為空，將 rear 設為 nullptr
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;  // 釋放原 front 節點
        return value;
    }

    // 取得 queue 前端的元素
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to peek." << endl;
            return -1;
        }
        return front->data;  // 返回 front 節點的資料
    }

    // 解構子：釋放所有節點的記憶體
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;

    // 測試 enqueue 操作
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    // 測試 dequeue 和 peek 操作
    cout << "Front element: " << q.peek() << endl;
    cout << "Dequeue element: " << q.dequeue() << endl;
    cout << "Front element after dequeue: " << q.peek() << endl;

    // 繼續測試 dequeue
    while (!q.isEmpty()) {
        cout << "Dequeue element: " << q.dequeue() << endl;
    }

    return 0;
}
