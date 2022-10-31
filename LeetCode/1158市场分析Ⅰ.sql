# Write your MySQL query statement below
select u.user_id buyer_id, u.join_date, ifnull(o.cnt, 0) orders_in_2019
from Users u
left join (
    select buyer_id, count(order_id) cnt 
    from Orders 
    where year(order_date) = '2019'
    group by buyer_id
) as o
on u.user_id = o.buyer_id;

# 注意多表查询的时候，产生的新表，必须有一个别名： as 别名 或者直接 别名