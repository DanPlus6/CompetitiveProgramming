# Author: DanPlus6 // David Fu
# Problem Name: 2879. Display the First Three Rows
# Problem Code: display-the-first-three-rows
# Problem URL:  https://leetcode.com/problems/display-the-first-three-rows/description/
import pandas as pd

def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame: return employees.head(3)
