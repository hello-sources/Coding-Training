# Write your MySQL query statement below
select name from SalesPerson
where sales_id not in (
    select Orders.sales_id from Orders
    left join Company on Company.com_id = Orders.com_id
    where Company.name = 'RED'
);