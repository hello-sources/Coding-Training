# Write your MySQL query statement below
select project_id from Project 
group by project_id
having  count(employee_id) >= all(select count(employee_id) from Project group by project_id);