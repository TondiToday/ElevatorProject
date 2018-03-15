# ElevatorProject
COMP-SCI 303, A project to efficiently simulate a system of n Elevators traversing m floors

Changes:
Separated function definitions to cpp files
Added header guards for header files
Created Dispatcher cpp/h files
Created Utilities cpp/h for misc. functions and enums
Created ElevatorOperations cpp/h for elevator_op and customer_input functions
Integrated Dispatcher logic with the elevator_op
	***ISSUE: The elevator does not update its floor number after moving

Things still to do:
Generate Users when elevator reaches floor and pass on User Requests to that elevator
-	Most of the code should already be ready, we just need to pass that into onto the elevator
Keep track of user numbers and waiting times
Expand dispatcher logic for worst case
Catch user input exceptions
Error check
