# Write your MySQL query statement below
select person1, person2, count(*) call_count, sum(duration) total_duration
from (select 
    if (from_id > to_id, to_id, from_id) person1,
    if (from_id < to_id, to_id, from_id) person2,
    duration
from Calls
) c 
group by person1, person2;