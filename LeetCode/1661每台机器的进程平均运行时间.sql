# Write your MySQL query statement below
select machine_id, round(
    sum(case when activity_type = 'end' then timestamp else -timestamp end) / count(distinct process_id)
    , 3) processing_time
from Activity
group by machine_id
order by machine_id;