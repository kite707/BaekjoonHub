-- 코드를 입력하세요
-- SELECT * FROM FIRST_HALF;
-- SELECT * FROM JULY;
SELECT F.flavor as TOTAL FROM FIRST_HALF F right outer JOIN JULY J ON J.SHIPMENT_ID=F.SHIPMENT_ID group by J.flavor order by sum(J.TOTAL_ORDER)+sum(F.TOTAL_ORDER) desc limit 3;