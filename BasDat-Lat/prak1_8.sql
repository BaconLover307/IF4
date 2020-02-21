select
	employees.first_name, employees.last_name
from
	employees, dept_manager, departments
where
	dept_manager.dept_no = departments.dept_no and departments.dept_name = "Quality Management" and employees.emp_no = dept_manager.emp_no;
;