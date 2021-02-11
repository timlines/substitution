#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    if (argc != 2) // check for two command lines
    {
        printf("Usage: ./substition key\n");
        return 1;
    }

    int n = strlen(argv[1]);

    if (n != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        int j = isalpha(argv[1][i]); //is it a letter
        if (j == 0) // Check if it's not a letter
        {
            printf("Key must only contain letters.\n"); // message
            return 1; // secrect error code
        }
    }

    for (int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
            printf("Key must not contain repeated characters.\n"); // message
            return 1; // secrect error code
            }
        }
    }

    string plaintext = get_string("plaintext:  "); //get text to encrypt
    printf("ciphertext: "); // ciphertext heading.

    for (int i = 0, p = strlen(plaintext); i < p; i++)
    {
        if (isupper(plaintext[i]))
        {
            int l = plaintext[i];
            l = l - 65;
            char c = toupper(argv[1][l]);
            printf("%c", c);
        }
        else if (islower(plaintext[i]))
        {
            int l = plaintext[i];
            l = l - 97;
            char c = tolower(argv[1][l]);
            printf("%c", c);
        }
        else // if it's not upper or lowercase don't rotate it.
        {
            printf("%c", plaintext[i]);
        }
    }




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

"Key must contain 26 characters."
"Key must only contain letters.""
"Key must not contain repeated characters."


LOG 1:25 PM

Okay I have the key working so that it rejects all the bad keys.

Now to make the encryption work. In caesar I had to first
change the string to a int, but in this case the string
is already providing characters so that's one less thing.

The first thing here is to get the plain text and make sure
I can iterate every charcter of that text and print it.

Okay so the next step is to change the normal letters into
numbers so that A = 0, and B = 1, and so on.

that way I could just type in key[1] to get a and so on.

Great that basic implementation works if you enter just
capital letters. The next problem is lowercase, then also
matching the spacing and puncuation. Then also, the key needs
to match the same puncuation and case.

Great, so with a few modication it will now accept upper and lower
case and then also carry over the spaces, puncutaion and
numbers.

The next problem is that it's not preserving the case,
becasue it's simply just writing whatever the key that was
given. The extra probelm with that is that the key can be
upper or lower case, but either way it needs to match the
case of the plaintext.

So I'll have to think about how I can do that?

Wow, that was easier than I expected becasuse of the ctype
thing called, tolower and toupper. So now it works?

Time to test it!

*/
