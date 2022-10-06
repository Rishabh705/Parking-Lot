# Parking-Lot
# Problem Statement
There is a multi-storey parking lot that can hold up to 'n' cars at any given point in time. Each slot is given a number starting at 1 increasing with increasing distance from the entry point in steps of one. I want to create an automated ticketing system that allows my customers use my parking lot without human intervention.

When a car enters my parking lot, I want to have a ticket issued to the driver. The ticket issuing process includes us documenting the registration number (number plate) and the colour of the car and allocating an available parking slot to the car before actually handing over a ticket to the driver (we assume that our customers are
nice enough to always park in the slots allocated to them). The customer should be allocated a parking slot which is nearest to the entry. At the exit the customer returns the ticket which then marks the slot they were using as being available. Due to government regulation, the system should provide me with the ability to find out:

a) Registration numbers of all cars of a particular colour.

b) Slot number in which a car with a given registration number is parked.

c) Slot numbers of all slots where a car of a particular colour is parked.

We interact with the system via a simple set of commands which produce
a specific output.

* It should provide us with an interactive shell.
* It should accept a filename as a parameter at the command prompt and read the commands from that file
* It is assumed that user enters number plates of India.
* Entered colours of cars are red, blue, yellow, green, black, white, grey, silver, orange, purple.

Commands are,

* create_parking_lot 50 where 50 is value of n.
* park KA01R9988 blue
* unpark KA01R9977 red
* find_parking_slot 5
* find_car_number KL01R6699
* find_car blue

# Code outline

- 2D vector slots - stores data regarding entry
 
+ lower(string) - to convert string to lowercase
+ countWords(string) - count number of words in a line

Class Valid - to check validity of input
+ checkNumber(string) - to check number plate
+ checkColour(string) - to check colour

Class Parking Entry : Valid - to maintain entry
+ exists(string) - to check if number plate already exists
+ park(string, string, int) - to park car
+ unpark(string) - to unpark car

Class Details : Valid - to find out details 
+ findCar(string, int, bool) -  to find details of car.
+ findByClr(string) - to find car by colour

