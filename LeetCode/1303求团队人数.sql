# Write your MySQL query statement below
select employee_id, count(employee_id) over(partition by team_id) as team_size 
from Employee
order by employee_id;

# 法二
# Write your MySQL query statement below
select employee_id, (select count(*) from Employee e2 where e2.team_id = e1.team_id) as team_size
from Employee e1;

# 法三
# Write your MySQL query statement below
select e1.employee_id, e2.team_size 
from Employee e1, (select team_id, count(*) as team_size from Employee e2 group by team_id) e2 
where e1.team_id = e2.team_id