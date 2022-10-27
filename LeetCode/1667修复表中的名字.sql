# Write your MySQL query statement below
select user_id,
concat(upper(left(name, 1)), lower(substring(name, 2))) name
from users
order by user_id;

# concat 多个拼接函数
# left(str, ind)从左边ind截取字符串str
# SUBSTRING(str, ind) 从ind开始截取到str最后
# UPPER(str) 将字符串中所有字符转为大写
# LOWER(str) 将字符串中所有字符转为小写
# length(str) str的长度