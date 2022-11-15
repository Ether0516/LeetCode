# LeetCode
class Solution {
public:
    #define MAX_SIZE 10000
    typedef struct Node{
        long long int *Array;
        int TopOfStack;
    }Node;
    typedef Node* Stack;
    void CreatStack(Stack &S){
        S = (Stack) malloc(sizeof (Node));
        if(!S)
            exit(0);
        S->Array = new long long int[MAX_SIZE];
        if(!S->Array)
            exit(0);
        S->TopOfStack = 0;
    }
    void PushStack(Stack &S, long long int elem){
        S->Array[S->TopOfStack] = elem;
        S->TopOfStack++;
    }
    int PopStack(Stack &S){
        int elem = S->Array[S->TopOfStack-1];
        S->TopOfStack--;
        return elem;
    }
    int evalRPN(vector<string>& tokens) {
        Stack S;
        CreatStack(S);
        for (int i = 0;i< tokens.size();i++)
        {
            long long int num1,num2;
            if(tokens[i] == "+")
            {
                num1 = PopStack(S);
                num2 = PopStack(S);
                PushStack(S,num1+num2);
            }
            else if(tokens[i] == "-")
            {
                num1 = PopStack(S);
                num2 = PopStack(S);
                PushStack(S,num2-num1);
            }
            else if(tokens[i] == "*")
            {
                num1 = PopStack(S);
                num2 = PopStack(S);
                PushStack(S,num1*num2);
            }
            else if(tokens[i] == "/")
            {
                num1 = PopStack(S);
                num2 = PopStack(S);
                PushStack(S,num2/num1);
            }
            else
            {
                int num = 0;
                int cut = 0;
                for(int j = 0;j <tokens[i].size();j++ )
                {

                    if(tokens[i][j] == '-')
                        cut++;
                    else
                        num  = num*10+(long long int)tokens[i][j]-'0';
                }
                if(cut == 1)
                    num = -num;
                PushStack(S,num);
            }
        }
        return PopStack(S);
    }
};
