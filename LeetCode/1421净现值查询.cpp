# Write your MySQL query statement below
select q.id, q.year, if (isNULL(n.npv), 0, n.npv) npv 
from Queries q
left join NPV n
on n.year = q.year and n.id = q.id
order by q.id;