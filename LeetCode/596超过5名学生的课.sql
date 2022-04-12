# Write your MySQL query statement below
select class from (
    select class, count(distinct student) num
    from Courses 
    group by class
) as temp
where num >= 5;

# 法二
select class from Courses
group by class
having count(distinct student) >= 5;