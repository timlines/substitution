#include <stdio.h>
#include <cs50.h>


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substition key\n");
        return 1;
    }
    string p = get_string("plaintext:  "); //get text to encrypt
    printf("ciphertext: "); // ciphertext heading.
    printf("VKXXN"); //encrypted text
    printf("\n"); //Print a new line
    return 0;
}

/*

LOG
11 FEB 2021, 9:37 AM

Today I'm implementing a program called substitution, that
encypts messages using a substitution cipher. I'm actually
kind of excited about this because it was fun to do the caeser
code and it's a fun to think about sending secretly encoded
messages to friends. Now, I just need a way that anyone can
access these codes online or on an app.I'll have to worry
about that later first I'll have to write substituion.

SPECIFICATION

Must accept a single command-line argument, the key.
The key is case insensitive.

If no command line is present or there are multiple,
it should print an error message and a value of 1.

If the key is invalid
    -as by not containing 26 characters,
    -contaning any character that is not alphabetic
    -not containin each letter exactly once.
It should print an error message, and a value of 1.

Your program must output plaintext with a newline and then
prompt the user for a string of plaintext using get_string.

Your program must output ciphertext followedd by the plaintext
corresponding ciphertext with each alphabetical character in the
plaintext substituted for the corresponding character in the
ciphertext; non-alphabetical charactgers should be outputted
unchanged.

Your program must preserve case; capitalized letters must
remain capitalized letters; lowercase letters must remain
lowercase letter.

After outputting ciphertext, you should print a newline.
Your program should then exit by returning 0 from main.

More details on the problem here:
https://cs50.harvard.edu/x/2021/psets/2/substitution/#:~:text=o









*/
