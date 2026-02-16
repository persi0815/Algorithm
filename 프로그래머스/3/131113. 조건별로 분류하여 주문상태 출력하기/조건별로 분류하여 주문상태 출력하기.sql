SELECT 
    ORDER_ID, 
    PRODUCT_ID, 
    DATE_FORMAT(OUT_DATE, '%Y-%m-%d') AS OUT_DATE, -- 날짜 형식 맞추기
    CASE -- 케이스로 나뉘는건 이렇게
        WHEN OUT_DATE <= '2022-05-01' THEN '출고완료'
        WHEN OUT_DATE > '2022-05-01' THEN '출고대기'
        ELSE '출고미정' -- NULL인 경우
    END AS "출고여부"
FROM FOOD_ORDER 
ORDER BY ORDER_ID ASC
