# Tour-Planner
•	The Tour Planner is a C Language GUI based application that helps the tourists in planning their tour of a completely anonymous place he wants to explore. This application plans the tour such that the user can save more time in exploring maximum places rather than wasting time in reaching his destinations.  It takes the information such as location, the list of places the user wants to visit the start and end place of the tour to make the plan.
•	Initially, it takes the information from the user whether he wants to travel a specific number of destinations and return to source location (ROUND TRIP) or whether he wants to travel to a particular destination (SINGLE TRIP). Then it will show the list of places of attractions of that place from which the user can opt for the places of his choice according to his priority. Then it takes the start and the end place of the tour. After making an analysis of the distances between all the places into account a route map with the shortest possible path is displayed.
•	This application is very useful to all the people who love to travel in planning a time efficient trips where he or she can travel between the cities through the most optimum route possible.



#ALGORITHM
       
1.	start
2.	main screen with options
a.	if option == “round trip”
•	Window of trending destinations
•	Window displaying list of sources which is to be selected by user
•	TSP () function is called and output is displayed to the user
•	Pressing any key results back to main screen 
b.	if option==” single trip”
•	Window displaying list of sources which is to be selected by user 
•	Window displaying list of destinations which is to be selected by user 
•	Dijkstra () function is called and output is displayed to the user
•	Pressing any key results back to main screen 
c.	if option==”user manual”
•	A text which gives idea of our application
•	Pressing any key results back to main screen
d.	if option==” about”
•	A text which shows developers details
•	Pressing any key results back to main screen
e.	if option==” exit”
•	EXITS OUT OF APPLICATION
3.	END

