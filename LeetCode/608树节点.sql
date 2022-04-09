# Write your MySQL query statement below
select id, 
    case
        when tree.id = (select tree.id from tree where tree.p_id is null) then 'Root'
        when tree.id in (select tree.p_id from tree) then 'Inner'
        else 'Leaf'
    end as type
from tree
order by id;