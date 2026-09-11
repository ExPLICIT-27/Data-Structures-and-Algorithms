<-- select the unique names of customers, followed by the number of times they visited without making a transaction -->


SELECT DISTINCT V.customer_id, COUNT(V.visit_id) as count_no_trans FROM Visits V 
LEFT JOIN TRANSACTIONS T ON V.visit_id = T.visit_id 
WHERE T.transaction_id is null GROUP BY V.customer_id;