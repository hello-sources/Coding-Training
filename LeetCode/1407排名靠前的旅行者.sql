# Write your MySQL query statement below
select name, coalesce(sum(distance), 0) as travelled_distance 
from Users left join Rides on Users.id = Rides.user_id
group by name
order by travelled_distance desc, name;

# coalesce提供一个缺省值， 函数按顺序对其参数求值并返回第一个非 NULL 值。
# 如果字段不存在为NULL ，则返回第二个参数值
# ifnull(a, b) 如果a为缺省值，则返回b，否则返回a