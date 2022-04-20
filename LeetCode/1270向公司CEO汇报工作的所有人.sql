# Write your MySQL query statement below
select t1.employee_id
from Employees t1 
join Employees t2 on t1.manager_id = t2.employee_id
join Employees t3 on t2.manager_id = t3.employee_id
where t1.employee_id != 1 and t3.manager_id = 1; 