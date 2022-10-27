# Write your MySQL query statement below
select employee_id from (
    select employee_id from Employees
    union all
    select employee_id from Salaries
) as t
group by employee_id
having COUNT(employee_id) = 1
order by employee_id;


# union 和 union all都可以起到关联结果集的作用,区别在于,union会自动去除关联的两个结果集中的重复数据
# union all则不会主动去除两个结果集中的重复数据,会展示所有的数据
# 每个派生表都必须有别名
# 由于使用union all 导致employee_id可能是一样的，having COUNT = 1时候就过滤出来了