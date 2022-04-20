# Write your MySQL query statement below
select w.name warehouse_name, sum(p.width * p.length * p.height * w.units) volume
from Warehouse w 
left join Products p 
on w.product_id = p.product_id
group by w.name;