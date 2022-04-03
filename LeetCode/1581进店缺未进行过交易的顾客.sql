# Write your MySQL query statement below
select customer_id, COUNT(customer_id) count_no_trans
from visits v 
left join transactions trans on v.visit_id = trans.visit_id
where amount is NULL
group by customer_id;