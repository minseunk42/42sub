#include <iostream>
using namespace std;
int arr[500001] = {0,};

int main(void)
{
    int n;
    cin >> n;
    int front = 1;
    int rear = n;
    for (int i = 1; i <= rear; ++i) arr[i] = i;
    while (front != rear)
    {
        arr[front++] = 0;
        while (arr[front] == 0)
        {
            front++;
            if (front > n)
                front = 1;
        }
        if (front == rear)
            break ;
        rear = front;
        cout << "f" << arr[front] << '\n';
        cout << "r" << arr[rear] << '\n';
    }
    cout << arr[front];
}