# Write your MySQL query statement below
select problem_id from Problems
where likes / (likes + dislikes) < 0.6
order by problem_id;