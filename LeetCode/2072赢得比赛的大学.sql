# Write your MySQL query statement below
with v1(cnt) as (select count(*) from NewYork where score >= 90),
    v2(cnt) as (select count(*) from California where score >= 90)
select case when v1.cnt > v2.cnt then 'New York University'
            when v1.cnt < v2.cnt then 'California University'
            else 'No Winner' end as winner 
from v1, v2;