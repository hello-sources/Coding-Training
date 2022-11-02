# Write your MySQL query statement below
select p.product_id, p.product_name from Product p
left join Sales s 
on s.product_id = p.product_id
group by s.product_id
having min(s.sale_date) >= '2019-01-01'
and max(s.sale_date) <= '2019-03-31';

# where 和 having 区别
# where 对查询数据进行过滤，
# having 用于对已分组的数据进行过滤 having 和 group by 必须配合使用
# 区别：where是数据从磁盘读入内存的时候进行判断，而having是磁盘读入内存后再判断。