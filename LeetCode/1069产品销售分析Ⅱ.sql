# Write your MySQL query statement below
select product_id, sum(quantity) as total_quantity 
from Sales
group by product_id;