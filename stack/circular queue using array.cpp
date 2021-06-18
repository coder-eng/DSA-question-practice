#include <iostream>
using namespace std;
#define n 4
class queue{
    int front,back;
    int arr[n];
    public:
    queue(){
        front = -1;
        back = -1;
    }
      bool isEmpty(){
        return(front == -1 && back == -1);
    }
    bool isfull(){
        return((back+1)%n == front);
    }
    void enqueue(int x){
         if(isfull()){
             cout<<"overflow"<<endl;
             return;

         }
           
         else if(isEmpty())
           front = back = 0;
         else
           back = (back+1)%n;

        arr[back] = x;

    }

    void dequeue(){
        int x;
        if(front == -1 && back == -1){
            cout<<"uderflow"<<endl;
            return;

        }
        

        else if(front == back){
            x = arr[front];
            front = back = -1;
        }
        else{
            x = arr[front];
            front = (front+1)%n;
        }
        cout<<x<<endl;
    }

    void peek(){
        if(front == -1 && back == -1)
        cout<<"queue is empty"<<endl;
        else
        cout<<arr[front]<<endl;
    }

  
};
int main(){
    queue que;
    que.enqueue(1);
    que.enqueue(2);
    que.enqueue(3);
    que.enqueue(4);
    
    que.peek();
    cout<<endl;
    que.dequeue();
    que.enqueue(5);
    que.dequeue();
    que.dequeue();
    que.dequeue();
    que.dequeue();

}