SELECT 
    a.employee_id, 
    a.name, 
    COUNT(b.employee_id) AS reports_count, 
    ROUND(AVG(b.age)) AS average_age
FROM Employees a
JOIN Employees b
    ON a.employee_id = b.reports_to
GROUP BY a.employee_id, a.name
ORDER BY a.employee_id;