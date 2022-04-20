# Write your MySQL query statement below
select p.project_id, round(sum(e.experience_years) / count(p.project_id), 2) average_years
from Project p
left join Employee e
on p.employee_id = e.employee_id
group by p.project_id;