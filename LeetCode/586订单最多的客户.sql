# Write your MySQL query statement below
# select MAX(customer_number) as customer_number from Orders;
select customer_number from Orders
group by customer_number
order by COUNT(*) desc
limit 1;

# count(*) 统计所有行数,在统计结果的时候，不会忽略列值为NULL
# count(1) 括了忽略所有列，用1代表代码行，在统计结果的时候，不会忽略列值为NULL。
# count(列名) 统计只包含列名那一列，忽略值为null

select customer_number from Orders
group by customer_number
order by count(customer_number) desc # count(customer_number)也是可以的
limit 1;