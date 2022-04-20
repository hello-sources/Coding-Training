# Write your MySQL query statement below
select project_id, employee_id from (
    select project_id, t1.employee_id,
    rank() over(partition by t1.project_id order by t2.experience_years desc) r
    from Project t1
    left join Employee t2
    on t1.employee_id = t2.employee_id
) t
where r = 1;