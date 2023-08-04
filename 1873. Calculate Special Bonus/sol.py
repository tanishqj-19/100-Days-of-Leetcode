import pandas as pd

def calculate_special_bonus(employees: pd.DataFrame) -> pd.DataFrame:
    employees['bonus'] = employees.apply(lambda x: x['salary'] if int(x['employee_id']) % 2 != 0 and x['name'][0] != 'M' else 0, axis = 1)

    return employees[['employee_id', 'bonus']].sort_values(by='employee_id')
