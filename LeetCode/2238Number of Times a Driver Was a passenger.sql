# Write your MySQL query statement below
select distinct t1.driver_id, count(t2.ride_id) cnt 
from (select distinct driver_id from Rides) t1
left join Rides t2 on t1.driver_id = t2.passenger_id
group by t1.driver_id;