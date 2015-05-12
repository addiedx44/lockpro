# lockpro
Recover lost Master Lock combinations.

## Overview
Given the third number, this will generate a list of possible combinations for
this type of Master Lock combination lock:

![Master Lock Model No. 1500D](http://puu.sh/hKFDK/fe09b399ea.jpg)

## How to use
First, you'll need to find the third number in the combination. For that,
you're on your own. The gist of of it is:

1. Start the dial at 0
2. Find the set of 12 numbers
    1. While pulling on the shackle, turn the dial until it gets stuck in a
       groove and take note of the number. If this groove is between two
       numbers, use the halfway point, e.g., between 13 and 14, use 13.5.
    2. Turn the dial to the next number, and repeat until you've got 12 numbers.
3. Find the third number
    1. From the set of 12 numbers, eliminate the halfway numbers. This should
       leave you with 5 remaining.
    2. From the 5 remaining numbers, there should be 4 that end in the same
       number, e.g., 5, 15, 25, 35. Eliminate these, and you're left with the
       third number.

Once you've got that third number, run lockpro like so:

    ./lockpro THIRD

where THIRD is your combination's third number. This will produce the list of
potential combinations.

From here, it's a matter of trying each combination until you find the one that
works.
