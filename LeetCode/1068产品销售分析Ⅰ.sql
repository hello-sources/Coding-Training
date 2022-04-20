# Write your MySQL query statement below
select product_name, year, price 
from Sales s, Product p
where s.product_id = p.product_id;

# left join on
select product_name, year, price 
from Sales s
left join Product p
on p.product_id = s.product_id;