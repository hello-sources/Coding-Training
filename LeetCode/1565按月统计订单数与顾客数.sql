# Write your MySQL query statement below
select left(order_date, 7) month,
count(order_id) order_count,
count(distinct customer_id) customer_count
from Orders
where invoice > 20
group by left(order_date, 7);