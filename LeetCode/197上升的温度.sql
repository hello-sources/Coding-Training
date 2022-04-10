# Write your MySQL query statement below
select w.id as 'Id' from Weather w 
join Weather t on datediff(w.recordDate, t.recordDate) = 1
and w.temperature > t.temperature;