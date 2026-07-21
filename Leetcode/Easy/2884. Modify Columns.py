# Author: DanPlus6 // David Fu
# Problem Name: 2884. Modify Columns
# Problem Code: modify-columns
# Problem URL:  https://leetcode.com/problems/modify-columns/
import pandas as pd

def modifySalaryColumn(df: pd.DataFrame) -> pd.DataFrame: 
    df['salary']*=2
    return df
