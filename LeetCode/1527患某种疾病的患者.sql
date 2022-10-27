# Write your MySQL query statement below
select * from Patients
where conditions rlike '^DIAB1|.*\\sDIAB1';

# Write your MySQL query statement below
select patient_id, patient_name, conditions
from Patients where conditions like "DIAB1%"
or conditions like "% DIAB1%"