# Write your MySQL query statement below
select min(abs(p1.x - p2.x)) shortest
from point p1
left join point p2
on p1.x != p2.x;