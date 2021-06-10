#include<iostream>
#include<stack>
using namespace std;
stack<int>st;
    void insert_bottom(int s){
        if(st.empty())
           st.push(s);
        else{
            int a = st.top();
            st.pop();
            insert_bottom(s);
            st.push(a);
        }       
    }
    void reverse_stack_using_recursion(){
        if(!st.empty()){
            int x = st.top();
            st.pop();
            reverse_stack_using_recursion();
            insert_bottom(x);
        }
    }

int main(){
    insert_bottom(1);
    insert_bottom(2);
    insert_bottom(3);
    insert_bottom(4);
    reverse_stack_using_recursion();
    while(!st.empty()){
       cout<<st.top()<<endl;
       st.pop();
    }
    return 0;

}