#include<iostream>
using namespace std;

// FIFO
class Queue{
    public:
    int currSize=0;
    int size = 10;
    int queue[10];
    int start  = -1 , end = -1;
    
    void push(int x){
       if(currSize == size){
            return;
        }
        else if(currSize == 0){
            start = 0 ;
            end = 0;
        }else{
            end = (end+1) % size;
        }
        queue[end] = x ;
        currSize +=1;
    };

    int pop(){
        if(currSize ==0) return -1;
        int ele = queue[start];

        if(currSize == 1){
            start = -1;
            end = -1;
        }else{
            start = (start+1) % size;
            currSize -=1;
        }
        return ele;
    }

    int maxSize(){
        return currSize;
    }
    int top(){
        if(currSize ==0) return -1;
        return queue[start];
    }

}; 

int main(){
       Queue q;
    q.push(1);
    q.push(4);
   cout << q.top() << endl;
   cout <<  q.maxSize() << endl;
    return 0;
}