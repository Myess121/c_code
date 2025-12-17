class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        stack<char>e;
        int i = 0;
        while(s[i] != '\0'){
            if(e.empty()){
                e.push(s[i]);
            }else{
                if(e.top() == '('&&s[i] == ')'){
                    e.pop();
                }else if(e.top() == '['&&s[i] == ']'){
                    e.pop();
                }else if(e.top() == '{'&&s[i] == '}'){
                    e.pop();
                }else{
                    e.push(s[i]);
                }
            }
            i++;
        }
        if(e.empty()){
            return true;
        }
        return false;

    }
};