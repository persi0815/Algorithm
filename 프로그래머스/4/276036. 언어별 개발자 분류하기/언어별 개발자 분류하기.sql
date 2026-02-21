SELECT 
    CASE 
        /* A: Front End 스킬 보유 AND Python 스킬 보유 */
        WHEN (SKILL_CODE & (SELECT SUM(CODE) FROM SKILLCODES WHERE CATEGORY = 'Front End'))
             AND (SKILL_CODE & (SELECT CODE FROM SKILLCODES WHERE NAME = 'Python')) THEN 'A'
        /* B: C# 스킬 보유 */
        WHEN (SKILL_CODE & (SELECT CODE FROM SKILLCODES WHERE NAME = 'C#')) THEN 'B'
        /* C: 그 외 Front End 스킬 보유 */
        WHEN (SKILL_CODE & (SELECT SUM(CODE) FROM SKILLCODES WHERE CATEGORY = 'Front End')) THEN 'C'
    END AS GRADE,
    ID,
    EMAIL
FROM DEVELOPERS
/* GRADE가 부여된 사람만 조회하기 위해 전체를 서브쿼리로 감싸거나 HAVING 사용 */
HAVING GRADE IS NOT NULL
ORDER BY GRADE ASC, ID ASC;