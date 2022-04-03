# Write your MySQL query statement below
SELECT
	`name` AS NAME,
	SUM( amount ) AS BALANCE 
FROM
	Users
	LEFT JOIN Transactions ON Users.account = Transactions.account 
GROUP BY
	Transactions.account 
HAVING
	balance > 10000