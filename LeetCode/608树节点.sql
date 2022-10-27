# Write your MySQL query statement below
select id, 
    case
        when tree.id = (select tree.id from tree where tree.p_id is null) then 'Root'
        when tree.id in (select tree.p_id from tree) then 'Inner'
        else 'Leaf'
    end as type
from tree
order by id;

# if语句 if(Ccondition, A, B) 如果条件成立就是A， 否则就是B
# Write your MySQL query statement below
select t.id, 
    if(isnull(t.p_id), 'Root', if (t.id in (select p_id from tree), 'Inner', 'Leaf')) Type
from tree t
order by t.id;