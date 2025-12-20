# slightly more efficient solution, but uses more mem
class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        
        for i in range(9):
            lst = []
            for j in range(9):
                if board[i][j] != '.':
                    if board[i][j] not in lst:
                        lst.append(board[i][j])
                    else:
                        return False

        for j in range(9):
            lst = []
            for i in range(9):
                if board[i][j] != '.':
                    if board[i][j] not in lst:
                        lst.append(board[i][j])
                    else:
                        return False

        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                lst = []
                for p in range(3):
                    for q in range(3):
                        if board[i+p][j+q] != '.':
                            if board[i+p][j+q] not in lst:
                                lst.append(board[i+p][j+q])
                            else:
                                return False

        return True


# my solution (could be refined in some parts, but this is an O(1) problem after all)
"""
class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        def valid(x):
            seen = set()
            return not any((i in seen and i != '.') or seen.add(i) for i in x)
        
        box = [[] for i in range(9)]
        boxn = 0
        for i in range(9):
            row = board[i]
            if not valid(row):
                return False
            
            if i == 3:
                boxn=3
            elif i == 6:
                boxn=6

            box[boxn]+=row[0:3]
            box[boxn+1]+=row[3:6]
            box[boxn+2]+=row[6:9]

            if not valid(box[boxn]):
                return False
            if not valid(box[boxn+1]):
                return False
            if not valid(box[boxn+2]):
                return False

            if not valid([j[i] for j in board]):
                return False
            
        return True
"""
