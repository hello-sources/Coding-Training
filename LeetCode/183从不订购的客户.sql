# Write your MySQL query statement below
select customers.name as 'Customers' from Customers 
where customers.id not in (select customerId from Orders);