# Write your MySQL query statement below
select product_id, round(sum(total) / sum(units), 2) average_price
from (
    select p.product_id as product_id, p.price * u.units as total,
    u.units as units
    from Prices p
    left join UnitsSold u on p.product_id = u.product_id
    where u.purchase_date between p.start_date and p.end_date
) calc
group by product_id;