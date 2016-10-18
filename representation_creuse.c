#include <stdio.h>
#include <stdlib.h>

typedef struct {
        int i; // long du doc (types)
        int *tabTermes; // indices des termes (array)
        float *tabPoids; // poids des termes (array)
} Document;

Document createDocument(int length, int termes[], float poids[])
{
        int i;
        Document d;
        d.i = length;
        // calloc = initialiser tableau avec zéro
        d.tabTermes = (int*) calloc(d.i, sizeof(int));
        d.tabPoids = (float*) calloc(d.i, sizeof(float));

        for (i = 0; i < length; ++i)
        {
                d.tabTermes[i] = termes[i];
                d.tabPoids[i] = poids[i];
        }

        return d;
}

void printDocument(Document d)
{
        int i;
        for (i = 0; i < d.i; ++i)
        {
                printf("[%d] %.3f - ", d.tabTermes[i], d.tabPoids[i]);
        }
        printf("\n");
}

float similariteDocuments(Document d1, Document d2)
{
        float similarite = 0;
        int p1, p2;
        p1 = p2 = 0;
        while (p1 < d1.i && p2 < d2.i) {
                if (d1.tabTermes[p1] == d2.tabTermes[p2]) {
                        similarite += d1.tabPoids[p1++] * d2.tabPoids[p2++];
                        continue;
                }
                d1.tabTermes[p1] < d2.tabTermes[p2] ? p1++ : p2++;
        }

        return similarite;
}

void premierExemple()
{
        Document d1, d2;

        int termesD1[] = {7, 3000, 85000};
        float poidsD1[] = {.1, 3.2, .08};

        int termesD2[] = {13, 300, 85000, 700003, 1000283};
        float poidsD2[] = {.7, 5.3, 4.5, .01, 2.5};

        d1 = createDocument(3, termesD1, poidsD1);
        d2 = createDocument(5, termesD2, poidsD2);

        printDocument(d1);
        printDocument(d2);

        printf("Similarité: %f\n", similariteDocuments(d1, d2));
}

int main()
{
        premierExemple();

        return 0;
}
