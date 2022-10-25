# Write your MySQL query statement below
select employee_id, CASE WHEN 
    MOD(employee_id, 2) = 1 AND name not rlike '^M' THEN salary ELSE 0 END AS bonus
    from employees
     order by employee_id;

# Write your MySQL query statement below
select employee_id, if (employee_id % 2 = 1 and left(name, 1) != 'M', salary, 0) as bonus
from Employees order by employee_id