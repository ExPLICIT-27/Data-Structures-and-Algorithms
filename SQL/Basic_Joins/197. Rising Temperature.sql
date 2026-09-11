<-- solution 1  (nested statements) -->
SELECT W1.id FROM Weather W1 
WHERE W1.temperature > (SELECT W2.temperature from Weather W2 WHERE W2.recordDate = SUBDATE(W1.recordDate, 1));

<-- sol 2 (self join) -->

SELECT W1.id FROM Weather W1 
JOIN Weather W2
ON W1.recordDate = ADDDATE(W2.recordDate, 1)
WHERE W1.temperature > W2.temperature;