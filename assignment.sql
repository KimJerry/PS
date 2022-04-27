/*
 -- student table -- 
ID	NAME	DEPT_NAME	TOT_CRED

-- takes table -----
ID	COURSE_ID	SEC_ID	SEMESTER	YEAR	GRADE

-- course table ---
COURSE_ID	TITLE	DEPT_NAME	CREDITS
*/
DECLARE
    st_dept_name varchar(20);
    st_cred numeric(22, 3);
    st_name varchar(20);
    st_id varchar(5);
    st_course_id varchar(8);
    st_semester varchar(6);
    st_year numeric(22, 4);
    st_grade varchar(2);
    st_course_title varchar(50);
    st_course_credit numeric(22, 2);

    CURSOR c1 is
        SELECT dept_name
        FROM student
        ORDER BY dept_name;

    CURSOR c2 is
        SELECT NAME
        FROM student
        --WHERE dept_name = st_dept_name;
        ORDER BY NAME;

BEGIN
    OPEN c1;
    LOOP
        FETCH c1 INTO st_dept_name;
        EXIT WHEN c1%NOTFOUND;
        dbms_output.put_line(st_dept_name);
        OPEN c2;
        LOOP
            FETCH c2 INTO st_name;
            EXIT WHEN c2%NOTFOUND;
            dbms_output.put_line('      '||st_name);
        END LOOP;
        CLOSE c2;
    END LOOP;
    CLOSE c1;
END;