# Write your MySQL query statement below
# select MAX(customer_number) as customer_number from Orders;
select customer_number from Orders
group by customer_number
order by COUNT(*) desc
limit 1;