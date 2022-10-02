# Parking-Lot
There is a multi-storey parking lot that can hold up to 'n' cars at any given point in time. Each slot is given a number starting at 1 increasing with increasing distance from the entry point in steps of one. I want to create an automated ticketing system that allows my customers use my parking lot without human intervention.

When a car enters my parking lot, I want to have a ticket issued to the driver. The ticket issuing process includes us documenting the registration number (number plate) and the colour of the car and allocating an available parking slot to the car before actually handing over a ticket to the driver (we assume that our customers are
nice enough to always park in the slots allocated to them). The customer should be allocated a parking slot which is nearest to the entry. At the exit the customer returns the ticket which then marks the slot they were using as being available. Due to government regulation, the system should provide me with the ability to find out:

a) Registration numbers of all cars of a particular colour.

b) Slot number in which a car with a given registration number is parked.

c) Slot numbers of all slots where a car of a particular colour is parked.

We interact with the system via a simple set of commands which produce
a specific output.

* It should provide us with an interactive command prompt based shell where commands can be typed in
* It should accept a filename as a parameter at the command prompt and read the commands from that file


Commands are,

* create_parking_lot 50 where 50 is value of n.
* park KA01R9988 blue
* unpark KA01R9977 red
* find_parking_slot 5
* find_car_number KL01R6699
* find_car blue
