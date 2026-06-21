# 150. Evaluate Reverse Polish Notation

class Solution:        
    def evalRPN(self, tokens: list[str]) -> int:
        def isInt(x):
            try:
                int(x)
                return True
            except ValueError:
                try:
                    float(x)
                    return True
                except ValueError:
                    return False
                
        stk = []
        for token in tokens:
            if isInt(token): stk.append(token)
            else:
                print(token)
                print(stk)
                second = int(stk.pop())
                first = int(stk.pop())

                if token == '+': stk.append(first + second)
                if token == '-': stk.append(first - second)
                if token == '*': stk.append(first * second)
                if token == '/': stk.append(first / second)

        return int(stk.pop())
