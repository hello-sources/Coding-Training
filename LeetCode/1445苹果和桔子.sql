# Write your MySQL query statement below
select sale_date, sum(case when fruit = 'apples' then sold_num else -sold_num end) diff
from Sales
group by sale_date
order by sale_date;