# Write your MySQL query statement below
SELECT E1.firstName,E1.lastName,E2.city,E2.state FROM PERSON E1 LEFT JOIN ADDRESS E2 ON E1.personId=E2.personId;