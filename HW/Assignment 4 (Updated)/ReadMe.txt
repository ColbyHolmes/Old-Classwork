Colby Holmes
Assignment 4
Submission 2

I found the time to update my code, luckily. Please, in the future, don't change
assignments after they have been submitted.

All of the code should work as asked, with a small exception in program 2.

I didn't see that we needed to do diagonal checking at first, and my algorithm
was written in such a way that it would be hard to fix this without redoing the 
whole thing. I put in a "bandage" the checks the left diagonal, but couldn't get
a similar fix on the right side.

EX.
A B A     it will pick up that the B cluster is connected diagonally
A A B     but will think that the A in the top right corner is a
A A B     separate cluster.

Besides this SNAFU, everything should work as the new assignment sheet wants.