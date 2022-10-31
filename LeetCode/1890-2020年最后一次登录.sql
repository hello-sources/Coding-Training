# Write your MySQL query statement below
select user_id, MAX(time_stamp) as last_stamp
from Logins 
where year(time_stamp) = '2020'
group by user_id;

# group by user_id，是因为用户可以登录好多次
# year(time_stamp)是取得对应日期的年份