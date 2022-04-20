# Write your MySQL query statement below
select round((sum(order_date = customer_pref_delivery_date) / count(*) * 100), 2) immediate_percentage 
from Delivery;