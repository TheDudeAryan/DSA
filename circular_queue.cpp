#include <iostream>
#include <string>

using namespace std;

class CircularQueue
{
private:
    int arr[5];
    int front;
    int rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is already full, try dequeing to add more elements" << endl;
            return;
        }

        if (isEmpty())
        {
            rear = front = 0;
            arr[rear] = value;
            return;
        }
        rear = (rear + 1) % 5;
        arr[rear] = value;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty, try enqueing to remove elements" << endl;
            return 0;
        }

        if (rear == front)
        {
            int deQueueElement = arr[rear];
            front = rear = -1;
            return deQueueElement;
        }

        int deQueueElement = arr[front];
        front = (front + 1) % 5;
        return deQueueElement;
    }

    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    bool isFull()
    {
        return ((rear + 1) % 5) == front;
    }

    int count()
    {
        if (isEmpty())
        {
            return 0;
        }
        return (rear - front) + 1;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "The queue is empty" << endl;
            return;
        }

        cout << "All values in the queue are" << endl;
        int i = front;
        while (i != rear)
        {
            cout << arr[i] << endl;
            i = (i + 1) % 5;
        }
        cout << arr[rear] << endl;
    }
};

int main()
{
    CircularQueue queue;
    int option, value;

    do
    {
        cout << "What operation do you want to perform? Select option number. Enter 0 to exit" << endl;
        cout << "1. enqueue" << endl;
        cout << "2. dequeue" << endl;
        cout << "3. isEmpty" << endl;
        cout << "4. isFull" << endl;
        cout << "5. count" << endl;
        cout << "6. display" << endl
             << endl;

        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter an item to enqueue" << endl;
            cin >> value;
            queue.enqueue(value);
            break;
        case 2:
            cout << "Item popped from the stack: " << queue.dequeue() << endl;
            break;

        case 3:
            if (queue.isEmpty())
            {
                cout << "Yes, the stack is empty" << endl;
                break;
            }
            cout << "No, the stack is not empty" << endl;
            break;

        case 4:
            if (queue.isFull())
            {
                cout << "Yes, the stack is full" << endl;
                break;
            }
            cout << "No, the stack is not full" << endl;
            break;

        case 5:
            cout << "Count of the stack is: " << queue.count() << endl;
            break;

        case 6:
            queue.display();
            break;

        default:
            cout << "Enter proper operation number" << endl;
            break;
        }
    } while (option != 0);

    return 0;
}
