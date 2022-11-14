class Solution {
public:
    struct Node{
        char elem;
        struct Node* next;
    };
    typedef struct Node* Stack;
    typedef struct Node* Position;
    void PushStack(Stack *S,char elem)
    {
        Position current;
        current = (Position)malloc(sizeof(struct Node));
        if(!current)
            exit(0);
        current->elem = elem;
        current->next = *S;
        *S = current;
    }
    void PopStack(Stack &S)
    {
        Position p = S;
        S = S->next;
        free(p);
    }
    bool isValid(const string& s){
        Stack S = nullptr;
        Position current;
        for (auto c : s)
        {
            if(c=='('||c=='['||c=='{')
                PushStack(&S,c);
            else {
                if(S==nullptr)
                   return false; 
                else if (c == ')' && S->elem == '(')
                    PopStack(S);
                else if (c == ']' && S->elem == '[')
                    PopStack(S);
                else if (c == '}' && S->elem == '{')
                    PopStack(S);
                else
                    return false;
            }
        }
        if(S!=nullptr)
            return false;
        return true;
    }
};
