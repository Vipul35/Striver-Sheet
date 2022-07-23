# Write your MySQL query statement below
SELECT MAX(salary) SecondHighestSalary FROM EMPLOYEE WHERE salary<(SELECT MAX(salary) FROM EMPLOYEE);