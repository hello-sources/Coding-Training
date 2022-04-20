# Write your MySQL query statement below
select distinct a.order_id, a.customer_id, a.order_type
from Orders a
left join Orders b
on a.customer_id = b.customer_id and a.order_type != b.order_type
where b.order_type is null or b.order_type = 1
order by a.order_id;  