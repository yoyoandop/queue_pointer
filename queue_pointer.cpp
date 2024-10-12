#include <iostream>
using namespace std;

// �`�I���c
struct Node {
    int data;       // �x�s���
    Node* next;     // ���V�U�@�Ӹ`�I

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Queue ���O��@
class Queue {
private:
    Node* front;    // ���V queue ���e��
    Node* rear;     // ���V queue �����

public:
    // �غc�l�G��l�ƪŪ� queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // �ˬd queue �O�_����
    bool isEmpty() {
        return front == nullptr;
    }

    // �N�����[�J�� queue �����
    void enqueue(int value) {
        Node* newNode = new Node(value); // �إ߷s�`�I
        if (isEmpty()) {
            // �Y queue ���šAfront �P rear �����V�s�`�I
            front = rear = newNode;
        } else {
            // �N�s�`�I�[�J�� rear ���᭱
            rear->next = newNode;
            rear = newNode; // ��s rear
        }
    }

    // �q queue ���e�ݲ�������
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // ��^-1��ܥ���
        }

        int value = front->data;  // ���o front �`�I�����
        Node* temp = front;       // �Ȧs front �`�I
        front = front->next;      // �N front ���V�U�@�Ӹ`�I

        // �Y������ queue ���šA�N rear �]�� nullptr
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;  // ����� front �`�I
        return value;
    }

    // ���o queue �e�ݪ�����
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to peek." << endl;
            return -1;
        }
        return front->data;  // ��^ front �`�I�����
    }

    // �Ѻc�l�G����Ҧ��`�I���O����
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;

    // ���� enqueue �ާ@
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    // ���� dequeue �M peek �ާ@
    cout << "Front element: " << q.peek() << endl;
    cout << "Dequeue element: " << q.dequeue() << endl;
    cout << "Front element after dequeue: " << q.peek() << endl;

    // �~����� dequeue
    while (!q.isEmpty()) {
        cout << "Dequeue element: " << q.dequeue() << endl;
    }

    return 0;
}
