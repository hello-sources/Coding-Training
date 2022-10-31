# Write your MySQL query statement below
select date_id, make_name, count(distinct lead_id) unique_leads, 
count(distinct partner_id) unique_partners
from DailySales
group by date_id, make_name;

# 学到个新玩意，group by可以是多个，表示对哪几个字段进行分组