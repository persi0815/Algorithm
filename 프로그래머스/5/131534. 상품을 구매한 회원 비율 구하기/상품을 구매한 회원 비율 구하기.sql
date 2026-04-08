-- 2021년에 가입한 전체 회원들 중 상품을 구매한 회원수
-- 상품을 구매한 회원의 비율: 2021년에 가입한 회원 중 상품을 구매한 회원수 / 2021년에 가입한 전체 회원 수
-- 년, 월 별로 출력

-- 2021년에 가입한 회원들
WITH TOTAL_USERS AS (
    SELECT COUNT(DISTINCT USER_ID) AS TOTAL
    FROM USER_INFO
    WHERE YEAR(JOINED) = 2021
)

SELECT YEAR(O.SALES_DATE) AS YEAR, 
       MONTH(O.SALES_DATE) AS MONTH, 
       
       -- 2021년에 가입한 전체 회원들 중 상품을 구매한 회원수
       COUNT(DISTINCT O.USER_ID) AS PURCHASED_USERS, 
       
       -- 2021년에 가입한 회원 중 상품을 구매한 회원수 / 2021년에 가입한 전체 회원 수
       ROUND(
            COUNT(DISTINCT O.USER_ID) * 1.0 / T.TOTAL
       , 1) AS PUCHASED_RATIO
        
FROM USER_INFO U JOIN ONLINE_SALE O ON U.USER_ID = O.USER_ID -- 상품 구입한 회원들
     JOIN TOTAL_USERS T ON 1=1
WHERE YEAR(U.JOINED) = 2021
GROUP BY YEAR(O.SALES_DATE), MONTH(O.SALES_DATE) 
ORDER BY YEAR ASC, MONTH ASC