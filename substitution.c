#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    //Patikrina, ar ivestas tik vienas command-line argumentas.
    if (argc == 2)
    {
        string s = argv[1];
        for (int i = 0; i < strlen(s); i++)
        {
            //Patikrina, ar ivestas argumentas yra sudarytas tik iš 26 simbolių.
            if (strlen(s) == 26)
            {
                //Patikrina, ar ivestas argumentas yra sudarytas tik is raidziu.
                for (int j = 0; j < strlen(s); j++)
                {
                    if (isalpha(s[j]) == 0)
                    {
                        printf("Key must contain only alphabetic characters\n");
                        return 1;
                    }
                }

                //Patikrina, ar ivestame argumente nera vienodu raidziu.
                for (int x = 0; x < 26; x++)
                {
                    for (int y = x + 1; y < 26; y++)
                    {
                        if (s[y] == s[x])
                        {
                            printf("Key must contain no duplicate characters\n");
                            return 1;
                        }
                    }
                }
            }
            else
            {
                printf("Key must contain 26 characters\n");
                return 1;
            }
        }

        //Papraso vartotojo ivesti teksta, kuris bus koduojamas.
        string text = get_string("plaintext: ");
        printf("ciphertext: ");

        for (int k = 0; k < strlen(text); k++)
        {
            //Patikrina kiekviena ivesto teksto simboli, ar jis yra raide. Veliau logika:
            //jei ivesto teksto simbolis yra mazoji raide ir kodo mazoji - pavercia teksto simboli kodo raide;
            //jei ivesto teksto simbolis yra mazoji raide, o kodo didzioji - kodo raide pavercia mazaja ir tada pavercia teksto simboli kodo raide;
            //jei ivesto teksto simbolis yra didzioji raide ir kodo didzioji - pavercia teksto simboli kodo raide;
            //jei ivesto teksto simbolis yra dizioji raide, o kodo mazoji - kodo raide pavercia didziaja ir tada pavercia teksto simboli kodo raide;
            if (isalpha(text[k]))
            {
                //Jei ivesto teksto simbolis yra raide, tikrina, ar ji yra didzioji.
                if (isupper(text[k]))
                {
                    //Kiekviena ivesto teksto simboli pavercia abeceles indeksu (A-1, B-2, C-3 ir t. t.)
                    int abc = text[k] - 65;
                    //Tikrina, ar atitinkamas rakto simbolis pagal abeceles indeksa yra didzioji/mazoji raide.
                    if (isupper(argv[1][abc]))
                    {
                        abc = argv[1][abc];
                        printf("%c", abc);
                    }
                    else
                    {
                        abc = toupper(argv[1][abc]);
                        printf("%c", abc);
                    }
                }

                //Jei ivesto teksto simbolis yra raide, tikrina, ar ji yra mazoji.
                else if (islower(text[k]))
                {
                    //Kiekviena ivesto teksto simboli pavercia abeceles indeksu (A-1, B-2, C-3 ir t. t.)
                    int abc = text[k] - 97;
                    //Tikrina, ar atitinkamas rakto simbolis pagal abeceles indeksa yra didzioji/mazoji raide.
                    if (islower(argv[1][abc]))
                    {
                        abc = argv[1][abc];
                        printf("%c", abc);
                    }
                    else
                    {
                        abc = tolower(argv[1][abc]);
                        printf("%c", abc);
                    }
                }
            }

            else
            {
                printf("%c", text[k]);
            }
        }

        printf("\n");
        return 0;
    }

    else
    {
        printf("Usage: ./ substitution key\n");
        return 1;
    }
}