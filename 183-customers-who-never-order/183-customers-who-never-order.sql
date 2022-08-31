# Write your MySQL query statement below
SELECT name AS CUSTOMERS from CUSTOMERS WHERE ID NOT IN(SELECT customerId FROM ORDERS)