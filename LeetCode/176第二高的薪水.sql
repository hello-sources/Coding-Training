# 子查询数据出虚表嵌套查询虚表,如果查询不到会返回null
# limit x offset y 每页x个，偏移y
select (select distinct salary from Employee
order by salary desc
limit 1 offset 1) SecondHighestSalary;


# 或者使用ISNULL代替
select IFNULL (
    (select distinct salary from Employee
    order by salary desc
    limit 1 offset 1),
    NULL
) AS SecondHighestSalary