# Write your MySQL query statement below
select A.name as 'Employee'
from Employee as A, Employee as B
where a.managerId = b.id and a.salary > b.salary;