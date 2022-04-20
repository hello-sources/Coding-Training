# Write your MySQL query statement below
select seller_id from Sales
group by seller_id
having sum(price) >= all(
    select sum(price) from Sales group by seller_id
);

# 法二
# Write your MySQL query statement below
select seller_id from (
    select seller_id, rank() over(order by sum(price) desc) as r 
    from Sales group by seller_id
) s 
where s.r = 1;