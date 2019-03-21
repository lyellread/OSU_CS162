## REFLECTION -- LYELL READ -- FINAL ##


What decisions or assumptions did you make about how to design your program?
	I assumed that the design plan already layed out in the readme was enough to get going. That assumption was quite right.
	I assumed that I would be using inheritance -- another right descision.

What was your test plan for your program?
	Test every time I added a new large function. That way, I would know where the issue was. I even went as far as making
	a shell script to run the `make clean`, `clear`, and `make` commands as well as run the program. By doing that, 
	all I had to do was `remake` (I aliased `remake`=`./remake.sh`) to rebuild and rerun the program.

How did your testing work out? What bugs did you uncover through testing? How did you fix those bugs?
	My testing worked out great. I uncovered a couple small bugs, but overall, becayse I tested as I coded, i had no major
	bugs... that is until I confused rows and cols, which I quickly realized i was being stupid and I fixed those issues.
	Probably the largest bug was that i used a switch statement that broke and reran where I wanted it to return. I spent an
	hour or two debugging (over and over) a separate function I assumed was the mistake, until I thought about this. 

What problems or obstacles did you run into while you were developing your program? How did you resolve these?
	I encountered the problem of how to make the grid print with all the information above it. I had to trial and error where 
	to put the clear screen function so that I could get what I wanted there. 

What resources were useful to you in solving problems you ran into? Were there helpful websites or Stack Overflow posts? What help 
did you get from the TAs and/or the Instructor? Were specific parts of the course notes helpful?
	I visited the c++ docs online, but mostly I rely on my own debugging (statements, error messages, rereading...) to
	debug this program.

