# Write your MySQL query statement below
select min(log_id) start_id, max(log_id) end_id
from (
    select log_id, log_id - row_number() over() diff
    from logs
) t
group by diff;