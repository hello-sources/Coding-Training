# Write your MySQL query statement below
select stu.id, stu.name
from Students stu
left join Departments dep 
on stu.department_id = dep.id
where dep.id is null;