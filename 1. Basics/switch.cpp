//Using if-else

if (n == 10)
    System.out.print1n("= 10");
else if (n == 90)
    System.c out.println("= 90");
else if (n == -3)                                      //---->Only one block will be executed at once 
    System.out.println("= -3");
else
    System.out.println("non of the above");

switch (n) 
{
    case 10:
        System.out.println(") 10");
     case 90:
        System.out.printIn("= 90");
     case -3:                                          //----->Multiple blocks will be executed
        System.out.printIn("= -3");
    default:
        System.out.println("non of the above"):
}

//To stop multiple blocks from executing at the same time we use "break"
switch (n) {
     case 10:
         System. out.println("= 10");
         break;
     case 90:
         System. out println("= 90");
         break;
    case -3:
         System. out. .println("= -3");
         break;
    default:
         System. out .println("non of the above");
}

/*A switch statement is significantly faster than an if-else ladder if there are many nested if-else's involved. 
This is due to the creation of a jump table for switch during compilation. 
As a result, instead of checking which case is satisfied throughout execution, it just decides which case must be completed. 
The number of comparisons made is lesser hence, reducing the compile time. 
Hence, the switch would work better while selecting from a large set of values.*/

