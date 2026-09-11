/*
grouped by machine id
avg(end - start) for all the processes of that machine id
*/

SELECT DISTINCT a1.machine_id, ROUND(AVG(a2.timestamp - a1.timestamp), 3) AS processing_time FROM Activity a1
JOIN Activity a2 on a1.machine_id = a2.machine_id AND a1.process_id = a2.process_id 
WHERE a2.activity_type = 'end' AND a1.activity_type = 'start' GROUP BY a1.machine_id;