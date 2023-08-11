import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:

    unique_salary = employee.salary.drop_duplicates(keep='first')

    sorted_salary = sorted(unique_salary, reverse=True)

    if(len(sorted_salary) < 2):
        return pd.DataFrame(data = [None], columns=['SecondHighestSalary'])

    
    return pd.DataFrame(data = [sorted_salary[1]], columns=['SecondHighestSalary'])
