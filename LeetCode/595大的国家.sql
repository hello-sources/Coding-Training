# Write your MySQL query statement below
select name, population, area from World where area >= 3000000 or population >= 25000000;

# 通过union连接两个查询，加快查询速度
SELECT
    name, population, area
FROM
    world
WHERE
    area >= 3000000
UNION
SELECT
    name, population, area
FROM
    world
WHERE
    population >= 25000000