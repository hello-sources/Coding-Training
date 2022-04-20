# Write your MySQL query statement below
select employee_id, department_id
from Employee
where primary_flag = 'Y' 
union select employee_id, department_id from Employee
group by employee_id
having count(department_id) = 1
order by employee_id;

# 法二
# Write your MySQL query statement below
select employee_id, 
    if (count(department_id) = 1, department_id, max(if (primary_flag = 'Y', department_id, null)))  
    as department_id 
from Employee 
group by employee_id
order by employee_id;