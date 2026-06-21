# 150. Evaluate Reverse Polish Notation

class Solution:        
    def evalRPN(self, tokens: list[str]) -> int:           
        stk = []
        for token in tokens:
            if token not in {'+','-','*','/'}: stk.append(int(token))
            else:
                second = stk.pop()
                first = stk.pop()

                if token == '+': stk.append(first + second)
                if token == '-': stk.append(first - second)
                if token == '*': stk.append(first * second)
                if token == '/': stk.append(int(first / second))

        return stk[0]
