#include<iostream>
#include<stack>
using namespace std;
stack<int>st;
void sorted_stack(int s){
    if(st.empty() || s>=st.top())
       st.push(s);
    else {
        int x = st.top();
        st.pop();
        sorted_stack(s);
        st.push(x);

    }
}

void sort_stack(){
    if(st.empty())
    return ;
    
    if(!st.empty()){
        int a = st.top();
        st.pop();
        sort_stack();
        sorted_stack(a);
    }

    
}


int main(){

    st.push(3);
    st.push(2);
    st.push(1);
    //st.push(7);
    //st.push(3);

    sort_stack();
    while(!st.empty()){
       cout<<st.top()<<endl;
       st.pop();
    }
    return 0;

}