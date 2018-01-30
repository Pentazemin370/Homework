/*
 THIS CODE IS MY OWN WORK, IT WAS WRITTEN WITHOUT CONSULTING
 A TUTOR OR CODE WRITTEN BY OTHER STUDENTS - Dennis Park
*/


//1
SELECT distinct pnum
FROM supplier,proj,spj
WHERE supplier.city = "London"
AND proj.city = "London"
AND supplier.snum = spj.snum
and proj.jnum = spj.jnum
ORDER BY pnum

//2
SELECT distinct spj.jnum
FROM proj, spj, part
WHERE proj.jnum = spj.jnum
AND part.pnum = spj.pnum
AND spj.jnum IN (
SELECT spj.jnum
 
FROM proj, spj, part, supplier
WHERE proj.jnum = spj.jnum
AND supplier.snum = spj.snum
AND part.pnum = spj.pnum
AND part.city = proj.city
AND supplier.city = proj.city
)
ORDER by jnum

//3
SELECT distinct pnum
FROM part
WHERE pnum IN (
SELECT pnum
FROM spj, proj
WHERE city = "Paris"
AND spj.jnum = proj.jnum
)

//4
SELECT distinct pnum
FROM part
WHERE pnum NOT IN (
SELECT pnum
FROM spj, proj
WHERE city = "Paris"
AND spj.jnum = proj.jnum
)

//5
SELECT distinct proj.jnum
FROM proj, spj
WHERE proj.jnum = spj.jnum
AND spj.pnum IN (
SELECT spj.pnum
FROM part, spj, supplier
WHERE part.pnum = spj.pnum
AND supplier.snum = "s4"
AND spj.snum = supplier.snum
)
ORDER BY jnum

//6
SELECT distinct sname
FROM supplier
WHERE snum NOT IN (
SELECT snum
FROM part, spj
WHERE weight >18
and spj.pnum = part.pnum
)
ORDER BY sname

//7
SELECT snum, sname
FROM supplier
WHERE snum IN (
SELECT snum
FROM part, spj
WHERE pname = "Nut"
AND part.pnum = spj.pnum
)
ORDER BY snum , sname

//8
SELECT snum, sname
FROM supplier
WHERE snum NOT IN (
SELECT snum
FROM part, spj
WHERE pname = "Nut"
AND part.pnum = spj.pnum
)
ORDER BY snum , sname

//9
SELECT distinct spj.jnum
 
FROM proj, spj, part
WHERE proj.jnum = spj.jnum
AND part.pnum = spj.pnum
AND spj.jnum NOT IN (
SELECT spj.jnum
 
FROM proj, spj, part
WHERE proj.jnum = spj.jnum
AND part.pnum = spj.pnum
AND part.city = proj.city
)
ORDER by spj.jnum, proj.city

//10
SELECT distinct spj.jnum, jname
 
FROM proj, spj, part
WHERE proj.jnum = spj.jnum
AND part.pnum = spj.pnum
AND spj.jnum NOT IN (
SELECT spj.jnum
 
FROM proj, spj, part
WHERE proj.jnum = spj.jnum
AND part.pnum = spj.pnum
AND part.color = "Red"
)
ORDER by jnum, jname

//11
SELECT distinct spj.jnum, jname
 
FROM proj, spj, part
WHERE proj.jnum = spj.jnum
AND part.pnum = spj.pnum
AND spj.jnum NOT IN (
SELECT spj.jnum
 
FROM proj, spj, part
WHERE proj.jnum = spj.jnum
AND part.pnum = spj.pnum
AND part.color != "Red"
)
ORDER by jnum, jname

//12
SELECT distinct snum,sname
from supplier A
WHERE not exists(
select null
from proj
where jnum not in (select jnum 
from spj
where spj.snum = A.snum
and spj.jnum = proj.jnum
)
and jnum in ( select jnum
from proj
where city = "Rome")
)

ORDER BY snum,sname

//13
SELECT distinct snum,sname
from supplier A
WHERE exists(
select null
from proj
where jnum not in (select jnum 
from spj
where spj.snum = A.snum
and spj.jnum = proj.jnum
)
and jnum in ( select jnum
from proj
where city = "Rome")
)

ORDER BY snum,sname

//14

SELECT distinct spj.snum,sname
FROM proj, spj, supplier A
WHERE spj.snum=A.snum
AND proj.jnum = spj.jnum
AND proj.city = "Rome"
AND A.snum IN(
select spj.snum
from proj
where jnum not in (select jnum 
from spj
where spj.snum = A.snum
and spj.jnum = proj.jnum
)
and jnum in ( select jnum
from proj
where city = "Rome")
)

ORDER BY snum,sname

//15
SELECT distinct jnum, jname
FROM proj p
WHERE NOT EXISTS (
SELECT pnum
FROM part
WHERE 
pnum not in (SELECT pnum 
FROM spj
WHERE jnum = p.jnum
)
 and pnum in (SELECT pnum
FROM spj
WHERE jnum = "j3"
)

)
ORDER BY jnum, jname

//16
SELECT distinct jnum, jname
FROM proj p
WHERE NOT EXISTS(
SELECT *
FROM part
WHERE pnum in (SELECT pnum
FROM spj
WHERE jnum = p.jnum)

AND pnum not in (SELECT pnum
FROM part
WHERE part.city = p.city)
)
ORDER BY jnum,jname

//17

SELECT snum,sname
FROM supplier s
WHERE NOT EXISTS (
SELECT *
FROM part
WHERE pnum not in (SELECT pnum
FROM spj
WHERE snum = s.snum)


AND pnum in (SELECT pnum
FROM part
WHERE color = "blue"
)
)

AND NOT EXISTS (SELECT pnum
FROM part
WHERE pnum IN (SELECT pnum 
From spj 
WHERE snum = s.snum)

AND pnum in (SELECT pnum
FROM part
WHERE color = "green")

)
ORDER BY snum,sname

//19
SELECT snum, sname
FROM supplier s
WHERE NOT EXISTS (
SELECT *
FROM part
WHERE pnum not IN (SELECT pnum
FROM spj
WHERE snum = s.snum)

AND pname = "Bolt"

)

//20
SELECT distinct spj.snum, sname
FROM supplier,spj,proj
WHERE supplier.snum = spj.snum
AND proj.jnum = spj.jnum
AND spj.snum NOT IN (
SELECT spj.snum
from supplier,spj,proj
WHERE supplier.snum = spj.snum
AND proj.jnum = spj.jnum
AND proj.city !="Rome"
)
ORDER BY spj.snum,sname

