#include<iostream>
#include<math.h>
#include<stack>
using namespace std;

class evaluations{
    public:
    stack<int>st;
    int flag = 0,mul = 10;
    int ans(string s){
        for(int i = s.size()-1; i>=0; i--){
            
            if(s[i]>= '0' && s[i]<= '9'){
                int a = s[i] - '0';
                if(flag == 0){
                    st.push(a);   
                }
                else if(flag == 1){
                    a = a*10;
                    int num = st.top();
                   st.pop();
                    st.push(num + a);
                }
                 flag = 1;
            }
            else if(s[i] == ' '){
                flag = 0;
                mul = mul*10;
            }
            
            
            else{
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                switch(s[i]){
                    case '+':
                        st.push(op1 + op2);
                        break;
                    case '-':
                        st.push(op1 - op2);
                        break;
                    case '*':
                        st.push(op1 * op2);
                        break;
                    case '/':
                        st.push(op1 / op2);
                        break;
                    case '^':
                        st.push(pow(op1,op2));
                        break;

                    default:
                        break;         
                }
            }
        }
        return st.top();
    }
};

int main(){
    evaluations obj1;
    cout<<obj1.ans("- + 7 * 4 5 ^ 2 0")<<endl;
    return 0;

}
